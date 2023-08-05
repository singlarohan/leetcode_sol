SELECT product_name, year, price
FROM Sales AS S
JOIN Product AS P 
    ON P.product_id = S.product_id