use PhoneDirectory

SELECT * FROM [PhoneDirectory].[dbo].[Directory]
  
create table Directory (
ID int not null identity(1,1) primary key,
Name varchar (100),
Age int, 
Phone bigint,
Gender bit
);

create procedure 
sp_insertData
@Name nvarchar (50),
@Age int,
@Phone bigint,
@Gender bit
as
insert into Directory (Name, Age, Phone, Gender) values (@Name,@Age,@Phone,@Gender);

sp_insertData 'Suraj', 12, 12345, 0;

delete from Directory