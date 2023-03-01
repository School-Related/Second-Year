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