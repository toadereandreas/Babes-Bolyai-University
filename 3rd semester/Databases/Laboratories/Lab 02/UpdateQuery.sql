USE [Lab01-Pharmacy]
-- Update data – for at least 2 tables;

UPDATE Addresses SET street = 'Giani Morandi' WHERE aid = 1;

UPDATE Prescribed_Medications SET quantity = 3 WHERE pid = 2;

-- I also use ">" operator here:
UPDATE Suppliers SET name = 'Monsters INC' WHERE sid > 2;

-- I also use "BETWEEN" here:
UPDATE Medications SET cost = cost - 10 WHERE cost BETWEEN 80 AND 200;