# Write your MySQL query statement below
select id,count(*) as num from
(select requester_id as id from RequestAccepted
union all
select accepter_id from requestaccepted) as new_table
group by id
order by num desc
limit 1