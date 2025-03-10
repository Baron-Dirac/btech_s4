exam231/exam231@172.16.50.33/FISAT
-- CREATE TABLE zsert (name varchar(20));
-- SELECT * FROM TAB;
--
-- SETTING UP AUTOCOMMIT
SET AUTOCOMMIT ON;
--
--SETTING UP ENVIRONMENT
-- CREATE TABLE Employee
-- CREATE TABLE Department
INSERT INTO Employee VALUES ('&eno', '&ename', '&salary', '&dno', '&mgrno', '&doj', '&desg', '&address', '&city', '&pincode');
e3
jeevan
2000
1
1
11-aug-08
employee
pune
delhi
986  
--
SET LINESIZE 100;
--
SET LINESIZE 200;
SELECT * FROM Employee;
SELECT * FROM Department;
--
SELECT ename, dname FROM Employee, Department;
SELECT * FROM Employee, Department;
--
SELECT COUNT(Salary) FROM Employee;
SELECT COUNT(*) FROM Employee;
SELECT SUM(Salary) FROM Employee GROUP BY dno;
SELECT SUM(Salary), dno FROM Employee GROUP BY dno;
SELECT dno, MIN(Salary) FROM Employee GROUP BY dno;
--
SELECT * FROM EMPLOYEE, DEPARTMENT WHERE EMPLOYEE.DNO=DEPARTMENT.DNO;
--
SELECT eno AS EMP_NAME, dname AS DEPT_NAME, EMPLOYEE.DNO FROM EMPLOYEE, DEPARTMENT WHERE EMPLOYEE.DNO=DEPARTMENT.DNO AND DEPARTMENT.DNAME='CSE'; --SPECIFICITY
--
SELECT E.ENO AS EMPLOYEE_NUMBER, E.ENAME AS EMPLOYEE_NAME, D.DNO AS DEPARTMENT_NUMBER FROM EMPLOYEE E, DEPARTMENT D WHERE E.DNO=D.DNO;
--
SELECT * FROM EMPLOYEE ORDER BY SALARY;
SELECT * FROM EMPLOYEE ORDER BY SALARY ASC;
SELECT * FROM EMPLOYEE ORDER BY SALARY DESC;
--
SELECT * FROM EMPLOYEE WHERE DNO=2 AND SALARY>1000;
/*
ENO	   ENAME	  SALARY DNO	    MGRNO DOJ	    DESG       ADDRESS	  CITY		PINCODE
---------- ---------- ---------- ----- ---------- --------- ---------- ---------- ---------- ----------
e2	   imaad	    2000 2		1 11-AUG-08 employee   pune	  delhi 	    986
e1	   elwin	   10000 2	      123 25-JAN-25 student    kunnath	  cochin	   3456

*/
SELECT * FROM EMPLOYEE WHERE SALARY BETWEEN 1000 AND 15000;
/* 
ENO	   ENAME	  SALARY DNO	    MGRNO DOJ	    DESG       ADDRESS	  CITY		PINCODE
---------- ---------- ---------- ----- ---------- --------- ---------- ---------- ---------- ----------
e2	   imaad	    2000 2		1 11-AUG-08 employee   pune	  delhi 	    986
e3	   jeevan	    2000 1		1 11-AUG-08 employee   pune	  delhi 	    986
e1	   elwin	   10000 2	      123 25-JAN-25 student    kunnath	  cochin	   3456
*/
SELECT SALARY,SALARY*12 ANNUAL_SALARY FROM EMPLOYEE;
/*    
SALARY ANNUAL_SALARY
---------- -------------
      2000	   24000
      2000	   24000
     10000	  120000 
*/
SELECT ENAME,SALARY*12 FROM EMPLOYEE;
/* 
ENAME	    SALARY*12
---------- ----------
imaad		24000
jeevan		24000
elwin	       120000 
*/
SELECT ENAME || ' EARN ' || SALARY FROM EMPLOYEE;
/*
ENAME||'EARN'||SALARY
--------------------------------------------------------
imaad EARN 2000
jeevan EARN 2000
elwin  EARN 10000
*/
--UPDATE EMPLOYEE SET SALARY=SALARY+(SALARY*0.1);
--DELETE FROM EMPLOYEE WHERE ENO='e1';
/*
3 rows updated
*/
--
ALTER TABLE EMPLOYEE MODIFY MGRNO NUMBER(15); 
DESC EMPLOYEE; --USE UPDATE INSTEAD
--
INSERT INTO Employee VALUES ('&eno', '&ename', '&salary', '&dno', '&mgrno', '&doj', '&desg', '&address', '&city', '&pincode');
e4
Goutham
3500
2

