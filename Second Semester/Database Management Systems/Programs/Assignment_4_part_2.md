MariaDB [dbms_lab]> CREATE TABLE zipcode (
    ->   zip VARCHAR(10) PRIMARY KEY,
    ->   city VARCHAR(50) NOT NULL
    -> );
Query OK, 0 rows affected (0.50 sec)

MariaDB [dbms_lab]> CREATE TABLE customers (
    ->   cno INT PRIMARY KEY,
    ->   cname VARCHAR(50) NOT NULL,
    ->   street VARCHAR(50),
    ->   zip VARCHAR(10),
    ->   phone VARCHAR(20),
    ->   CONSTRAINT zip_fk FOREIGN KEY (zip) REFERENCES zipcode (zip)
    -> );
Query OK, 0 rows affected (0.39 sec)


MariaDB [dbms_lab]> CREATE TABLE emp (
    ->   eno INT PRIMARY KEY,
    ->   ename VARCHAR(50) NOT NULL,
    ->   zip VARCHAR(10),
    ->   hdate DATE,
    ->   FOREIGN KEY (zip) REFERENCES zipcode (zip)
    -> );
Query OK, 0 rows affected (0.44 sec)

MariaDB [dbms_lab]> CREATE TABLE parts (
    ->   pno INT PRIMARY KEY,
    ->   pname VARCHAR(50) NOT NULL,
    ->   qty_on_hand INT CHECK (qty_on_hand >= 0),
    ->   price DECIMAL(10, 2) CHECK (price >= 0)
    -> );
Query OK, 0 rows affected (0.40 sec)

MariaDB [dbms_lab]> ^C
MariaDB [dbms_lab]> CREATE TABLE orders (
    ->   ono INT PRIMARY KEY,
    ->   cno INT,
    ->   receivedate DATE,
    ->   shippeddate DATE,
    ->   CONSTRAINT cno_fk FOREIGN KEY (cno) REFERENCES customers (cno)
    -> );
Query OK, 0 rows affected (0.22 sec)

MariaDB [dbms_lab]> CREATE TABLE odetails (
    ->   ono INT,
    ->   pno INT,
    ->   qty INT CHECK (qty >= 0),
    ->   PRIMARY KEY (ono, pno),
    ->   CONSTRAINT ono_fk FOREIGN KEY (ono) REFERENCES orders (ono),
    ->   CONSTRAINT pno_fk FOREIGN KEY (pno) REFERENCES parts (pno)
    -> );
Query OK, 0 rows affected (0.24 sec)

MariaDB [dbms_lab]> INSERT INTO zipcode (zip, city) VALUES
    ->   ('10001', 'New York'),
    ->   ('10002', 'Los Angeles'),
    ->   ('10003', 'Chicago');
Query OK, 3 rows affected (0.44 sec)
Records: 3  Duplicates: 0  Warnings: 0

MariaDB [dbms_lab]> INSERT INTO emp (eno, ename, zip, hdate) VALUES
    ->   (1, 'John Smith', '10001', '2022-01-01'),
    ->   (2, 'Jane Doe', '10002', '2022-02-01'),
    ->   (3, 'Bob Johnson', '10003', '2022-03-01');
Query OK, 3 rows affected (0.39 sec)
Records: 3  Duplicates: 0  Warnings: 0

MariaDB [dbms_lab]> INSERT INTO parts (pno, pname, qty_on_hand, price) VALUES
    ->   (1, 'Widget', 10, 19.99),
    ->   (2, 'Gizmo', 5, 29.99),
    ->   (3, 'Doodad', 20, 9.99);
Query OK, 3 rows affected (0.01 sec)
Records: 3  Duplicates: 0  Warnings: 0

