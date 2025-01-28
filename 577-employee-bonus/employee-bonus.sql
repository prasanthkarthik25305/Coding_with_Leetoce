/* Write your PL/SQL query statement below */
select e.name,b.bonus from Employee e left join Bonus b on b.empId=e.empId 
where b.bonus<1000 or b.empId is null ;