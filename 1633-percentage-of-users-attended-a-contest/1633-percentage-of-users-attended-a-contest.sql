# Write your MySQL query statement below

select contest_id,ROUND(count(distinct user_id)/
( select count(user_id) from Users )*100,2) AS percentage
from Register
group by contest_id
order by percentage desc, contest_id