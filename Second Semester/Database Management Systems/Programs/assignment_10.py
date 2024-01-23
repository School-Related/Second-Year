## read a csv file and convert it into json file
import csv
import json

# Open the CSV file and read its contents
with open('data.csv', newline='') as csv_file:
    csv_reader = csv.DictReader(csv_file)

    # Create an empty list to hold the JSON objects
    json_objects = []

    # Loop through each row in the CSV file
    for row in csv_reader:
        # Convert the row to a JSON object and append it to the list
        json_objects.append(row)

# Write the JSON objects to a file with indentation
with open('data.json', 'w') as json_file:
    json.dump(json_objects, json_file, indent=4)
