use happy;

select * from employee;

alter table employee
Add JoiningDate date;

select * from employee;

alter table employee
drop column JoiningDate;

select * from employee;