CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  Declare M INT;
  set M=N-1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct salary
      from Employee
      order by salary Desc
      limit 1 OFFSET M
  );
END