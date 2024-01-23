-- Assignment 7 Triggers

-- Consider the following relational schema: BOOK (Isbn, Title,
-- SoldCopies) WRITING (Isbn, Name) AUTHOR (Name, SoldCopies)

-- Define a set of triggers for keeping SoldCopies in AUTHOR updated
-- with respect to: updates on SoldCopies in BOOK insertion of new tuples
-- in the WRITING relation

-- Create Database and Tables

CREATE database if not exists store;
use store;
CREATE TABLE BOOK (
    Isbn VARCHAR(10) PRIMARY KEY,
    Title VARCHAR(100),
    SoldCopies INT
);

CREATE TABLE WRITING (
    Isbn VARCHAR(10),
    Name VARCHAR(50),
    PRIMARY KEY (Isbn, Name),
    FOREIGN KEY (Isbn) REFERENCES BOOK(Isbn)
);

CREATE TABLE AUTHOR (
    Name VARCHAR(50) PRIMARY KEY,
    SoldCopies INT
);

CREATE TABLE Customer (
    cust_id INT PRIMARY KEY,
    Principal_amount DOUBLE,
    Rate_of_interest DOUBLE,
    Years INT
);


INSERT INTO BOOK (Isbn, Title, SoldCopies)
VALUES ('9783161', 'Crime and Punishment', 500);

INSERT INTO WRITING (Isbn, Name)
VALUES ('9783161', 'Fyodor Dostoevsky');

INSERT INTO AUTHOR (Name, SoldCopies)
VALUES ('Fyodor Dostoevsky', 500);

INSERT INTO Customer (cust_id, Principal_amount, Rate_of_interest, Years)
VALUES (1, 1000, 0.05, 5);

-- Create Triggers

DELIMITER //
CREATE TRIGGER update_author_soldcopies
AFTER UPDATE ON BOOK
FOR EACH ROW
BEGIN
    IF NEW.SoldCopies != OLD.SoldCopies THEN
        UPDATE AUTHOR
        SET SoldCopies = SoldCopies + (NEW.SoldCopies - OLD.SoldCopies) WHERE Name IN (SELECT Name FROM WRITING WHERE Isbn = NEW.Isbn);
    END IF;
END//
DELIMITER ;

delimiter $$
CREATE TRIGGER insert_author_soldcopies
AFTER INSERT ON WRITING
FOR EACH ROW
BEGIN
    UPDATE AUTHOR
    SET SoldCopies = SoldCopies + (SELECT SoldCopies FROM BOOK WHERE Isbn = NEW.Isbn)
    WHERE Name = NEW.Name;
END $$
delimiter ;

