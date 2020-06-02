IF OBJECT_ID('Women','U') IS NOT NULL
	DROP TABLE Women

IF OBJECT_ID('PresentationShops','U') IS NOT NULL
	DROP TABLE PresentationShops

IF OBJECT_ID('Shoes','U') IS NOT NULL
	DROP TABLE Shoes

IF OBJECT_ID('Models','U') IS NOT NULL
	DROP TABLE Models

IF OBJECT_ID('Purchases','U') IS NOT NULL
	DROP TABLE Purchases

IF OBJECT_ID('ShoePresentations','U') IS NOT NULL
	DROP TABLE ShoePresentations

-- 1.
CREATE TABLE Women(
	wid INT PRIMARY KEY,
	budget INT,
	name CHAR(30)
)

CREATE TABLE PresentationShops(
	pid INT PRIMARY KEY,
	name CHAR(30),
	city CHAR(30)
)

CREATE TABLE Models(
	mid INT PRIMARY KEY,
	name CHAR(30),
	season CHAR(30)
)

CREATE TABLE Shoes(
	sid INT PRIMARY KEY,
	mid INT FOREIGN KEY REFERENCES Models(mid),
	price INT
)

CREATE TABLE ShoePresentations(
	pid INT FOREIGN KEY REFERENCES PresentationShops(pid),
	sid INT FOREIGN KEY REFERENCES Shoes(sid),
	numberOfShoes INT,
	PRIMARY KEY(pid,sid)
)

CREATE TABLE Purchases(
	wid INT FOREIGN KEY REFERENCES Women(wid),
	sid INT FOREIGN KEY REFERENCES Shoes(sid),
	quantity INT,
	totalAmount INT
)
GO

-- populating

INSERT INTO PresentationShops VALUES (1,'Prada','Berlin')
INSERT INTO PresentationShops VALUES (2,'Gucci','Paris')
INSERT INTO PresentationShops VALUES (3,'Versace','Madrid')

INSERT INTO Models VALUES (1,'Stiletto','16/17')
INSERT INTO Models VALUES (2,'Sandal','18/19')
INSERT INTO Models VALUES (3,'Sport','19/20')

INSERT INTO Shoes VALUES (1,1,200)
INSERT INTO Shoes VALUES (2,1,600)
INSERT INTO Shoes VALUES (3,2,550)
INSERT INTO Shoes VALUES (4,2,890)
INSERT INTO Shoes VALUES (5,1,350)
INSERT INTO Shoes VALUES (6,3,100)
INSERT INTO Shoes VALUES (7,1,200)

INSERT INTO ShoePresentations VALUES (1,1,30)
INSERT INTO ShoePresentations VALUES (1,2,10)
INSERT INTO ShoePresentations VALUES (2,1,8)
INSERT INTO ShoePresentations VALUES (2,2,12)
INSERT INTO ShoePresentations VALUES (2,3,16)
INSERT INTO ShoePresentations VALUES (3,3,100)

INSERT INTO Women VALUES (1,2000,'Anne')
INSERT INTO Women VALUES (2,3500,'Jessica')
INSERT INTO Women VALUES (3,1750,'Kim')

INSERT INTO Purchases VALUES (1,1,1,200)
INSERT INTO Purchases VALUES (2,1,2,400)
INSERT INTO Purchases VALUES (3,2,1,600)
INSERT INTO Purchases VALUES (1,5,2,700)
INSERT INTO Purchases VALUES (2,6,3,300)

GO
-- 2.

CREATE OR ALTER PROCEDURE ud_procedure_insertShoeToPresentationShop @shoe INT, @presentationShop INT, @numberOfShoes INT
AS

	DECLARE @pid INT = ( SELECT PresentationShops.pid FROM PresentationShops WHERE PresentationShops.pid = @presentationShop )
	DECLARE @sid INT = ( SELECT Shoes.sid FROM Shoes WHERE Shoes.sid = @shoe )

	IF @pid IS NULL OR @sid IS NULL
	BEGIN
		RAISERROR('No such presentation shop or shoe!',16,1)
		RETURN 1
	END -- end-if

	INSERT INTO ShoePresentations VALUES(@presentationShop,@shoe,@numberOfShoes)
GO

EXEC ud_procedure_insertShoeToPresentationShop 5, 2, 69
GO
-- 3.
CREATE OR ALTER VIEW ud_view
AS
	SELECT Purchases.wid, SUM(Purchases.quantity) AS numberOfPurchasedShoes
	FROM Purchases
	GROUP BY Purchases.wid
	HAVING SUM(Purchases.quantity) >= 2
GO

SELECT * FROM ud_view
GO

-- 4.
CREATE OR ALTER FUNCTION my_function(@number INT)
RETURNS TABLE
RETURN
	SELECT Shoes.sid
	FROM Shoes
	WHERE Shoes.sid IN (  SELECT ShoePresentations.sid
									  FROM ShoePresentations
									  GROUP BY ShoePresentations.sid 
									  HAVING COUNT(*) >= @number )

GO
SELECT * FROM my_function(2)
GO