# Write your MySQL query statement below
SELECT ROUND(AVG(has_activity), 2) AS fraction
FROM (
    SELECT A.player_id, 
           COUNT(A2.date) AS has_activity
    FROM Activity A
    LEFT JOIN (
        SELECT player_id, MIN(event_date) as date
        FROM Activity
        GROUP BY player_id
    ) AS A2 ON A.player_id = A2.player_id AND DATEDIFF(A.event_date, A2.date) = 1
    GROUP BY A.player_id
) AS activity_summary;