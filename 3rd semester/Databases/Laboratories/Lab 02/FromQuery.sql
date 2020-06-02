-- 2 queries with a subquery in the FROM clause;       
SELECT *
FROM ( SELECT Medications.cost, Medications.name FROM Medications ) AS NameAndPrice

SELECT *
FROM ( SELECT Doctors.salary, Doctors.position FROM Doctors ) AS PositionAndFunction
WHERE PositionAndFunction.salary > 10000