# Write your MySQL query statement below
SELECT IF(COUNT(M.id >= 5), E.name, null) as name
FROM Employee E
JOIN( 
    SELECT managerId as Mid, id
    FROM Employee
    GROUP BY managerId) AS M

    ON E.id = M.Mid;