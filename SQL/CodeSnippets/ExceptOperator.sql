use happy;

create table list5 (
id int,
name varchar(20),
marks int
);

insert into list5 values(1, 'Sam', 89);
insert into list5 values(2, 'Bob', 96);
insert into list5 values(3, 'Anne', 91);
insert into list5 values(4, 'Julia', 81);

select * from list5;


create table list6 (
id int,
name varchar(20),
marks int
);

insert into list6 values(3, 'Anne', 91);
insert into list6 values(4, 'Julia', 81);
insert into list6 values(5, 'Matt', 91);

select * from list6;

select * from list5
except
select * from list6;
