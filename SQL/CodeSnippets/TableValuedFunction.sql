use happy;
select * from employee;

create function select_gender(@gender as varchar)
Returns table
as 
return (select * from employee where gender=@gender)

select * from dbo.select_gender('M')	--select * from keywords are used since the function returns a table
select * from dbo.select_gender ('F')