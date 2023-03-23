-- Active: 1678946907415@@127.0.0.1@3306@dbms_lab
use dbms_lab;

show tables;

create table airline(name varchar(50) primary key);

create table airplane(reg_no int primary key, model_no int, capacity int, name varchar(50), foreign key(name) references airline(name));
create table flights(flight_no int primary key, place_from varchar(50), place_to varchar(50), departure_date date, departure_time time, arrival_date date, arrival_time time, reg_no int, foreign key(reg_no) references airplane(reg_no));

create table passenger(email varchar(50) primary key, first_name varchar(50), surname varchar(50));
create table flight_booking(email varchar(50), flight_no int, no_seats int, foreign key(email) references passenger(email), foreign key(flight_no) references flights(flight_no), primary key(email, flight_no));

describe airplane;

insert into airline values("Qatar Airways");
insert into airline values("Emirates");
insert into airline values("Air India");

insert into airplane values(111,007,180,"Qatar Airways");	 
insert into airplane values(112,007,169,"Qatar Airways");	 
insert into airplane values(113,008,200,"Qatar Airways");	
insert into airplane values(221,017,150,"Emirates");	  
insert into airplane values(222,017,140,"Emirates");	
insert into airplane values(223,018,175,"Emirates");	  
insert into airplane values(333,027,200,"Air India");	 
insert into airplane values(334,027,150,"Air India");	 
insert into airplane values(335,028,175,"Air India");

select * from airplane;

describe flights;
insert into flights values(12345,"Mumbai","London","2021-07-27","12:12:12","2021-07-28","23:59:56",111);
insert into flights values(67890,"Pune","Bangalore","2021-07-27","12:12:12","2021-07-27","16:59:56",221);
insert into flights values(23456,"London","Pune","2021-07-27","12:12:12","2021-07-28","22:59:56",333);

select * from flights;

describe passenger;

insert into passenger values("love@gmail.com","Love","Quinn");
insert into passenger values("joe@gmail.com","Joe","Goldberg");
insert into passenger values("beck@gmail.com","Gwen","Beck");

describe flight_booking;

insert into flight_booking values("love@gmail.com",12345,6);
insert into flight_booking values("joe@gmail.com",23456,2);
insert into flight_booking values("beck@gmail.com",67890,6);

select * from flight_booking;
select * from flights;

-- QUERIES

-- 1. Display the Passenger email ,Flight_no,Source and Destination Airport Names for all flights
-- booked

select b.email, b.flight_no, f.place_from, f.place_to from flight_booking as b inner join flights as f where b.flight_no = f.flight_no;

-- 2.
--  Display the flight and passenger details for the flights booked having Departure Date between
-- 23-08-2021 and 25-08-2021

select * from flights as f, passenger as p, flight_booking as b where b.email = p.email and b.flight_no = f.flight_no and departure_date between "2021-07-27" and "2021-07-28";

-- 3.
--  Display the top 5 airplanes that participated in Flights from ‘Mumbai’ to ‘London’ based on the
-- airplane capacity

select * from airplane as a, flights as f where a.reg_no = f.reg_no and f.place_from = "Mumbai" and f.place_to = "London" order by a.capacity desc limit 5;

-- 4.Display the passenger first names who have booked the no_of seats smaller than the average
-- number of seats booked by all passengers for the arrival airport:”New Delhi”

select * from passenger as p, flight_booking as b, flights as f where p.email = b.email and f.flight_no = b.flight_no and f.place_to = "New Delhi" and b.no_seats < all(select avg(no_seats) from flight_booking);


/*5.Display the surnames of passengers who have not booked a flight from “Pune” to “Bangalore”*/
select surname
from passenger
where email not in(
        select email
        from flight_booking
        where flight_no in (
                select flight_no
                from flights
                where place_from = 'Pune'
                    and place_to = 'Bangalore'
            )
    );

/*6. Display the Passenger details only if they have booked flights on 21st July 2021. (Use Exists)*/
select *
from passenger
where exists (
        select email
        from flight_booking
        where flight_no in(
                select flight_no
                from flights
                where departure_date = '2021-07-27'
            )
    );
/*--7.Display the Flight-wise total time duration of flights if the duration is more than 8 hours (Hint : Date function,Aggregation,Grouping)*/

select flight_no, timediff(f.arrival_time, f.departure_time ) from flights as f where timediff(f.arrival_time, f.departure_time ) > "8:00:00" group by flight_no;

/*8.Display the Airplane-wise average seating capacity for any airline*/
select name,
    avg(capacity)
from airplane
group by name;

/*9.Display the total number of flights which are booked and travelling to “London” airport.*/
select count(b.flight_no) as total
from flight_booking b,
    flights f
where f.place_to = 'London';

/*10. Create a view having information about flight_no,airplane_no,capacity.*/
create view flightinfo as
select f.flight_no,
    a.reg_no,
    a.capacity
from flights f,
    airplane a
where a.reg_no = f.reg_no;

select * from flightinfo;



