# Write your MySQL query statement below
select customer_id
from
(select customer_id,count(distinct product_key) as total_prdts
from customer
group by customer_id) as new_table
where total_prdts= (select COUNT(*) FROM product);