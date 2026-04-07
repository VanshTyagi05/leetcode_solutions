# Write your MySQL query statement below
select customer_number from
(select customer_number , count(customer_number) as no_of_orders
from orders 
group by customer_number
order by no_of_orders desc) as A
limit 1;