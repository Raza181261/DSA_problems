# Write your MySQL query statement below
-- SELECT E.name,B.bonus 
-- FROM Employee AS E 
-- LEFT JOIN Bonus AS B
-- ON E.empId = B.empId 
-- WHERE B.bonus < 1000 OR B.bonus IS NULL








select e.name, b.bonus
from Employee as e
left join Bonus as b
on e.empId = b.empId
where b.bonus < 1000 or b.bonus is null