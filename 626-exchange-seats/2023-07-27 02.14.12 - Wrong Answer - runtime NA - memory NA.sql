# Write your MySQL query statement below
SELECT S2.id, S1.student
FROM Seat S1
JOIN Seat S2 ON (S1.id = S2.id AND S2.id = (SELECT COUNT(student) FROM Seat)) OR
              CASE WHEN (SELECT COUNT(student) FROM Seat) % 2 = 0 THEN S1.id = S2.id
              ELSE (CASE WHEN S2.id % 2 = 0 THEN S2.id - 1 = S1.id ELSE S2.id + 1 = S1.id END)  
              END;