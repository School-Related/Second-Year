

## Queries Set 1

1. List the number of employees and average salary for employees in department 20.

MariaDB [Company]> select avg(sal),count(*) from emp where deptno=20;
+-----------+----------+
| avg(sal)  | count(*) |
+-----------+----------+
| 5214.0000 |        3 |
+-----------+----------+
1 row in set (0.007 sec)

2. List name, salary and PF amount of all employees. (PF is calculated as 10% of basic salary)

MariaDB [Company]> select empname, sal, sal * 0.10 as PF from emp;
+----------+------+--------+
| empname  | sal  | PF     |
+----------+------+--------+
| Isabella | 2534 | 253.40 |
| Jeffery  | 2033 | 203.30 |
| Cameron  | 6311 | 631.10 |
| Stephen  | 6556 | 655.60 |
| Angel    | 9352 | 935.20 |
| Ramesh   |  500 |  50.00 |
| Krish    | 2000 | 200.00 |
| Mollie   | 3999 | 399.90 |
| Katie    | 8241 | 824.10 |
| Jesse    | 3562 | 356.20 |
| Isaiah   | 4000 | 400.00 |
| Matilda  | 2494 | 249.40 |
| Amelia   | 5368 | 536.80 |
+----------+------+--------+
13 rows in set (0.001 sec)

3. List the employee details in the ascending order of their basic salary.

MariaDB [Company]> select * from emp order by sal;
+-------+----------+------------+------+------------+------+------+--------+
| empno | empname  | job        | mgr  | hiredate   | sal  | comm | deptno |
+-------+----------+------------+------+------------+------+------+--------+
|  8343 | Ramesh   | PT         | 7698 | 2023-12-12 |  500 |  300 |     60 |
|  8344 | Krish    | PT         | 7698 | 2023-12-12 | 2000 |  300 |     60 |
|  5883 | Jeffery  | Research   | 5817 | 2057-08-03 | 2033 |  549 |     20 |
|  9384 | Matilda  | Operations | 5817 | 2025-05-23 | 2494 | 1170 |     40 |
|  5595 | Isabella | Sales      | 8245 | 2075-09-10 | 2534 | 1545 |     30 |
|  9180 | Jesse    | Accounting | 2678 | 2101-08-22 | 3562 | 1796 |     10 |
|  8467 | Mollie   | Accounting | 5919 | 2015-02-09 | 3999 |  526 |     10 |
|  9360 | Isaiah   | Accounting | 7940 | 2101-09-03 | 4000 | 1390 |     10 |
|  9487 | Amelia   | Research   | 7940 | 2123-01-17 | 5368 | 1998 |     20 |
|  6880 | Cameron  | Sales      | 8245 | 2059-05-09 | 6311 | 1406 |     30 |
|  7235 | Stephen  | Operations | 2678 | 2083-00-31 | 6556 | 1698 |     40 |
|  9085 | Katie    | Research   | 5919 | 1997-01-26 | 8241 | 1166 |     20 |
|  7553 | Angel    | Sales      | 2678 | 2099-06-03 | 9352 |  983 |     30 |
+-------+----------+------------+------+------------+------+------+--------+
13 rows in set (0.001 sec)


4. List the employee name and hire date in the descending order of the hire date.

MariaDB [Company]> select empname, hiredate from emp order by hiredate desc;
+----------+------------+
| empname  | hiredate   |
+----------+------------+
| Amelia   | 2123-01-17 |
| Isaiah   | 2101-09-03 |
| Jesse    | 2101-08-22 |
| Angel    | 2099-06-03 |
| Stephen  | 2083-00-31 |
| Isabella | 2075-09-10 |
| Cameron  | 2059-05-09 |
| Jeffery  | 2057-08-03 |
| Matilda  | 2025-05-23 |
| Ramesh   | 2023-12-12 |
| Krish    | 2023-12-12 |
| Mollie   | 2015-02-09 |
| Katie    | 1997-01-26 |
+----------+------------+
13 rows in set (0.002 sec)

5. List employee name, salary, PF, HRA, DA and gross; order the results in the ascending order of
gross. HRA is 50% of the salary and DA is 30% of the salary.

