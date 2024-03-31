select dept, avg(salary) as average_salary
from employee
group by dept;

select dept, avg(salary) as average_salary
from employee
group by dept
having avg(salary) > 100000;