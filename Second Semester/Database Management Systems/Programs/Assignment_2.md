# Basic commands

CREATE TABLE - creates a new table
alter table 
drop table
truncate table
select

# DCL Commands
GRANT - gives permissions to users
REVOKE - removes permissions from users


# DDL Commands
CREATE DATABASE - creates a new database
ALTER DATABASE - modifies a database
DROP DATABASE - deletes a database
CREATE INDEX - creates an index (search key)
DROP INDEX - deletes an index


# DML Commands

INSERT - inserts new records in a table
UPDATE - modifies the records in a table
DELETE - deletes records from a table
SELECT - extracts data from a database


# TCL Commands

COMMIT - saves changes
ROLLBACK - undoes changes
SAVEPOINT - sets a savepoint within a transaction
SET TRANSACTION - defines the transaction properties for the session


# Data Types

VARCHAR - stores variable length strings
CHAR - stores fixed length strings
INT - stores integers
FLOAT - stores floating point numbers
DATE - stores date and time
BLOB - stores binary large objects
CLOB - stores character large objects


# Commands Entered in this Assignment

 krishnaraj@Krishnaraj-Arch  ~   master ±  mariadb -u krishnaraj -p
Enter password:
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 3
Server version: 10.10.3-MariaDB Arch Linux

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> show databases;
+--------------------+
| Database           |
+--------------------+
| class              |
| class_stuff        |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
| test               |
| test_libreoffice   |
+--------------------+
8 rows in set (0.005 sec)

MariaDB [(none)]> create database dbms_lab;
Query OK, 1 row affected (0.001 sec)

MariaDB [(none)]> use dbms_lab;
Database changed
MariaDB [dbms_lab]> show databases;
+--------------------+
| Database           |
+--------------------+
| class              |
| class_stuff        |
| dbms_lab           |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
| test               |
| test_libreoffice   |
+--------------------+
9 rows in set (0.001 sec)

MariaDB [dbms_lab]> show tables;
Empty set (0.000 sec)

MariaDB [dbms_lab]> create table books(ISBN varchar(20), Title varchar(100), author_id int, Price float);
Query OK, 0 rows affected (0.019 sec)

MariaDB [dbms_lab]> show tables;
+--------------------+
| Tables_in_dbms_lab |
+--------------------+
| books              |
+--------------------+
1 row in set (0.001 sec)

MariaDB [dbms_lab]> describe books;
+-----------+--------------+------+-----+---------+-------+
| Field     | Type         | Null | Key | Default | Extra |
+-----------+--------------+------+-----+---------+-------+
| ISBN      | varchar(20)  | YES  |     | NULL    |       |
| Title     | varchar(100) | YES  |     | NULL    |       |
| author_id | int(11)      | YES  |     | NULL    |       |
| Price     | float        | YES  |     | NULL    |       |
+-----------+--------------+------+-----+---------+-------+
4 rows in set (0.002 sec)


MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null, country varchar(25) not null, home_city varchar(25) not null);
Query OK, 0 rows affected (0.007 sec)

MariaDB [dbms_lab]> show tables;
+--------------------+
| Tables_in_dbms_lab |
+--------------------+
| books              |
| newauthor          |
+--------------------+
2 rows in set (0.001 sec)

MariaDB [dbms_lab]> describe newauthor;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| auth_id   | varchar(8)  | NO   |     | NULL    |       |
| aut_name  | varchar(50) | NO   |     | NULL    |       |
| country   | varchar(25) | NO   |     | NULL    |       |
| home_city | varchar(25) | NO   |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
4 rows in set (0.002 sec)

MariaDB [dbms_lab]> insert into newauthor values(NULL, NULL, NULL, NULL);
ERROR 1048 (23000): Column 'auth_id' cannot be null


MariaDB [dbms_lab]> show tables;
+--------------------+
| Tables_in_dbms_lab |
+--------------------+
| books              |
+--------------------+
1 row in set (0.000 sec)

MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) unique, aut_name varchar(50) not null , country varchar(25) not null , home_city varchar(25) not null );
Query OK, 0 rows affected (0.005 sec)

