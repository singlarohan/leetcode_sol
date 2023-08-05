# Write your MySQL query statement below
SELECT customer_id, COUNT(V.visit_id) as count_no_trans
FROM Visits AS V
LEFT JOIN Transactions AS T ON V.visit_id = T.visit_id
WHERE transaction_id IS null
GROUP BY customer_id