MariaDB [dbms_lab]> select * from Room;
+--------+---------+-------+-------+
| RoomNo | HotelNo | Type  | Price |
+--------+---------+-------+-------+
|      1 |       1 | Suite |  1646 |
|      2 |       2 | Suite |  1264 |
|      3 |       1 | 2 Bed |   773 |
|      4 |       4 | 2 Bed |  1949 |
|      5 |       1 | 3 Bed |  1959 |
|      6 |       3 | 3 Bed |   674 |
|      7 |       1 | 1 Bed |  1018 |
|      8 |       3 | 1 Bed |  1314 |
|      9 |       1 | Suite |  1308 |
|     10 |       9 | 3 Bed |  1366 |
|     11 |      10 | 1 Bed |   666 |
|     12 |       7 | 2 Bed |  1498 |
|     13 |       7 | Suite |   984 |
+--------+---------+-------+-------+
13 rows in set (0.001 sec)

MariaDB [dbms_lab]> select * from Hotel;
+---------+------------------+-----------------------+
| HotelNo | Name             | City                  |
+---------+------------------+-----------------------+
|       1 | Hotel love       | Guernsey              |
|       2 | Hotel imagine    | Jordan                |
|       3 | Hotel rice       | Equatorial Guinea     |
|       4 | Hotel perhaps    | Bolivia               |
|       5 | Hotel show       | Reunion               |
|       6 | Hotel native     | Brunei                |
|       7 | Hotel pool       | Panama                |
|       8 | Hotel spin       | Guyana                |
|       9 | Hotel toward     | St. Barthélemy        |
|      10 | Hotel expression | St. Pierre & Miquelon |
|      11 | Hotel cheese     | Guinea-Bissau         |
|      12 | Hotel motion     | Latvia                |
|      13 | Hotel lay        | Fiji                  |
|      14 | Hotel stiff      | Brazil                |
|      15 | Hotel suddenly   | Lithuania             |
|      16 | Hotel stretch    | Montenegro            |
|      17 | Hotel current    | Isle of Man           |
|      18 | Hotel forest     | Haiti                 |
+---------+------------------+-----------------------+
18 rows in set (0.001 sec)

MariaDB [dbms_lab]> select * from booking;
+---------+---------+------------+------------+--------+
| HotelNo | GuestNo | DateFrom   | DateTo     | RoomNo |
+---------+---------+------------+------------+--------+
|       7 |      10 | 2096-04-21 | 2099-12-21 |     10 |
|       8 |       5 | 2077-09-29 | 2109-09-10 |     11 |
|      11 |       4 | 2123-01-05 | 2063-08-30 |      2 |
|      10 |       5 | 2027-02-05 | 2119-12-21 |      7 |
|       9 |       5 | 2081-07-11 | 2031-06-20 |     13 |
|       5 |       5 | 2059-11-19 | 2113-05-22 |     11 |
+---------+---------+------------+------------+--------+
6 rows in set (0.000 sec)

MariaDB [dbms_lab]> select * from Guest;
+---------+----------------+-----------------+
| GuestNo | GuestName      | GuessAddress    |
+---------+----------------+-----------------+
|       2 | Patrick Taylor | Lebanon         |
|       4 | Mattie Vargas  | St. Barthélemy  |
|       5 | Travis Frazier | Gambia          |
|      10 | Sarah Ramsey   | Jamaica         |
|      11 | Rachel Keller  | Kenya           |
|      15 | Nathan Higgins | Puerto Rico     |
|      16 | Maude Gonzales | St. Lucia       |
+---------+----------------+-----------------+
7 rows in set (0.000 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]>
MariaDB [dbms_lab]> -- 1. many hotels are there?
MariaDB [dbms_lab]> select count(*) from Hotel;
+----------+
| count(*) |
+----------+
|       18 |
+----------+
1 row in set (0.000 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]> -- 2. the price and type of all rooms at the Grosvenor Hotel.
MariaDB [dbms_lab]> select price, type, Name from Room, Hotel where Room.HotelNo = Hotel.HotelNo and Name = 'Hotel love';
+-------+-------+------------+
| price | type  | Name       |
+-------+-------+------------+
|  1646 | Suite | Hotel love |
|   773 | 2 Bed | Hotel love |
|  1959 | 3 Bed | Hotel love |
|  1018 | 1 Bed | Hotel love |
|  1308 | Suite | Hotel love |
+-------+-------+------------+
5 rows in set (0.001 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]> -- 3. the number of rooms in each hotel.
MariaDB [dbms_lab]> select Room.HotelNo, Hotel.NAME,  count(*) from Room, Hotel where Room.HotelNo = Hotel.HotelNo group by HotelNo;
+---------+------------------+----------+
| HotelNo | NAME             | count(*) |
+---------+------------------+----------+
|       1 | Hotel love       |        5 |
|       2 | Hotel imagine    |        1 |
|       3 | Hotel rice       |        2 |
|       4 | Hotel perhaps    |        1 |
|       7 | Hotel pool       |        2 |
|       9 | Hotel toward     |        1 |
|      10 | Hotel expression |        1 |
+---------+------------------+----------+
7 rows in set (0.000 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]> -- 4. Update the price of all rooms by 5%.
MariaDB [dbms_lab]> select r.Price, r.Price + r.Price * 0.05 as Updated_price from Room r;
+-------+---------------+
| Price | Updated_price |
+-------+---------------+
|  1646 |       1728.30 |
|  1264 |       1327.20 |
|   773 |        811.65 |
|  1949 |       2046.45 |
|  1959 |       2056.95 |
|   674 |        707.70 |
|  1018 |       1068.90 |
|  1314 |       1379.70 |
|  1308 |       1373.40 |
|  1366 |       1434.30 |
|   666 |        699.30 |
|  1498 |       1572.90 |
|   984 |       1033.20 |
+-------+---------------+
13 rows in set (0.000 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]> -- 5. full details of all hotels in London.
MariaDB [dbms_lab]>
MariaDB [dbms_lab]> select * from Hotel where City = 'Jordan';
+---------+---------------+--------+
| HotelNo | Name          | City   |
+---------+---------------+--------+
|       2 | Hotel imagine | Jordan |
+---------+---------------+--------+
1 row in set (0.000 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]> -- 6. What is the average price of a room?
MariaDB [dbms_lab]>
MariaDB [dbms_lab]> select avg(Price) from Room;
+------------+
| avg(Price) |
+------------+
|  1263.0000 |
+------------+
1 row in set (0.000 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]>
MariaDB [dbms_lab]> -- 7. all guests currently staying at the Grosvenor Hotel.
MariaDB [dbms_lab]>
MariaDB [dbms_lab]> select Guest.* from Guest, booking, Hotel where Guest.GuestNo = booking.GuestNo and booking.HotelNo = Hotel.HotelNo and Hotel.Name = 'Hotel pool';
+---------+--------------+--------------+
| GuestNo | GuestName    | GuessAddress |
+---------+--------------+--------------+
|      10 | Sarah Ramsey | Jamaica      |
+---------+--------------+--------------+
1 row in set (0.001 sec)

MariaDB [dbms_lab]>
MariaDB [dbms_lab]> -- 8. the number of rooms in each hotel in London.
MariaDB [dbms_lab]>
MariaDB [dbms_lab]> select count(*) from Room, Hotel where Room.HotelNo = Hotel.HotelNo and Hotel.City = 'Jordan';
+----------+
| count(*) |
+----------+
|        1 |
+----------+
1 row in set (0.000 sec)

MariaDB [dbms_lab]>


