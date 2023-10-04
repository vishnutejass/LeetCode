# Write your MySQL query statement below

# select p.project_id,
#  ROUND(AVG(e.experience_years),2)  as average_years
#  from Employee e
#  left join Project p on
#  p.employee_id=e.employee_id
#  group by p.project_id;

SELECT project_id, ROUND(SUM(e.experience_years)/COUNT(e.experience_years), 2) as average_years
FROM Project as p
inner JOIN Employee e ON p.employee_id = e.employee_id
GROUP BY project_id

