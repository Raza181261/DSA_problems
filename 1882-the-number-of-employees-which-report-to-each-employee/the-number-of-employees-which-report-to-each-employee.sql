# Write your MySQL query statement below
select m.employee_id, m.name, count(*) as reports_count, round(avg(e.age)) as average_age
from Employees as m
join Employees as e
on m.employee_id = e.reports_to
group by m.employee_id
order by m.employee_id