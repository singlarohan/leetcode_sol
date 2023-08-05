# Write your MySQL query statement below
SELECT P.product_id, ROUND(SUM(U.units * P.price)/SUM(U.units), 2) as average_price
FROM Prices AS P
JOIN UnitsSold AS U 
ON P.product_id = U.product_id AND (U.purchase_date BETWEEN P.start_date AND P.end_date) 
GROUP BY product_id