MariaDB [dbms_lab]> show tables;
+--------------------+
| Tables_in_dbms_lab |
+--------------------+
| books              |
| newauthor          |
+--------------------+
2 rows in set (0.000 sec)

MariaDB [dbms_lab]> describe newauthor;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| auth_id   | varchar(8)  | YES  | UNI | NULL    |       |
| aut_name  | varchar(50) | NO   |     | NULL    |       |
| country   | varchar(25) | NO   |     | NULL    |       |
| home_city | varchar(25) | NO   |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [dbms_lab]> drop table newauthor;
Query OK, 0 rows affected (0.003 sec)

MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null , home_city varchar(25) not null);
Query OK, 0 rows affected (0.005 sec)

MariaDB [dbms_lab]> drop table newauthor;
Query OK, 0 rows affected (0.004 sec)

MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null , home_city varchar(25) not null, unique(auth_id));
Query OK, 0 rows affected (0.004 sec)

MariaDB [dbms_lab]> describe newauthor;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| auth_id   | varchar(8)  | NO   | PRI | NULL    |       |
| aut_name  | varchar(50) | NO   |     | NULL    |       |
| country   | varchar(25) | NO   |     | NULL    |       |
| home_city | varchar(25) | NO   |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [dbms_lab]> drop table newauthor;
Query OK, 0 rows affected (0.003 sec)

MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null , home_city varchar(25) not null, unique(auth_id, aut_name));
Query OK, 0 rows affected (0.004 sec)

MariaDB [dbms_lab]> describe newauthor;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| auth_id   | varchar(8)  | NO   | PRI | NULL    |       |
| aut_name  | varchar(50) | NO   | PRI | NULL    |       |
| country   | varchar(25) | NO   |     | NULL    |       |
| home_city | varchar(25) | NO   |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [dbms_lab]> drop table newauthor;
Query OK, 0 rows affected (0.002 sec)

MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) primary key, aut_name varchar(50) not null , country varchar(25) not null , home_city varchar(25) not null);
Query OK, 0 rows affected (0.004 sec)

MariaDB [dbms_lab]> describe newauthor;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| auth_id   | varchar(8)  | NO   | PRI | NULL    |       |
| aut_name  | varchar(50) | NO   |     | NULL    |       |
| country   | varchar(25) | NO   |     | NULL    |       |
| home_city | varchar(25) | NO   |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [dbms_lab]> drop table newauthor;
Query OK, 0 rows affected (0.004 sec)

MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) primary key, aut_name varchar(50) not null , country varchar(25) not null , home_city varchar(25) not null, primary key(auth_id, aut_name));
ERROR 1068 (42000): Multiple primary key defined
MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null , home_city varchar(25) not null, primary key(auth_id, aut_name));
Query OK, 0 rows affected (0.005 sec)

MariaDB [dbms_lab]> describe newauthor;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| auth_id   | varchar(8)  | NO   | PRI | NULL    |       |
| aut_name  | varchar(50) | NO   | PRI | NULL    |       |
| country   | varchar(25) | NO   |     | NULL    |       |
| home_city | varchar(25) | NO   |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
4 rows in set (0.001 sec)


MariaDB [dbms_lab]> drop table newauthor;
Query OK, 0 rows affected (0.005 sec)

MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null check (country in ( , home_city varchar(25) not null, primary key(auth_id, aut_name));
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near ' home_city varchar(25) not null, primary key(auth_id, aut_name))' at line 1
MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null check (country in ('USA', 'India', 'Madagascar') , home_city varchar(25) not null, primary key(auth_id, aut_name));
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near ' home_city varchar(25) not null, primary key(auth_id, aut_name))' at line 1
MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null check (country in ('USA', 'India', 'Madagascar')) , home_city varchar(25) not null, primary key(auth_id, aut_name));
Query OK, 0 rows affected (0.004 sec)

MariaDB [dbms_lab]> describe newauthor;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| auth_id   | varchar(8)  | NO   | PRI | NULL    |       |
| aut_name  | varchar(50) | NO   | PRI | NULL    |       |
| country   | varchar(25) | NO   |     | NULL    |       |
| home_city | varchar(25) | NO   |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [dbms_lab]> insert into newauthor values("1234", "Ahmed", "Pakistan", "instanbul");
ERROR 4025 (23000): CONSTRAINT `newauthor.country` failed for `dbms_lab`.`newauthor`
MariaDB [dbms_lab]> drop table newauthor;
Query OK, 0 rows affected (0.003 sec)

MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null check (country in ('USA', 'India', 'Madagascar')) default 'India', home_city varchar(25) not null, primary key(auth_id, aut_name));
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'default 'India', home_city varchar(25) not null, primary key(auth_id, aut_name))' at line 1
MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null default 'India', home_city varchar(25) not null, primary key(auth_id, aut_name));Query OK, 0 rows affected (0.004 sec)

MariaDB [dbms_lab]> drop table newauthor;
Query OK, 0 rows affected (0.003 sec)

MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null check (country in ('USA', 'India', 'Madagascar')) default 'India', home_city varchar(25) not null, primary key(auth_id, aut_name), check((country='India' AND home_city='Mumbai'));
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'default 'India', home_city varchar(25) not null, primary key(auth_id, aut_nam...' at line 1
MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null default 'India', home_city varchar(25) not null, primary key(auth_id, aut_name), check((country='India' AND home_city='Mumbai'));
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '' at line 1
MariaDB [dbms_lab]> create table if not exists newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null default 'India', home_city varchar(25) not null, primary key(auth_id, aut_name), check((country='India' AND home_city='Mumbai'));
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '' at line 1
MariaDB [dbms_lab]> create table newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null default 'India', home_city varchar(25) not null, primary key(auth_id, aut_name), check((country='India' AND home_city='Mumbai'));ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '' at line 1
MariaDB [dbms_lab]> create table newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null default 'India', home_city varchar(25) not null, primary key(auth_id, aut_name), check(country='India' AND home_city='Mumbai');
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '' at line 1
MariaDB [dbms_lab]> create table newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null default 'India', home_city varchar(25) not null, primary key(auth_id, aut_name), check(country='India' AND home_city='Mumbai'));
Query OK, 0 rows affected (0.012 sec)

MariaDB [dbms_lab]> describe newauthor;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| auth_id   | varchar(8)  | NO   | PRI | NULL    |       |
| aut_name  | varchar(50) | NO   | PRI | NULL    |       |
| country   | varchar(25) | NO   |     | India   |       |
| home_city | varchar(25) | NO   |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [dbms_lab]> create table newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null default 'India', home_city varchar(25) not null, primary key(auth_id, aut_name), check((country='India' AND home_city='Mumbai') or (country='India' and home_city = 'New Delhi')));
ERROR 1050 (42S01): Table 'newauthor' already exists
MariaDB [dbms_lab]> drop table newauthor;
Query OK, 0 rows affected (0.021 sec)

MariaDB [dbms_lab]> create table newauthor (auth_id varchar(8) not null, aut_name varchar(50) not null , country varchar(25) not null default 'India', home_city varchar(25) not null, primary key(auth_id, aut_name), check((country='India' AND home_city='Mumbai') or (country='India' and home_city = 'New Delhi')));
Query OK, 0 rows affected (0.005 sec)

MariaDB [dbms_lab]> describe newauthor;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| auth_id   | varchar(8)  | NO   | PRI | NULL    |       |
| aut_name  | varchar(50) | NO   | PRI | NULL    |       |
| country   | varchar(25) | NO   |     | India   |       |
| home_city | varchar(25) | NO   |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [dbms_lab]> create table newbook_master(book_id varchar(15) not null primary key, book_name varchar(50), isbn_no varchar(15) not null, cate_id varchar(8), aut_id varchar(8), pub_id varchar(8), dt_of_pub date, pub_lang varchar(15) , no_page decimal(5, 0) not null, book_price decimal(8, 2), foreign key(aut_id) references new_author(aut_id));
ERROR 1005 (HY000): Can't create table `dbms_lab`.`newbook_master` (errno: 150 "Foreign key constraint is incorrectly formed")
MariaDB [dbms_lab]> create table newbook_master(book_id varchar(15) not null primary key, book_name varchar(50), isbn_no varchar(15) not null, cate_id varchar(8), auth_id varchar(8), pub_id varchar(8), dt_of_pub date, pub_lang varchar(15) , no_page decimal(5, 0) not null, book_price decimal(8, 2), foreign key(aut_id) references new_author(auth_id));
ERROR 1072 (42000): Key column 'aut_id' doesn't exist in table
MariaDB [dbms_lab]> create table newbook_master(book_id varchar(15) not null primary key, book_name varchar(50), isbn_no varchar(15) not null, cate_id varchar(8), auth_id varchar(8), pub_id varchar(8), dt_of_pub date, pub_lang varchar(15) , no_page decimal(5, 0) not null, book_price decimal(8, 2), foreign key(aut_id) references new_author(auth_id));
ERROR 1072 (42000): Key column 'aut_id' doesn't exist in table
MariaDB [dbms_lab]> show tables;
+--------------------+
| Tables_in_dbms_lab |
+--------------------+
| books              |
| newauthor          |
+--------------------+
2 rows in set (0.000 sec)

