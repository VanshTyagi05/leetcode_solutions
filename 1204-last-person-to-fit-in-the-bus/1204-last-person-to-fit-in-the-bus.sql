# Write your MySQL query statement below
select person_name 
from(
SELECT 
        person_name, 
        SUM(weight) OVER (ORDER BY turn asc) AS cumulative_weight
    FROM Queue) as subquery
    where cumulative_weight<=1000
    order by cumulative_weight desc
    limit 1; 