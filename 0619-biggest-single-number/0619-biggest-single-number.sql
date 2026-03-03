# Write your MySQL query statement below
select max(num) as num
from
(select num,count(num) as count_num 
from MyNumbers
group by num) as new_table
where count_num=1;

