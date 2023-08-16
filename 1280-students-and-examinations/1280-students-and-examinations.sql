
# SELECT s.student_id, s.student_name, sub.subject_name, COUNT(e.subject_name) AS attended_exams
# FROM Students s
# CROSS JOIN Subjects sub
# LEFT JOIN Examinations e ON s.student_id = e.student_id AND sub.subject_name = e.subject_name
# GROUP BY s.student_id, sub.subject_name
# ORDER BY s.student_id, sub.subject_name;

WITH cte AS (
    select * from Students
    cross join Subjects
),
cte2 AS(
    select student_id,subject_name,count(subject_name) as count
    from Examinations 
    group by student_id,subject_name
)
select cte.student_id,cte.student_name,cte.subject_name,
CASE WHEN count is not null then count else 0 end as attended_exams
from cte left join
cte2 on cte.student_id=cte2.student_id
AND cte.subject_name=cte2.subject_name
order by student_id ,subject_name


















# WITH cte AS (
#     SELECT * 
#     FROM Students 
#     CROSS JOIN Subjects
# ),
# cte2 AS (
#     SELECT student_id, subject_name, COUNT(subject_name) AS count
#     FROM Examinations
#     GROUP BY student_id, subject_name
# )

# SELECT cte.student_id, cte.student_name, cte.subject_name, 
#        CASE WHEN count IS NOT NULL THEN count ELSE 0 END AS attended_exams
# FROM cte
# LEFT JOIN cte2 ON cte.student_id = cte2.student_id AND cte.subject_name = cte2.subject_name
# ORDER BY cte.student_id, cte.subject_name;




