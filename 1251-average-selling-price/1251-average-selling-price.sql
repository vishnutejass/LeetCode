# Write your MySQL query statement below

with cte as (
    select 
    u.product_id,u.purchase_date,u.units,p.price 
    from UnitsSold u
    join Prices p on
    u.product_id = p.product_id
    and u.purchase_date between p.start_date and p.end_date
)

select 
product_id ,
ROUND(SUM(units*price)/ SUM(units),2) AS average_price

from cte
group by product_id;