MariaDB [Company]> select empname, sal, sal*.10 as PF, sal*.50 as HRA, sal*.30 as DA, sal + sal*.90 as Gross from emp order by Gross;
+----------+------+--------+---------+---------+----------+
| empname  | sal  | PF     | HRA     | DA      | Gross    |
+----------+------+--------+---------+---------+----------+
| Ramesh   |  500 |  50.00 |  250.00 |  150.00 |   950.00 |
| Krish    | 2000 | 200.00 | 1000.00 |  600.00 |  3800.00 |
| Jeffery  | 2033 | 203.30 | 1016.50 |  609.90 |  3862.70 |
| Matilda  | 2494 | 249.40 | 1247.00 |  748.20 |  4738.60 |
| Isabella | 2534 | 253.40 | 1267.00 |  760.20 |  4814.60 |
| Jesse    | 3562 | 356.20 | 1781.00 | 1068.60 |  6767.80 |
| Mollie   | 3999 | 399.90 | 1999.50 | 1199.70 |  7598.10 |
| Isaiah   | 4000 | 400.00 | 2000.00 | 1200.00 |  7600.00 |
| Amelia   | 5368 | 536.80 | 2684.00 | 1610.40 | 10199.20 |
| Cameron  | 6311 | 631.10 | 3155.50 | 1893.30 | 11990.90 |
| Stephen  | 6556 | 655.60 | 3278.00 | 1966.80 | 12456.40 |
| Katie    | 8241 | 824.10 | 4120.50 | 2472.30 | 15657.90 |
| Angel    | 9352 | 935.20 | 4676.00 | 2805.60 | 17768.80 |
+----------+------+--------+---------+---------+----------+
13 rows in set (0.001 sec)

6. List the department numbers and number of employees in each department.

MariaDB [Company]> select deptno,count(*) from emp group by deptno;
+--------+----------+
| deptno | count(*) |
+--------+----------+
|     10 |        3 |
|     20 |        3 |
|     30 |        3 |
|     40 |        2 |
|     60 |        2 |
+--------+----------+
5 rows in set (0.002 sec)

7. Increment the Salary of salesman by 10% of basic salary.

MariaDB [Company]> update emp set sal=sal+(sal*.10) where job='sales';
Query OK, 3 rows affected (0.006 sec)
Rows matched: 3  Changed: 3  Warnings: 0

8. List the total salary, maximum and minimum salary and average salary of the employees, for
department 20.

select sum(sal),max(sal),min(sal),avg(sal) from emp where deptno=20;
+----------+----------+----------+-----------+
| sum(sal) | max(sal) | min(sal) | avg(sal)  |
+----------+----------+----------+-----------+
|    15642 |     8241 |     2033 | 5214.0000 |
+----------+----------+----------+-----------+
1 row in set (0.001 sec)

9. List the employees whose names contains 3 rd letter as 'I'.

MariaDB [Company]> select empname from emp where empname like '__i%';
+---------+
| empname |
+---------+
| Krish   |
+---------+
1 row in set (0.001 sec)

10. List the maximum salary paid to a salesman.

MariaDB [Company]> select *, max(sal) from emp where job='sales';
+-------+----------+-------+------+------------+------+------+--------+----------+
| empno | empname  | job   | mgr  | hiredate   | sal  | comm | deptno | max(sal) |
+-------+----------+-------+------+------------+------+------+--------+----------+
|  5595 | Isabella | Sales | 8245 | 2075-09-10 | 2787 | 1545 |     30 |    10287 |
+-------+----------+-------+------+------------+------+------+--------+----------+
1 row in set (0.001 sec)


11. Increase the salary of salesman by 10% of their current salary.

MariaDB [Company]> update emp set sal=sal+(sal*.10) where job='sales';
Query OK, 3 rows affected (0.001 sec)
Rows matched: 3  Changed: 3  Warnings: 0

## Queries Set 2

1. List the employee names and his annual salary dept wise.

