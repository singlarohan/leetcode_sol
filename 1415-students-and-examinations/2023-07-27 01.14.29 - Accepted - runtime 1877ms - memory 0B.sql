# Write your MySQL query statement below
SELECT 
    S.student_id, S.student_name,
    sub.subject_name,
    COUNT(E.subject_name) as attended_exams

FROM Students S
JOIN Subjects sub ON 1
LEFT JOIN Examinations E ON S.student_id = E.student_id AND sub.subject_name = E.subject_name
GROUP BY subject_name, student_id
ORDER BY student_id, subject_name