11-sep-08
employee
pune
delhi
983
--
INSERT INTO Employee VALUES ('&eno', '&ename', '&salary', '&dno', &mgrno, '&doj', '&desg', '&address', '&city', '&pincode');
e5
Jaico
2500
3
NULL
18-sep-08
employee
pune
delhi
953 
--
-- VIEW SETUP ENVIRONMENT
DESC EMPLOYEE;
DESC DEPARTMENT;
SELECT * FROM EMPLOYEE;
SELECT * FROM DEPARTMENT;
--TODAY
SELECT * FROM EMPLOYEE WHERE MGRNO IS NOT NULL;
--
SELECT * FROM EMPLOYEE WHERE MGRNO IS NULL;
--
--SELECT * FROM EMPLOYEE WHERE MGRNO=NULL; -- DOES NOT WORK DEMO
--
SELECT * FROM EMPLOYEE, DEPARTMENT WHERE EMPLOYEE.DNO=DEPARTMENT.DNO;
--
SELECT ENAME,DNAME,DEPARTMENT.DNO FROM EMPLOYEE,DEPARTMENT WHERE EMPLOYEE.DNO=DEPARTMENT.DNO;
--
SELECT ENAME,DNAME,DEPARTMENT.DNO FROM EMPLOYEE 

 DEPARTMENT ON EMPLOYEE.DNO=DEPARTMENT.DNO;
--
SELECT E.ENO,E.ENAME,D.DNAME FROM EMPLOYEE E JOIN DEPARTMENT D ON E.DNO=D.DNO;
--
COUNT 
SELECT COUNT (MGRNO) FROM EMPLOYEE;
/*
COUNT(MGRNO)
------------
	   3
*/
SELECT COUNT (*) FROM EMPLOYEE;
/*
  COUNT(*)
----------
	 5
*/
SELECT COUNT (ENO) FROM EMPLOYEE;
/*
COUNT(ENO)
----------
	 5
*/
SELECT COUNT (SALARY), MAX (SALARY), MIN (SALARY) FROM EMPLOYEE;
/*
COUNT(SALARY) MAX(SALARY) MIN(SALARY)
------------- ----------- -----------
	    5	  3349580      182315
*/
SELECT COUNT (*), MAX (SALARY), MIN (SALARY), DNO FROM EMPLOYEE GROUP BY DNO;
/*
  COUNT(*) MAX(SALARY) MIN(SALARY) DNO
---------- ----------- ----------- -----
	 3     3349580	    280676 2
	 1	670130	    670130 1
	 1	182315	    182315 3
*/
--ALTER TABLE EMPLOYEE MODIFY MGRNO VARCHAR2(10); 
DESC EMPLOYEE; --USE UPDATE INSTEAD
-- ERROR MGRNO AND ENO SHOULD HAVE BEEN SAME
--SELECT E.ENO,E.ENAME,D.DNAME FROM EMPLOYEE E JOIN DEPARTMENT D ON E.MGRNO=E.ENO;

