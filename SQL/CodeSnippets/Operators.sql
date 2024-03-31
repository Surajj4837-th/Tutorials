select * from employee where gender = 'M' AND age < 30;

select * from employee where gender = 'F' or age < 30;

select * from employee where not gender = 'M';

select * from employee where name LIKE '_up%';

select * from employee where age LIKE '2_';		-- employee with age in 20s.

select * from employee where age between 25 and 30;