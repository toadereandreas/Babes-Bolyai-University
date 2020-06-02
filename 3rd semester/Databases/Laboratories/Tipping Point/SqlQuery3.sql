CREATE TABLE Runners2(
   RunnerID INT NOT NULL,
   Position INT NOT NULL,
   Description CHAR(8000),
   Trophies CHAR(40)
)

DELETE FROM Runners2

DECLARE @id INT = 1
WHILE @id <= 100000
	BEGIN
		INSERT INTO Runners2 VALUES(@id, @id, 'Default_description', 'Default_trophies')
		SET @id = @id + 1
	END

SET STATISTICS IO ON
SELECT * FROM Runners2

CREATE UNIQUE CLUSTERED INDEX idx_Runners2 ON Runners2(RunnerID)
CREATE UNIQUE NONCLUSTERED INDEX idx_NC_onPosition2_Runners2 ON Runners2(Position)

SELECT * 
FROM Runners2
WHERE Position < 25385

SELECT * 
FROM Runners2
WHERE Position < 25384
