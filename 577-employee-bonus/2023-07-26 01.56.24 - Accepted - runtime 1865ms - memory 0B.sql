# Write your MySQL query statement below
SELECT name, bonus
FROM Employee E
LEFT JOIN Bonus B ON E.empId = B.empId AND B.bonus < 1000
WHERE 
    bonus IS NOT NULL OR E.empId NOT IN(
        SELECT empID
        FROM Bonus B
        WHERE bonus >= 1000
    )