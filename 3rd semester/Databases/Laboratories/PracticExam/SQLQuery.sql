-- 1.
IF OBJECT_ID('Uses','U') IS NOT NULL
	DROP TABLE Uses

IF OBJECT_ID('RechargingStations','U') IS NOT NULL
	DROP TABLE RechargingStations

IF OBJECT_ID ('ElectricCars','U') IS NOT NULL
	DROP TABLE ElectricCars

IF OBJECT_ID('Membership','U') IS NOT NULL
	DROP TABLE Membership

IF OBJECT_ID('Cities','U') IS NOT NULL 
	DROP TABLE Cities

IF OBJECT_ID('Citizens','U') IS NOT NULL
	DROP TABLE Citizens

CREATE TABLE Cities(
	cyd INT PRIMARY KEY,
	name CHAR(30),
	mayor CHAR(30)
)

CREATE TABLE Citizens(
	cid INT PRIMARY KEY,
	name CHAR(30),
	age INT
)

CREATE TABLE Membership(
	cyd INT FOREIGN KEY REFERENCES Cities(cyd),
	cid INT FOREIGN KEY REFERENCES Citizens(cid),
	remainingTaxes INT
	PRIMARY KEY(cyd,cid)
)

CREATE TABLE ElectricCars(
	eid INT PRIMARY KEY,
	fuelLevel INT,
	seats INT,
	ownerCid INT REFERENCES Citizens(cid)
)

CREATE TABLE RechargingStations(
	rid INT PRIMARY KEY,
	location CHAR(30)
)

CREATE TABLE Uses(
	eid INT FOREIGN KEY REFERENCES ElectricCars(eid),
	rid INT FOREIGN KEY REFERENCES RechargingStations(rid),
	times INT,
	PRIMARY KEY(eid,rid)
)

-- populating the tables

INSERT INTO Cities VALUES (1,'Bucuresti','Razvan Lucescu')
INSERT INTO Cities VALUES (2,'Cluj-Napoca','Emil Boc')
INSERT INTO Cities VALUES (3,'Bistrita','Ovidiu Cretu')

INSERT INTO Citizens VALUES(1,'Andrei',20)
INSERT INTO Citizens VALUES(2,'Cristian',26)
INSERT INTO Citizens VALUES(3,'Cristina',71)
INSERT INTO Citizens VALUES(4,'Andreas',34)
INSERT INTO Citizens VALUES(5,'Matei',37)
INSERT INTO Citizens VALUES(6,'Marius',10)
INSERT INTO Citizens VALUES(7,'Iosif',8)
INSERT INTO Citizens VALUES(8,'Robert',55)

INSERT INTO Membership VALUES(1,1,0)
INSERT INTO Membership VALUES(1,2,0)
INSERT INTO Membership VALUES(1,3,250)
INSERT INTO Membership VALUES(2,4,0)
INSERT INTO Membership VALUES(2,5,3000)
INSERT INTO Membership VALUES(2,6,2550)
INSERT INTO Membership VALUES(3,7,0)
INSERT INTO Membership VALUES(3,8,712)
INSERT INTO Membership VALUES(3,1,923)
INSERT INTO Membership VALUES(1,8,9111)
INSERT INTO Membership VALUES(1,7,0)

INSERT INTO ElectricCars VALUES(1,50,4,1)
INSERT INTO ElectricCars VALUES(2,75,4,2)
INSERT INTO ElectricCars VALUES(3,20,7,3)
INSERT INTO ElectricCars VALUES(4,10,9,4)
INSERT INTO ElectricCars VALUES(5,33,4,2)
-- for 4)
-- INSERT INTO ElectricCars VALUES(6,33,4,8)
-- INSERT INTO ElectricCars VALUES(7,33,4,8)

INSERT INTO RechargingStations VALUES(1,'Piata Mare')
INSERT INTO RechargingStations VALUES(2,'Piata Mihai Viteazul')
INSERT INTO RechargingStations VALUES(3,'Bulevardul Republicii')
INSERT INTO RechargingStations VALUES(4,'Arcul de Triumf')
INSERT INTO RechargingStations VALUES(5,'Bloc lama')

INSERT INTO Uses VALUES(1,1,3)
INSERT INTO Uses VALUES(1,2,2)
INSERT INTO Uses VALUES(1,3,0)
INSERT INTO Uses VALUES(1,4,7)
INSERT INTO Uses VALUES(2,1,11)
INSERT INTO Uses VALUES(2,5,9)
INSERT INTO Uses VALUES(3,1,10)
INSERT INTO Uses VALUES(4,5,3)
INSERT INTO Uses VALUES(4,3,20)
INSERT INTO Uses VALUES(4,1,12)
-- for 3)
-- INSERT INTO Uses VALUES(4,2,10)
INSERT INTO Uses VALUES(5,2,15)
GO

-- 2. Implement a stored procedure that receives a city and deletes all citizens living in that city
CREATE OR ALTER PROCEDURE ud_deleteAllCitizensFrom @cyd INT
AS
	DELETE FROM Membership WHERE Membership.cyd = @cyd
GO

-- EXEC ud_deleteAllCitizensFrom @cyd = 2
GO

-- 3. Create a view that shows the electric cars that can be recharged at the largest number of stations
CREATE OR ALTER VIEW ud_carUsingMaximumNumberOfStations 
AS
	SELECT Uses.eid
	FROM Uses
	GROUP BY Uses.eid
	HAVING COUNT(*) >= ( SELECT MAX(NewTable.NumberOfStationsUsed) AS MaxNumberOfStationsUsed
						 FROM ( SELECT Uses.eid, count(*) AS NumberOfStationsUsed
			                    FROM Uses
								GROUP BY Uses.eid) AS NewTable 
					   )
GO

 SELECT * FROM ud_carUsingMaximumNumberOfStations
GO

-- 4. Implement a function that lists all cities that have at least on citizen who owns at least N electric cars, where N >= 1 is a function parameter
GO
CREATE OR ALTER FUNCTION ud_citiesWithCitizenWhoOwnsNCars(@N INT)
RETURNS TABLE
RETURN
	SELECT Cities.name
	FROM Cities
	WHERE Cities.cyd IN (SELECT Membership.cyd
						 FROM Membership
						 WHERE Membership.cid IN (SELECT ElectricCars.ownerCid
	                                              FROM ElectricCars
	                                              GROUP BY ElectricCars.ownerCid
	                                              HAVING COUNT(*) >= @N )
		                )
GO

SELECT * FROM ud_citiesWithCitizenWhoOwnsNCars(2)