MariaDB [Company]> select deptno, empname, sal*12 as Annual_Sal from emp order by deptno;
+--------+----------+------------+
| deptno | empname  | Annual_Sal |
+--------+----------+------------+
|     10 | Mollie   |      47988 |
|     10 | Isaiah   |      48000 |
|     10 | Jesse    |      38856 |
|     20 | Katie    |      98892 |
|     20 | Amelia   |      64416 |
|     20 | Jeffery  |      24396 |
|     30 | Angel    |     112224 |
|     30 | Cameron  |      75732 |
|     30 | Isabella |      30408 |
|     50 | Stephen  |      78672 |
|     50 | Matilda  |      29928 |
+--------+----------+------------+
11 rows in set (0.000 sec)

2. Find out least 5 earners of the company.

MariaDB [Company]> select empname from emp order by sal asc limit 5;
+----------+
| empname  |
+----------+
| Jeffery  |
| Matilda  |
| Isabella |
| Jesse    |
| Mollie   |
+----------+
5 rows in set (0.001 sec)
3. List the records from emp whose deptno is not in dept

MariaDB [Company]> select * from emp where deptno not in (select deptno from dept);
+-------+---------+------+------+------------+------+------+--------+
| empno | empname | job  | mgr  | hiredate   | sal  | comm | deptno |
+-------+---------+------+------+------------+------+------+--------+
|  8344 | Krish   | PT   | 7698 | 2023-12-12 | 2000 |  300 |     60 |
+-------+---------+------+------+------------+------+------+--------+
1 row in set (0.002 sec)

4. List those employees whose sal is odd value.

MariaDB [Company]> select * from emp where sal % 2 != 0;
+-------+---------+------------+------+------------+------+------+--------+
| empno | empname | job        | mgr  | hiredate   | sal  | comm | deptno |
+-------+---------+------------+------+------------+------+------+--------+
|  5883 | Jeffery | Research   | 5817 | 2057-08-03 | 2033 |  549 |     20 |
|  6880 | Cameron | Sales      | 8245 | 2059-05-09 | 6311 | 1406 |     30 |
|  8467 | Mollie  | Accounting | 5919 | 2015-02-09 | 3999 |  526 |     10 |
|  9085 | Katie   | Research   | 5919 | 1997-01-26 | 8241 | 1166 |     20 |
+-------+---------+------------+------+------------+------+------+--------+
4 rows in set (0.001 sec)

5. List the employees whose sal contain 3 digits.

MariaDB [Company]> select * from emp where sal/1000 < 1;
+-------+---------+------+------+------------+-----+------+--------+
| empno | empname | job  | mgr  | hiredate   | sal | comm | deptno |
+-------+---------+------+------+------------+-----+------+--------+
|  8343 | Ramesh  | PT   | 7698 | 2023-12-12 | 500 |  300 |     60 |
+-------+---------+------+------+------------+-----+------+--------+
1 row in set (0.001 sec)

6. List the employees who joined in the month of 'DEC'

MariaDB [Company]> select * from emp where hiredate like "%%%%-12-%%";
+-------+---------+------+------+------------+------+------+--------+
| empno | empname | job  | mgr  | hiredate   | sal  | comm | deptno |
+-------+---------+------+------+------------+------+------+--------+
|  8343 | Ramesh  | PT   | 7698 | 2023-12-12 |  500 |  300 |     60 |
|  8344 | Krish   | PT   | 7698 | 2023-12-12 | 2000 |  300 |     60 |
+-------+---------+------+------+------------+------+------+--------+
2 rows in set (0.001 sec)

7. List the employees whose names contains 'A'

MariaDB [Company]> select * from emp where empname like "A%";
+-------+---------+----------+------+------------+------+------+--------+
| empno | empname | job      | mgr  | hiredate   | sal  | comm | deptno |
+-------+---------+----------+------+------------+------+------+--------+
|  7553 | Angel   | Sales    | 2678 | 2099-06-03 | 9352 |  983 |     30 |
|  9487 | Amelia  | Research | 7940 | 2123-01-17 | 5368 | 1998 |     20 |
+-------+---------+----------+------+------------+------+------+--------+
2 rows in set (0.001 sec)

8. List the maximum, minimum and average salary in the company.

