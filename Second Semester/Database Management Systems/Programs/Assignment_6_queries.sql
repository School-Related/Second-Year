-- Procedures and Functions

-- BATCH 2 EXERCISE 1 - PROCEDURES

-- product(prod_id, prod_name, qty_on_hand)
-- Order(cust_id, prod_id, order_date, qty_ordered)
-- Customer(cust_id, cust_name, phone, address)

-- Write a stored procedure to take the cust_id, prod_id and qty_ordered as
-- input. Procedure should check if the order for a particular customer can be
-- fulfilled and if yes then insert the new order and update the product
-- quantity on hand. Display appropriate message if the order cannot be
-- fulfilled. Output parameter must have updated value of the qty_on_hand

-- 1. Create database and tables

create database if not exists lab_procedures;
use lab_procedures;

CREATE TABLE `product` (
	`product_id` INT NOT NULL AUTO_INCREMENT,
	`prod_name` varchar(255) NOT NULL,
	`qty_on_hand` INT(255) NOT NULL,
	PRIMARY KEY (`product_id`)
);

CREATE TABLE `customer` (
	`cust_id` INT NOT NULL AUTO_INCREMENT,
	`cust_name` varchar(255) NOT NULL,
	`phone` VARCHAR(255) NOT NULL,
	`address` VARCHAR(255) NOT NULL,
	PRIMARY KEY (`cust_id`)
);

CREATE TABLE `order_details` (
	`cust_id` INT NOT NULL,
	`product_id` INT NOT NULL,
	`order_date` DATE NOT NULL,
	`qty_order` INT NOT NULL
);

INSERT INTO product (prod_name, qty_on_hand) VALUES 
    ('Product A', 50),
    ('Product B', 100),
    ('Product C', 75);

INSERT INTO customer (cust_name, phone, address) VALUES 
    ('John Smith', '123-456-7890', '123 Main St'),
    ('Jane Doe', '555-555-1212', '456 Oak Ave'),
    ('Bob Johnson', '555-123-4567', '789 Elm St');

INSERT INTO order_details values
    (1, 1, '2023-04-25', 10),
    (1, 2, '2023-04-26', 5),
    (2, 3, '2023-04-27', 8),
    (3, 1, '2023-04-26', 15),
    (3, 3, '2023-04-27', 3);
    

ALTER TABLE `order_details` ADD CONSTRAINT `order_fk0` FOREIGN KEY (`cust_id`) REFERENCES `customer`(`cust_id`);

ALTER TABLE `order_details` ADD CONSTRAINT `order_fk1` FOREIGN KEY (`product_id`) REFERENCES `product`(`product_id`);


-- Creating Procedure

DELIMITER $$
CREATE PROCEDURE Fulfill_Order_proc3 (
    IN p_cust_id INT,
    IN p_prod_id INT,
    IN p_qty_ordered INT,
    OUT p_qty_on_hand INT
)


BEGIN
    DECLARE v_qty_on_hand INT;

    -- Get the current quantity on hand for the product
    SELECT qty_on_hand INTO v_qty_on_hand
    FROM product
    WHERE product_id = p_prod_id;

    -- Check if the order can be fulfilled
    IF v_qty_on_hand >= p_qty_ordered THEN
        -- Insert the new order
        INSERT INTO order_details (cust_id, product_id, order_date, qty_order)
        VALUES (p_cust_id, p_prod_id, CURDATE(), qty_order);

        -- Update the quantity on hand for the product
        UPDATE product
        SET qty_on_hand = qty_on_hand - p_qty_ordered
        WHERE product_id = p_prod_id;

        -- Set the output parameter to the updated quantity on hand
        SELECT qty_on_hand INTO p_qty_on_hand
        FROM product
        WHERE product_id = p_prod_id;

        -- Display a success message
        SELECT CONCAT('Order fulfilled. New quantity on hand for product ', p_prod_id, ' is ', p_qty_on_hand) AS message;
    ELSE
        -- Display an error message
        SELECT CONCAT('Order cannot be fulfilled. Only ', v_qty_on_hand, ' units of product ', p_prod_id, ' are available.') AS message;
    END IF;
END$$
DELIMITER ;


-- Calling Procedure

-- Get the current quantity on hand for product 1
SELECT qty_on_hand FROM product WHERE product_id = 1;

-- Attempt to place an order for 20 units of product 1 for customer 1
CALL Fulfill_Order_proc3(1, 1, 20, @qty_on_hand);

-- Get the error message returned by the stored procedure
SELECT message FROM (SELECT @p_qty_on_hand AS message) AS result;

-- BATCH 2 EXERCISE 2 - FUNCTIONS

-- Write a function to find total quantity ordered by taking
-- cust_id and prod_id as input parameter
-- Also write a code to call the function

-- Creating Function

DELIMITER $$
CREATE FUNCTION Total_Qty_Ordered2(cust_id INT, prod_id INT)
RETURNS INT deterministic
BEGIN
    DECLARE total_qty INT;
    SELECT SUM(qty_order) INTO total_qty
    FROM order_details
    WHERE cust_id = cust_id AND prod_id = product_id;
    RETURN total_qty;
END $$

DELIMITER ;

-- Calling Function

SELECT Total_Qty_Ordered2(1, 1) AS total_qty;


