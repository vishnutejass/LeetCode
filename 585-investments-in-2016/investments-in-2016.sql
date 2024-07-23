# Write your MySQL query statement below
with cte as(
select concat(lat,',',lon) as loc
from Insurance
group by lon,lat 
having count(pid) >1
), 
cte2 as(
    select DISTINCT i1.*
    from Insurance  i1
    left join Insurance  i2
    on i1.tiv_2015 = i2.tiv_2015
    where i1.pid <> i2.pid and
    concat(i1.lat,',',i1.lon) NOT IN (SELECT loc from cte) )

    select round(sum(tiv_2016),2) as tiv_2016 from cte2





