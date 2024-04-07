select 
case 
when 10>20 then '10 greater than 20'
when 10<20 then '10 is less than 20'
else '10 is equal to 20'
end

use happy;
select * from employee

select * , grade=
case 
when salary<90000 then 'C'
when salary<120000 then 'B'
else 'A'
end
from employee
go