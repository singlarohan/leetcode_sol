# Write your MySQL query statement below
SELECT S1.product_id, S2.year as first_year, quantity, price
FROM Sales AS S1
JOIN (
  SELECT product_id, MIN(year) as year
  FROM Sales 
  GROUP BY product_id) AS S2 ON (S1.product_id = S2.product_id) AND (S1.year = S2.year);