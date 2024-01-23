

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

-- Test Triggers


MariaDB [store]> select * from AUTHOR;
+-------------------+------------+
| Name              | SoldCopies |
+-------------------+------------+
| Fyodor Dostoevsky |        500 |
+-------------------+------------+
1 row in set (0.001 sec)

MariaDB [store]> UPDATE BOOK SET SoldCopies = 600 WHERE Isbn = '9783161';
Query OK, 1 row affected (0.004 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [store]> select * from AUTHOR;
+-------------------+------------+
| Name              | SoldCopies |
+-------------------+------------+
| Fyodor Dostoevsky |        600 |
+-------------------+------------+
1 row in set (0.000 sec)