MariaDB [Company]> select max(sal), min(sal), avg(sal) from emp;
+----------+----------+-----------+
| max(sal) | min(sal) | avg(sal)  |
+----------+----------+-----------+
|     9352 |      500 | 4355.8462 |
+----------+----------+-----------+
1 row in set (0.001 sec)

9. Write a query to return the day of the week for any date(or HIRE_DATE) entered in format
'DD-MM-YY'


MariaDB [Company]> select dayname(hiredate) from emp;
+-------------------+
| dayname(hiredate) |
+-------------------+
| Tuesday           |
| Friday            |
| Friday            |
| NULL              |
| Wednesday         |
| Tuesday           |
| Tuesday           |
| Monday            |
| Sunday            |
| Monday            |
| Saturday          |
| Friday            |
| Sunday            |
+-------------------+
13 rows in set (0.002 sec)

10. Count the no of characters in employee name without considering spaces for each name.

MariaDB [Company]> select empname, length(replace(empname, ' ', '')) + 1 as length from emp;
+----------+--------+
| empname  | length |
+----------+--------+
| Isabella |      9 |
| Jeffery  |      8 |
| Cameron  |      8 |
| Stephen  |      8 |
| Angel    |      6 |
| Ramesh   |      7 |
| Krish    |      6 |
| Mollie   |      7 |
| Katie    |      6 |
| Jesse    |      6 |
| Isaiah   |      7 |
| Matilda  |      8 |
| Amelia   |      7 |
+----------+--------+
13 rows in set (0.001 sec)

11. List the employees who are drawing less than 1000. sort the output by salary.

MariaDB [Company]> select * from emp where sal < 1000 order by sal;
+-------+---------+------+------+------------+-----+------+--------+
| empno | empname | job  | mgr  | hiredate   | sal | comm | deptno |
+-------+---------+------+------+------------+-----+------+--------+
|  8343 | Ramesh  | PT   | 7698 | 2023-12-12 | 500 |  300 |     60 |
+-------+---------+------+------+------------+-----+------+--------+
1 row in set (0.002 sec)

## Queries Set 3

1. Write a query in SQL to display the unique designations for the employees.

MariaDB [Company]> select distinct job from emp;
+------------+
| job        |
+------------+
| Sales      |
| Research   |
| Operations |
| PT         |
| Accounting |
+------------+
5 rows in set (0.001 sec)

2. Delete Employees who joined in Year 1980.

MariaDB [Company]> delete from emp where year(hiredate) = 1980;
Query OK, 0 rows affected (0.001 sec)

3. Increase the salary of Managers by 20% of their current salary.

MariaDB [Company]> update emp set sal = sal + sal*0.2 where job = 'Manager';
Query OK, 0 rows affected (0.001 sec)
Rows matched: 0  Changed: 0  Warnings: 0

4. List employees not belonging to department 30, 40, or 10.

MariaDB [Company]> select * from emp where deptno not in (30, 40, 10);
+-------+---------+----------+------+------------+------+------+--------+
| empno | empname | job      | mgr  | hiredate   | sal  | comm | deptno |
+-------+---------+----------+------+------------+------+------+--------+
|  5883 | Jeffery | Research | 5817 | 2057-08-03 | 2236 |  549 |     20 |
|  8343 | Ramesh  | PT       | 7698 | 2023-12-12 |  500 |    0 |     60 |
|  8344 | Krish   | PT       | 7698 | 2023-12-12 | 2000 |  300 |     60 |
|  9085 | Katie   | Research | 5919 | 1997-01-26 | 9065 | 1166 |     20 |
|  9487 | Amelia  | Research | 7940 | 2123-01-17 | 5905 | 1998 |     20 |
+-------+---------+----------+------+------------+------+------+--------+
5 rows in set (0.001 sec)

5. List the different designations in the company.

MariaDB [Company]> select distinct job from emp;
+------------+
| job        |
+------------+
| Sales      |
| Research   |
| Operations |
| PT         |
| Accounting |
+------------+
5 rows in set (0.001 sec)

6. List the names of employees who are not eligible for commission.

