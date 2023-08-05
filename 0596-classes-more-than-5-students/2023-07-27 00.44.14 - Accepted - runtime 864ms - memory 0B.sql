# Write your MySQL query statement below
SELECT class
FROM Courses C
GROUP BY class
HAVING COUNT(C.student) > 4;