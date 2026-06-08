-- Write your PostgreSQL query statement below
-- Write your PostgreSQL query statement below
SELECT w1.id
FROM Weather w1
JOIN Weather w2
ON w1.recordDate - w2.recordDate = 1
WHERE w1.temperature > w2.temperature;