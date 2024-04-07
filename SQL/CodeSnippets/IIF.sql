select
iif(10>20, '10 is greater then 20', '10 is lesser then 20')

use happy
select * from employee

select ID, name, age,
iif(age>30, 'Old', 'Young') as generation from employee