SELECT S1.product_id, S3.min_year as first_year, S1.quantity, S1.price
FROM Sales AS S1
JOIN (
  SELECT product_id, MIN(year) as min_year
  FROM Sales
  GROUP BY product_id
) AS S3 ON S1.product_id = S3.product_id AND S1.year = S3.min_year;