MariaDB [dbms_lab]> describe newauthor;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| auth_id   | varchar(8)  | NO   | PRI | NULL    |       |
| aut_name  | varchar(50) | NO   | PRI | NULL    |       |
| country   | varchar(25) | NO   |     | India   |       |
| home_city | varchar(25) | NO   |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [dbms_lab]> create table newbook_master(book_id varchar(15) not null primary key, book_name varchar(50), isbn_no varchar(15) not null, cate_id varchar(8), auth_id varchar(8), pub_id varchar(8), dt_of_pub date, pub_lang varchar(15) , no_page decimal(5, 0) not null, book_price decimal(8, 2), foreign key(auth_id) references new_author(auth_id));
ERROR 1005 (HY000): Can't create table `dbms_lab`.`newbook_master` (errno: 150 "Foreign key constraint is incorrectly formed")
MariaDB [dbms_lab]> create table newbook_master(book_id varchar(15) primary key, book_name varchar(50), isbn_no varchar(15) not null, cate_id varchar(8), auth_id varchar(8) primary key, pub_id varchar(8), dt_of_pub date, pub_lang varchar(15) , no_page decimal(5, 0) not null, book_price decimal(8, 2), foreign key(auth_id) references new_author(auth_id));
ERROR 1068 (42000): Multiple primary key defined
MariaDB [dbms_lab]> create table newbook_master(book_id varchar(15) primary key, book_name varchar(50), isbn_no varchar(15) not null, cate_id varchar(8), auth_id varchar(8) not null, pub_id varchar(8), dt_of_pub date, pub_lang varchar(15) , no_page decimal(5, 0) not null, book_price decimal(8, 2), foreign key(auth_id) references new_author(auth_id));
ERROR 1005 (HY000): Can't create table `dbms_lab`.`newbook_master` (errno: 150 "Foreign key constraint is incorrectly formed")
MariaDB [dbms_lab]> describe newauthor;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| auth_id   | varchar(8)  | NO   | PRI | NULL    |       |
| aut_name  | varchar(50) | NO   | PRI | NULL    |       |
| country   | varchar(25) | NO   |     | India   |       |
| home_city | varchar(25) | NO   |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [dbms_lab]> create table newbook_master(book_id varchar(15) primary key, book_name varchar(50), isbn_no varchar(15) not null, cate_id varchar(8), auth_id varchar(8), pub_id varchar(8), dt_of_pub date, pub_lang varchar(15) , no_page decimal(5, 0) not null, book_price decimal(8, 2), foreign key(auth_id) references newauthor(auth_id));
Query OK, 0 rows affected (0.005 sec)

MariaDB [dbms_lab]> describe newbook_master;
+------------+--------------+------+-----+---------+-------+
| Field      | Type         | Null | Key | Default | Extra |
+------------+--------------+------+-----+---------+-------+
| book_id    | varchar(15)  | NO   | PRI | NULL    |       |
| book_name  | varchar(50)  | YES  |     | NULL    |       |
| isbn_no    | varchar(15)  | NO   |     | NULL    |       |
| cate_id    | varchar(8)   | YES  |     | NULL    |       |
| auth_id    | varchar(8)   | YES  | MUL | NULL    |       |
| pub_id     | varchar(8)   | YES  |     | NULL    |       |
| dt_of_pub  | date         | YES  |     | NULL    |       |
| pub_lang   | varchar(15)  | YES  |     | NULL    |       |
| no_page    | decimal(5,0) | NO   |     | NULL    |       |
| book_price | decimal(8,2) | YES  |     | NULL    |       |
+------------+--------------+------+-----+---------+-------+
10 rows in set (0.002 sec)


