use happy;

create table list3 (
id int,
name varchar(20),
marks int
);

insert into list3 values(1, 'Suraj', 89);
insert into list3 values(2, 'Ashish', 96);
insert into list3 values(3, 'Rupali', 91);
insert into list3 values(4, 'Mahesh', 81);

select * from list3;


create table list4 (
id int,
name varchar(20),
marks int
);

insert into list4 values(1, 'Suraj', 89);
insert into list4 values(2, 'Ashish', 96);
insert into list4 values(3, 'Rupali', 91);
insert into list4 values(4, 'Mahesh', 81);

select * from list4;


select * from list3
union all
select * from list4;