# Write your MySQL query statement below
select actor_id,director_id from
(select actor_id,director_id,count(*) as total_pairs 
from ActorDirector
group by actor_id,director_id) as s
where total_pairs>=3;
