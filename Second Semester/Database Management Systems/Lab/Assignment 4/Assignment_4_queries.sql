
-- View the Tables
select * from Room;
select * from Hotel;
select * from booking;
select * from Guest;


-- 1. many hotels are there?
select count(*) from Hotel;

-- 2. the price and type of all rooms at the Grosvenor Hotel.
select price, type, Name from Room, Hotel where Room.HotelNo = Hotel.HotelNo and Name = 'Hotel love';

-- 3. the number of rooms in each hotel.
select Room.HotelNo, Hotel.NAME,  count(*) from Room, Hotel where Room.HotelNo = Hotel.HotelNo group by HotelNo;

-- 4. Update the price of all rooms by 5%.
select r.Price, r.Price + r.Price * 0.05 as Updated_price from Room r;

-- 5. full details of all hotels in London.

select * from Hotel where City = 'Jordan';

-- 6. What is the average price of a room?

select avg(Price) from Room;


-- 7. all guests currently staying at the Grosvenor Hotel.

select Guest.* from Guest, booking, Hotel where Guest.GuestNo = booking.GuestNo and booking.HotelNo = Hotel.HotelNo and Hotel.Name = 'Hotel pool';

-- 8. the number of rooms in each hotel in London.

select count(*) from Room, Hotel where Room.HotelNo = Hotel.HotelNo and Hotel.City = 'Jordan';

-- 9. one view on above database and query it.

create view IF NOT EXISTS HotelView as select Hotel.













-- emp (eno,ename,Zip,hdate)
-- – parts(pno,pname,qty_on_hand, price)
-- – customer(cno,cname,street,Zip,phone)
-- – order(ono,cno,receivedate,shippeddate)
-- – odetails(ono,pno,qty)
-- – zipcode(Zip,city)
-- Solve the following queries
-- get pno,pname values of parts that are priced less than $20.00
-- get the ono & cname values of customer whose orders have not yet been shipped
-- get the cname values of customer who have placed order with emp living in ‘Pune’ or ‘mumbai’
-- get the cities in which customer or emp are located
-- get the totalquantity of part 1060 that has been ordered
-- get the total no of customer
-- Create one view