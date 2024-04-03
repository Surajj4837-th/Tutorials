select * from employee;

create table Department (
Name varchar (20),
Location varchar(20)
);

insert into Department values('ADAS', 'India');
insert into Department values('Admin', 'South Korea');
insert into Department values('HR', 'USA');
insert into Department values('Analytics', 'England');
insert into Department values('Sales', 'Italy');
insert into Department values('Finance', 'South Korea');
insert into Department values('Support', 'India');
insert into Department values('Tech', 'India');

select * from Department;

select employee.name, employee.dept, Department.Name, Department.Location
FROM employee
INNER JOIN Department ON employee.dept=Department.Name;

select employee.name, employee.dept, Department.Name, Department.Location
FROM employee
LEFT JOIN Department 
ON employee.dept=Department.Name;

select employee.name, employee.dept, Department.Name, Department.Location
FROM employee
RIGHT JOIN Department 
ON employee.dept=Department.Name;

select employee.name, employee.dept, Department.Name, Department.Location
FROM employee
FULL JOIN Department 
ON employee.dept=Department.Name;



-- problem statement 1

create table dept_table(
name varchar(20),
location varchar (20)
);

create table emp_table(
name varchar(20),
salary int,
age int,
gender varchar(1),
dept varchar(20)
);

insert into dept_table values('Content', 'New York'); 
insert into dept_table values('Support', 'Chicago'); 
insert into dept_table values('Analytics', 'New York'); 
insert into dept_table values('Sales', 'Boston'); 
insert into dept_table values('Tech', 'Dallas'); 
insert into dept_table values('Finance', 'Chicago'); 

select * from dept_table;

insert into emp_table values('Sam', 95000, 45, 'M', 'Operations');
insert into emp_table values('Bob', 80000, 21, 'M', 'Support');
insert into emp_table values('Anne', 125000, 25, 'F', 'Analytics');
insert into emp_table values('Julia', 73000, 30, 'F', 'Analytics');
insert into emp_table values('Matt', 159000, 33, 'M', 'Sales');
insert into emp_table values('Jeff', 112000, 27, 'M', 'Operations');

select * from emp_table;

-- Upadate age of the New York based employees. Age = Age + 10

/*
Solution: Use of update and join clauses.
*/

update emp_table
set age = age + 10
from emp_table
join dept_table
on emp_table.dept = dept_table.name
where dept_table.location='New York';

select * from emp_table;


-- problem statement 2
-- Delete employee table records which are based in New York.

delete emp_table
from emp_table
join dept_table
on emp_table.dept = dept_table.name
where location='New York';

select * from emp_table;