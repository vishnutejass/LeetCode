# Write your MySQL query statement below
with cte as(
select e.*,d.name as Department
from Employee e
join Department d
on e.departmentId = d.id
)
select Department,Employee,Salary from(
select Department,name as Employee, salary as Salary ,dense_rank() over(partition by Department order by salary desc) as dr
from cte 
) as a
where dr <=3

