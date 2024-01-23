/*
 * Class that does everything that we wanna do with mongodb. Things like inserting, deleting, creating and fetching data. 
 */

package org.howmuch;

import com.mongodb.MongoClient;
import com.mongodb.client.*;
import org.bson.Document;

public class MongoManager {
    static MongoDatabase database;
    public static String MONGO_DATABASE_NAME = "HowMuch";
    public static int MONGO_PORT_NO = 27017;
    public static String MONGO_HOST = "localhost";

    public static String[] fetchDataFromMongo(String currentTopic, int randomIndex) {
        MongoCollection<org.bson.Document> collection = database.getCollection(currentTopic);
        FindIterable<Document> iterDoc = collection.find();
        int i = 0;
        for (Document document : iterDoc) {
            System.out.println(document);
            if (i == randomIndex) {
                return new String[] { (String) document.get("Name"), document.getString("Price"),
                        document.getString("Image") };
            }
            i++;
        }
        return new String[] { "Sadly Not Found", "Sadly Not Found", "Sadly Not Found" };

    }

    public static boolean establishConnectionWithMongo() {
        // Creating a MongoDB client
        try {
            MongoClient mongoClient = new MongoClient(MONGO_HOST, MONGO_PORT_NO);
            // Connecting to the database
            database = mongoClient.getDatabase(MONGO_DATABASE_NAME);
            System.out.println("Connected Successfully to mongoDb");
            return true;

        } catch (Exception e) {
            System.out.println("Couldnt establish connection due to some reason");
            System.out.println(e.getMessage());
            return false;
        }
    }

    public static void addDataToMongo(String Topic, String[] data) {
        try {
            MongoClient mongoClient = new MongoClient(MONGO_HOST, MONGO_PORT_NO);
            // Connecting to the database
            database = mongoClient.getDatabase(MONGO_DATABASE_NAME);
            Topic = Topic.substring(0, 1).toUpperCase() + Topic.substring(1);
            MongoCollection<Document> collection = database.getCollection(Topic);
            Document dataDocToAdd = new Document();
            dataDocToAdd.append("Name", data[0]);
            dataDocToAdd.append("Price", data[1]);
            dataDocToAdd.append("Image", data[2]);
            collection.insertOne(dataDocToAdd);
            System.out.println(data[0]);
            System.out.println("\n\nAdded record to mongo---------\n\n");
        } catch (Exception e) {
            System.out.println("Couldnt add data");
        }
    }

    public static void clearMongoDb() {
        MongoCollection<Document> collection = database.getCollection(Main.Topics[0]);
        collection.drop();
        collection = database.getCollection(Main.Topics[1]);
        collection.drop();
        collection = database.getCollection(Main.Topics[2]);
        collection.drop();
        collection = database.getCollection(Main.Topics[3]);
        collection.drop();
    }
}
