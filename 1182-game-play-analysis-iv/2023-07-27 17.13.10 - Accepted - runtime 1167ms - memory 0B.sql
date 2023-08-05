# Write your MySQL query statement below
SELECT ROUND(
            COUNT(A1.player_id) / 
                    (SELECT COUNT(DISTINCT A3.player_id) FROM Activity A3), 2) AS fraction

FROM Activity A1
JOIN (
    SELECT player_id, MIN(EVENT_DATE) as date
    FROM Activity
    GROUP BY player_id) AS A2

    ON A1.player_id = A2.player_id AND DATEDIFF(A1.event_date, A2.date) = 1