
MariaDB [class_stuff]> create table Movies(movie_id int primary key, title varchar(50), category varchar(50));
Query OK, 0 rows affected (0.008 sec)

MariaDB [class_stuff]> create table artist(id int primary key, first_name varchar(50), last_name varchar(50), movie_id int, foreign key(movie_id) references Movies(movie_id));
Query OK, 0 rows affected (0.009 sec)

MariaDB [class_stuff]> insert into Movies values(1, "Assassin's creed", "Animations");
Query OK, 1 row affected (0.003 sec)

MariaDB [class_stuff]> insert into Movies values(2, "Real Steel", "Animations");
Query OK, 1 row affected (0.001 sec)

MariaDB [class_stuff]> insert into artist values(1, "Adam", "Smith", 1);
Query OK, 1 row affected (0.002 sec)

MariaDB [class_stuff]> insert into artist values(2, "Ravi", "Kumar", 2);
Query OK, 1 row affected (0.001 sec)

MariaDB [class_stuff]> select * from Movies, artist;
+----------+------------------+------------+----+------------+-----------+----------+
| movie_id | title            | category   | id | first_name | last_name | movie_id |
+----------+------------------+------------+----+------------+-----------+----------+
|        1 | Assassin's creed | Animations |  1 | Adam       | Smith     |        1 |
|        2 | Real Steel       | Animations |  1 | Adam       | Smith     |        1 |
|        1 | Assassin's creed | Animations |  2 | Ravi       | Kumar     |        2 |
|        2 | Real Steel       | Animations |  2 | Ravi       | Kumar     |        2 |
+----------+------------------+------------+----+------------+-----------+----------+
4 rows in set (0.002 sec)

MariaDB [class_stuff]> select * from Movies cross join artist;
+----------+------------------+------------+----+------------+-----------+----------+
| movie_id | title            | category   | id | first_name | last_name | movie_id |
+----------+------------------+------------+----+------------+-----------+----------+
|        1 | Assassin's creed | Animations |  1 | Adam       | Smith     |        1 |
|        2 | Real Steel       | Animations |  1 | Adam       | Smith     |        1 |
|        1 | Assassin's creed | Animations |  2 | Ravi       | Kumar     |        2 |
|        2 | Real Steel       | Animations |  2 | Ravi       | Kumar     |        2 |
+----------+------------------+------------+----+------------+-----------+----------+
4 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from artist, Movies;
+----+------------+-----------+----------+----------+------------------+------------+
| id | first_name | last_name | movie_id | movie_id | title            | category   |
+----+------------+-----------+----------+----------+------------------+------------+
|  1 | Adam       | Smith     |        1 |        1 | Assassin's creed | Animations |
|  2 | Ravi       | Kumar     |        2 |        1 | Assassin's creed | Animations |
|  1 | Adam       | Smith     |        1 |        2 | Real Steel       | Animations |
|  2 | Ravi       | Kumar     |        2 |        2 | Real Steel       | Animations |
+----+------------+-----------+----------+----------+------------------+------------+
4 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from Movies, artist where artist.movie_id = Movies.movie_id;
+----------+------------------+------------+----+------------+-----------+----------+
| movie_id | title            | category   | id | first_name | last_name | movie_id |
+----------+------------------+------------+----+------------+-----------+----------+
|        1 | Assassin's creed | Animations |  1 | Adam       | Smith     |        1 |
|        2 | Real Steel       | Animations |  2 | Ravi       | Kumar     |        2 |
+----------+------------------+------------+----+------------+-----------+----------+
2 rows in set (0.003 sec)

MariaDB [class_stuff]> select * from Movies inner join artist on Movies.movie_id = artist.movie_id;
+----------+------------------+------------+----+------------+-----------+----------+
| movie_id | title            | category   | id | first_name | last_name | movie_id |
+----------+------------------+------------+----+------------+-----------+----------+
|        1 | Assassin's creed | Animations |  1 | Adam       | Smith     |        1 |
|        2 | Real Steel       | Animations |  2 | Ravi       | Kumar     |        2 |
+----------+------------------+------------+----+------------+-----------+----------+
2 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from Movies, artist where artist.movie_id = Movies.movie_id;
+----------+------------------+------------+----+------------+-----------+----------+
| movie_id | title            | category   | id | first_name | last_name | movie_id |
+----------+------------------+------------+----+------------+-----------+----------+
|        1 | Assassin's creed | Animations |  1 | Adam       | Smith     |        1 |
|        2 | Real Steel       | Animations |  2 | Ravi       | Kumar     |        2 |
+----------+------------------+------------+----+------------+-----------+----------+
2 rows in set (0.001 sec)


