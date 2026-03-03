# Write your MySQL query statement below
SELECT 
activity_date as day,
count(distinct user_id)  as active_users
from activity
WHERE activity_date BETWEEN SUBDATE('2019-07-27', 29) AND '2019-07-27'
group by day;
