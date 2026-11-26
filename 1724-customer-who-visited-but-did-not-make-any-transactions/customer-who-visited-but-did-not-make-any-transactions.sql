# Write your MySQL query statement below
-- SELECT customer_id, COUNT(*) AS count_no_trans
-- FROM Visits
-- WHERE visit_id NOT IN (SELECT visit_id FROM Transactions)
-- GROUP BY customer_id




















Select customer_id, count(*) as count_no_trans
from Visits
where visit_id not in(select visit_id from Transactions)
group by customer_id