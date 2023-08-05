# Write your MySQL query statement below
SELECT 100*(AVG(order_date = customer_pref_delivery_date)) as immediate_percentage 
FROM Delivery
WHERE (customer_id, order_date) IN(
    SELECT customer_id, MIN(order_date)
    FROM Delivery
    GROUP BY customer_id)

