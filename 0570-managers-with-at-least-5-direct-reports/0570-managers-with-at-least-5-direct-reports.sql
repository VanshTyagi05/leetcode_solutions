# Write your MySQL query statement below
select name
from employee 
where id In(
    select managerId
    from employee
    group by managerId
    having count(*) >=5
)