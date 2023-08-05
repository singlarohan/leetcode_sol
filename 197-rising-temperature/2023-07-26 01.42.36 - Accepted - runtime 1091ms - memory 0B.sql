# Write your MySQL query statement below
SELECT W.id
FROM Weather AS W
INNER JOIN Weather AS W2 ON
    DATE_ADD(W2.recordDate, INTERVAL 1 DAY) = W.recordDate 
    AND W2.temperature < W.temperature;