select person_name from(
select person_name,weight,turn, sum(weight)over(order by turn asc) as s_wt from Queue
) as final
where s_wt <=1000
order by s_wt desc
limit 1;