MariaDB [Company]> select * from emp where sal < 1000;
+-------+---------+------+------+------------+-----+------+--------+
| empno | empname | job  | mgr  | hiredate   | sal | comm | deptno |
+-------+---------+------+------+------------+-----+------+--------+
|  8343 | Ramesh  | PT   | 7698 | 2023-12-12 | 500 |    0 |     60 |
+-------+---------+------+------+------------+-----+------+--------+
1 row in set (0.001 sec)

7. List employees whose names either start or end with "S".

MariaDB [Company]>  select * from emp where empname like 'S%' or empname like '%S';
+-------+---------+------------+------+------------+------+------+--------+
| empno | empname | job        | mgr  | hiredate   | sal  | comm | deptno |
+-------+---------+------------+------+------------+------+------+--------+
|  7235 | Stephen | Operations | 2678 | 2083-00-31 | 6556 | 1698 |     40 |
+-------+---------+------------+------+------------+------+------+--------+
1 row in set (0.001 sec)

8. List employees whose names have letter "A" as second letter in their names.

MariaDB [Company]> select * from emp where empname like '_A%';
+-------+---------+------------+------+------------+------+------+--------+
| empno | empname | job        | mgr  | hiredate   | sal  | comm | deptno |
+-------+---------+------------+------+------------+------+------+--------+
|  6880 | Cameron | Sales      | 8245 | 2059-05-09 | 7636 | 1406 |     30 |
|  8343 | Ramesh  | PT         | 7698 | 2023-12-12 |  500 |    0 |     60 |
|  9085 | Katie   | Research   | 5919 | 1997-01-26 | 9065 | 1166 |     20 |
|  9384 | Matilda | Operations | 5817 | 2025-05-23 | 2494 | 1170 |     40 |
+-------+---------+------------+------+------------+------+------+--------+
4 rows in set (0.001 sec)

9. List the number of employees working with the company.

MariaDB [Company]> select count(*) from emp;
+----------+
| count(*) |
+----------+
|       13 |
+----------+
1 row in set (0.001 sec)

10. List the emps with hiredate in format June 4,1988.

MariaDB [Company]> select * from emp where hiredate = '1988-06-04';
Empty set (0.001 sec)

11. List the salesmen who get the commission within a range of 200 and 5000.

MariaDB [Company]> select * from emp where job = 'Sales' and comm between 200 and 5000;
+-------+----------+-------+------+------------+-------+------+--------+
| empno | empname  | job   | mgr  | hiredate   | sal   | comm | deptno |
+-------+----------+-------+------+------------+-------+------+--------+
|  5595 | Isabella | Sales | 8245 | 2075-09-10 |  3066 | 1545 |     30 |
|  6880 | Cameron  | Sales | 8245 | 2059-05-09 |  7636 | 1406 |     30 |
|  7553 | Angel    | Sales | 2678 | 2099-06-03 | 11316 |  983 |     30 |
+-------+----------+-------+------+------------+-------+------+--------+
3 rows in set (0.001 sec)

## Queries Set 4

1. List names of employees who are more than 2 years old in the company.

MariaDB [Company]> select empname from emp where datediff(curdate(), hiredate)/365 > 2;
+---------+
| empname |
+---------+
| Mollie  |
| Katie   |
+---------+
2 rows in set (0.001 sec)

2. List the employee details in the ascending order of their basic salary.

MariaDB [Company]> select * from emp order by sal;
+-------+----------+------------+------+------------+------+------+--------+
| empno | empname  | job        | mgr  | hiredate   | sal  | comm | deptno |
+-------+----------+------------+------+------------+------+------+--------+
|  8343 | Ramesh   | PT         | 7698 | 2023-12-12 |  500 |  300 |     60 |
|  8344 | Krish    | PT         | 7698 | 2023-12-12 | 2000 |  300 |     60 |
|  5883 | Jeffery  | Research   | 5817 | 2057-08-03 | 2033 |  549 |     20 |
|  9384 | Matilda  | Operations | 5817 | 2025-05-23 | 2494 | 1170 |     40 |
|  5595 | Isabella | Sales      | 8245 | 2075-09-10 | 2534 | 1545 |     30 |
|  9180 | Jesse    | Accounting | 2678 | 2101-08-22 | 3238 | 1796 |     10 |
|  8467 | Mollie   | Accounting | 5919 | 2015-02-09 | 3999 |  526 |     10 |
|  9360 | Isaiah   | Accounting | 7940 | 2101-09-03 | 4000 | 1390 |     10 |
|  9487 | Amelia   | Research   | 7940 | 2123-01-17 | 5368 | 1998 |     20 |
|  6880 | Cameron  | Sales      | 8245 | 2059-05-09 | 6311 | 1406 |     30 |
|  7235 | Stephen  | Operations | 2678 | 2083-00-31 | 6556 | 1698 |     40 |
|  9085 | Katie    | Research   | 5919 | 1997-01-26 | 8241 | 1166 |     20 |
|  7553 | Angel    | Sales      | 2678 | 2099-06-03 | 9352 |  983 |     30 |
+-------+----------+------------+------+------------+------+------+--------+
13 rows in set (0.002 sec)

