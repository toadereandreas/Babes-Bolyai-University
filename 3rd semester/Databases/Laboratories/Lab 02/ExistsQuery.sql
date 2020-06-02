-- f. 2 queries using the EXISTS operator to introduce a subquery in the WHERE clause;

-- doctors who have prescribed medicine
SELECT *
FROM Doctors
WHERE EXISTS ( SELECT did
			   FROM Prescriptions)

			   --
SELECT city
FROM Addresses
WHERE EXISTS( SELECT did
			  FROM Doctors )