MariaDB [class_stuff]> select * from movies as m, artist as a;
+----------+------------------+------------+----+------------+-----------+----------+
| movie_id | title            | category   | id | first_name | last_name | movie_id |
+----------+------------------+------------+----+------------+-----------+----------+
|        1 | Assassin's creed | Animations |  1 | Adam       | Smith     |        1 |
|        2 | Real Steel       | Animations |  1 | Adam       | Smith     |        1 |
|        3 | Jurassic Park    | Animations |  1 | Adam       | Smith     |        1 |
|        1 | Assassin's creed | Animations |  2 | Ravi       | Kumar     |        2 |
|        2 | Real Steel       | Animations |  2 | Ravi       | Kumar     |        2 |
|        3 | Jurassic Park    | Animations |  2 | Ravi       | Kumar     |        2 |
+----------+------------------+------------+----+------------+-----------+----------+
6 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from movies left outer join artist using("movie_id");
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '"movie_id")' at line 1
MariaDB [class_stuff]> select * from movies left outer join artist using "movie_id"
    -> l
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '"movie_id"
l' at line 1
MariaDB [class_stuff]> select * from movies left outer join artist using "movie_id";
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '"movie_id"' at line 1
MariaDB [class_stuff]> select A.title, B.first_name, B.last_name from movies "A" left outer join artist "B" using("movie_id");
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '"A" left outer join artist "B" using("movie_id")' at line 1
MariaDB [class_stuff]> select A.title, B.first_name, B.last_name from movies "A" left outer join artist "B" using(movie_id);
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '"A" left outer join artist "B" using(movie_id)' at line 1
MariaDB [class_stuff]> select A.title, B.first_name, B.last_name from movies "A" left outer join artist "B" using('movie_id');
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '"A" left outer join artist "B" using('movie_id')' at line 1
MariaDB [class_stuff]> select * from movies left outer join artist on movies.movie_id = artist.movie_id;
+----------+------------------+------------+------+------------+-----------+----------+
| movie_id | title            | category   | id   | first_name | last_name | movie_id |
+----------+------------------+------------+------+------------+-----------+----------+
|        1 | Assassin's creed | Animations |    1 | Adam       | Smith     |        1 |
|        2 | Real Steel       | Animations |    2 | Ravi       | Kumar     |        2 |
|        3 | Jurassic Park    | Animations | NULL | NULL       | NULL      |     NULL |
+----------+------------------+------------+------+------------+-----------+----------+
3 rows in set (0.001 sec)

MariaDB [class_stuff]> show tables;
+-----------------------+
| Tables_in_class_stuff |
+-----------------------+
| Employee              |
| artist                |
| course                |
| dept                  |
| dept_sample           |
| movies                |
+-----------------------+
6 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from course;
Empty set (0.001 sec)

MariaDB [class_stuff]> describe course;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| course_id | varchar(10) | YES  |     | NULL    |       |
| title     | varchar(30) | YES  |     | NULL    |       |
| dept_name | varchar(30) | YES  |     | NULL    |       |
| credits   | int(11)     | YES  |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
4 rows in set (0.003 sec)

MariaDB [class_stuff]> insert into course values("Bio-301"), "Genetics", "Biology", 4);
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '"Genetics", "Biology", 4)' at line 1
MariaDB [class_stuff]> insert into course values("Bio-301", "Genetics", "Biology", 4);
Query OK, 1 row affected (0.001 sec)

MariaDB [class_stuff]> insert into course values("CS-190", "Game Design", "Comp Sci", 4);
Query OK, 1 row affected (0.001 sec)

MariaDB [class_stuff]> insert into course values("CS-315", "Robotics", "Comp Sci", 3);
Query OK, 1 row affected (0.003 sec)

MariaDB [class_stuff]> create table pre_req(course_id varchar(10) primary key, prereq_id varchar(10));
Query OK, 0 rows affected (0.007 sec)

