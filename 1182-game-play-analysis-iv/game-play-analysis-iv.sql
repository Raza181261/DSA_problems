# Write your MySQL query statement below
-- SELECT ROUND(
--   COUNT(A2.player_id) / COUNT(A1.player_id), 2
-- ) AS fraction
-- FROM (
--   SELECT player_id, MIN(event_date) AS first_date
--   FROM Activity
--   GROUP BY player_id
-- ) AS A1
-- LEFT JOIN Activity AS A2
--   ON A1.player_id = A2.player_id
--  AND A2.event_date = DATE_ADD(A1.first_date, INTERVAL 1 DAY);















 select round(count(A2.player_id) / count(A1.player_id), 2) as fraction
 from(
    select player_id, min(event_date) as first_date
    from Activity
    group by player_id
 ) as A1
 left join Activity as A2
 on A1.player_id = A2.player_id
 and A2.event_date = date_add(A1.first_date, interval 1 day)