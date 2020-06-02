-- SELECT queries: 2 queries with the difference operation; use EXCEPT and NOT IN;

-- doctors who didn't prescribe medicine
SELECT mid FROM Medications
EXCEPT
SELECT mid FROM Prescribed_Medications;

-- medication which does not cost the specified values
SELECT name FROM Medications WHERE cost NOT IN (20,18,34);