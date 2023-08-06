# Write your MySQL query statement below
# select name as Customers 
# from Customers c left join
# Orders o on c.id=o.customerId
# where o.customerId is null




select c.name as Customers 
from Customers c
where c.id  not in
(select c.id from Customers c
inner join Orders o
on c.id=o.customerId)
