# Write your MySQL query statement below
SELECT E.employee_id, E.name, 
      COUNT(M.reports_to) AS reports_count, ROUND(AVG(M.age)) AS average_Age
FROM Employees AS M
JOIN Employees AS E ON E.employee_id = M.reports_to
GROUP BY M.reports_to