MariaDB [dbms_lab]> INSERT INTO customers (cno, cname, street, zip, phone) VALUES
    ->   (1, 'Acme Inc.', '123 Main St.', '10001', '555-1234'),
    ->   (2, 'Globex Corp.', '456 Elm St.', '10002', '555-5678'),
    ->   (3, 'Initech Ltd.', '789 Oak St.', '10003', '555-9101');
Query OK, 3 rows affected (0.38 sec)
Records: 3  Duplicates: 0  Warnings: 0

MariaDB [dbms_lab]> INSERT INTO orders (ono, cno, receivedate, shippeddate) VALUES
    ->   (1, 1, '2022-01-01', '2022-01-02'),
    ->   (2, 2, '2022-02-01', NULL),
    ->   (3, 3, '2022-03-01', '2022-03-02');
Query OK, 3 rows affected (0.08 sec)
Records: 3  Duplicates: 0  Warnings: 0

MariaDB [dbms_lab]> INSERT INTO odetails (ono, pno, qty) VALUES
    ->   (1, 1, 5),
    ->   (1, 2, 2),
    ->   (2, 3, 10),
    ->   (3, 1, 3),
    ->   (3, 2, 1),
    ->   (3, 3, 5);
Query OK, 6 rows affected (0.13 sec)
Records: 6  Duplicates: 0  Warnings: 0


-- q1
SELECT pno, pname
FROM parts
WHERE price < 20.00 at line 1
MariaDB [dbms_lab]> SELECT pno, pname
    -> FROM parts
    -> WHERE price < 20.00;
+-----+--------+
| pno | pname  |
+-----+--------+
|   1 | Widget |
|   3 | Doodad |
+-----+--------+
2 rows in set (0.00 sec)

MariaDB [dbms_lab]> -- q2
MariaDB [dbms_lab]> SELECT orders.ono, customers.cname
    -> FROM orders
    -> JOIN customers ON orders.cno = customers.cno
    -> WHERE orders.shippeddate IS NULL;
+-----+--------------+
| ono | cname        |
+-----+--------------+
|   2 | Globex Corp. |
+-----+--------------+
1 row in set (0.00 sec)

MariaDB [dbms_lab]> -- q4
MariaDB [dbms_lab]> SELECT DISTINCT zipcode.city
    -> FROM emp
    -> JOIN zipcode ON emp.zip = zipcode.zip
    -> UNION
    -> SELECT DISTINCT zipcode.city
    -> FROM customers
    -> JOIN zipcode ON customers.zip = zipcode.zip;
    
+------------+
| city       |
+------------+
| New York   |
| Los Angeles|
| Chicago    |
+------------+

MariaDB [dbms_lab]> -- q5
MariaDB [dbms_lab]> SELECT SUM(qty)
    -> FROM odetails
    -> WHERE pno = '1060';
+----------+
| SUM(qty) |
+----------+
|     NULL |
+----------+
1 row in set (0.00 sec)

MariaDB [dbms_lab]> -- q6
MariaDB [dbms_lab]> SELECT COUNT(*) as total_customers
    -> FROM customers;
+-----------------+
| total_customers |
+-----------------+
|               3 |
+-----------------+
1 row in set (0.37 sec)

MariaDB [dbms_lab]> -- q7
MariaDB [dbms_lab]> CREATE VIEW customer_orders AS
    -> SELECT orders.ono, orders.receivedate, orders.shippeddate, customers.cname
    -> FROM orders
    -> JOIN customers ON orders.cno = customers.cno;
Query OK, 0 rows affected (0.44 sec)


MariaDB [dbms_lab]> select * from customer_orders;
+-----+-------------+-------------+--------------+
| ono | receivedate | shippeddate | cname        |
+-----+-------------+-------------+--------------+
|   1 | 2022-01-01  | 2022-01-02  | Acme Inc.    |
|   2 | 2022-02-01  | NULL        | Globex Corp. |
|   3 | 2022-03-01  | 2022-03-02  | Initech Ltd. |
+-----+-------------+-------------+--------------+
3 rows in set (0.35 sec)
