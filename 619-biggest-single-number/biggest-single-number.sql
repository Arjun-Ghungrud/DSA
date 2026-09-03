# Write your MySQL query statement below
SELECT(
    SELECT num
    FROM (
        SELECT num,COUNT(*)
        FROM MyNumbers
        GROUP BY num
        HAVING COUNT(*)=1
    ) AS T
    ORDER BY num DESC
    LIMIT 1 
) AS num;
