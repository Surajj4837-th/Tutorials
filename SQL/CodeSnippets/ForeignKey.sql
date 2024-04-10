use happy;

CREATE TABLE customer(
ID int identity,
name varchar(20),
city varchar(20),

primary key(ID)
);


insert into customer values
('Suraj', 'Pune'),
('Ashish', 'Bengaluru'),
('Rupali', 'Kolhapur');

Select * from customer;

create table transactions(
transaction_id int identity(1000,1),
amount decimal(5,2),
customer_id int,

primary key(transaction_id),
foreign key(customer_id) references customer(ID)
);



insert into transactions values(5, 3);
insert into transactions values(3, 2);
insert into transactions values(3, 3);
insert into transactions values(5, 1);

Select * from transactions;
Select * from customer;
