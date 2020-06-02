CREATE TABLE Runners(
   RunnerID INT NOT NULL,
   Position INT NOT NULL,
   Description CHAR(92),
)

-- Populate table with 100000 records
DECLARE @id INT = 1
WHILE @id <= 100000
	BEGIN
		INSERT INTO Runners VALUES(@id, @id,'DESCRIPTION')
		SET @id = @id + 1
	END
-- A record is 100 bytes long (aprox)
-- A page has 8kb
--	   => A page will contain 80 records ( aprox )
--     => 80 000 records / 80 records/page = 1000 pages ( aprox )

-- We confirm that by selecting all the rows in the table
SELECT *
FROM Runners

-- We create the indexes that we will work with
CREATE UNIQUE CLUSTERED INDEX idx_Students ON Runners(RunnerID)

CREATE UNIQUE NONCLUSTERED INDEX idx_NC_Number ON Runners(Position)

-- To see how many logical reads are performed
SET STATISTICS IO ON

SELECT * FROM Runners 
WHERE Position <407

SELECT * FROM Runners 
WHERE Position < 406