--Exception handeling

declare @val1 int;
declare @val2 int;

begin try
set @val1=8;
set @val2=@val1/0;
end try

begin catch
print error_message()
end catch


--user defined messages
use happy;

begin try
select name + salary from employee
end try
begin catch
print 'Cannot add a numerical value to a string value'
end catch
go
