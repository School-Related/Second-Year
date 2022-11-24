/*
 * The class that Performs the role of the heart of the code. It is what downloads the images from aamzon, and saves them. 
 * It scraps them, and we get the html page from the website. From there we can get the parts that we need as xml and then by parsing that xml
 * We can then get exactly what we want. 
 */

package org.howmuch;

import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

import com.groupdocs.conversion.Converter;
import com.groupdocs.conversion.filetypes.ImageFileType;
import com.groupdocs.conversion.options.convert.ImageConvertOptions;
import org.apache.commons.io.FileExistsException;
import org.w3c.dom.*;

import javax.xml.parsers.*;
import java.io.*;

import com.gargoylesoftware.htmlunit.*;
import com.gargoylesoftware.htmlunit.html.*;
import org.xml.sax.SAXException;

public class AmazonScrapper {
    static Converter converter;
    static ImageConvertOptions options;
    static WebClient webClient;
    static DocumentBuilder builder;
    static DocumentBuilderFactory factory;
    public static HashMap<Integer, String[]> searchQueries_map = new HashMap<>();
    public static String AMAZON_PREFIX_URL = "https://www.amazon.in/s?k=";

    AmazonScrapper() {
        options = new ImageConvertOptions();
        options.setFormat(ImageFileType.Png);
        fillSearchQueries();

        factory = DocumentBuilderFactory.newInstance();
        try {
            builder = factory.newDocumentBuilder();
        } catch (ParserConfigurationException e) {
            throw new RuntimeException(e);
        }

        // Define and declare basic web browser
        webClient = new WebClient(BrowserVersion.CHROME);
        webClient.getOptions().setCssEnabled(false);
        webClient.getOptions().setThrowExceptionOnFailingStatusCode(false);
        webClient.getOptions().setJavaScriptEnabled(false);
        webClient.getOptions().setThrowExceptionOnScriptError(false);
        webClient.getOptions().setPrintContentOnFailingStatusCode(false);
    }

    public static void fillSearchQueries() {
        System.out.println(Arrays.toString(Main.Topics));

//         This is the final stuff here, but is commented out for quicker debugging.

         searchQueries_map.put(0, new String[]{"Televisions", "Mobile Phones",
         "Laptops", "Iphone", "Macbook", "Refrigerators", "Washing Machines", "Smart Watches", "Gaming Laptops", "Computer Accessories", "GPUs", "Tablets",
         "Playstation", "Xbox"});
         searchQueries_map.put(1, new String[]{"Mens TShirts", "Formal Suits", "Mens Casual Wear", "Womens Casual Wear", "Womens Formal Wear", "Kids Clothes",
         "Makeup", "Beauty Products", "Analog Watches", "Earrings", "Necklaces",
         "Jewellery", "Branded Clothes", "Gold Jewellery", "Shoes"});
         searchQueries_map.put(2, new String[]{"Furniture", "Tape", "Stationary", "Cutlery", "Kitchen Products", "Toothpaste", "Chocolates", "Soaps", "Water Bottles", "Carpets", "Sofa Sets", "Tables and Desks", "Cleaning Products"});
         searchQueries_map.put(3, new String[]{"Gifts", "Car Appliances", "Diwali Lights", "Decoration", "Birthday Decor", "Lenses"});
//
//        searchQueries_map.put(0, new String[] { "8k OLED Televisions" });
//        searchQueries_map.put(1, new String[] { "Kurti", "Womens Dresses" });
//        searchQueries_map.put(2, new String[] { "Furniture" });
//        searchQueries_map.put(3, new String[] { "Gifts" });

        for (Map.Entry<Integer, String[]> m : searchQueries_map.entrySet()) {
            System.out.println(m.getKey() + " " + Arrays.toString(m.getValue()));
        }
    }

