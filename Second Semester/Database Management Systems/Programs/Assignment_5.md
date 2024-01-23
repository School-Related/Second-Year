MariaDB [dbms_lab]> -- QUERIES
MariaDB [dbms_lab]>
MariaDB [dbms_lab]> -- 1. Display the Passenger email ,Flight_no,Source and Destination Airport Names for all flights
MariaDB [dbms_lab]> -- booked
MariaDB [dbms_lab]>
MariaDB [dbms_lab]> select b.email, b.flight_no, f.place_from, f.place_to from flight_booking as b inner join flights as f where b.flight_no = f.flight_no;
+----------------+-----------+------------+-----------+
| email          | flight_no | place_from | place_to  |
+----------------+-----------+------------+-----------+
| love@gmail.com |     12345 | Mumbai     | London    |
| joe@gmail.com  |     23456 | London     | Pune      |
| beck@gmail.com |     67890 | Pune       | Bangalore |
+----------------+-----------+------------+-----------+
3 rows in set (0.001 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]> -- 2.
MariaDB [dbms_lab]> --  Display the flight and passenger details for the flights booked having Departure Date between
MariaDB [dbms_lab]> -- 23-08-2021 and 25-08-2021
MariaDB [dbms_lab]>
MariaDB [dbms_lab]> select * from flights as f, passenger as p, flight_booking as b where b.email = p.email and b.flight_no = f.flight_no and departure_date between "2021-07-27" and "2021-07-28";
+-----------+------------+-----------+----------------+----------------+--------------+--------------+--------+----------------+------------+----------+----------------+-----------+----------+
| flight_no | place_from | place_to  | departure_date | departure_time | arrival_date | arrival_time | reg_no | email          | first_name | surname  | email          | flight_no | no_seats |
+-----------+------------+-----------+----------------+----------------+--------------+--------------+--------+----------------+------------+----------+----------------+-----------+----------+
|     67890 | Pune       | Bangalore | 2021-07-27     | 12:12:12       | 2021-07-27   | 16:59:56     |    221 | beck@gmail.com | Gwen       | Beck     | beck@gmail.com |     67890 |        6 |
|     23456 | London     | Pune      | 2021-07-27     | 12:12:12       | 2021-07-28   | 22:59:56     |    333 | joe@gmail.com  | Joe        | Goldberg | joe@gmail.com  |     23456 |        2 |
|     12345 | Mumbai     | London    | 2021-07-27     | 12:12:12       | 2021-07-28   | 23:59:56     |    111 | love@gmail.com | Love       | Quinn    | love@gmail.com |     12345 |        6 |
+-----------+------------+-----------+----------------+----------------+--------------+--------------+--------+----------------+------------+----------+----------------+-----------+----------+
3 rows in set (0.004 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]> -- 3.
MariaDB [dbms_lab]> --  Display the top 5 airplanes that participated in Flights from Mumbai to London based on the
MariaDB [dbms_lab]> -- airplane capacity
MariaDB [dbms_lab]>
MariaDB [dbms_lab]> select * from airplane as a, flights as f where a.reg_no = f.reg_no and f.place_from = "Mumbai" and f.place_to = "London" order by a.capacity desc limit 5;
+--------+----------+----------+---------------+-----------+------------+----------+----------------+----------------+--------------+--------------+--------+
| reg_no | model_no | capacity | name          | flight_no | place_from | place_to | departure_date | departure_time | arrival_date | arrival_time | reg_no |
+--------+----------+----------+---------------+-----------+------------+----------+----------------+----------------+--------------+--------------+--------+
|    111 |        7 |      180 | Qatar Airways |     12345 | Mumbai     | London   | 2021-07-27     | 12:12:12       | 2021-07-28   | 23:59:56     |    111 |
+--------+----------+----------+---------------+-----------+------------+----------+----------------+----------------+--------------+--------------+--------+
1 row in set (0.002 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]> -- 4.Display the passenger first names who have booked the no_of seats smaller than the average
MariaDB [dbms_lab]> -- number of seats booked by all passengers for the arrival airport:New Delhi
MariaDB [dbms_lab]>
MariaDB [dbms_lab]> select * from passenger as p, flight_booking as b, flights as f where p.email = b.email and f.flight_no = b.flight_no and f.place_to = "New Delhi" and b.no_seats < all(select avg(no_seats) from flight_booking);
Empty set (0.002 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]>
MariaDB [dbms_lab]> /*5.Display the surnames of passengers who have not booked a flight from Pune to Bangalore*/
MariaDB [dbms_lab]> select surname
    -> from passenger
    -> where email not in(
    ->         select email
    ->         from flight_booking
    ->         where flight_no in (
    ->                 select flight_no
    ->                 from flights
    ->                 where place_from = 'Pune'
    ->                     and place_to = 'Bangalore'
    ->             )
    ->     );