3. Display the employees who have more salary as that of Smith

MariaDB [Company]> select * from emp where sal > (select sal from emp where empname = 'Mollie');
+-------+---------+------------+------+------------+------+------+--------+
| empno | empname | job        | mgr  | hiredate   | sal  | comm | deptno |
+-------+---------+------------+------+------------+------+------+--------+
|  6880 | Cameron | Sales      | 8245 | 2059-05-09 | 6311 | 1406 |     30 |
|  7235 | Stephen | Operations | 2678 | 2083-00-31 | 6556 | 1698 |     40 |
|  7553 | Angel   | Sales      | 2678 | 2099-06-03 | 9352 |  983 |     30 |
|  9085 | Katie   | Research   | 5919 | 1997-01-26 | 8241 | 1166 |     20 |
|  9360 | Isaiah  | Accounting | 7940 | 2101-09-03 | 4000 | 1390 |     10 |
|  9487 | Amelia  | Research   | 7940 | 2123-01-17 | 5368 | 1998 |     20 |
+-------+---------+------------+------+------------+------+------+--------+
6 rows in set (0.001 sec)

4. Increment the salary of Emp no. 9180 by 10% of his current salary.

MariaDB [Company]> select * from emp where empno = 9180;
+-------+---------+------------+------+------------+------+------+--------+
| empno | empname | job        | mgr  | hiredate   | sal  | comm | deptno |
+-------+---------+------------+------+------------+------+------+--------+
|  9180 | Jesse   | Accounting | 2678 | 2101-08-22 | 3562 | 1796 |     10 |
+-------+---------+------------+------+------------+------+------+--------+
1 row in set (0.001 sec)

5. List the employees whose salary is between 10000 and 25000.

MariaDB [Company]> select * from emp where sal between 10000 and 25000;
+-------+---------+-------+------+------------+-------+------+--------+
| empno | empname | job   | mgr  | hiredate   | sal   | comm | deptno |
+-------+---------+-------+------+------------+-------+------+--------+
|  7553 | Angel   | Sales | 2678 | 2099-06-03 | 11316 |  983 |     30 |
+-------+---------+-------+------+------------+-------+------+--------+
1 row in set (0.000 sec)

6. List the names of employees who are not eligible for commission.

MariaDB [Company]> select * from emp where sal < 1000;
+-------+---------+------+------+------------+-----+------+--------+
| empno | empname | job  | mgr  | hiredate   | sal | comm | deptno |
+-------+---------+------+------+------------+-----+------+--------+
|  8343 | Ramesh  | PT   | 7698 | 2023-12-12 | 500 |    0 |     60 |
+-------+---------+------+------+------------+-----+------+--------+
1 row in set (0.001 sec)

7. Increment the Salary of Research by 10% of basic salary.

MariaDB [Company]> update emp set sal = sal + sal*0.1 where job = "Research";
Query OK, 3 rows affected (0.001 sec)
Rows matched: 3  Changed: 3  Warnings: 0

8. List the total salary, maximum and minimum salary and average salary of the employees
jobwise.

