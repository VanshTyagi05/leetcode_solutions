# Write your MySQL query statement below

select actor_id,director_id
from ActorDirector
group by actor_id,director_id
having count(*) >=3;
# agr tumne group by function use kiya hai toh count(*) humesha count krta hai created groups ka size

