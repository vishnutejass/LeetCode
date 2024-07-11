-- select product_id,
-- 10 as price
-- from Products
-- group by product_id
-- having min(change_date) > '2019-08-16'

-- UNION ALL

-- select product_id,
-- new_price as price
-- from Products 
-- where (product_id , change_date) IN (
--     select 
--     product_id, MAX(change_date) from
--     Products
--     where change_date <= '2019-08-16'
--     group by
--     product_id
-- )
select product_id, IFNULL(price,10) as price from(
select distinct product_id from products) as unique_products
left join(
    select distinct product_id, first_value(new_price) over(
        partition by product_id order by change_date desc
    )as price
    from Products 
    where change_date <= '2019-08-16'
) as lastchangedprice using (product_id);

-- SELECT 
--     product_id,
--     new_price,
--     FIRST_VALUE(change_date) OVER (
--         PARTITION BY product_id 
--         ORDER BY change_date DESC
--     ) AS latest_change_date
-- FROM Products
-- WHERE change_date <= '2019-08-16';