MariaDB [class_stuff]> alter table pre_req add constraint foreign key(course_id) references course_id(course_id);
ERROR 1005 (HY000): Can't create table `class_stuff`.`pre_req` (errno: 150 "Foreign key constraint is incorrectly formed")
MariaDB [class_stuff]> alter table pre_req add constraint foreign key(course_id) references course(course_id);
ERROR 1005 (HY000): Can't create table `class_stuff`.`pre_req` (errno: 150 "Foreign key constraint is incorrectly formed")
MariaDB [class_stuff]> insert into pre_req("Bio-301", "Bio-101");
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '"Bio-301", "Bio-101")' at line 1
MariaDB [class_stuff]> insert into pre_req values("Bio-301", "Bio-101");
Query OK, 1 row affected (0.001 sec)

MariaDB [class_stuff]> insert into pre_req values("CS-190", "CS-101");
Query OK, 1 row affected (0.001 sec)

MariaDB [class_stuff]> insert into pre_req values("CS-315", "CS-101");
Query OK, 1 row affected (0.001 sec)

MariaDB [class_stuff]> select * from course left outer jjoin pre_req on course.course_id = pre_req.course_id;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'jjoin pre_req on course.course_id = pre_req.course_id' at line 1
MariaDB [class_stuff]> select * from course left outer join pre_req on course.course_id = pre_req.course_id;
+-----------+-------------+-----------+---------+-----------+-----------+
| course_id | title       | dept_name | credits | course_id | prereq_id |
+-----------+-------------+-----------+---------+-----------+-----------+
| Bio-301   | Genetics    | Biology   |       4 | Bio-301   | Bio-101   |
| CS-190    | Game Design | Comp Sci  |       4 | CS-190    | CS-101    |
| CS-315    | Robotics    | Comp Sci  |       3 | CS-315    | CS-101    |
+-----------+-------------+-----------+---------+-----------+-----------+
3 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from course left outer join pre_req on course.course_id = pre_req.course_id union
    -> select * from course right outer join pre_req on course.course_id = pre_req.course_id;
+-----------+-------------+-----------+---------+-----------+-----------+
| course_id | title       | dept_name | credits | course_id | prereq_id |
+-----------+-------------+-----------+---------+-----------+-----------+
| Bio-301   | Genetics    | Biology   |       4 | Bio-301   | Bio-101   |
| CS-190    | Game Design | Comp Sci  |       4 | CS-190    | CS-101    |
| CS-315    | Robotics    | Comp Sci  |       3 | CS-315    | CS-101    |
+-----------+-------------+-----------+---------+-----------+-----------+
3 rows in set (0.002 sec)

MariaDB [class_stuff]> insert into pre_req values("Bio-315", "Bio-101");
Query OK, 1 row affected (0.001 sec)

