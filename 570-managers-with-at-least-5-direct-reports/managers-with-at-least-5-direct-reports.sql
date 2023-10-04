
#    with cte as(
#     SELECT managerId
#     FROM Employee
#     GROUP BY managerId
#     HAVING COUNT(id) >= 5  #to filter aggregate function we use having clause
#    )
#  select e.name 
#    from Employee e join
#    cte on
#    e.Id = cte.managerId    
 #or #  select name from Employee where id in (select managerId from cte)
   
   # Write your MySQL query statement below
select name from Employee where id in (select managerId from Employee group by managerId having count(*)>=5)

# select name from Employee where id in(select managerId from Employee group by 
# managerId having count(*)>=5)

##checking whether that managerid is repeating or >5 timesor not 