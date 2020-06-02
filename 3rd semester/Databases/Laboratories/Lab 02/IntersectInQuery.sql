-- SELECT queries: 2 queries with the intersection operation; use INTERSECT and IN;

SELECT mid FROM Medications
INTERSECT
SELECT mid FROM Prescribed_Medications;

SELECT *
FROM Medications

SELECT name
FROM Medications
WHERE cost IN (10,27,31,2);