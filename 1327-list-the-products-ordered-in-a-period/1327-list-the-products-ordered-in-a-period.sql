# Write your MySQL query statement below
SELECT product_name, SUM(unit) AS unit
FROM (
    SELECT p.product_name, o.unit 
    FROM orders AS o 
    INNER JOIN products AS p ON o.product_id = p.product_id
    WHERE MONTH(o.order_date) = 2 AND YEAR(o.order_date) = 2020
) AS newtable
GROUP BY product_name
HAVING unit >= 100;


