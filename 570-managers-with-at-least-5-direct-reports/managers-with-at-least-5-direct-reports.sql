# Write your MySQL query statement below
SELECT E.name
FROM Employee E
INNER JOIN Employee D
ON E.id=D.managerId
GROUP BY E.id
HAVING COUNT(*) >= 5;