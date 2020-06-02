--  4 queries with the GROUP BY clause, 3 of which also contain the HAVING clause; 2 of the latter will also have a subquery in the HAVING clause; use the aggregation operators: COUNT, SUM, AVG, MIN, MAX;

--
SELECT COUNT(p.did) AS nrOfPrescriptions, p.did
FROM Prescriptions p
GROUP BY p.did

SELECT SUM(Prescribed_Medications.quantity) AS quantity, Prescribed_Medications.mid
FROM ( Prescribed_Medications INNER JOIN Medications on Prescribed_Medications.mid = Medications.mid )
GROUP BY Prescribed_Medications.mid

SELECT SUM(Prescribed_Medications.quantity) AS quantity, Prescribed_Medications.mid
FROM ( Prescribed_Medications INNER JOIN Medications on Prescribed_Medications.mid = Medications.mid )
GROUP BY Prescribed_Medications.mid
HAVING Prescribed_Medications.mid > 3

SELECT MAX(Prescribed_Medications.quantity) AS maxQuantity, Prescribed_Medications.mid
FROM Prescribed_Medications
GROUP BY Prescribed_Medications.mid
-- HAVING Prescribed_Medications.maxQuantity > 3