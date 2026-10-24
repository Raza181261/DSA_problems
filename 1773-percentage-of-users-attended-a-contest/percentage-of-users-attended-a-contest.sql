# Write your MySQL query statement below
select r.contest_id, round(count(user_id)*100 / (select count(*) from users), 2) as percentage
from Register as r
group by contest_id
order by percentage desc, contest_id asc