# Write your MySQL query statement below
select class from 
(select class,count(distinct student) as numofstud
from courses
group by class) as new_table
where numofstud>=5;