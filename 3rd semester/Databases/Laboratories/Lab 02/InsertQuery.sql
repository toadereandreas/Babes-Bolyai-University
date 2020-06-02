USE [Lab01-Pharmacy]

-- Insert data – for at least 4 tables;
INSERT INTO Addresses VALUES (1,'Mihail Kogalniceanu',23,'Bistrita','BN','Romania',420023)
INSERT INTO Addresses VALUES (2,'Lucian Blaga',11,'Bistrita','BN','Romania',420123)
INSERT INTO Addresses VALUES (3,'Mihai Eminescu',67,'Cluj','CN','Romania',420723)
INSERT INTO Addresses VALUES (4,'Andrei Muresanu',92,'Satu-Mare','SM','Romania',420925)
INSERT INTO Addresses VALUES (5,'Liviu Rebreanu',1,'Oradea','BH','Romania',420428)
INSERT INTO Addresses VALUES (6,'Ioan Cuza',4,'Oradea','BH','Romania',421428)
INSERT INTO Addresses VALUES (7,'Stefan cel Mare',19,'Mamaia','CT','Romania',490428)

INSERT INTO Customers VALUES (1,1,'Daniel','Mihai','0734865912')
INSERT INTO Customers VALUES (2,2,'Tudor','Natan','0738115913')
INSERT INTO Customers VALUES (3,3,'Andreas','Iosif','0744005914')
INSERT INTO Customers VALUES (4,6,'Sara','Chaos','0744002294')
INSERT INTO Customers VALUES (5,7,'Xi','Min Son','0744105984')

INSERT INTO Doctors VALUES (1,4,'Ziggy Orban','Chirurg',12000,'0723822912')
INSERT INTO Doctors VALUES (2,5,'Alex Velea','Oftalmolog',10000,'0723227132')

INSERT INTO Managers VALUES (1,1)

-- At least one statement should violate referential integrity constraints;
INSERT INTO Addresses VALUES (NULL,'Asdasdas',20,'Narnia','Lost','China',490128)
-- Error: Cannot insert the value NULL into column 'aid', table 'Lab01-Pharmacy.dbo.Addresses'; column does not allow nulls. INSERT fails.
