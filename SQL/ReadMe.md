# C# Tutorial

Source: [SQL Course | SQL Training | SQL Tutorial For Beginners | Intellipaat](https://www.youtube.com/watch?v=LGTbdjoEBVM)

## Lecture Sequence: 
1. 

## General Notes
1. SQL - Relational database (RDBMS), database that stores and provides access to data points that are related to one another.
1. In RDMS, each row in the table is a record with a unique ID called the key. Columns of the table hold data attributes.
1. Types of SQL:
    1. MySQL
    2. ORACLE
    3. Microsoft SQL
    4. SYBASE
1. Sample SQL query:
   > SELECT * FROM data1 WHERE Age < 20
   
   `*` means complete data  
   `data1` is DB name  
   `Age < 20` is a condition
1. SQL is a data definition language(DDL), a data control language(DCL) and a data manipulation language(DML).
1. SQL is a server client language.
1. SQL keywords are not case-sensitive, which means you can write them in uppercase, lowercase, or a combination of both. The convention of using uppercase for SQL keywords is more of a readability and stylistic choice.

## Basics
1. Table consists of rows and columns.
1. Fields: columns of a table.
1. Records: rows of a table.
1. Datatypes: 
    1. Numerics: bigint, int, smallint, tinyint, decimal(s,d).
    2. Charachter: char(s), carchar(s), text.
    3. Date-Time: date, time, Year.
5. Syntax to create database: CREATE DATABASE \<databasename>;
5. Syntax to delete existing database: DROP DATABASE \<databasename>;
5. Syntax to use an existing database: USE \<databasename>;
5. Contraints in SQL: Used to specify rules for data in table.  
    1. Not Null: Ensures a column cannot have a NULL value.
    2. Default: Sets a default value for a column when no value is specified.
    3. Unique: All the values in a column are different.
    4. Primary key: Combination of unique and null constraint. All columns will have a unique value and not null. We specify a column as primary key when we want to access the resords using the same. A table cannot have more than 1 primary key.
9. Syntax to create a table:  
    ```SQL
    CREATE TABLE table_name (
        column1 datatype,
        column2 datatype,
        column3 datatype,
        ....
    );
    ```
    Example:  
    ```SQL
    create table employee(
        ID int not null,
        name varchar (50),
        salaray int,
        age int,
        gender varchar(20),
        dept varchar(20),

        primary key(ID)
    );
    ```
9. Syntax to insert records in a table: 
   ```SQL 
   INSERT INTO table_name VALUES(.....);
   ```
   Example: 
   ```SQL
   insert into employee values (
        1, 'Suraj', 50000, 30, 'M', 'ADAS'
    );
   ```
10. Select statement: Select some values from table.

11. Select Distinct: Select distinct values from a column.

12. Where clause: Used to extract records which staisfy a condition.
    ```SQL 
    SELECT col1, col2, colN FROM table_name WHERE [condition]
    ```
    Example:  
    ```SQL
    Select ID, name from employee where gender='F'; 
    ```
13. Operators:  
    1. And
    2. Or
    3. Not
    4. Like: Extract records where a particular pattern is present. Like operator uses wild card charachters.
        1. % - represents zero, one or multiple charachters.
        2. _ - represents a single charachter.  
       Pattern should e inside single quotes.
       Example:
       ```SQL
       select * from employee where name LIKE '_up%';    -- employee name with any first charachter 2nd charachter as 'u', third charather as 'p' and anything followed after that.
       select * from employee where age LIKE '2_';       -- employee with age in 20s.
       ```
    5. Between: Extract values between a range, both the mentioned values are inclusive.
14. SQL functions:
    1. min()
    2. max()
    3. count()
    4. sum()
    5. avg()
15. String functions:
    1. LTRIM(): Remove blanks on the left side of the charachter expression.
    2. LOWER(): Convert all charachters to lower case.
    3. UPPER(): Convert all charachters to upper case.
    4. REVERSE(): Reverse the charachter string.
    5. SUBSTRING(): Provides a substring from a string.
16. Order by: Sort data, default ascending.
17. Top: Get top records from the list.
18. Group by: Used to get aggregate results with respect to a group. Sequence of instruction is important, group by clause follows the where clause and precedes the order by clause.
19. Having: Used in combination with group by to impose conditions on groups. Having clause must follow group by clause and must precede order by clause.
20. Update: Modify existing records.