MariaDB [dbms_lab]>
MariaDB [dbms_lab]> alter table newauthor add no_of_books varchar(50);
Query OK, 0 rows affected (0.011 sec)
Records: 0  Duplicates: 0  Warnings: 0

MariaDB [dbms_lab]> alter table newauthor drop no_of_books;
Query OK, 0 rows affected (0.006 sec)
Records: 0  Duplicates: 0  Warnings: 0

MariaDB [dbms_lab]> alter table newauthor add no_of_books varchar(50);
Query OK, 0 rows affected (0.007 sec)
Records: 0  Duplicates: 0  Warnings: 0

MariaDB [dbms_lab]> desc newauthor;
+-------------+-------------+------+-----+---------+-------+
| Field       | Type        | Null | Key | Default | Extra |
+-------------+-------------+------+-----+---------+-------+
| auth_id     | varchar(8)  | NO   | PRI | NULL    |       |
| aut_name    | varchar(50) | NO   | PRI | NULL    |       |
| country     | varchar(25) | NO   |     | India   |       |
| home_city   | varchar(25) | NO   |     | NULL    |       |
| no_of_books | varchar(50) | YES  |     | NULL    |       |
+-------------+-------------+------+-----+---------+-------+
5 rows in set (0.001 sec)

MariaDB [dbms_lab]> alter table newauthor drop no_of_books;
Query OK, 0 rows affected (0.006 sec)
Records: 0  Duplicates: 0  Warnings: 0

MariaDB [dbms_lab]> desc newauthor;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| auth_id   | varchar(8)  | NO   | PRI | NULL    |       |
| aut_name  | varchar(50) | NO   | PRI | NULL    |       |
| country   | varchar(25) | NO   |     | India   |       |
| home_city | varchar(25) | NO   |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [dbms_lab]> alter table newauthor modify home_city varchar(100) not null;
Query OK, 0 rows affected (0.006 sec)
Records: 0  Duplicates: 0  Warnings: 0

MariaDB [dbms_lab]> desc newauthor;
+-----------+--------------+------+-----+---------+-------+
| Field     | Type         | Null | Key | Default | Extra |
+-----------+--------------+------+-----+---------+-------+
| auth_id   | varchar(8)   | NO   | PRI | NULL    |       |
| aut_name  | varchar(50)  | NO   | PRI | NULL    |       |
| country   | varchar(25)  | NO   |     | India   |       |
| home_city | varchar(100) | NO   |     | NULL    |       |
+-----------+--------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [dbms_lab]> alter table newauthor add constraint country not null;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'not null' at line 1
MariaDB [dbms_lab]> alter table newauthor add constraint country unique(country);
Query OK, 0 rows affected (0.011 sec)
Records: 0  Duplicates: 0  Warnings: 0

MariaDB [dbms_lab]> desc newauthor;
+-----------+--------------+------+-----+---------+-------+
| Field     | Type         | Null | Key | Default | Extra |
+-----------+--------------+------+-----+---------+-------+
| auth_id   | varchar(8)   | NO   | PRI | NULL    |       |
| aut_name  | varchar(50)  | NO   | PRI | NULL    |       |
| country   | varchar(25)  | NO   | UNI | India   |       |
| home_city | varchar(100) | NO   |     | NULL    |       |
+-----------+--------------+------+-----+---------+-------+
4 rows in set (0.001 sec)

MariaDB [dbms_lab]> select * from newauthor;
Empty set (0.007 sec)

