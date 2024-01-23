
-- Use a cursor to calculate compound interest for each customer
-- and insert customer id and simple interest in another table
-- named TEMPLIST.
-- Customer(cust_id, Prinicipal_amount, Rate_of_interest, No. of
-- Years)

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


-- Create Cursors
USE store;

DROP TABLE IF EXISTS TEMPLIST;
CREATE TABLE TEMPLIST (
  cust_id INT PRIMARY KEY,
  Compound_interest DOUBLE
);

DROP PROCEDURE IF EXISTS calculate_interest;
DELIMITER //
CREATE PROCEDURE calculate_interest()
BEGIN
  DECLARE done INT DEFAULT FALSE;
  DECLARE custid INT;
  DECLARE princ_amt, rate, num_years, interest_amt, temp_amt DOUBLE;
  DECLARE cur CURSOR FOR SELECT cust_id, Principal_amount, Rate_of_interest, Years FROM Customer;
  
  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;
  
  OPEN cur;
  loop1: LOOP
    FETCH cur INTO custid, princ_amt, rate, num_years;
    IF done THEN
      LEAVE loop1;
    END IF;
    
    SET temp_amt = 1 + rate / 12;
    SET interest_amt = princ_amt * POWER(temp_amt, num_years * 12) - princ_amt;
    
    INSERT INTO TEMPLIST (cust_id, Compound_interest) VALUES (custid, interest_amt);
  END LOOP;
  CLOSE cur;
END//
DELIMITER ;

CALL calculate_interest();
SELECT * FROM TEMPLIST;
