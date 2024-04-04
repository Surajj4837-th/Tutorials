use happy;

create table list1 (
id int,
name varchar(20),
marks int
);

insert into list1 values(1, 'Suraj', 89);
insert into list1 values(2, 'Ashish', 96);
insert into list1 values(3, 'Rupali', 91);
insert into list1 values(4, 'Mahesh', 81);

select * from list1;

create table list2 (
id int,
name varchar(20),
marks int
);

insert into list2 values(5, 'Suresh', 89);
insert into list2 values(6, 'Kapil', 96);
insert into list2 values(7, 'Sonali', 91);
insert into list2 values(8, 'Abhishek', 81);

select * from list2;


select * from list1
union
select * from list2;