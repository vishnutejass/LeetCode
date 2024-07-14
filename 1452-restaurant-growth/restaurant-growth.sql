-- SELECT visited_on, amount, average_amount 
-- FROM (
--     SELECT 
--         visited_on,
--         SUM(total_amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount,
--         ROUND(AVG(total_amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW), 2) AS average_amount
--     FROM (
--         SELECT visited_on, SUM(amount) AS total_amount
--         FROM customer
--         GROUP BY visited_on
--     ) AS cte
-- ) AS cte2
-- WHERE visited_on >= (SELECT MIN(visited_on) FROM customer) + INTERVAL 6 DAY
-- ORDER BY visited_on;

select visited_on,amount,average_amount from
    (select visited_on,sum(total_amount)over(order by visited_on rows between 6 preceding 
    and current row) as amount,
   round(avg(total_amount)over(order by visited_on rows between 6 preceding 
    and current row),2) as average_amount

    from (select visited_on,sum(amount) as total_amount
    from customer
    group by visited_on) as cte
    ) as cte2

where visited_on >= (select min(visited_on) from customer) +6
order by visited_on









-- select visited_on,
-- sum(total_sum)over(order by visited_on rows between 6 preceding and current row) as amount,
-- ROUND(avg(total_sum)over(order by visited_on rows between 6 preceding and current row),2) as average_amount from(

-- select visited_on , sum(amount) as total_sum from customer
-- group by visited_on
-- )as fn

-- where visited_on >= (SELECT MIN(visited_on) FROM customer) + INTERVAL 6 DAY;

-- SELECT 
--     visited_on,
--     SUM(total_sum) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount,
--     ROUND(AVG(total_sum) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW), 2) AS average_amount 
-- FROM (
--     SELECT 
--         visited_on, 
--         SUM(amount) AS total_sum 
--     FROM 
--         customer 
--     GROUP BY 
--         visited_on
-- ) AS fn
-- WHERE 
--     visited_on >= (SELECT MIN(visited_on) FROM customer) + INTERVAL 6 DAY;
