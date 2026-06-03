# Write your MySQL query statement below
select id,visit_date,people from
(select id,visit_date ,people,COUNT(*) OVER (PARTITION BY group_id) AS total_streak_days from 
(select id,visit_date ,people ,id - ROW_NUMBER() OVER (ORDER BY id) AS group_id from
 stadium 
where people>=100
order by visit_date asc) as sub) as sub2
where total_streak_days>=3
order by visit_date asc
