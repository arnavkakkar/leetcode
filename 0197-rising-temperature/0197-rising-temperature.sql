# Write your MySQL query statement below
SELECT e.id 
FROM Weather e
JOIN Weather m
ON m.recordDate = DATE_SUB(e.recordDate, INTERVAL 1 DAY)
WHERE e.temperature > m.temperature;