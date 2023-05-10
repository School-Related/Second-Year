import java.io.IOException;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

public class FileLoggingExample {
    private static final Logger logger = Logger.getLogger(FileLoggingExample.class.getName());

    public static void main(String[] args) {
        FileHandler fileHandler;
        try {
            // Specify the file path for logging
            String filePath = "./logfile.log";

            // Create the FileHandler with append mode
            fileHandler = new FileHandler(filePath, true);

            // Set the formatter for the FileHandler
            SimpleFormatter formatter = new SimpleFormatter();
            fileHandler.setFormatter(formatter);

            // Add the FileHandler to the logger
            logger.addHandler(fileHandler);

            // Log some messages
            logger.log(Level.INFO, "This is an informational message.");
            logger.log(Level.WARNING, "This is a warning message.");

            // Close the FileHandler
            fileHandler.close();

            System.out.println("Log messages written to the file.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
