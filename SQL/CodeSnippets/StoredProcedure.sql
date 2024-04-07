--procedure to get age column of the table
create procedure employee_age
as 
select age from employee
go

exec employee_age

-- procedure to get all details
create procedure employee_details
as
select * from employee
go


exec employee_details


-- Stored procedure with params
create procedure employee_gender
@gender varchar(20)
as
select * from employee
where gender=@gender
go

exec employee_gender @gender='M'
exec employee_gender @gender='F'