MariaDB [Company]> select job, sum(sal) as total, max(sal) as max, min(sal) as min, avg(sal) as avg from emp group by job;
+------------+-------+-------+------+-----------+
| job        | total | max   | min  | avg       |
+------------+-------+-------+------+-----------+
| Accounting | 11561 |  4000 | 3562 | 3853.6667 |
| Operations |  9050 |  6556 | 2494 | 4525.0000 |
| PT         |  2500 |  2000 |  500 | 1250.0000 |
| Research   | 17206 |  9065 | 2236 | 5735.3333 |
| Sales      | 22018 | 11316 | 3066 | 7339.3333 |
+------------+-------+-------+------+-----------+
5 rows in set (0.002 sec)

9. Delete the Employee whose name starts with P.

MariaDB [Company]> delete from emp where empname like 'P%';
Query OK, 0 rows affected (0.001 sec)

10. List the employees whose designation is "Research" and commission is > 500.

MariaDB [Company]> select * from emp where job = 'Research' and comm > 500;
+-------+---------+----------+------+------------+------+------+--------+
| empno | empname | job      | mgr  | hiredate   | sal  | comm | deptno |
+-------+---------+----------+------+------------+------+------+--------+
|  5883 | Jeffery | Research | 5817 | 2057-08-03 | 2236 |  549 |     20 |
|  9085 | Katie   | Research | 5919 | 1997-01-26 | 9065 | 1166 |     20 |
|  9487 | Amelia  | Research | 7940 | 2123-01-17 | 5905 | 1998 |     20 |
+-------+---------+----------+------+------------+------+------+--------+
3 rows in set (0.001 sec)

11. List employees belonging to department 20, 30, 40.

MariaDB [Company]> select * from emp where deptno in (20, 30, 40);
+-------+----------+------------+------+------------+-------+------+--------+
| empno | empname  | job        | mgr  | hiredate   | sal   | comm | deptno |
+-------+----------+------------+------+------------+-------+------+--------+
|  5595 | Isabella | Sales      | 8245 | 2075-09-10 |  3066 | 1545 |     30 |
|  5883 | Jeffery  | Research   | 5817 | 2057-08-03 |  2236 |  549 |     20 |
|  6880 | Cameron  | Sales      | 8245 | 2059-05-09 |  7636 | 1406 |     30 |
|  7235 | Stephen  | Operations | 2678 | 2083-00-31 |  6556 | 1698 |     40 |
|  7553 | Angel    | Sales      | 2678 | 2099-06-03 | 11316 |  983 |     30 |
|  9085 | Katie    | Research   | 5919 | 1997-01-26 |  9065 | 1166 |     20 |
|  9384 | Matilda  | Operations | 5817 | 2025-05-23 |  2494 | 1170 |     40 |
|  9487 | Amelia   | Research   | 7940 | 2123-01-17 |  5905 | 1998 |     20 |
+-------+----------+------------+------+------------+-------+------+--------+
8 rows in set (0.002 sec)

## Queries Set 5

1. List the employee names and his annual salary Job wise.

MariaDB [Company]> select job, empname, sal*12 as annual from emp;
+------------+----------+--------+
| job        | empname  | annual |
+------------+----------+--------+
| Sales      | Isabella |  36792 |
| Research   | Jeffery  |  26832 |
| Sales      | Cameron  |  91632 |
| Operations | Stephen  |  78672 |
| Sales      | Angel    | 135792 |
| PT         | Ramesh   |   6000 |
| PT         | Krish    |  24000 |
| Accounting | Mollie   |  47988 |
| Research   | Katie    | 108780 |
| Accounting | Jesse    |  42744 |
| Accounting | Isaiah   |  48000 |
| Operations | Matilda  |  29928 |
| Research   | Amelia   |  70860 |
+------------+----------+--------+
13 rows in set (0.001 sec)


2. Delete the Employee whose name starts with A & R

MariaDB [Company]> delete from emp where empname like 'A%' or empname like 'R%';
Query OK, 3 rows affected (0.002 sec)

3. Increment the salary of Emp no. 7000 by 30% of his current salary.

MariaDB [Company]> update emp set sal = sal + sal*0.3 where empno = 7000;
Query OK, 0 rows affected (0.001 sec)
Rows matched: 0  Changed: 0  Warnings: 0

4. List the total salary, maximum and minimum salary and average salary of the employees hire date wise.

