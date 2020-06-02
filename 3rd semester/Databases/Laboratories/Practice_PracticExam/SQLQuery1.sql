-- 1.
IF OBJECT_ID('RoutesStations','U') IS NOT NULL
	DROP TABLE RoutesStations

IF OBJECT_ID('Stations','U') IS NOT NULL
	DROP TABLE Stations

IF OBJECT_ID('Routes','U') IS NOT NULL
	DROP TABLE Routes

IF OBJECT_ID('Trains','U') IS NOT NULL
	DROP TABLE Trains

IF OBJECT_ID('TrainTypes','U') IS NOT NULL
	DROP TABLE TrainTypes
GO

CREATE TABLE TrainTypes(
	TTID TINYINT PRIMARY KEY IDENTITY(1,1),
	Description VARCHAR(300)
)

CREATE TABLE Trains(
	TID SMALLINT PRIMARY KEY IDENTITY(1,1),
	TName VARCHAR(100),
	TTID TINYINT REFERENCES TrainTypes(TTID)
)

CREATE TABLE Routes(
	RID SMALLINT PRIMARY KEY IDENTITY(1,1),
	RName VARCHAR(100) UNIQUE,
	TID SMALLINT REFERENCES Trains(TID)
)

CREATE TABLE Stations(
	SID SMALLINT PRIMARY KEY IDENTITY(1,1),
	SName VARCHAR(300) UNIQUE
)

CREATE TABLE RoutesStations(
	RID SMALLINT REFERENCES Routes(RID),
	SID SMALLINT REFERENCES Stations(SID),
	ArrivalTime TIME,
	DepartureTime TIME,
	PRIMARY KEY(RID,SID)
)

GO

-- 2.
CREATE OR ALTER PROCEDURE my_proc @Route VARCHAR(100), @Station VARCHAR(100), @Arrival TIME, @Departure TIME
AS
	DECLARE @RID INT = ( SELECT Routes.RID   FROM Routes   WHERE Routes.RName   = @Route)
	DECLARE @SID INT = ( SELECT Stations.SID FROM Stations WHERE Stations.SName = @Station)

	IF @RID IS NULL OR @SID IS NULL 
	BEGIN
		RAISERROR('No such station or route',16,1)
		RETURN 1
	END -- end-if

	-- if it exists we update arrival and departure
	IF EXISTS ( SELECT * FROM RoutesStations WHERE RID = @RID AND SID = @SID )
		UPDATE RoutesStations SET ArrivalTime = @Arrival, DepartureTime = @Departure WHERE RID = @RID AND SID = @SID
	 -- else, we add it
	ELSE 
		INSERT INTO RoutesStations VALUES(@RID,@SID,@Arrival,@Departure)
GO

INSERT TrainTypes VALUES('regio'),('inter-regio')
INSERT Trains     VALUES('t1',1),('t2',1),('t3',1)
INSERT Stations   VALUES('s1'),('s2'),('s3')
INSERT Routes     VALUES('r1',1),('r2',2),('r3',3)

SELECT * FROM TrainTypes
SELECT * FROM Trains
SELECT * FROM Stations
SELECT * FROM Routes
SELECT * FROM RoutesStations

EXEC my_proc 'r1','s1', '6:10', '7:10'
EXEC my_proc 'r1','s2', '8:10','10:10'
EXEC my_proc 'r1','s3','13:50','15:25'
EXEC my_proc 'r2','s3','17:50','21:25'

-- 3.
GO

CREATE OR ALTER VIEW my_view
AS
	SELECT Routes.RName
	FROM Routes
	WHERE NOT EXISTS ( SELECT Stations.SID
					   FROM Stations
					   EXCEPT
					   SELECT RoutesStations.SID
					   FROM RoutesStations
					   WHERE RoutesStations.RID = Routes.RID )
GO		

SELECT *
FROM my_view

-- 4.
GO
CREATE OR ALTER FUNCTION my_fct(@R INT)
RETURNS TABLE
RETURN
	SELECT Stations.SName
	FROM Stations
	WHERE Stations.SID IN ( SELECT RoutesStations.SID
							FROM RoutesStations
							GROUP BY RoutesStations.SID
							HAVING COUNT(*) >= @R)
GO
SELECT *
FROM my_fct(2)