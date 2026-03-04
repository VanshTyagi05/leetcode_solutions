# Write your MySQL query statement below
select d.name as Department,e.name as Employee, e.salary as Salary 
from employee as e
join department as d
on e.departmentId=d.id
where 3> (
    select count(distinct(e2.salary))
    from employee e2
    where e2.salary >e.salary
    and e.departmentid=e2.departmentid
)