SELECT DNAME,COUNT(*),MAX(SALARY),MIN(SALARY) FROM EMPLOYEE,DEPARTMENT WHERE DEPARTMENT.DNO=EMPLOYEE.DNO GROUP BY DNAME;
/*
DNAME	     COUNT(*) MAX(SALARY) MIN(SALARY)
---------- ---------- ----------- -----------
MECH		    1	   182315      182315
CSE		    3	  3349580      280676
Jiz Kayala	    1	   670130      670130

*/
--
/*--FROM EMPLOYEE WHERE DNO=1 HAVING --INCOMPLETE*/
--
SELECT COUNT (*), MAX (SALARY), MIN (SALARY), DNO FROM EMPLOYEE GROUP BY DNO HAVING DNO=1; -- HAVING IS USED IN CONJUCTION WITH GROUP BY
/*
  COUNT(*) MAX(SALARY) MIN(SALARY) DNO
---------- ----------- ----------- -----
	 1	670130	    670130 1
*/ 
--SELECT COUNT (*), MAX (SALARY), MIN (SALARY), DNO FROM EMPLOYEE GROUP BY DNO;
/*
  COUNT(*) MAX(SALARY) MIN(SALARY) DNO
---------- ----------- ----------- -----
	 3     3349580	    280676 2
	 1	670130	    670130 1
	 1	182315	    182315 3

*/
--
--SELECT DNO, COUNT (*), MAX (SALARY), MIN (SALARY) FROM EMPLOYEE GROUP BY DNO HAVING MAX(SALARY) > 10000; --AGGREGATE FUNCTION
/*
DNO	COUNT(*) MAX(SALARY) MIN(SALARY)
----- ---------- ----------- -----------
2	       3     6527384	  546959
1	       1     1305894	 1305894
3	       1      355281	  355281
*/
SELECT * FROM EMPLOYEE ORDER BY ENO; --ASC BY DEFAULT
/*
ENO	   ENAME	  SALARY DNO	    MGRNO DOJ	    DESG       ADDRESS	  CITY		PINCODE
---------- ---------- ---------- ----- ---------- --------- ---------- ---------- ---------- ----------
e1	   elwin	11563658 2	      123 25-JAN-25 student    kunnath	  cochin	   3456
e2	   imaad	 2313469 2		1 11-AUG-08 employee   pune	  delhi 	    986
e3	   jeevan	 2313469 1		1 11-AUG-08 employee   pune	  delhi 	    986
e4	   Goutham	  968971 2		  11-SEP-08 employee   pune	  delhi 	    983
e5	   Jaico	  629402 3		  18-SEP-08 employee   pune	  delhi 	    953
*/
SELECT * FROM EMPLOYEE ORDER BY ENO DESC;
/*
ENO	   ENAME	  SALARY DNO	    MGRNO DOJ	    DESG       ADDRESS	  CITY		PINCODE
---------- ---------- ---------- ----- ---------- --------- ---------- ---------- ---------- ----------
e5	   Jaico	  692342 3		  18-SEP-08 employee   pune	  delhi 	    953
e4	   Goutham	 1065868 2		  11-SEP-08 employee   pune	  delhi 	    983
e3	   jeevan	 2544816 1		1 11-AUG-08 employee   pune	  delhi 	    986
e2	   imaad	 2544816 2		1 11-AUG-08 employee   pune	  delhi 	    986
e1	   elwin	12720024 2	      123 25-JAN-25 student    kunnath	  cochin	   3456
*/
SELECT * FROM EMPLOYEE ORDER BY DNO DESC,ENO ASC;
/*
ENO	   ENAME	  SALARY DNO	    MGRNO DOJ	    DESG       ADDRESS	  CITY		PINCODE
---------- ---------- ---------- ----- ---------- --------- ---------- ---------- ---------- ----------
e5	   Jaico	 1349179 3		  18-SEP-08 employee   pune	  delhi 	    953
e1	   elwin	24787729 2	      123 25-JAN-25 student    kunnath	  cochin	   3456
e2	   imaad	 4959128 2		1 11-AUG-08 employee   pune	  delhi 	    986
e4	   Goutham	 2077076 2		  11-SEP-08 employee   pune	  delhi 	    983
e3	   jeevan	 4959128 1		1 11-AUG-08 employee   pune	  delhi 	    986
*/
SELECT * FROM EMPLOYEE JOIN DEPARTMENT ON EMPLOYEE.DNO=DEPARTMENT.DNO;
/*
ENO	   ENAME	  SALARY DNO	    MGRNO DOJ	    DESG       ADDRESS	  CITY		PINCODE DNO   DNAME	 EMP_COUNT  DEPT_HOD
---------- ---------- ---------- ----- ---------- --------- ---------- ---------- ---------- ---------- ----- ---------- ---------- ----------
e3	   jeevan	 5455041 1		1 11-AUG-08 employee   pune	  delhi 	    986 1     Jiz Kayala	    Hisham
e2	   imaad	 5455041 2		1 11-AUG-08 employee   pune	  delhi 	    986 2     CSE		    P Mathai
e4	   Goutham	 2284784 2		  11-SEP-08 employee   pune	  delhi 	    983 2     CSE		    P Mathai
e1	   elwin	27266502 2	      123 25-JAN-25 student    kunnath	  cochin	   3456 2     CSE		    P Mathai
e5	   Jaico	 1484097 3		  18-SEP-08 employee   pune	  delhi 	    953 3     MECH		    Poulos
*/
SELECT * FROM EMPLOYEE JOIN DEPARTMENT; --NATURAL JOIN
/*
ENO	   ENAME	  SALARY DNO	    MGRNO DOJ	    DESG       ADDRESS	  CITY		PINCODE DNO   DNAME	 EMP_COUNT  DEPT_HOD
---------- ---------- ---------- ----- ---------- --------- ---------- ---------- ---------- ---------- ----- ---------- ---------- ----------
e3	   jeevan	 6000545 1		1 11-AUG-08 employee   pune	  delhi 	    986 1     Jiz Kayala	    Hisham
e2	   imaad	 6000545 2	~/Documents/42323/btech_s4/DBMS	1 11-AUG-08 employee   pune	  delhi 	    986 2     CSE		    P Mathai
e4	   Goutham	 2513262 2		  11-SEP-08 employee   pune	  delhi 	    983 2     CSE		    P Mathai
e1	   elwin	29993152 2	      123 25-JAN-25 student    kunnath	  cochin	   3456 2     CSE		    P Mathai
e5	   Jaico	 1632507 3		  18-SEP-08 employee   pune	  delhi 	    953 3     MECH		    Poulos
*/
--ALTER TABLE EMPLOYEE RENAME COLUMN TO NEW_NAME_COLUMN;
SELECT * FROM EMPLOYEE LEFT OUTER JOIN DEPARTMENT ON EMPLOYEE.DNO=DEPARTMENT.DNO;
COMMIT;
/*
ENO	   ENAME	  SALARY DNO	    MGRNO DOJ	    DESG       ADDRESS	  CITY		PINCODE DNO   DNAME	 EMP_COUNT  DEPT_HOD
---------- ---------- ---------- ----- ---------- --------- ---------- ---------- ---------- ---------- ----- ---------- ---------- ----------
e3	   jeevan	 9663939 1		1 11-AUG-08 employee   pune	  delhi 	    986 1     Jiz Kayala	    Hisham
e2	   imaad	 9663939 2		1 11-AUG-08 employee   pune	  delhi 	    986 2     CSE		    P Mathai
e4	   Goutham	 4047634 2		  11-SEP-08 employee   pune	  delhi 	    983 2     CSE		    P Mathai
e1	   elwin	48304271 2	      123 25-JAN-25 student    kunnath	  cochin	   3456 2     CSE~/Documents/42323/btech_s4/DBMS		    P Mathai
e5	   Jaico	 2629169 3		  18-SEP-08 employee   pune	  delhi 	    953 3     MECH		    Poulos
*/
SELECT * FROM EMPLOYEE LEFT OUTER JOIN DEPARTMENT ON EMPLOYEE.DNO=DEPARTMENT.DNO;
--
--
--
--05/03/25
CREATE TABLE Dependent(
	empid varchar(10) references employee(eno),
	ename varchar(10),
	gender varchar(6),
	dob date,
	relations varchar(10),
	PRIMARY KEY (empid,ename)
	);
