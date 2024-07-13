-- with cte as(
--     select mr.*,u.name,m.title
--     from MovieRating mr left join Users u
--     on mr.user_id = u.user_id
--     left join Movies m 
--     on m.movie_id = mr.movie_id
-- )

-- (select name  from cte
-- group by name
-- order by count(movie_id) desc , name
-- limit 1)

-- union 

-- (select title from cte
-- where date_format(created_at , '%y-%m') = '2020-02'
-- group by title
-- order by avg(rating) desc, title
-- limit 1)

WITH cte AS (
    SELECT mr.*, u.name, m.title
    FROM MovieRating mr 
    LEFT JOIN Users u ON mr.user_id = u.user_id
    LEFT JOIN Movies m ON m.movie_id = mr.movie_id
)
(
SELECT name AS results
FROM cte
GROUP BY name
ORDER BY COUNT(movie_id) DESC, name
LIMIT 1
)
UNION ALL
(
SELECT title AS results
FROM cte
WHERE DATE_FORMAT(created_at, '%Y-%m') = '2020-02'
GROUP BY title
ORDER BY AVG(rating) DESC, title
LIMIT 1
)