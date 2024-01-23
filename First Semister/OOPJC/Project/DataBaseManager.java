/*
 * An Important class, As it controls a lot of the important variables, and all interactions with the Local CSV File databases. 
 */

package org.howmuch;

import com.mongodb.client.MongoDatabase;
import com.opencsv.CSVReader;
import com.opencsv.CSVWriter;
import org.apache.commons.io.FileUtils;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;

public class DataBaseManager {

    public static String LOCAL_DATAFOLDER = "/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/data";
    public static String LOCAL_CSV_FOLDER = "/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/data/csvs";
    public static String LOCAL_IMG_FOLDER = "/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/data/images";
    public static String LOCAL_BACKUP_DATAFOLDER = "/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/data_backup";
    public static String LOCAL_BACKUP_CSV_FOLDER = "/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/data_backup/csvs";
    public static String LOCAL_BACKUP_IMG_FOLDER = "/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/data_backup/images";
    public static String USERDATA_FILEPATH = "/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/data/user_details.csv";
    public static String BACKUP_USERDATA_FILEPATH = "/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/data_backup/user_details.csv";
    public static String LOCAL_DATEFILE = "/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/data/dateUpdated.txt";
    public static String LOCAL_MONGODATEFILE = "/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/data/MongoDateUpdated.txt";
    public static String LOCAL_BACKUP_DATEFILE = "/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/data_backup/dateUpdated.txt";

    static String currentUsername = "guest";
    static int USER_INDEX = -1;
    static String currentPassword = "guest";
    static int currentScore = 0;

    /**
     * Brutally Clear the images and csv in the local Database and start fresh with
     * only files.
     **/
    public static void clearLocalDatabase() {
        try {
            // Delete all pre existing images
            File data_deleter = new File(LOCAL_IMG_FOLDER);
            listFilesForFolder(data_deleter);
            for (File subfile : Objects.requireNonNull(data_deleter.listFiles())) {
                if (subfile.isDirectory()) {
                    for (File f : Objects.requireNonNull(subfile.listFiles())) {
                        f.delete();
                    }
                }
            }

            // Also clear the csv files.
            data_deleter = new File(LOCAL_CSV_FOLDER);
            listFilesForFolder(data_deleter);
            for (File subfile : Objects.requireNonNull(data_deleter.listFiles())) {
                subfile.delete();
            }

            // Recreate them.
            File createfiles = new File(LOCAL_BACKUP_CSV_FOLDER + "/" + Main.Topics[0].toLowerCase() + ".csv");
            createfiles.createNewFile();
            createfiles = new File(LOCAL_BACKUP_CSV_FOLDER + "/" + Main.Topics[1].toLowerCase() + ".csv");
            createfiles.createNewFile();
            createfiles = new File(LOCAL_BACKUP_CSV_FOLDER + "/" + Main.Topics[2].toLowerCase() + ".csv");
            createfiles.createNewFile();
            createfiles = new File(LOCAL_BACKUP_CSV_FOLDER + "/" + Main.Topics[3].toLowerCase() + ".csv");
            createfiles.createNewFile();
        } catch (Exception e) {
            System.out.println("Some io excepition occured");
        }
    }

    /*
     * Simply displays every file in a directory
     */
    public static void listFilesForFolder(final File folder) {
        Arrays.stream(folder.listFiles()).forEach(fileEntry -> {
            if (fileEntry.isDirectory()) {
                listFilesForFolder(fileEntry);
            } else {
                System.out.println(fileEntry.getName());
                System.out.println(fileEntry.getPath());
            }
        });
    }

