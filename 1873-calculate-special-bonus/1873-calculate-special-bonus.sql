# Write your MySQL query statement below
select employee_id,
 case when employee_id%2 !=0 and left(name,1) <> 'M' then salary else 0 end as bonus
 from employees
 order by employee_id

# SELECT employee_id, 
#        IF( employee_id % 2 != 0 AND LEFT(name, 1) <> 'M', salary, 0) as bonus
# FROM Employees
# ORDER BY employee_id;

# SELECT employee_id, 
#        CASE WHEN employee_id % 2 != 0 AND LEFT(name, 1) <> 'M' THEN salary ELSE 0 END as bonus
# FROM Employees
# ORDER BY employee_id;
