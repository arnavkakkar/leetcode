# Write your MySQL query statement below
SELECT MAX(second_salary) AS SecondHighestSalary
FROM (
    SELECT LEAD(salary, 1) OVER (ORDER BY salary DESC) AS second_salary
    FROM (
        SELECT DISTINCT salary
        FROM Employee
    ) s
) t;
