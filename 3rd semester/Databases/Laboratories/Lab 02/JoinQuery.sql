-- SELECT queries: 4 queries with INNER JOIN, LEFT JOIN, RIGHT JOIN, and FULL JOIN; one query will join at least 3 tables, while another one will join at least two many-to-many relationships;

SELECT Addresses.city, Doctors.name
FROM Doctors
RIGHT JOIN Addresses
ON Doctors.aid = Addresses.aid;

SELECT Medications.name, Prescribed_Medications.quantity
FROM Medications
LEFT JOIN Prescribed_Medications
ON Medications.mid = Prescribed_Medications.mid;

SELECT Doctors.did, Prescribed_Medications.mid, Prescribed_Medications.quantity
FROM Doctors
INNER JOIN Prescribed_Medications
ON Doctors.did = Prescribed_Medications.did 
INNER JOIN Prescriptions
ON Prescriptions.did = Doctors.did
WHERE Prescribed_Medications.quantity > 1;

SELECT * 
FROM Prescriptions
FULL OUTER JOIN Prescribed_Medications
ON Prescriptions.pid = Prescribed_Medications.pid;