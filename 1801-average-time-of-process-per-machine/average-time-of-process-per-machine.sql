# Write your MySQL query statement below
SELECT A.machine_id,

ROUND(AVG(B.timestamp - A.timestamp),3) AS processing_time

FROM Activity AS A, Activity AS B

WHERE A.machine_id = B.machine_id

AND A.process_id = B.process_id

AND A.activity_type = "start"

AND b.activity_type = "end"

GROUP BY machine_id
