# Write your MySQL query statement below
select product_name, sum(unit) as unit
from 
(select o.product_id as product_id,o.order_date as order_date,o.unit as unit,p.product_name as product_name from
orders as o inner join products as p
where  o.product_id=p.product_id
and  month(order_date)='02' and year(order_date)='2020') as newtable
group by product_id
having unit>=100

