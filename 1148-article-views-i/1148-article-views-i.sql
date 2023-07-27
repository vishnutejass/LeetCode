# Write your MySQL query statement below
select DISTINCT author_id AS ID
FROM Views
where author_id = viewer_id
ORDER BY author_id ASC;

