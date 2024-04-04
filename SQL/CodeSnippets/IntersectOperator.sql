use happy;

create table list7 (
id int,
name varchar(20),
marks int
);

insert into list7 values(1, 'Sam', 89);
insert into list7 values(2, 'Bob', 96);
insert into list7 values(3, 'Anne', 91);
insert into list7 values(4, 'Julia', 81);

select * from list7;


create table list8 (
id int,
name varchar(20),
marks int
);

insert into list8 values(3, 'Anne', 91);
insert into list8 values(4, 'Julia', 81);
insert into list8 values(5, 'Matt', 91);

select * from list8;

select * from list7
intersect
select * from list8;