MariaDB [class_stuff]> select * from course left outer join pre_req on course.course_id = pre_req.course_id union  select * from course right outer join pre_req on course.course_id = pre_req.course_id;
+-----------+-------------+-----------+---------+-----------+-----------+
| course_id | title       | dept_name | credits | course_id | prereq_id |
+-----------+-------------+-----------+---------+-----------+-----------+
| Bio-301   | Genetics    | Biology   |       4 | Bio-301   | Bio-101   |
| CS-190    | Game Design | Comp Sci  |       4 | CS-190    | CS-101    |
| CS-315    | Robotics    | Comp Sci  |       3 | CS-315    | CS-101    |
| NULL      | NULL        | NULL      |    NULL | Bio-315   | Bio-101   |
+-----------+-------------+-----------+---------+-----------+-----------+
4 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from course right outer join pre_req on course.course_id = pre_req.course_id;
+-----------+-------------+-----------+---------+-----------+-----------+
| course_id | title       | dept_name | credits | course_id | prereq_id |
+-----------+-------------+-----------+---------+-----------+-----------+
| Bio-301   | Genetics    | Biology   |       4 | Bio-301   | Bio-101   |
| CS-190    | Game Design | Comp Sci  |       4 | CS-190    | CS-101    |
| CS-315    | Robotics    | Comp Sci  |       3 | CS-315    | CS-101    |
| NULL      | NULL        | NULL      |    NULL | Bio-315   | Bio-101   |
+-----------+-------------+-----------+---------+-----------+-----------+
4 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from course right outer join pre_req on course.course_id = pre_req.course_id;
+-----------+-------------+-----------+---------+-----------+-----------+
| course_id | title       | dept_name | credits | course_id | prereq_id |
+-----------+-------------+-----------+---------+-----------+-----------+
| Bio-301   | Genetics    | Biology   |       4 | Bio-301   | Bio-101   |
| CS-190    | Game Design | Comp Sci  |       4 | CS-190    | CS-101    |
| CS-315    | Robotics    | Comp Sci  |       3 | CS-315    | CS-101    |
| NULL      | NULL        | NULL      |    NULL | Bio-315   | Bio-101   |
+-----------+-------------+-----------+---------+-----------+-----------+
4 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from course left outer join pre_req on course.course_id = pre_req.course_id;
+-----------+-------------+-----------+---------+-----------+-----------+
| course_id | title       | dept_name | credits | course_id | prereq_id |
+-----------+-------------+-----------+---------+-----------+-----------+
| Bio-301   | Genetics    | Biology   |       4 | Bio-301   | Bio-101   |
| CS-190    | Game Design | Comp Sci  |       4 | CS-190    | CS-101    |
| CS-315    | Robotics    | Comp Sci  |       3 | CS-315    | CS-101    |
+-----------+-------------+-----------+---------+-----------+-----------+
3 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from course left outer join pre_req on course.course_id = pre_req.course_id;
+-----------+-------------+-----------+---------+-----------+-----------+
| course_id | title       | dept_name | credits | course_id | prereq_id |
+-----------+-------------+-----------+---------+-----------+-----------+
| Bio-301   | Genetics    | Biology   |       4 | Bio-301   | Bio-101   |
| CS-190    | Game Design | Comp Sci  |       4 | CS-190    | CS-101    |
| CS-315    | Robotics    | Comp Sci  |       3 | CS-315    | CS-101    |
+-----------+-------------+-----------+---------+-----------+-----------+
3 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from course right outer join pre_req on course.course_id = pre_req.course_id;
+-----------+-------------+-----------+---------+-----------+-----------+
| course_id | title       | dept_name | credits | course_id | prereq_id |
+-----------+-------------+-----------+---------+-----------+-----------+
| Bio-301   | Genetics    | Biology   |       4 | Bio-301   | Bio-101   |
| CS-190    | Game Design | Comp Sci  |       4 | CS-190    | CS-101    |
| CS-315    | Robotics    | Comp Sci  |       3 | CS-315    | CS-101    |
| NULL      | NULL        | NULL      |    NULL | Bio-315   | Bio-101   |
+-----------+-------------+-----------+---------+-----------+-----------+
4 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from course left outer join pre_req on course.course_id = pre_req.course_id union  select * from course right outer join pre_req on course.course_id = pre_req.course_id;
+-----------+-------------+-----------+---------+-----------+-----------+
| course_id | title       | dept_name | credits | course_id | prereq_id |
+-----------+-------------+-----------+---------+-----------+-----------+
| Bio-301   | Genetics    | Biology   |       4 | Bio-301   | Bio-101   |
| CS-190    | Game Design | Comp Sci  |       4 | CS-190    | CS-101    |
| CS-315    | Robotics    | Comp Sci  |       3 | CS-315    | CS-101    |
| NULL      | NULL        | NULL      |    NULL | Bio-315   | Bio-101   |
+-----------+-------------+-----------+---------+-----------+-----------+
4 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from course natural join pre_req;
+-----------+-------------+-----------+---------+-----------+
| course_id | title       | dept_name | credits | prereq_id |
+-----------+-------------+-----------+---------+-----------+
| Bio-301   | Genetics    | Biology   |       4 | Bio-101   |
| CS-190    | Game Design | Comp Sci  |       4 | CS-101    |
| CS-315    | Robotics    | Comp Sci  |       3 | CS-101    |
+-----------+-------------+-----------+---------+-----------+
3 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from pre_req;
+-----------+-----------+
| course_id | prereq_id |
+-----------+-----------+
| Bio-301   | Bio-101   |
| Bio-315   | Bio-101   |
| CS-190    | CS-101    |
| CS-315    | CS-101    |
+-----------+-----------+
4 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from course;
+-----------+-------------+-----------+---------+
| course_id | title       | dept_name | credits |
+-----------+-------------+-----------+---------+
| Bio-301   | Genetics    | Biology   |       4 |
| CS-190    | Game Design | Comp Sci  |       4 |
| CS-315    | Robotics    | Comp Sci  |       3 |
+-----------+-------------+-----------+---------+
3 rows in set (0.001 sec)

