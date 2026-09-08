# Write your MySQL query statement below
SELECT S.student_id,S.student_name,SU.subject_name,COUNT(E.student_id) AS attended_exams
FROM Students S 
CROSS JOIN Subjects SU #CREATES EVERY POSSIBLE COMBIANTION OF STUEDENTS AND SUBJECTS
LEFT JOIN Examinations E
ON E.student_id=S.student_id AND SU.subject_name = E.subject_name
GROUP BY S.Student_id,S.student_name,SU.subject_name
ORDER BY S.student_id,SU.subject_name;