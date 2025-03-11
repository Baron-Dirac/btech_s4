--@function.sql
--SET SERVEROUTPUT ON;
/*SET LINESIZE 200;
CREATE TABLE customers (
    id NUMBER PRIMARY KEY,                -- Customer ID (unique)
    name VARCHAR2(100) NOT NULL,          -- Customer's name
    email VARCHAR2(150) UNIQUE,           -- Customer's email (unique)
    phone_number VARCHAR2(15),            -- Customer's phone number
    created_at DATE DEFAULT SYSDATE,      -- Date when the customer was added
    updated_at DATE DEFAULT SYSDATE       -- Date when the customer details were last updated
);

INSERT INTO customers (id, name, email, phone_number) 
VALUES (1, 'John Doe', 'john.doe@example.com', '1234567890');

INSERT INTO customers (id, name, email, phone_number) 
VALUES (2, 'Jane Smith', 'jane.smith@example.com', '0987654321');
*/
CREATE OR REPLACE FUNCTION totalcustomers
RETURN NUMBER IS
    total NUMBER;  
BEGIN
    SELECT count(*) INTO total
    FROM customers;
    
    RETURN total;
END;

--SELECT totalcustomers() FROM dual;
/*
TOTALCUSTOMERS()
----------------
	       2
*/


-- SHOW ERRORS;
/