+----------+
| surname  |
+----------+
| Goldberg |
| Quinn    |
+----------+
2 rows in set (0.003 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]> /*6. Display the Passenger details only if they have booked flights on 21st July 2021. (Use Exists)*/
MariaDB [dbms_lab]> select *
    -> from passenger
    -> where exists (
    ->         select email
    ->         from flight_booking
    ->         where flight_no in(
    ->                 select flight_no
    ->                 from flights
    ->                 where departure_date = '2021-07-27'
    ->             )
    ->     );
+----------------+------------+----------+
| email          | first_name | surname  |
+----------------+------------+----------+
| beck@gmail.com | Gwen       | Beck     |
| joe@gmail.com  | Joe        | Goldberg |
| love@gmail.com | Love       | Quinn    |
+----------------+------------+----------+
3 rows in set (0.001 sec)

MariaDB [dbms_lab]> /*--7.Display the Flight-wise total time duration of flights if the duration is more than 8 hours (Hint : Date function,Aggregation,Grouping)*/
MariaDB [dbms_lab]>
MariaDB [dbms_lab]> select flight_no, timediff(f.arrival_time, f.departure_time ) from flights as f where timediff(f.arrival_time, f.departure_time ) > "8:00:00" group by flight_no;
+-----------+---------------------------------------------+
| flight_no | timediff(f.arrival_time, f.departure_time ) |
+-----------+---------------------------------------------+
|     12345 | 11:47:44                                    |
|     23456 | 10:47:44                                    |
+-----------+---------------------------------------------+
2 rows in set (0.001 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]> /*8.Display the Airplane-wise average seating capacity for any airline*/
MariaDB [dbms_lab]> select name,
    ->     avg(capacity)
    -> from airplane
    -> group by name;
+---------------+---------------+
| name          | avg(capacity) |
+---------------+---------------+
| Air India     |      175.0000 |
| Emirates      |      155.0000 |
| Qatar Airways |      183.0000 |
+---------------+---------------+
3 rows in set (0.001 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]> /*9.Display the total number of flights which are booked and travelling to London airport.*/
MariaDB [dbms_lab]> select count(b.flight_no) as total
    -> from flight_booking b,
    ->     flights f
    -> where f.place_to = 'London';
+-------+
| total |
+-------+
|     3 |
+-------+
1 row in set (0.000 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]> /*10. Create a view having information about flight_no,airplane_no,capacity.*/
MariaDB [dbms_lab]> create view flightinfo as
    -> select f.flight_no,
    ->     a.reg_no,
    ->     a.capacity
    -> from flights f,
    ->     airplane a
    -> where a.reg_no = f.reg_no;
ERROR 1050 (42S01): Table 'flightinfo' already exists
MariaDB [dbms_lab]>
MariaDB [dbms_lab]> select * from flightinfo;
+-----------+--------+----------+
| flight_no | reg_no | capacity |
+-----------+--------+----------+
|     12345 |    111 |      180 |
|     67890 |    221 |      150 |
|     23456 |    333 |      200 |
+-----------+--------+----------+
3 rows in set (0.001 sec)