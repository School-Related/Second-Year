import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import java.net.URL;

public class DownloadImage {

    public static void main(String[] args) throws Exception {

        try {
            String fileName = "digital_image_processing.jpg";
            String website = "https://upload.wikimedia.org/wikipedia/commons/thumb/e/e7/Everest_North_Face_toward_Base_Camp_Tibet_Luca_Galuzzi_2006.jpg/495px-Everest_North_Face_toward_Base_Camp_Tibet_Luca_Galuzzi_2006.jpg" + fileName;

            System.out.println("Downloading File From: " + website);

            URL url = new URL(website);
            InputStream inputStream = url.openStream();
            OutputStream outputStream = new FileOutputStream(fileName);
            byte[] buffer = new byte[2048];

            int length = 0;

            while ((length = inputStream.read(buffer)) != -1) {
                System.out.println("Buffer Read of length: " + length);
                outputStream.write(buffer, 0, length);
            }

            inputStream.close();
            outputStream.close();

        } catch (Exception e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }
}
