-- SELECT queries: 2 queries using the IN operator to introduce a subquery in the WHERE clause; in at least one query, the subquery should include a subquery in its own WHERE clause;

SELECT * 
FROM Medications
WHERE Medications.sid 
IN ( SELECT DISTINCT sid
	 FROM Suppliers );

SELECT name
FROM Medications
WHERE mid > ( SELECT DISTINCT Prescribed_Medications.mid FROM Prescribed_Medications WHERE Prescribed_Medications.quantity > 5 )

SELECT Prescribed_Medications.mid, Prescribed_Medications.description, Prescribed_Medications.quantity
FROM Prescribed_Medications
WHERE Prescribed_Medications.quantity > ( SELECT AVG(Prescribed_Medications.quantity)
										  FROM Prescribed_Medications
										  WHERE Prescribed_Medications.did IN ( SELECT Doctors.did
																				FROM Doctors
																				WHERE Doctors.salary > 10000 ))