MariaDB [dbms_lab]> describe
Display all 747 possibilities? (y or n)
MariaDB [dbms_lab]> describe newbook_master;
+------------+--------------+------+-----+---------+-------+
| Field      | Type         | Null | Key | Default | Extra |
+------------+--------------+------+-----+---------+-------+
| book_id    | varchar(15)  | NO   | PRI | NULL    |       |
| book_name  | varchar(50)  | YES  |     | NULL    |       |
| isbn_no    | varchar(15)  | NO   |     | NULL    |       |
| cate_id    | varchar(8)   | YES  |     | NULL    |       |
| auth_id    | varchar(8)   | YES  | MUL | NULL    |       |
| pub_id     | varchar(8)   | YES  |     | NULL    |       |
| dt_of_pub  | date         | YES  |     | NULL    |       |
| pub_lang   | varchar(15)  | YES  |     | NULL    |       |
| no_page    | decimal(5,0) | NO   |     | NULL    |       |
| book_price | decimal(8,2) | YES  |     | NULL    |       |
+------------+--------------+------+-----+---------+-------+
10 rows in set (0.001 sec)

MariaDB [dbms_lab]> alter table newbook_master rename to new_book_master;
Query OK, 0 rows affected (0.005 sec)

MariaDB [dbms_lab]> show tables;
+--------------------+
| Tables_in_dbms_lab |
+--------------------+
| books              |
| new_book_master    |
| newauthor          |
+--------------------+
3 rows in set (0.000 sec)

MariaDB [dbms_lab]> alter table new_book_master change pub_id publi_id varchar(50);
Query OK, 0 rows affected (0.007 sec)
Records: 0  Duplicates: 0  Warnings: 0

MariaDB [dbms_lab]> desc new_book_master;
+------------+--------------+------+-----+---------+-------+
| Field      | Type         | Null | Key | Default | Extra |
+------------+--------------+------+-----+---------+-------+
| book_id    | varchar(15)  | NO   | PRI | NULL    |       |
| book_name  | varchar(50)  | YES  |     | NULL    |       |
| isbn_no    | varchar(15)  | NO   |     | NULL    |       |
| cate_id    | varchar(8)   | YES  |     | NULL    |       |
| auth_id    | varchar(8)   | YES  | MUL | NULL    |       |
| publi_id   | varchar(50)  | YES  |     | NULL    |       |
| dt_of_pub  | date         | YES  |     | NULL    |       |
| pub_lang   | varchar(15)  | YES  |     | NULL    |       |
| no_page    | decimal(5,0) | NO   |     | NULL    |       |
| book_price | decimal(8,2) | YES  |     | NULL    |       |
+------------+--------------+------+-----+---------+-------+
10 rows in set (0.001 sec)

Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 4
Server version: 10.10.3-MariaDB Arch Linux

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> use dbms_lab;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [dbms_lab]> alter table course change course_id course_id varchar(50);
Query OK, 0 rows affected (0.013 sec)
Records: 0  Duplicates: 0  Warnings: 0

MariaDB [dbms_lab]> insert into course values('CS-437', 'Database Systems', 'Comp.Sci', 4);
Query OK, 1 row affected (0.001 sec)

MariaDB [dbms_lab]> insert into course values('CS-437', 'Python', 'Comp.Sci', 1);
Query OK, 1 row affected (0.001 sec)

MariaDB [dbms_lab]> select * from course;
+-----------+------------------+-----------+---------+
| course_id | title            | dept_name | credits |
+-----------+------------------+-----------+---------+
| CS-437    | Database Systems | Comp.Sci  |       4 |
| CS-437    | Python           | Comp.Sci  |       1 |
+-----------+------------------+-----------+---------+
2 rows in set (0.001 sec)