--
CREATE TABLE Deploc(
	dno varchar(5) references department(dno),
	location varchar(10),
	PRIMARY KEY (dno,location)
	);
--ALTER TABLE Dependent MODIFY relations varchar(10); 
--

INSERT INTO Dependent VALUES(
	'&empid',
	'&ename',
	'&gender',
	'&date',
	'&relations'
	);
e2
alex
male
11-aug-20
son
INSERT INTO Dependent VALUES(
	'&empid',
	'&ename',
	'&gender',
	'&date',
	'&relations'
	);
e1
Elwina
female
17-sep-20
wife
SELECT * FROM Dependent;
/*
EMPID	   ENAME      GENDER DOB       RELATIONS
---------- ---------- ------ --------- ----------
e1	   Elwina     female 17-SEP-20 wife
e2	   alex       male   11-AUG-20 son
*/
SELECT ENAME,DNO,SALARY FROM Employee WHERE SALARY
--UPDATE EMPLOYEE SET MGRNO='e2' WHERE ENO='e4' ;
SELECT ENAME,DNO,SALARY FROM EMPLOYEE WHERE SALARY>ANY(SELECT SALARY FROM EMPLOYEE WHERE DNO='1');
/*
ENAME	   DNO	     SALARY
---------- ----- ----------
elwin	   2	  393210052
*/
--DELETE FROM DEPARTMENT WHERE DNO='1';



--10-MAR-25--
CREATE VIEW V1 AS SELECT ENO,ENAME,DNAME FROM EMPLOYEE,DEPARTMENT WHERE EMPLOYEE.DNO=DEPARTMENT.DNO;
/*
view created.
*/
SELECT * FROM V1;
/*
ENO	   ENAME      DNAME
---------- ---------- ----------
e3	   jeevan     Jiz Kayala
e2	   imaad      CSE
e4	   Goutham    CSE
e1	   elwin      CSE
e5	   Jaico      MECH
*/
SELECT * FROM TAB;
DESC V1;
--CREATE VIEW V9 AS SELECT DNO,COUNT(*),MAX(SALARY) FROM EMPLOYEE GROUP BY DNO; --DON'T WORK
CREATE VIEW V9 (DNO,COUNT_EMP,MAX_SALARY) AS SELECT DNO,COUNT(*),MAX(SALARY) FROM EMPLOYEE GROUP BY DNO;
/*
View created.
*/
SELECT * FROM V9;
/*
DNO    COUNT_EMP MAX_SALARY
----- ---------- ----------
2	       3  393210052
1	       1   78667119
3	       1   21402173
*/
--DROP VIEW V9;

@hello_world.sql

@create_procedure.sql

exec greetings;





COMMIT;
