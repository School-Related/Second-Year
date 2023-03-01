Enter password:
Welcome to the MariaDB monitor.  Commands end with ; or \g.
Your MariaDB connection id is 3
Server version: 10.11.2-MariaDB Arch Linux

Copyright (c) 2000, 2018, Oracle, MariaDB Corporation Ab and others.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

MariaDB [(none)]> show databases;
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
9 rows in set (0.004 sec)

MariaDB [(none)]> use dbms_lab
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [dbms_lab]> show tables;
+--------------------+
| Tables_in_dbms_lab |
+--------------------+
| books              |
| course             |
| new_book_master    |
| newauthor          |
| newbook_master     |
+--------------------+
5 rows in set (0.001 sec)

MariaDB [dbms_lab]> create table Hotel (HotelNo int Primary Key, Name varchar(50), City varchar(50));
Query OK, 0 rows affected (0.020 sec)

MariaDB [dbms_lab]> describe Hotel;
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| HotelNo | int(11)     | NO   | PRI | NULL    |       |
| Name    | varchar(50) | YES  |     | NULL    |       |
| City    | varchar(50) | YES  |     | NULL    |       |
+---------+-------------+------+-----+---------+-------+
3 rows in set (0.002 sec)

MariaDB [dbms_lab]> create table Room (RoomNo int Primary Key, HotelNo int, Type varchar(50), Price int, foreign key(HotelNo) references Hotel(HotelNo));
Query OK, 0 rows affected (0.014 sec)

MariaDB [dbms_lab]> describe Room;
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| RoomNo  | int(11)     | NO   | PRI | NULL    |       |
| HotelNo | int(11)     | YES  | MUL | NULL    |       |
| Type    | varchar(50) | YES  |     | NULL    |       |
| Price   | int(11)     | YES  |     | NULL    |       |
+---------+-------------+------+-----+---------+-------+
4 rows in set (0.002 sec)

MariaDB [dbms_lab]> create table Booking (HotelNo int, GuestNo int, DateFrom date, DateTo date, RoomNo int, foreign key(HotelNo) references Hotel(HotelNo), foreign key(RoomNo) references Room(RoomNo));
Query OK, 0 rows affected (0.011 sec)

MariaDB [dbms_lab]> describe Booking;
+----------+---------+------+-----+---------+-------+
| Field    | Type    | Null | Key | Default | Extra |
+----------+---------+------+-----+---------+-------+
| HotelNo  | int(11) | YES  | MUL | NULL    |       |
| GuestNo  | int(11) | YES  |     | NULL    |       |
| DateFrom | date    | YES  |     | NULL    |       |
| DateTo   | date    | YES  |     | NULL    |       |
| RoomNo   | int(11) | YES  | MUL | NULL    |       |
+----------+---------+------+-----+---------+-------+
5 rows in set (0.002 sec)

MariaDB [dbms_lab]> create table Guest(GuestNo int primary key, GuestName varchar(50), GuessAddress varchar(50));
Query OK, 0 rows affected (0.007 sec)

MariaDB [dbms_lab]> alter table Booking add constraint foreign key(GuestNo) references Guest(GuestNo);
Query OK, 0 rows affected (0.022 sec)
Records: 0  Duplicates: 0  Warnings: 0

MariaDB [dbms_lab]> describe Booking;
+----------+---------+------+-----+---------+-------+
| Field    | Type    | Null | Key | Default | Extra |
+----------+---------+------+-----+---------+-------+
| HotelNo  | int(11) | YES  | MUL | NULL    |       |
| GuestNo  | int(11) | YES  | MUL | NULL    |       |
| DateFrom | date    | YES  |     | NULL    |       |
| DateTo   | date    | YES  |     | NULL    |       |
| RoomNo   | int(11) | YES  | MUL | NULL    |       |
+----------+---------+------+-----+---------+-------+
5 rows in set (0.004 sec)

MariaDB [dbms_lab]> describe Guest;
+--------------+-------------+------+-----+---------+-------+
| Field        | Type        | Null | Key | Default | Extra |
+--------------+-------------+------+-----+---------+-------+
| GuestNo      | int(11)     | NO   | PRI | NULL    |       |
| GuestName    | varchar(50) | YES  |     | NULL    |       |
| GuessAddress | varchar(50) | YES  |     | NULL    |       |
+--------------+-------------+------+-----+---------+-------+
3 rows in set (0.001 sec)

