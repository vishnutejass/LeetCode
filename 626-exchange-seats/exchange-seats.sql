with cte as(
select *,lead(id) over(order by id) as next , lag(id) over(order by id) as prev
from seat
)
select case when ((id%2=1) and next is not null) then next
when (id%2=0) then prev
else id
end as id, student from cte
order by id asc;



















-- -- -- # Write your MySQL query statement below
-- -- -- with cte as (
-- -- -- SELECT (id-1) as id , student
-- -- -- FROM seat
-- -- -- WHERE id % 2 = 0
-- -- -- union
-- -- -- select(id+1) as id , student
-- -- -- from seat 
-- -- -- where id%2!=0
-- -- -- ),
-- -- -- cte2 as(
-- -- -- select * from seat
-- -- -- order by id desc
-- -- -- limit 1
-- -- -- ),

-- -- -- SELECT *
-- -- -- FROM cte

-- -- -- UNION

-- -- -- SELECT *
-- -- -- FROM cte2

-- -- -- ORDER BY id ASC
-- -- -- LIMIT (SELECT COUNT(*)  FROM seat);

-- -- Common Table Expression (CTE) to handle even and adjusted odd id rows
-- WITH cte AS (
--     SELECT (id - 1) AS id, student
--     FROM seat
--     WHERE id % 2 = 0  -- Select even id rows and adjust id by subtracting 1

--     UNION ALL

--     SELECT (id + 1) AS id, student
--     FROM seat
--     WHERE id % 2 != 0  -- Select odd id rows and adjust id by adding 1
-- ),

-- cte2 AS (
--     SELECT id, student
--     FROM seat
--     ORDER BY id DESC
--     LIMIT 1  -- Selects the last row based on id in descending order
-- )

-- SELECT id, student
-- FROM (
--     SELECT id, student
--     FROM cte

--     UNION ALL

--     SELECT id, student
--     FROM cte2
-- ) AS final_result
-- WHERE id <= (SELECT MAX(id) FROM seat)  -- Ensure id is less than or equal to max id in seat table
-- ORDER BY id ASC;  -- Orders the final result set by id in ascending order
