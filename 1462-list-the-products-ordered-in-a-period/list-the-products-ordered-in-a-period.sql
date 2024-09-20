# Write your MySQL query statement below
select product_name,sum(unit) as unit  from 
(
select p.product_name,o.unit,o.order_date,p.product_id
from Products p
right join Orders o
on p.product_id = o.product_id
where o.order_date >='2020-02-01' and o.order_date <='2020-02-29'
order by p.product_id
) as first

group by product_name
having sum(unit)>=100;