    /*
     * Adds a new user to the local CSV Database. Creates that file if it doesnt
     * exist.
     */
    public static void addNewUser() {
        System.out.println("gonna add new user");
        File userDatafile = new File(USERDATA_FILEPATH);

        try (CSVReader reader = new CSVReader(new FileReader(userDatafile), ',')) {
            List<String[]> csvBody = reader.readAll();
            USER_INDEX = csvBody.size();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        // append the new user to the login file.
        try (FileWriter userDataFileWriter = new FileWriter(userDatafile, true)) {

            // create CSVWriter object filewriter object as parameter
            try (CSVWriter writer = new CSVWriter(userDataFileWriter, CSVWriter.DEFAULT_SEPARATOR,
                    CSVWriter.NO_QUOTE_CHARACTER, CSVWriter.DEFAULT_ESCAPE_CHARACTER, CSVWriter.DEFAULT_LINE_END)) {

                String[] data = { currentUsername, currentPassword, String.valueOf(currentScore) };
                writer.writeNext(data);
                System.out.println("added new user");
            }

        } catch (IOException e) {
            System.out.println("Cant open user data file. ");
        }
    }

    public static void addDataToCSV(String filePath, String[] data) {
        File userDatafile = new File(filePath);

        // append the new user to the login file.
        try (FileWriter userDataFileWriter = new FileWriter(userDatafile, true)) {

            // create CSVWriter object filewriter object as parameter
            try (CSVWriter writer = new CSVWriter(userDataFileWriter, CSVWriter.DEFAULT_SEPARATOR,
                    CSVWriter.NO_QUOTE_CHARACTER, CSVWriter.DEFAULT_ESCAPE_CHARACTER, CSVWriter.DEFAULT_LINE_END)) {
                // System.out.println(Arrays.toString(data));
                writer.writeNext(data);
            }

        } catch (IOException e) {
            System.out.println("Cant open user data file. ");
        }
    }

    public static boolean doesUsernameExist(String username) {
        File inputFile = new File(USERDATA_FILEPATH);
        try (CSVReader reader = new CSVReader(new FileReader(inputFile), ',')) {
            List<String[]> csvBody = reader.readAll();
            for (String[] s : csvBody) {
                if (s[0].equals(username)) {
                    System.out.println("User Already Exists");
                    return true;
                }
            }
        } catch (IOException e) {
            System.out.println("couldnt create csvreader in username exists checker method. ");
        }
        return false;
    }

    public static boolean doesPasswordMatch(String username, String password) {
        File inputFile = new File(USERDATA_FILEPATH);
        try (CSVReader reader = new CSVReader(new FileReader(inputFile), ',')) {
            List<String[]> csvBody = reader.readAll();
            for (int i = 0; i < csvBody.size(); i++) {
                String[] s = csvBody.get(i);
                if (s[0].equals(username)) {
                    System.out.println("User Found");
                    if (s[1].equals(password)) {
                        System.out.println("Password Matches");
                        USER_INDEX = i;
                        return true;
                    } else
                        return false;
                }
            }
        } catch (IOException e) {
            System.out.println("couldnt create csvreader in password matching method");
        }
        return false;
    }

    public static List<String[]> getStoredUserScores() {
        File inputFile = new File(USERDATA_FILEPATH);
        List<String[]> csvBody = null;
        try (CSVReader reader = new CSVReader(new FileReader(inputFile), ',')) {
            csvBody = reader.readAll();
            return csvBody;
        } catch (IOException e) {
            System.out.println("couldnt create csvreader in userscore method");
        }
        return csvBody;
    }

    public static void updateUserScore() {

        File inputFile = new File(USERDATA_FILEPATH);

        List<String[]> csvBody;
        try (CSVReader reader = new CSVReader(new FileReader(inputFile), ',')) {
            csvBody = reader.readAll();
            csvBody.get(USER_INDEX)[2] = String.valueOf(currentScore);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        try (CSVWriter writer = new CSVWriter(new FileWriter(inputFile), ',')) {
            writer.writeAll(csvBody);
            writer.flush();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void createLocalDatabaseBackupOfUsers() {
        System.out.println("---------------CREATING LOCAL DATABASE BACKUP of the user file------------");
        try {
            File sourceDirectory = new File(USERDATA_FILEPATH);
            File destinationDirectory = new File(BACKUP_USERDATA_FILEPATH);
            FileUtils.copyFile(sourceDirectory, destinationDirectory);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void createLocalDatabaseBackup() {
        try {
            System.out.println("---------------CREATING LOCAL DATABASE BACKUP------------");
            // Delete all pre existing images
            File data_deleter = new File(LOCAL_BACKUP_IMG_FOLDER);
            // listFilesForFolder(data_deleter);
            for (File subfile : Objects.requireNonNull(data_deleter.listFiles())) {
                if (subfile.isDirectory()) {
                    for (File f : Objects.requireNonNull(subfile.listFiles())) {
                        f.delete();
                    }
                }
            }
            data_deleter = new File(LOCAL_BACKUP_CSV_FOLDER);
            for (File subfile : Objects.requireNonNull(data_deleter.listFiles())) {
                subfile.delete();
            }
            File createfiles = new File(LOCAL_BACKUP_CSV_FOLDER + "/" + Main.Topics[0].toLowerCase() + ".csv");
            createfiles.createNewFile();
            createfiles = new File(LOCAL_BACKUP_CSV_FOLDER + "/" + Main.Topics[1].toLowerCase() + ".csv");
            createfiles.createNewFile();
            createfiles = new File(LOCAL_BACKUP_CSV_FOLDER + "/" + Main.Topics[2].toLowerCase() + ".csv");
            createfiles.createNewFile();
            createfiles = new File(LOCAL_BACKUP_CSV_FOLDER + "/" + Main.Topics[3].toLowerCase() + ".csv");
            createfiles.createNewFile();
        } catch (Exception e) {
            System.out.println("Some io excepition occured");
        }

        try {
            File sourceDirectory = new File(LOCAL_DATAFOLDER);
            File destinationDirectory = new File(LOCAL_BACKUP_DATAFOLDER);
            FileUtils.copyDirectory(sourceDirectory, destinationDirectory);

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static String[] readFromLocalDatabase(String Topic, int index) {
        File inputFile;
        if (Main.isLocalDatabaseUpToDate) {
            System.out.println("running from the local database");
            inputFile = new File(LOCAL_CSV_FOLDER + '/' + Topic.toLowerCase() + ".csv");
            try (CSVReader reader = new CSVReader(new FileReader(inputFile), ',')) {
                List<String[]> csvBody = reader.readAll();
                if (index > csvBody.size()) {
                    return csvBody.get(csvBody.size() - 1);
                }
                return csvBody.get(index);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }

        } else {
            System.out.println("running from the backup local database");
            inputFile = new File(LOCAL_BACKUP_CSV_FOLDER + '/' + Topic.toLowerCase() + ".csv");
            try (CSVReader reader = new CSVReader(new FileReader(inputFile), ',')) {
                List<String[]> csvBody = reader.readAll();
                if (index > csvBody.size()) {
                    String[] s;
                    s = csvBody.get(csvBody.size() - 1);
                    s[2] = s[2].replace("/data/", "/data_backup/");
                    return s;
                }
                String[] s;
                s = csvBody.get(index);
                s[2] = s[2].replace("/data/", "/data_backup/");
                return s;
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

    }

    public static int findLength(String Topic) {
        File inputFile;
        if (Main.isLocalDatabaseUpToDate) {
            inputFile = new File(LOCAL_CSV_FOLDER + '/' + Topic.toLowerCase() + ".csv");
        } else {
            inputFile = new File(LOCAL_BACKUP_CSV_FOLDER + '/' + Topic.toLowerCase() + ".csv");
        }
        try (CSVReader reader = new CSVReader(new FileReader(inputFile), ',')) {
            List<String[]> csvBody = reader.readAll();
            return csvBody.size();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
