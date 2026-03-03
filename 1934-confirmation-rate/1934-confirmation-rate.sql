# Write your MySQL query statement below
select s.user_id ,  ROUND(IFNULL(AVG(c.action = 'confirmed'), 0), 2) as confirmation_rate
from Signups as s
left join confirmations as c
on s.user_id=c.user_id
group by s.user_id;