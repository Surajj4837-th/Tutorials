use happy;

create table source_table(
ID int,
name varchar(30),
salary int,
age int,
gender varchar,
dept varchar(20)
);

insert into source_table values(1, 'Sam', 93000, 40, 'M', 'Operations');
insert into source_table values(2, 'Bob', 80000, 21, 'M', 'Support');
insert into source_table values(3, 'Anne', 130000, 25, 'F', 'Analytics');
insert into source_table values(6, 'Jeff', 112000, 27, 'M', 'Operations');
insert into source_table values(7, 'Adam', 100000, 28, 'M', 'Contech');
insert into source_table values(8, 'Priya', 85000, 37, 'F', 'Tech');

create table target_table(
ID int,
name varchar(30),
salary int,
age int,
gender varchar,
dept varchar(20)
);

insert into target_table values(1, 'Sam', 95000, 45, 'M', 'Operations');
insert into target_table values(2, 'Bob', 80000, 21, 'M', 'Support');
insert into target_table values(3, 'Anne', 125000, 25, 'F', 'Analytics');
insert into target_table values(4, 'Julia', 112000, 30, 'M', 'Analytics');
insert into target_table values(5, 'Matt', 159000, 33, 'M', 'Sales');
insert into target_table values(8, 'Jeff', 112000, 27, 'M', 'Operations');

select * from source_table;
select * from target_table;


merge target_table as T
using source_table as S
	on T.ID = S.ID
when matched
	then update set T.salary = S.salary, T.age = S.age
when not matched by target
	then insert (ID, name, salary, age, gender, dept)
	values (S.ID, S.name, S.salary, S.age, S.gender, S.dept)
when not matched by source
	then delete;


select * from target_table;
	
/*
Once merge command is given:
1. The items which are there in source and target tables with same ID then the salary and age values in target table are updated from source table.
2. The items which are present in source table but absent in target table then those values will be copied to the target table.
3. If there are some records which are there in the target table but absent in source table then we will simply delete them from target table.
*/