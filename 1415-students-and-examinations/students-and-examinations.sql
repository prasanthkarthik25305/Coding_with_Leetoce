# Write your MySQL query statement below
#select student_id,student_name,subject_name from Students cross join Subjects;
 select  S.student_id,S.student_name,SU.subject_name,count(e.subject_name)as attended_exams from Students S cross join Subjects SU 
 left join Examinations E on E.student_id=S.student_id and E.subject_name=SU.subject_name
 group by student_id,student_name,subject_name
 order by student_id,student_name,subject_name;