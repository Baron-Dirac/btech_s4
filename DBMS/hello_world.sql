/*
To run script in sql prompt
SQL> @script3.sql
  6  /
*/

SET SERVEROUTPUT ON;

DECLARE 
	message varchar(20) := 'Hello, World!';
BEGIN 
	dbms_output.put_line(message);
END;

/*
Hello, World!

PL/SQL procedure successfully completed.
*/

/
