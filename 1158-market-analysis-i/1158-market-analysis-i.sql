# Write your MySQL query statement below
with o as (select * from orders where Year(order_date)=2019)
select u.user_id as buyer_id,
u.join_date,count(item_id) as orders_in_2019
from users as u
left join o
on u.user_id=o.buyer_id
group by u.user_id;