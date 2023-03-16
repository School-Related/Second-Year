
-- View the Tables
select * from Room;
select * from Hotel;
select * from booking;
select * from Guest;


-- 1. many hotels are there?
select count(*) from Hotel;

-- 2. the price and type of all rooms at the Grosvenor Hotel.
select price, type, Name from Room, Hotel where Room.HotelNo = Hotel.HotelNo and Name = 'Hotel love';
select count(RoomNo) from (select * from Room INNER JOIN Hotel where Hotel.HotelNo = Room.HotelNo);

select RoomNo, Hotel.HotelNo from Room INNER JOIN Hotel where Hotel.HotelNo = Room.HotelNo;

-- 3. the number of rooms in each hotel.

-- 4. the price of all rooms by 5%.

-- 5. full details of all hotels in London.

-- 6. is the average price of a room?

-- 7. all guests currently staying at the Grosvenor Hotel.

-- 8. the number of rooms in each hotel in London.

-- 9. one view on above database and query it.