MariaDB [Company]> select hiredate, sum(sal) as total, max(sal) as max, min(sal) as min, avg(sal) as avg from emp group by hiredate;
+------------+-------+------+------+-----------+
| hiredate   | total | max  | min  | avg       |
+------------+-------+------+------+-----------+
| 1997-01-26 |  9065 | 9065 | 9065 | 9065.0000 |
| 2015-02-09 |  3999 | 3999 | 3999 | 3999.0000 |
| 2023-12-12 |  2000 | 2000 | 2000 | 2000.0000 |
| 2025-05-23 |  2494 | 2494 | 2494 | 2494.0000 |
| 2057-08-03 |  2236 | 2236 | 2236 | 2236.0000 |
| 2059-05-09 |  7636 | 7636 | 7636 | 7636.0000 |
| 2075-09-10 |  3066 | 3066 | 3066 | 3066.0000 |
| 2083-00-31 |  6556 | 6556 | 6556 | 6556.0000 |
| 2101-08-22 |  3562 | 3562 | 3562 | 3562.0000 |
| 2101-09-03 |  4000 | 4000 | 4000 | 4000.0000 |
+------------+-------+------+------+-----------+
10 rows in set (0.001 sec)

5. List the employees whose names contains last letter as 'T'.

MariaDB [Company]> select * from emp where empname like '%T';
Empty set (0.001 sec)

6. Display the employees who have less salary as that of Ankush

MariaDB [Company]> select * from emp where sal < (select sal from emp where empname = 'Ankush');
Empty set (0.001 sec)

7. Display the employees who have salary between 10000

MariaDB [Company]> select * from emp where sal between 10000 and 20000;
Empty set (0.001 sec)

8. List employees belonging to department 30, 40, or 10.

MariaDB [Company]> select * from emp where deptno in (30, 40, 10);
+-------+----------+------------+------+------------+------+------+--------+
| empno | empname  | job        | mgr  | hiredate   | sal  | comm | deptno |
+-------+----------+------------+------+------------+------+------+--------+
|  5595 | Isabella | Sales      | 8245 | 2075-09-10 | 3066 | 1545 |     30 |
|  6880 | Cameron  | Sales      | 8245 | 2059-05-09 | 7636 | 1406 |     30 |
|  7235 | Stephen  | Operations | 2678 | 2083-00-31 | 6556 | 1698 |     40 |
|  8467 | Mollie   | Accounting | 5919 | 2015-02-09 | 3999 |  526 |     10 |
|  9180 | Jesse    | Accounting | 2678 | 2101-08-22 | 3562 | 1796 |     10 |
|  9360 | Isaiah   | Accounting | 7940 | 2101-09-03 | 4000 | 1390 |     10 |
|  9384 | Matilda  | Operations | 5817 | 2025-05-23 | 2494 | 1170 |     40 |
+-------+----------+------------+------+------------+------+------+--------+
7 rows in set (0.001 sec)

9. List the employees whose designation is 'Research' and sal is > 5000.

MariaDB [Company]> select * from emp where job = 'Research' and sal > 5000;
+-------+---------+----------+------+------------+------+------+--------+
| empno | empname | job      | mgr  | hiredate   | sal  | comm | deptno |
+-------+---------+----------+------+------------+------+------+--------+
|  9085 | Katie   | Research | 5919 | 1997-01-26 | 9065 | 1166 |     20 |
+-------+---------+----------+------+------------+------+------+--------+
1 row in set (0.001 sec)

10. List the employees details descending wise whose designation is 'Research' and commission is > 500.

MariaDB [Company]> select * from emp where job = 'Research' and comm > 500 order by comm desc;
+-------+---------+----------+------+------------+------+------+--------+
| empno | empname | job      | mgr  | hiredate   | sal  | comm | deptno |
+-------+---------+----------+------+------------+------+------+--------+
|  9085 | Katie   | Research | 5919 | 1997-01-26 | 9065 | 1166 |     20 |
|  5883 | Jeffery | Research | 5817 | 2057-08-03 | 2236 |  549 |     20 |
+-------+---------+----------+------+------------+------+------+--------+
2 rows in set (0.001 sec)
