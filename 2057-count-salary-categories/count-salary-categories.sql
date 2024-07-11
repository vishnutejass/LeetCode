
select "Low Salary" As category,sum(income<20000) as accounts_count from Accounts union
select "Average Salary" as category,sum(income BETWEEN 20000 AND 50000) as accounts_count from Accounts union
select "High Salary" As category,sum(income>50000) as accounts_count from Accounts