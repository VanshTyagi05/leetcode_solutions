# Write your MySQL query statement below
select employee_id from
(select employee_id,manager_id 
from employees where salary<30000) as newtable
where manager_id not in(
    select employee_id from employees
)
order by employee_id;