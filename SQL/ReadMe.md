# C# Tutorial

Source: [SQL Course | SQL Training | SQL Tutorial For Beginners | Intellipaat](https://www.youtube.com/watch?v=LGTbdjoEBVM)


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
    4. Primary key: Combination of unique and null constraint. All columns will have a unique value and not null. We specify a column as primary key when we want to access the records using the same. A table cannot have more than 1 primary key. A primary key can be declared later by using `alter` command.
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
    The WHERE clause is used to filter records. The WHERE clause is used to extract only those records that fulfill a specified condition.
13. Operators:  
    1. And
    2. Or
    3. Not
    4. Like: Extract records where a particular pattern is present. Like operator uses wild card charachters.
        1. % - represents zero, one or multiple charachters.
        2. _ - represents a single charachter.  
       Pattern should be inside single quotes. Example:
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
    ```SQL
    Update table_name set col1=val1, col2=val2 ... [where condition];
    ```
21. Delete: Delete the existing records.
    ```SQL
    Delete from table_name [where condition];
    ```
22. Truncate: Deletes all data inside table. The table structure i.e. the column names remains intact.
    ```SQL
    Truncate table table_name;
    ```
23. Inner join: These are the records which have matching values in 2 different tables Also known as simple join. Syntax:
    ```SQL
    SELECT column1, column2, ..., columnN
    FROM table1
    INNER JOIN table2
    ON [condition];
    ```
    In the end a new table is created where the selected columns are present mapped by the condition given.
24. Left join: Returns all records from the left table and the matched records from right table. Unmatched data is assigned NULL value.
25. Right join: Returns all records from the right table and the matched records from the left table. Unmatched data is assigned NULL value.
26. FULL join returns all the records from right and left table and NULL assigned to the records no meeting the condition.
27. Union operator: Used to combine the result-set of 2 or more SELECT statements. The number and order of column is important while using this operator. Syntax:
    ```SQL
    select columnList from table1
    union
    select columnList from table2;
    ```
28. Union all operator: It gives all the rows from both the tables including the duplicates. The number and order of column is important while using this operator. Syntax:
    ```SQL
    select columnList from table1
    union all
    select columnList from table2;
    ```
29. Except operator: Combines 2 select statements and returns the unique records from the left query which are not part of the right query. This is equal to Set(A) - Set(B) operation. The number and order of column is important while using this operator. Syntax:
    ```SQL
    select columnList from table1
    except
    select columnList from table2;
    ```
30. Intersect operator: Combines 2 select statements and returns records which are common in both the select statements. The number and order of column is important while using this operator. Syntax:
    ```SQL
    select columnList from table1
    intersect
    select columnList from table2;
    ```
31. Views: View is a virtual table based on the result of an SQL statement.
    ```SQL
    create view_name as
    select columnList from table1
    where [condition];
    ```
    In order to list the view use:
    ```SQL
    select * from view_name;*
    ```
    In order to deop a view use:
    ```SQL
    drop view view_name;*
    ```
32. Alter table: This is used to add, delete or modify **columns** in a table.
    Add a column:  
    ```SQL
    Alter table table_name
    Add column_name datatype;
    ```
    Drop a column:
    ```SQL
    Alter table table_name
    drop column column_name;
    ```
33. Merge: Combines insert, update and delete in single statement. It requires 2 tables: source and target. Source table contains all the changes which are to be applied to the target table. Syntax:
    ```SQL
    merge [target] as T
    using [source] as S
    on [join condition]
    when matched
    then [update statement]
    when not matched by taret
    then [insert statement]
    when not matched by source
    then [delete statement];
    ```
    When rows match by join condition then update the target table. When rows in source are not in target then insert them in target table. When rows present in target table but absent in source table then delete these rows.
34. User defined functions: There are 2 types of user defined functions: Scalar valued and table valued.
    1. Scalar valued function returns a scalar value.
    Syntax:
        ```SQL
        CREATE FUNCTION fun_name(@param1 data_type, @param2 data_type, ...)
        RETURNS return_data_type
        AS
        BEGIN
            -- function body
        RETURN value
        END
        ```
    2. Table valued function return a table instead of a scale.
    Syntax:
        ```SQL
        CREATE FUNCTION fun_name(@param1 data_type, @param2 data_type, ...)
        RETURNS table
        AS
        BEGIN
            -- function body
        RETURN (SELECT column_list FROM table_name WHERE[condition])
        END
        ```
35. Temporary tables: These are created in tempDB and deleted as soon as the session is terminated. These are useful whenever temporary data is generated. Syntax:
    ```SQL
    CREATE TABLE #table_name(
    );
    ```
36. Case statement: Helps in multi way decision making. Syntax:
    ```SQL
    CASE
        When condition1 THEN Operation1
        When condition2 THEN Operation2
        When conditionN THEN OperationN
        ELSE oeprationM
    END;
    ```
37. IIF() function: Alternative of case statement. Syntax:
    ```SQL
    IIF(boolean_expression, true_value, false_value)
    ```
38. Stored procedure: It is a prepared SQL code which can be saved and reused.   
    Stored procedure without parameter syntax:
    ```SQL
    CREATE PROCEDURE procedure_name
    AS
    sql_statement
    GO
    ```
    While executing the stored procedure:
    ```SQL
    EXEC procedure_name
    ```
    Stored prcedure with parameter syntax:
    ```SQL
    CREATE PROCEDURE procedure_name
    @param1 data_type, param2 data_type
    AS
    sql_statement
    GO
    ```
40. Exception handeling: Error condition during a program execution is called as an exception and the mechanism for resolving such an exception is called exception handling. SQL provides try and catch block for exception handling. Syntax:
    ```SQL
    BEGIN TRY
    SQL statements
    END TRY
    
    BEGIN CATCH
    print error
    SQL statements
    END CATCH
    ```
41. Transactions: It is a group of commands that change data stored in a database. Transaction is treated as a single unit if any of the command in the transaction fails then all the commands will fail and any modified data in the database is rolled back. Similarly if all the commands in the database are successful then the data is committed. The data from the transaction can be rolled back by using `rollback transaction` command. The final change in the database will be done once `commit transaction` command is given. After this the change is permanent.
42. DB Administrator (DBA): DBA performs all activities related to maintaininga successful database environment. Types of DBA:
    1. Production DBA
    2. Application DBA
    3. Development DBA
    4. UAT DBA
    5. Data warehouse DBA
43. MS SQL Server: It is RDBMS from Microsoft.
44. Server instance: It is a collection of SQL server databases run by a single SQL server service. There is option of default and named instance while server installation. If you plan to install a single instance of SQL server on a DB server then go with a default instance. Use a named instance for situations where you plan to have multiple instances on the same server. A computer can host only 1 default instance and all other instances must be named.
45. Backup and restore: One of the important tasks of a DBA is to backup and restore the DB to ake sure there is no data loss. The system DBs that you must always back up include msdb, master and model.
46. Recovery model: A recovery model is a database property that controls how transactions are logged, whether the transaction log requires backing up and what kinds of restore operations are available. There are 3 models:
    1. Simple: 
        1. Maintains only a minimum amount of information in the SQL server transaction log file.
        2. SQL server on its own truncates the transaction log files and removes the information related to the transactions which have reached transaction checkpoints so that the space can be reused, leaving no transaction log entries fordisaster recovery purpose.
        3. The data is recoverable only to the most full database or differential back ups.
        4. Here, the transcation log truncation happens after a checkpoint or as soon as you can change the recovery model of your database to simple recovery model.
        5. It requires very less administration. Data loss is also higher if a data file is damaged.
        6. Recovery command:
            ```SQL
            USE [master]
            Go
            Alter Database [db_name]
            Set Recovery Simple With No_Wait
            Go
            ```
    2. Full:
        1. It logs every transaction and maintains it there until a transaction log backup is taken.
        2. With this recovery model you can devise a disaster recovery plan that includes a combination of full backup and transaction log and backups. To control the size of the transaction log, you need to take a transaction log backup so that it gets truncated.
        3. No work is lost due to damaged data files.
        4. Recovery command:
            ```SQL
            USE [master]
            Go
            Alter Database [db_name]
            Set Recovery Full With No_Wait
            Go
            ```
    3. Bulk logged:
        1. It is similar to full recovery model with the difference of handeling bulk data modification operations. The bulk log model records the transactions using minimal logging so that this saves processing time.
        2. There is no point in time recovery option like full recovery model.
        3. Recovery command:
            ```SQL
            USE [master]
            Go
            Alter Database [db_name]
            Set Recovery Bulk_Logged With No_Wait
            Go
            ```
47. Planning a backup strategy: After you have selected a recovery model that suits your business requirements for a specific database, you have to plan and implement a corresponding backup strategy. Questions to keep in mind:
    1. How many hours a day do applications have to access the database?
    2. How frequently are the changes and updates likely to occur?
    3. Are the changes likely to occur in only a small part of the database or in a large part?
48. Types of back up models:
    1. Full backup: Back ups the complete database.
    2. Partial backup.
    3. Differential backup: It is a backup that copies all the data that has changed since the last full back up.The full backup upon which a differential backup is based is called as base of the differential.
    4. Copy-only backup: It is an independent backup and it does not break the chain of database backups. In other words, it does not disturb the original backup workflow, but just creates a copy of the original database independently.
    5. File and filegroup backup: When database size and performance requirements make a full database backup impractical, you can create a file backup instead. A file backup contains al the data in one or more files or filegroups.
    6. Mirror backup: Identical copies of the same backup. Admins store them on multiple backup devices thus increasing the reliability of the backups and reducing the probability of data loss.
    7. Transaction log backup: Allows you to backup the active part of the transaction log. So after you issue a "Full" or "Differential" backup, the transaction log backup will have any transactions that were created after those other backups are completed.
49. Point in time recovery: It allows to recover a database into a state it was in any point in time. This type of recovery is applicable only to databases that run under the full or bulk logged recovery model.
50 Import and export data in SSMS.
51. Dynamic management views (DMVs): It returns server state information that can be used to monitor the health of a server instance, diagnose problems and tune performance. Properties:
    1. These are composed of both views and table valued functions. Some apply to the entire server and are stored in the master database, others are specific to each database.
    2. All dynamic management views and functions exist in the sys schema and follow this naming convention dm_*.
    Categories:
    1. Database related.
    2. SQL server OS related.
    3. Execution related.
52. SQL server activity monitor.
53. SQL server performance monitor.
54. SQL server profiler.
55. Data integrity: Used to maintain accuracy and consistency of data in a table.
56. Index: It is an on disk structure associated with a table or a view that speeds retrieval of rows from table or view.
57. Fragmentation.
58. CRUD operations in MySQL.
59. SQL injection (SQLi): It is a kind of attack in web based applications where the attacker can run malicious queries in the website's database. How to prevent SQLi:
    1. Principle of least privilege: Provide level of previleges to different users.
    2. Password hashing.
    3. Third party authentication: Login with Google, login with FB, etc.
    4. Hueristic ways.
60. SQL developer tasks:
    1. Data modeling
    2. Data management.
    3. Data backup and restore.
    4. Data migration.
61. SQL developer skills:
    1. SQL language.
    2. Programming language as interface between application and database.
    3. Profiling.
    4. Performance tuning.
62. SQL demo.
63. SQL vs MySQL.


## Notes from other sources
1. GO command: Used to create batches of statements instead of executing them together. Also used to run a SQL code multiple times.
1. Foreign key: It makes relational database "relational" by creating relationships between tables. It also helps to ensure all the data entering the database is consistent and valid. Foreign key of one table is used as primary key of another table. Foregn key can be added later by using `alter` command. Join commands can be used to combine multiple tables based on foreign key values.
1. Auto increment keyword: It allows a unique number to be generated automatically when a new record is inserted into a table. Often this is the primary key field that we would like to be created automatically every time a new record is inserted. THis keyword works in MySQL. Example
   ```SQL
   CREATE TABLE Persons (
   Personid int NOT NULL AUTO_INCREMENT,
   LastName varchar(255) NOT NULL,
   FirstName varchar(255),
   Age int,
   PRIMARY KEY (PersonId)
   );
   ```
   In case of MSSQL use `identity` keyword. Example:
   ```SQL
   CREATE TABLE Persons (
   Personid int NOT NULL IDENTITY,
   LastName varchar(255) NOT NULL,
   FirstName varchar(255),
   Age int,
   PRIMARY KEY (PersonId)
   );
   ```
1. Alter statement: Used to add, delete or modify columns of an existing table.