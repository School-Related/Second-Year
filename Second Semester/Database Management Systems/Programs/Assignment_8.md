

MariaDB [(none)]>
MariaDB [(none)]> CREATE database if not exists store;
Query OK, 1 row affected (0.001 sec)

MariaDB [(none)]> use store;
Database changed
MariaDB [store]> CREATE TABLE BOOK (
    ->     Isbn VARCHAR(10) PRIMARY KEY,
    ->     Title VARCHAR(100),
    ->     SoldCopies INT
    -> );
Query OK, 0 rows affected (0.006 sec)

MariaDB [store]>
MariaDB [store]> CREATE TABLE WRITING (
    ->     Isbn VARCHAR(10),
    ->     Name VARCHAR(50),
    ->     PRIMARY KEY (Isbn, Name),
    ->     FOREIGN KEY (Isbn) REFERENCES BOOK(Isbn)
    -> );
Query OK, 0 rows affected (0.006 sec)

MariaDB [store]>
MariaDB [store]> CREATE TABLE AUTHOR (
    ->     Name VARCHAR(50) PRIMARY KEY,
    ->     SoldCopies INT
    -> );
Query OK, 0 rows affected (0.005 sec)

MariaDB [store]>
MariaDB [store]> CREATE TABLE Customer (
    ->     cust_id INT PRIMARY KEY,
    ->     Principal_amount DOUBLE,
    ->     Rate_of_interest DOUBLE,
    ->     Years INT
    -> );
Query OK, 0 rows affected (0.005 sec)

MariaDB [store]>
MariaDB [store]>
MariaDB [store]> INSERT INTO BOOK (Isbn, Title, SoldCopies)
    -> VALUES ('9783161', 'Crime and Punishment', 500);
Query OK, 1 row affected (0.001 sec)

MariaDB [store]>
MariaDB [store]> INSERT INTO WRITING (Isbn, Name)
    -> VALUES ('9783161', 'Fyodor Dostoevsky');
Query OK, 1 row affected (0.001 sec)

MariaDB [store]>
MariaDB [store]> INSERT INTO AUTHOR (Name, SoldCopies)
    -> VALUES ('Fyodor Dostoevsky', 500);
Query OK, 1 row affected (0.001 sec)

MariaDB [store]>
MariaDB [store]> INSERT INTO Customer (cust_id, Principal_amount, Rate_of_interest, Years)
    -> VALUES (1, 1000, 0.05, 5);
Query OK, 1 row affected (0.001 sec)

MariaDB [store]>
MariaDB [store]> -- Create Triggers
MariaDB [store]>
MariaDB [store]> DELIMITER //
MariaDB [store]> CREATE TRIGGER update_author_soldcopies
    -> AFTER UPDATE ON BOOK
    -> FOR EACH ROW
    -> BEGIN
    ->     IF NEW.SoldCopies != OLD.SoldCopies THEN
    ->         UPDATE AUTHOR
    ->         SET SoldCopies = SoldCopies + (NEW.SoldCopies - OLD.SoldCopies) WHERE Name IN (SELECT Name FROM WRITING WHERE Isbn = NEW.Isbn);
    ->     END IF;
    -> END//
Query OK, 0 rows affected (0.003 sec)

MariaDB [store]> DELIMITER ;
MariaDB [store]>
MariaDB [store]> delimiter $$
MariaDB [store]> CREATE TRIGGER insert_author_soldcopies
    -> AFTER INSERT ON WRITING
    -> FOR EACH ROW
    -> BEGIN
    ->     UPDATE AUTHOR
    ->     SET SoldCopies = SoldCopies + (SELECT SoldCopies FROM BOOK WHERE Isbn = NEW.Isbn)
    ->     WHERE Name = NEW.Name;
    -> END $$
Query OK, 0 rows affected (0.003 sec)

MariaDB [store]> delimiter ;
MariaDB [store]>
MariaDB [store]> select * from BOOK;
+---------+----------------------+------------+
| Isbn    | Title                | SoldCopies |
+---------+----------------------+------------+
| 9783161 | Crime and Punishment |        500 |
+---------+----------------------+------------+
1 row in set (0.002 sec)

MariaDB [store]> select * from AUTHOR;
+-------------------+------------+
| Name              | SoldCopies |
+-------------------+------------+
| Fyodor Dostoevsky |        500 |
+-------------------+------------+
1 row in set (0.001 sec)

MariaDB [store]> select * from WRITING;
+---------+-------------------+
| Isbn    | Name              |
+---------+-------------------+
| 9783161 | Fyodor Dostoevsky |
+---------+-------------------+
1 row in set (0.001 sec)

MariaDB [store]> select * from Customer;
+---------+------------------+------------------+-------+
| cust_id | Principal_amount | Rate_of_interest | Years |
+---------+------------------+------------------+-------+
|       1 |             1000 |             0.05 |     5 |
+---------+------------------+------------------+-------+
1 row in set (0.001 sec)

MariaDB [store]> USE store;
Database changed
MariaDB [store]>
MariaDB [store]> DROP TABLE IF EXISTS TEMPLIST;
Query OK, 0 rows affected (0.007 sec)

MariaDB [store]> CREATE TABLE TEMPLIST (
    ->   cust_id INT PRIMARY KEY,
    ->   Compound_interest DOUBLE
    -> );
Query OK, 0 rows affected (0.007 sec)

MariaDB [store]>
MariaDB [store]> DROP PROCEDURE IF EXISTS calculate_interest;
Query OK, 0 rows affected (0.003 sec)

MariaDB [store]> DELIMITER //
MariaDB [store]> CREATE PROCEDURE calculate_interest()
    -> BEGIN
    ->   DECLARE done INT DEFAULT FALSE;
    ->   DECLARE custid INT;
    ->   DECLARE princ_amt, rate, num_years, interest_amt, temp_amt DOUBLE;
    ->   DECLARE cur CURSOR FOR SELECT cust_id, Principal_amount, Rate_of_interest, Years FROM Customer;
    ->
    ->   DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;
    ->
    ->   OPEN cur;
    ->   loop1: LOOP
    ->     FETCH cur INTO custid, princ_amt, rate, num_years;
    ->     IF done THEN
    ->       LEAVE loop1;
    ->     END IF;
    ->
    ->     SET temp_amt = 1 + rate / 12;
    ->     SET interest_amt = princ_amt * POWER(temp_amt, num_years * 12) - princ_amt;
    ->
    ->     INSERT INTO TEMPLIST (cust_id, Compound_interest) VALUES (custid, interest_amt);
    ->   END LOOP;
    ->   CLOSE cur;
    -> END//
Query OK, 0 rows affected (0.002 sec)

MariaDB [store]> DELIMITER ;
MariaDB [store]>
MariaDB [store]> CALL calculate_interest();
Query OK, 1 row affected (0.001 sec)

MariaDB [store]> SELECT * FROM TEMPLIST;
+---------+-------------------+
| cust_id | Compound_interest |
+---------+-------------------+
|       1 | 283.3586785035118 |
+---------+-------------------+
1 row in set (0.000 sec)

MariaDB [store]>