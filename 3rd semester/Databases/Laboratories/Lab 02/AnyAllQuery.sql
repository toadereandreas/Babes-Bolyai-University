-- 4 queries using ANY and ALL to introduce a subquery in the WHERE clause; 2 of them should be rewritten with aggregation operators, while the other 2 should also be rewritten with [NOT] IN

--name of the prescribed medication
SELECT Medications.name
FROM Medications
WHERE Medications.mid = ANY( SELECT Prescribed_Medications.mid
							 FROM Prescribed_Medications)

-- Rewritten
SELECT Medications.name
FROM Medications
WHERE Medications.mid IN (  SELECT DISTINCT Prescribed_Medications.mid
							FROM Prescribed_Medications
							WHERE Prescribed_Medications.mid >= ( SELECT MIN(Prescribed_Medications.mid)
																  FROM Prescribed_Medications )
		                 )





-- average of the cost of the prescribed medication of a given doctor
SELECT Medications.cost
FROM Medications
WHERE Medications.mid = ANY( SELECT Prescribed_Medications.mid
							 FROM Prescribed_Medications
							 WHERE Prescribed_Medications.did = 3)

-- Rewritten
SELECT MAX(Medications.cost) AS cost
FROM Medications
WHERE Medications.mid IN (3,4)
GROUP BY Medications.cost





SELECT Addresses.city
FROM Addresses
WHERE Addresses.county = ALL ( SELECT Addresses.county
							   FROM Addresses
							   WHERE Addresses.county NOT IN ('BN','SM'))
-- Rewritten
SELECT Addresses.city
FROM Addresses
WHERE Addresses.city IN ('Bucuresti')





SELECT Prescribed_Medications.quantity
FROM Prescribed_Medications
WHERE Prescribed_Medications.quantity >= ALL( SELECT MIN(Prescribed_Medications.quantity)	
                                              FROM Prescribed_Medications)
											  

-- Rewritten
SELECT Prescribed_Medications.quantity
FROM Prescribed_Medications
WHERE Prescribed_Medications.quantity >= ( SELECT MIN(Prescribed_Medications.quantity)
										   FROM Prescribed_Medications )