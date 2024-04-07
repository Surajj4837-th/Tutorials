
use happy;
create function add_five(@num as int)
returns int
as
begin
return(@num+5)
end

select dbo.add_five(5)