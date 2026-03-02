# Write your MySQL query statement below
select e1.name,e2.unique_id
from Employees as e1
Left Join EmployeeUNI as e2
On e1.id=e2.id;