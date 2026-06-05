-- Write your PostgreSQL query statement below
SELECT distinct author_id AS id
FROM Views
WHERE author_id = viewer_id