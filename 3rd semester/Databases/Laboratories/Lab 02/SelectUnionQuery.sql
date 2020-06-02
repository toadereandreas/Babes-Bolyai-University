-- SELECT queries: 2 queries with the union operation; use UNION [ALL] and OR;

-- get all phone numbers in the database
SELECT phoneNumber FROM Doctors
UNION
SELECT phoneNumber FROM Customers;

-- get medication costs for medicine from specified supplier
SELECT cost FROM Medications WHERE sid = 1 or sid = 3;