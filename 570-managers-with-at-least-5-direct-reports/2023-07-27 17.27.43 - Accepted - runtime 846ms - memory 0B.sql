# Write your MySQL query statement below
SELECT name
FROM Employee E
JOIN( 
    SELECT managerId as Mid, COUNT(id) as cnt
    FROM Employee
    GROUP BY managerId) AS M

    ON M.cnt >= 5 AND E.id = M.Mid;