MariaDB [dbms_lab]> describe Room;
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| RoomNo  | int(11)     | NO   | PRI | NULL    |       |
| HotelNo | int(11)     | YES  | MUL | NULL    |       |
| Type    | varchar(50) | YES  |     | NULL    |       |
| Price   | int(11)     | YES  |     | NULL    |       |
+---------+-------------+------+-----+---------+-------+
4 rows in set (0.002 sec)

MariaDB [dbms_lab]> describe Hotel;
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| HotelNo | int(11)     | NO   | PRI | NULL    |       |
| Name    | varchar(50) | YES  |     | NULL    |       |
| City    | varchar(50) | YES  |     | NULL    |       |
+---------+-------------+------+-----+---------+-------+
3 rows in set (0.002 sec)

ariaDB [dbms_lab]> create table emp(eno int primary key, ename varchar(50), zip int check(zip in (400110, 400111)), hdate date unique);
Query OK, 0 rows affected (0.009 sec)

MariaDB [dbms_lab]> describe emp;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| eno   | int(11)     | NO   | PRI | NULL    |       |
| ename | varchar(50) | YES  |     | NULL    |       |
| zip   | int(11)     | YES  |     | NULL    |       |
| hdate | date        | YES  | UNI | NULL    |       |
+-------+-------------+------+-----+---------+-------+
4 rows in set (0.002 sec)

MariaDB [dbms_lab]> create table parts(pno int primary key, pname varchar(50), qty_on_hand int not null, price int);
Query OK, 0 rows affected (0.007 sec)

MariaDB [dbms_lab]> describe parts;
+-------------+-------------+------+-----+---------+-------+
| Field       | Type        | Null | Key | Default | Extra |
+-------------+-------------+------+-----+---------+-------+
| pno         | int(11)     | NO   | PRI | NULL    |       |
| pname       | varchar(50) | YES  |     | NULL    |       |
| qty_on_hand | int(11)     | NO   |     | NULL    |       |
| price       | int(11)     | YES  |     | NULL    |       |
+-------------+-------------+------+-----+---------+-------+
4 rows in set (0.002 sec)

MariaDB [dbms_lab]> create table customer(cno primary key, cname varchar(50), street varchar(50), Zip int not null, phone int not null unique);
ERROR 4161 (HY000): Unknown data type: 'primary'
MariaDB [dbms_lab]> create table customer(cno int primary key, cname varchar(50), street varchar(50), Zip int not null, phone int not null unique);
Query OK, 0 rows affected (0.009 sec)

MariaDB [dbms_lab]> describe customer;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| cno    | int(11)     | NO   | PRI | NULL    |       |
| cname  | varchar(50) | YES  |     | NULL    |       |
| street | varchar(50) | YES  |     | NULL    |       |
| Zip    | int(11)     | NO   |     | NULL    |       |
| phone  | int(11)     | NO   | UNI | NULL    |       |
+--------+-------------+------+-----+---------+-------+
5 rows in set (0.002 sec)

MariaDB [dbms_lab]> create table Orders(ono int primary key, cno int, receivedDate date, shippedDate date, foreign key(cno) references customer(cno));
Query OK, 0 rows affected (0.010 sec)

MariaDB [dbms_lab]> describe Orders;
+--------------+---------+------+-----+---------+-------+
| Field        | Type    | Null | Key | Default | Extra |
+--------------+---------+------+-----+---------+-------+
| ono          | int(11) | NO   | PRI | NULL    |       |
| cno          | int(11) | YES  | MUL | NULL    |       |
| receivedDate | date    | YES  |     | NULL    |       |
| shippedDate  | date    | YES  |     | NULL    |       |
+--------------+---------+------+-----+---------+-------+
4 rows in set (0.002 sec)

MariaDB [dbms_lab]> create table odetails(ono int, pno int, qty int, foreign key(ono) references Orders(ono));
Query OK, 0 rows affected (0.009 sec)

MariaDB [dbms_lab]> describe odetails;
+-------+---------+------+-----+---------+-------+
| Field | Type    | Null | Key | Default | Extra |
+-------+---------+------+-----+---------+-------+
| ono   | int(11) | YES  | MUL | NULL    |       |
| pno   | int(11) | YES  |     | NULL    |       |
| qty   | int(11) | YES  |     | NULL    |       |
+-------+---------+------+-----+---------+-------+
3 rows in set (0.002 sec)

MariaDB [dbms_lab]> create table zipcode(zip int primary key, city varchar(50) not null check(city in ('Pune', 'Mumbai')));
Query OK, 0 rows affected (0.008 sec)

MariaDB [dbms_lab]> describe zipcode;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| zip   | int(11)     | NO   | PRI | NULL    |       |
| city  | varchar(50) | NO   |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
2 rows in set (0.002 sec)