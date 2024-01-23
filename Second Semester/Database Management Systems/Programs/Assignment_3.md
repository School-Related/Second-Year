MariaDB [dbms_lab]> create database Company;
Query OK, 1 row affected (0.001 sec)

MariaDB [dbms_lab]> show databases;
+--------------------+
| Database           |
+--------------------+
| Company            |
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
10 rows in set (0.001 sec)

MariaDB [dbms_lab]> use Company;
Database changed
MariaDB [Company]> create table emp(empno int primary key, empname varchar(50) not null, job varchar(10), mgr int not null, hiredate date, sal int not null, comm int, deptno int not null);
Query OK, 0 rows affected (0.008 sec)

MariaDB [Company]> describe emp;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| empno    | int(11)     | NO   | PRI | NULL    |       |
| empname  | varchar(50) | NO   |     | NULL    |       |
| job      | varchar(10) | YES  |     | NULL    |       |
| mgr      | int(11)     | NO   |     | NULL    |       |
| hiredate | date        | YES  |     | NULL    |       |
| sal      | int(11)     | NO   |     | NULL    |       |
| comm     | int(11)     | YES  |     | NULL    |       |
| deptno   | int(11)     | NO   |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+
8 rows in set (0.002 sec)

MariaDB [Company]> create table dept(deptno int primary key, dname varchar(50), loc varchar(50) not null);
Query OK, 0 rows affected (0.008 sec)

MariaDB [Company]> describe dept;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| deptno | int(11)     | NO   | PRI | NULL    |       |
| dname  | varchar(50) | YES  |     | NULL    |       |
| loc    | varchar(50) | NO   |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+
3 rows in set (0.002 sec)

MariaDB [Company]> insert into emp values (7369,  "Smith",  "Clerk",  7902,  "1980-12-17",  800,  300,  20);
Query OK, 1 row affected (0.001 sec)

MariaDB [Company]> select * from emp;
+-------+---------+-------+------+------------+-----+------+--------+
| empno | empname | job   | mgr  | hiredate   | sal | comm | deptno |
+-------+---------+-------+------+------------+-----+------+--------+
|  7369 | Smith   | Clerk | 7902 | 1980-12-17 | 800 |  300 |     20 |
+-------+---------+-------+------+------------+-----+------+--------+
1 row in set (0.001 sec)

MariaDB [Company]> insert into emp values (7499, "Allen", "Salesman", 7698, "1981-02-20", 1600, 300, 30);
Query OK, 1 row affected (0.001 sec)

MariaDB [Company]> select * from emp;
+-------+---------+----------+------+------------+------+------+--------+
| empno | empname | job      | mgr  | hiredate   | sal  | comm | deptno |
+-------+---------+----------+------+------------+------+------+--------+
|  7369 | Smith   | Clerk    | 7902 | 1980-12-17 |  800 |  300 |     20 |
|  7499 | Allen   | Salesman | 7698 | 1981-02-20 | 1600 |  300 |     30 |
+-------+---------+----------+------+------------+------+------+--------+
2 rows in set (0.000 sec)

MariaDB [Company]> insert into dept values(10, "Accounting", "New York");
Query OK, 1 row affected (0.001 sec)

MariaDB [Company]> insert into dept values(20, "Research", "Dallas");
Query OK, 1 row affected (0.001 sec)

MariaDB [Company]> insert into dept values
    -> (30, "Sales", "Chicago");
Query OK, 1 row affected (0.001 sec)

MariaDB [Company]> insert into dept values(40, "Operations", "Boston");
Query OK, 1 row affected (0.001 sec)

MariaDB [Company]> select * from dept;
+--------+------------+----------+
| deptno | dname      | loc      |
+--------+------------+----------+
|     10 | Accounting | New York |
|     20 | Research   | Dallas   |
|     30 | Sales      | Chicago  |
|     40 | Operations | Boston   |
+--------+------------+----------+
4 rows in set (0.001 sec)

MariaDB [Company]> select * from emp;
+-------+---------+----------+------+------------+------+------+--------+
| empno | empname | job      | mgr  | hiredate   | sal  | comm | deptno |
+-------+---------+----------+------+------------+------+------+--------+
|  7369 | Smith   | Clerk    | 7902 | 1980-12-17 |  800 |  300 |     20 |
|  7499 | Allen   | Salesman | 7698 | 1981-02-20 | 1600 |  300 |     30 |
+-------+---------+----------+------+------------+------+------+--------+
2 rows in set (0.001 sec)

MariaDB [Company]> insert into emp values(9360, "Isaiah", "Accounting", 7940, "2101-9-3", 4000, 1390, 10);
Query OK, 1 row affected 

MariaDB [Company]> insert into emp values(9085, "Katie", "Research", 5919, "1997-1-26", 8241, 1166, 20);
Query OK, 1 row affected 

MariaDB [Company]> insert into emp values(5883, "Jeffery", "Research", 5817, "2057-8-3", 2033, 549, 20);
Query OK, 1 row affected 

MariaDB [Company]> insert into emp values(5595, "Isabella", "Sales", 8245, "2075-9-10", 2534, 1545, 30);
Query OK, 1 row affected 

MariaDB [Company]> insert into emp values(9180, "Jesse", "Accounting", 2678, "2101-8-22", 3238, 1796, 10);
Query OK, 1 row affected 

MariaDB [Company]> insert into emp values(9487, "Amelia", "Research",7940 , "2123-1-17", 5368, 1998, 20);
Query OK, 1 row affected 

MariaDB [Company]> insert into emp values(8467, "Mollie", "Accounting", 5919, "2015-2-9", 3999, 526, 10);
Query OK, 1 row affected 

MariaDB [Company]> insert into emp values(9384, "Matilda", "Operations", 5817, "2025-5-23", 2494, 1170, 50);
Query OK, 1 row affected 

MariaDB [Company]> insert into emp values(6880, "Cameron", "Sales", 8245, "2059-5-9", 6311, 1406, 30);
Query OK, 1 row affected 

MariaDB [Company]> insert into emp values(7235, "Stephen", "Operations", 2678, "2083-0-31", 6556, 1698, 50);
Query OK, 1 row affected 

MariaDB [Company]> insert into emp values(7553, "Angel", "Sales", 2678, "2099-6-3", 9352, 983, 30);
Query OK, 1 row affected 
