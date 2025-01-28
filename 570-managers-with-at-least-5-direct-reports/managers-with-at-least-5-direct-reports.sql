# Write your MySQL query statement below
select e2.name  from Employee e1,Employee e2 where e1.managerId=e2.id group by e2.id having  Count(e1.id)>=5;