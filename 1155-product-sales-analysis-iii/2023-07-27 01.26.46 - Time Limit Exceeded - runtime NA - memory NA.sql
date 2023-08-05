# Write your MySQL query statement below
SELECT product_id, year as first_year, quantity, price
FROM Sales AS S1
WHERE year = (
  SELECT MIN(year) 
  FROM Sales AS S2 
  GROUP BY S2.product_id 
  HAVING S1.product_id = S2.product_id);