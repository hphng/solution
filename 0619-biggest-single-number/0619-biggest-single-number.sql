# Write your MySQL query statement below
SELECT MAX(num) as num
FROM MyNumbers a 
WHERE num IN (
    SELECT b.num
    FROM MyNumbers b
    GROUP BY b.num
    HAVING COUNT(b.num) = 1
)
