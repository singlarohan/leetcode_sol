# Write your MySQL query statement below
SELECT customer_id
FROM Customer AS C
GROUP BY customer_id
HAVING COUNT(C.product_key) = (SELECT COUNT(*) FROM PRODUCT)