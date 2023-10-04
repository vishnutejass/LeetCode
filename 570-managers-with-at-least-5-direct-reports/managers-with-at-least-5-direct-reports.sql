# Write your MySQL query statement below
# select name
# from Employee  e
# where id= 
# case when managerId is null then 0 else sum(managerId)/5 END
# group by id,name

   with cte as(
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(id) >= 5  #to filter aggregate function we use having clause
   )

  #  select name from Employee where id in (select managerId from cte)
   select e.name 
   from Employee e join
   cte on
   e.Id = cte.managerId
   