-- # Write your MySQL query statement below
-- with cte as(
-- select employee_id,manager_id from Employees
-- where salary < 30000
-- )
-- -- select employee_id from cte
-- -- where manager_id  not in (
-- --     select employee_id from employees
-- -- )
-- -- order by employee_id

-- select employee_id from
-- employees a where salary >30000
-- AND manager_id IS NOT NULL
-- and not exists(
--     select 1 from employees b
--     where  b.manager_id = a.employee_id
-- )
-- order by employee_id;

SELECT employee_id
FROM Employees a
WHERE salary < 30000 
      AND manager_id IS NOT NULL
      AND manager_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY employee_id;
