select * from employee;

select avg(salary), gender from employee group by gender;	-- print average salary for each gender

select avg(age), dept from employee group by dept order by avg(age) desc;