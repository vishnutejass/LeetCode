SELECT MAX(freq.num) AS num
FROM (
    SELECT num, COUNT(num) AS num_count
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1
) AS freq;