MariaDB [class_stuff]> select course_id as c, * from course;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '* from course' at line 1
MariaDB [class_stuff]> select course_id, * from course;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near '* from course' at line 1
MariaDB [class_stuff]> select * from course natural join dept;
+-----------+-------------+-----------+---------+--------+-------------+----------+
| course_id | title       | dept_name | credits | deptno | dname       | loc      |
+-----------+-------------+-----------+---------+--------+-------------+----------+
| Bio-301   | Genetics    | Biology   |       4 |     10 | Purchase    | Pune     |
| CS-190    | Game Design | Comp Sci  |       4 |     10 | Purchase    | Pune     |
| CS-315    | Robotics    | Comp Sci  |       3 |     10 | Purchase    | Pune     |
| Bio-301   | Genetics    | Biology   |       4 |     20 | Sales       | Mumbai   |
| CS-190    | Game Design | Comp Sci  |       4 |     20 | Sales       | Mumbai   |
| CS-315    | Robotics    | Comp Sci  |       3 |     20 | Sales       | Mumbai   |
| Bio-301   | Genetics    | Biology   |       4 |     30 | Coffee      | vaishali |
| CS-190    | Game Design | Comp Sci  |       4 |     30 | Coffee      | vaishali |
| CS-315    | Robotics    | Comp Sci  |       3 |     30 | Coffee      | vaishali |
| Bio-301   | Genetics    | Biology   |       4 |     50 | Development | NULL     |
| CS-190    | Game Design | Comp Sci  |       4 |     50 | Development | NULL     |
| CS-315    | Robotics    | Comp Sci  |       3 |     50 | Development | NULL     |
+-----------+-------------+-----------+---------+--------+-------------+----------+
12 rows in set (0.001 sec)

MariaDB [class_stuff]> describe dept;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| deptno | int(11)     | NO   |     | NULL    |       |
| dname  | varchar(15) | YES  |     | NULL    |       |
| loc    | varchar(30) | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+
3 rows in set (0.002 sec)