MariaDB [dbms_lab]> update course set course_id = 'CS-451' where title ='Python';
Query OK, 1 row affected (0.003 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [dbms_lab]> select * from course;
+-----------+------------------+-----------+---------+
| course_id | title            | dept_name | credits |
+-----------+------------------+-----------+---------+
| CS-437    | Database Systems | Comp.Sci  |       4 |
| CS-451    | Python           | Comp.Sci  |       1 |
+-----------+------------------+-----------+---------+
2 rows in set (0.000 sec)

MariaDB [dbms_lab]> insert into course values('CS-433', 'Operating Systems', 'Comp.Sci', 3);
Query OK, 1 row affected (0.001 sec)

MariaDB [dbms_lab]> insert into course values('CS-333', 'OOPCJ', 'Comp.Sci', 4);
Query OK, 1 row affected (0.001 sec)

MariaDB [dbms_lab]> insert into course values('CS-331', 'CBS', 'Math', 1);
Query OK, 1 row affected (0.001 sec)

MariaDB [dbms_lab]> insert into course values('MA-123', 'DMGT', 'Math', 1);
Query OK, 1 row affected (0.002 sec)

MariaDB [dbms_lab]> update course set course_id = 'MA-451' where title='CBS';
Query OK, 1 row affected (0.001 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [dbms_lab]> insert into course values('MA-554', 'Integral Calculus', 'Math', 2);
Query OK, 1 row affected (0.007 sec)

MariaDB [dbms_lab]> insert into course values('MA-124', 'Linear Algebra and Differential Calc', 'Math', 3);
Query OK, 1 row affected (0.001 sec)

MariaDB [dbms_lab]> insert into course values('CS-113', 'Computer Networks', 'Comp.Sci', 3);
Query OK, 1 row affected (0.001 sec)

MariaDB [dbms_lab]> insert into course values('CS-945', 'Information and Cybsersecurity', 'Comp.Sci', 3);
Query OK, 1 row affected (0.001 sec)

MariaDB [dbms_lab]> insert into course values('CS-911', 'Digital Elecronics', 'Electronics', 3);
Query OK, 1 row affected (0.001 sec)

MariaDB [dbms_lab]> insert into course values('EE-911', 'BEEE', 'Electronics', 3);
Query OK, 1 row affected (0.001 sec)

MariaDB [dbms_lab]> update course set course_id = 'EE-451' where title='Digital Electronics';
Query OK, 0 rows affected (0.000 sec)
Rows matched: 0  Changed: 0  Warnings: 0

MariaDB [dbms_lab]> select * from course;
+-----------+--------------------------------------+-------------+---------+
| course_id | title                                | dept_name   | credits |
+-----------+--------------------------------------+-------------+---------+
| CS-437    | Database Systems                     | Comp.Sci    |       4 |
| CS-451    | Python                               | Comp.Sci    |       1 |
| CS-433    | Operating Systems                    | Comp.Sci    |       3 |
| CS-333    | OOPCJ                                | Comp.Sci    |       4 |
| MA-451    | CBS                                  | Math        |       1 |
| MA-123    | DMGT                                 | Math        |       1 |
| MA-554    | Integral Calculus                    | Math        |       2 |
| MA-124    | Linear Algebra and Differential Calc | Math        |       3 |
| CS-113    | Computer Networks                    | Comp.Sci    |       3 |
| CS-945    | Information and Cybsersecurity       | Comp.Sci    |       3 |
| CS-911    | Digital Elecronics                   | Electronics |       3 |
| EE-911    | BEEE                                 | Electronics |       3 |
+-----------+--------------------------------------+-------------+---------+
12 rows in set (0.000 sec)

MariaDB [dbms_lab]> update course set course_id = 'EE-451' where title='Digital Elecronics';
Query OK, 1 row affected (0.001 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [dbms_lab]> update course set title='Digital Electronics' where title='Digital Elecronics';
Query OK, 1 row affected (0.001 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [dbms_lab]> select * from course;
+-----------+--------------------------------------+-------------+---------+
| course_id | title                                | dept_name   | credits |
+-----------+--------------------------------------+-------------+---------+
| CS-437    | Database Systems                     | Comp.Sci    |       4 |
| CS-451    | Python                               | Comp.Sci    |       1 |
| CS-433    | Operating Systems                    | Comp.Sci    |       3 |
| CS-333    | OOPCJ                                | Comp.Sci    |       4 |
| MA-451    | CBS                                  | Math        |       1 |
| MA-123    | DMGT                                 | Math        |       1 |
| MA-554    | Integral Calculus                    | Math        |       2 |
| MA-124    | Linear Algebra and Differential Calc | Math        |       3 |
| CS-113    | Computer Networks                    | Comp.Sci    |       3 |
| CS-945    | Information and Cybsersecurity       | Comp.Sci    |       3 |
| EE-451    | Digital Electronics                  | Electronics |       3 |
| EE-911    | BEEE                                 | Electronics |       3 |
+-----------+--------------------------------------+-------------+---------+
12 rows in set (0.000 sec)

MariaDB [dbms_lab]>


