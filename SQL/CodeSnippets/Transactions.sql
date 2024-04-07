select * from employee

begin transaction
update employee set age=30 where name='Suraj'
select * from employee

rollback transaction		-- restore transaction
select * from employee


begin transaction
update employee set age=30 where name='Suraj'
select * from employee

commit transaction			-- commit transaction
select * from employee


--transaction in try catch block
begin try
	begin transaction
		update employee set salary = 50 where gender='M'
		update employee set salary = 195/0 where gender='F'		--error command
		commit transaction
		print 'Transaction committed'
end try

begin catch
	rollback transaction
	print 'Error occurred. Transaction restored.'
end catch