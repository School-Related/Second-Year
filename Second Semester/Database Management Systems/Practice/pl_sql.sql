-- Active: 1678946907415@@127.0.0.1@3306@learning_dbms

-- Path: Practice/pl_sql.sql

-- create a basic TABLE that would be useful in learning PLSQL

use learning_dbms;

drop table if exists plsql_table;

create table plsql_table (
    id int not null auto_increment,
    name varchar(255) not null,
    age int not null,
    primary key (id)
);

-- insert some data into the table

insert into plsql_table (name, age) values ('John', 25);
insert into plsql_table (name, age) values ('Jane', 30);
insert into plsql_table (name, age) values ('Jack', 35);
insert into plsql_table (name, age) values ('Jill', 40);
insert into plsql_table (name, age) values ('James', 45);
insert into plsql_table (name, age) values ('Jenny', 50);
insert into plsql_table (name, age) values ('Jared', 55);
insert into plsql_table (name, age) values ('Jasmine', 60);
insert into plsql_table (name, age) values ('Jasper', 65);
insert into plsql_table (name, age) values ('Jade', 70);

-- select all the data from the table

select * from plsql_table;

-- write a simple pl sql function to find the max age of the employee

delimiter //
create function get_max_age()
returns integer DETERMINISTIC

BEGIN
    declare max_age integer;
    select max(age) into max_age from plsql_table;
    return max_age;
END//

DELIMITER //
create function checklegal(age integer)
returns boolean DETERMINISTIC

BEGIN
    declare legal boolean;
    if age >= 18 then
        set legal = true
    else
        set legal = false
    end if
    return legal
END//

delimiter ;

-- call the function

select get_max_age();
DELIMITER ##

-- create a procecure to insert data into the table

create procedure selectall()
begin
    select * from plsql_table;
end##

DELIMITER ;
call selectall();

-- create a procedure with a CURSOR

DELIMITER ##
create procedure selectall2()
begin
declare done int default 0;
declare v_id int;
declare v_name varchar(255);
declare v_age int;
declare c1 cursor for select * from plsql_table;
declare continue handler for not found set done = 1;

    open c1;
    loop
        fetch c1 into v_id, v_name, v_age;
        if done = 0 then
            select v_id, v_name, v_age;
        end if;
        else
            leave;
    end loop;
    close c1;
end##

DELIMITER ;
drop procedure selectall2;

call selectall2();