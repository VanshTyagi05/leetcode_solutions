# Write your MySQL query statement below
(select name as results
from users inner join movierating using(user_id)
group by user_id
order by count(user_id) DESC, name
limit 1)


Union all

(select title as results
from movies inner join movierating using(movie_id)
where month(created_at)='02' and year(created_at)='2020'
group by title
order by avg(rating)  DESC,title
limit 1)