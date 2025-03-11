DECLARE 
	c NUMBER;
BEGIN
	c := totalcustomers();
	dbms_output.put_line('Total no. of Customers: ' || c);
END;
/*
Total no. of Customers: 2

PL/SQL procedure successfully completed.

*/
/
