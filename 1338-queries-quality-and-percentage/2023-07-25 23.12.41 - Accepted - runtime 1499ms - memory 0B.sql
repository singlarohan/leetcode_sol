# Write your MySQL query statement below
SELECT 
    Q.query_name, ROUND(SUM(rating/position)/SUM(1), 2) AS quality,
    ROUND(100*AVG(CASE WHEN rating < 3 THEN 1 ELSE 0 END), 2) AS poor_query_percentage
FROM
    Queries as Q
GROUP BY 
    query_name;