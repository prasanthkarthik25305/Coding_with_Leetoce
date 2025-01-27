/* Write your PL/SQL query statement below */
select DISTINCT author_id as id from Views where viewer_id =author_id ORDER BY id;