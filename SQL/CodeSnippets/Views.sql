use happy;

select * from employee;

create view female_employee as
select * from employee where gender='F';

select * from female_employee;

drop view female_employee;