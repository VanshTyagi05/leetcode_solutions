SELECT 
    e.employee_id, 
    e.department_id
FROM Employee e
JOIN 
(SELECT 
        employee_id, 
        COUNT(department_id) AS dept_count
    FROM Employee
    GROUP BY employee_id
) AS counts 
ON e.employee_id = counts.employee_id
WHERE e.primary_flag = 'Y' 
   OR counts.dept_count = 1;
