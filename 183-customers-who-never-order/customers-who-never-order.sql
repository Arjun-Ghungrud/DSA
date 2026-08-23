# Write your MySQL query statement below
SELECT c1.name AS Customers
FROM Customers AS c1
LEFT JOIN Orders AS o1
    ON c1.id=o1.customerId 
WHERE o1.id IS NULL;