    /*
     * Main function that scraps amazon
     */
    public static void scrapAndSave() throws ParserConfigurationException, IOException, SAXException {
        for (Map.Entry<Integer, String[]> topic : searchQueries_map.entrySet()) {
            for (int topic_queries = 0; topic_queries < topic.getValue().length; topic_queries++) {
                for (int page = 1; page < 2; page++) {
                    try {
                        HtmlPage urlHTML = webClient.getPage(
                                AMAZON_PREFIX_URL + topic.getValue()[topic_queries] + "&crid=2JOW4XXQM1KWM&sprefix="
                                        + topic.getValue()[topic_queries] + "%2Caps%2C220&ref=sr_pg_" + page);
                        webClient.getCurrentWindow().getJobManager().removeAllJobs();

                        List<HtmlElement> searchResults_List = urlHTML
                                .getByXPath("//div[@data-component-type='s-search-result']");
                        int max = Math.min(searchResults_List.size(), 10);
                        for (int searchResult = 0; searchResult < max; searchResult++) {
                            HtmlDivision divv = (HtmlDivision) searchResults_List.get(searchResult);

                            StringBuilder xmlStringBuilder = new StringBuilder();
                            xmlStringBuilder.append("<?xml version=\"1.0\"?>");
                            xmlStringBuilder.append(divv.asXml());

                            ByteArrayInputStream input = new ByteArrayInputStream(
                                    xmlStringBuilder.toString().getBytes(StandardCharsets.UTF_8));
                            xmlParser(input,
                                    DataBaseManager.LOCAL_IMG_FOLDER + '/' + Main.Topics[topic.getKey()].toLowerCase()
                                            + '/' + topic.getValue()[topic_queries] + searchResult + ".webp",
                                    Main.Topics[topic.getKey()].toLowerCase());
                        }
                    } catch (IOException e) {
                        System.out.println("An error occurred: " + e);
                    }

                }
            }

        }
    }

    /*
     * Function that uses Xpath to go through the xml code, parse it and then return
     * the necessary strings.
     */
    public static void xmlParser(ByteArrayInputStream inputFile, String imageFilePath, String Topic)
            throws ParserConfigurationException, IOException, SAXException {

        String productName = "Sadly Not Found", productPrice = "Sadly Not Found", productImagePath = "Sadly Not Found";

        Document doc = builder.parse(inputFile);

        NodeList nListImages = doc.getElementsByTagName("img");
        Element imageElement = (Element) nListImages.item(0);
        String[] allImageURLs = imageElement.getAttribute("srcset").split(",");
        String hdImageIrl = allImageURLs[allImageURLs.length - 1].split(" ")[1];

        productName = imageElement.getAttribute("alt");
        productName = productName.replace(",", " -");
        if (productName.contains("Sponsored Ad - ")) {
            productName = productName.replace("Sponsored Ad - ", "");
        }
        System.out.println(productName);

        saveImage(hdImageIrl, imageFilePath);
        productImagePath = imageFilePath.replace(".webp", ".png");

        NodeList nList = doc.getElementsByTagName("span");
        for (int i = 0; i < nList.getLength(); i++) {
            Element currElement = (Element) nList.item(i);
            if (currElement.getAttribute("class").equals("a-price-whole")) {
                System.out.println("Price is: ");
                productPrice = currElement.getTextContent().replace(".", "");
                productPrice = productPrice.strip().replace(",", "");
                System.out.println(productPrice);
            }
        }
        String[] data = new String[] { productName, productPrice, productImagePath };
        if (productName.equalsIgnoreCase("Sadly Not Found") || productPrice.equalsIgnoreCase("Sadly Not Found")
                || productImagePath.equalsIgnoreCase("Sadly Not Found")) {
            System.out.println("Not adding this data");
        } else {
            if (!Main.isLocalDatabaseUpToDate) {
                DataBaseManager.addDataToCSV(DataBaseManager.LOCAL_CSV_FOLDER + '/' + Topic + ".csv", data);
            }
            if (Main.usingMongo) {
                if (!Main.isMongoUpToDate) {
                    MongoManager.addDataToMongo(Topic, data);
                }
            }
        }
    }

    /*
     * Simple function save the image, but coz we cant work with webp images, we
     * gotta convert them to png and save them right away.
     */
    public static void saveImage(String URLst, String filepath) {
        if (new File(filepath).exists()) {
            System.out.println("File Exists, gonna replace it");
            new File(filepath).delete();
        }

        try (InputStream in = new URL(URLst).openStream()) {
            Files.copy(in, Paths.get(filepath));
            converter = new Converter(filepath);
            filepath = filepath.replace(".webp", ".png");
            converter.convert(filepath, options);
            Files.delete(Path.of(filepath.replace(".png", ".webp")));

        } catch (IOException e) {
            System.out.println("we got some issue here with this file");
        }
    }

}
