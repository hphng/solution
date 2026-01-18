# Write your MySQL query statement below
SELECT p.project_id, ROUND(AVG(e.experience_years), 2) AS average_years
FROM Employee e
RIGHT JOIN Project p ON p.employee_id = e.employee_id
GROUP BY project_id