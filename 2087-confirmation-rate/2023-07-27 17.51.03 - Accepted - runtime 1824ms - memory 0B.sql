# Write your MySQL query statement below
# SELECT S.user_id, (CASE WHEN action IS NULL THEN 0.0
#             ELSE 
#             ROUND (SUM(CASE WHEN action = 'confirmed' THEN 1 ELSE 0 END) 
#             / COUNT(action), 2) END) 
#             AS confirmation_rate
SELECT 
    S.user_id, 
    CASE WHEN C.total IS null THEN 0 ELSE ROUND(C.confirm/C.total, 2) END as confirmation_rate
FROM 
    Signups AS S
LEFT JOIN (
    SELECT 
        user_id, 
        SUM(CASE WHEN action = 'confirmed' THEN 1 ELSE 0 END) as confirm,
        COUNT(action) as total
    FROM Confirmations 
    GROUP BY user_id) AS C
    
    ON C.user_id = S.user_id
GROUP BY S.user_id