MariaDB [class_stuff]> select * from course cross join pre_req;
+-----------+-------------+-----------+---------+-----------+-----------+
| course_id | title       | dept_name | credits | course_id | prereq_id |
+-----------+-------------+-----------+---------+-----------+-----------+
| Bio-301   | Genetics    | Biology   |       4 | Bio-301   | Bio-101   |
| CS-190    | Game Design | Comp Sci  |       4 | Bio-301   | Bio-101   |
| CS-315    | Robotics    | Comp Sci  |       3 | Bio-301   | Bio-101   |
| Bio-301   | Genetics    | Biology   |       4 | Bio-315   | Bio-101   |
| CS-190    | Game Design | Comp Sci  |       4 | Bio-315   | Bio-101   |
| CS-315    | Robotics    | Comp Sci  |       3 | Bio-315   | Bio-101   |
| Bio-301   | Genetics    | Biology   |       4 | CS-190    | CS-101    |
| CS-190    | Game Design | Comp Sci  |       4 | CS-190    | CS-101    |
| CS-315    | Robotics    | Comp Sci  |       3 | CS-190    | CS-101    |
| Bio-301   | Genetics    | Biology   |       4 | CS-315    | CS-101    |
| CS-190    | Game Design | Comp Sci  |       4 | CS-315    | CS-101    |
| CS-315    | Robotics    | Comp Sci  |       3 | CS-315    | CS-101    |
+-----------+-------------+-----------+---------+-----------+-----------+
12 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from dept;
+--------+-------------+----------+
| deptno | dname       | loc      |
+--------+-------------+----------+
|     10 | Purchase    | Pune     |
|     20 | Sales       | Mumbai   |
|     30 | Coffee      | vaishali |
|     50 | Development | NULL     |
+--------+-------------+----------+
4 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from crouse;
ERROR 1146 (42S02): Table 'class_stuff.crouse' doesn't exist
MariaDB [class_stuff]> select * from course;
+-----------+-------------+-----------+---------+
| course_id | title       | dept_name | credits |
+-----------+-------------+-----------+---------+
| Bio-301   | Genetics    | Biology   |       4 |
| CS-190    | Game Design | Comp Sci  |       4 |
| CS-315    | Robotics    | Comp Sci  |       3 |
+-----------+-------------+-----------+---------+
3 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from course inner join dept;
+-----------+-------------+-----------+---------+--------+-------------+----------+
| course_id | title       | dept_name | credits | deptno | dname       | loc      |
+-----------+-------------+-----------+---------+--------+-------------+----------+
| Bio-301   | Genetics    | Biology   |       4 |     10 | Purchase    | Pune     |
| CS-190    | Game Design | Comp Sci  |       4 |     10 | Purchase    | Pune     |
| CS-315    | Robotics    | Comp Sci  |       3 |     10 | Purchase    | Pune     |
| Bio-301   | Genetics    | Biology   |       4 |     20 | Sales       | Mumbai   |
| CS-190    | Game Design | Comp Sci  |       4 |     20 | Sales       | Mumbai   |
| CS-315    | Robotics    | Comp Sci  |       3 |     20 | Sales       | Mumbai   |
| Bio-301   | Genetics    | Biology   |       4 |     30 | Coffee      | vaishali |
| CS-190    | Game Design | Comp Sci  |       4 |     30 | Coffee      | vaishali |
| CS-315    | Robotics    | Comp Sci  |       3 |     30 | Coffee      | vaishali |
| Bio-301   | Genetics    | Biology   |       4 |     50 | Development | NULL     |
| CS-190    | Game Design | Comp Sci  |       4 |     50 | Development | NULL     |
| CS-315    | Robotics    | Comp Sci  |       3 |     50 | Development | NULL     |
+-----------+-------------+-----------+---------+--------+-------------+----------+
12 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from course cross join dept;
+-----------+-------------+-----------+---------+--------+-------------+----------+
| course_id | title       | dept_name | credits | deptno | dname       | loc      |
+-----------+-------------+-----------+---------+--------+-------------+----------+
| Bio-301   | Genetics    | Biology   |       4 |     10 | Purchase    | Pune     |
| CS-190    | Game Design | Comp Sci  |       4 |     10 | Purchase    | Pune     |
| CS-315    | Robotics    | Comp Sci  |       3 |     10 | Purchase    | Pune     |
| Bio-301   | Genetics    | Biology   |       4 |     20 | Sales       | Mumbai   |
| CS-190    | Game Design | Comp Sci  |       4 |     20 | Sales       | Mumbai   |
| CS-315    | Robotics    | Comp Sci  |       3 |     20 | Sales       | Mumbai   |
| Bio-301   | Genetics    | Biology   |       4 |     30 | Coffee      | vaishali |
| CS-190    | Game Design | Comp Sci  |       4 |     30 | Coffee      | vaishali |
| CS-315    | Robotics    | Comp Sci  |       3 |     30 | Coffee      | vaishali |
| Bio-301   | Genetics    | Biology   |       4 |     50 | Development | NULL     |
| CS-190    | Game Design | Comp Sci  |       4 |     50 | Development | NULL     |
| CS-315    | Robotics    | Comp Sci  |       3 |     50 | Development | NULL     |
+-----------+-------------+-----------+---------+--------+-------------+----------+
12 rows in set (0.001 sec)

MariaDB [class_stuff]> select * from dept, course;
+--------+-------------+----------+-----------+-------------+-----------+---------+
| deptno | dname       | loc      | course_id | title       | dept_name | credits |
+--------+-------------+----------+-----------+-------------+-----------+---------+
|     10 | Purchase    | Pune     | Bio-301   | Genetics    | Biology   |       4 |
|     10 | Purchase    | Pune     | CS-190    | Game Design | Comp Sci  |       4 |
|     10 | Purchase    | Pune     | CS-315    | Robotics    | Comp Sci  |       3 |
|     20 | Sales       | Mumbai   | Bio-301   | Genetics    | Biology   |       4 |
|     20 | Sales       | Mumbai   | CS-190    | Game Design | Comp Sci  |       4 |
|     20 | Sales       | Mumbai   | CS-315    | Robotics    | Comp Sci  |       3 |
|     30 | Coffee      | vaishali | Bio-301   | Genetics    | Biology   |       4 |
|     30 | Coffee      | vaishali | CS-190    | Game Design | Comp Sci  |       4 |
|     30 | Coffee      | vaishali | CS-315    | Robotics    | Comp Sci  |       3 |
|     50 | Development | NULL     | Bio-301   | Genetics    | Biology   |       4 |
|     50 | Development | NULL     | CS-190    | Game Design | Comp Sci  |       4 |
|     50 | Development | NULL     | CS-315    | Robotics    | Comp Sci  |       3 |
+--------+-------------+----------+-----------+-------------+-----------+---------+
12 rows in set (0.001 sec)
