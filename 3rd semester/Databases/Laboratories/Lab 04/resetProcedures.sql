-- This procedure deletes all the rows from Events, Albums, Singers, TestRuns, TestRunTables and resets identity of TestRuns to 0
CREATE OR ALTER PROCEDURE my_resetRows
AS
	PRINT 'Deleting all rows from Events, Albums & Singers..'
	DECLARE @times INT = 0

	DELETE FROM Events
	DELETE FROM Albums
	DELETE FROM Singers

	INSERT INTO Singers VALUES(1,'DEFAULT','DEFAULT')
	INSERT INTO Albums  VALUES(1,1,'DEFAULT',1)
	INSERT INTO Events VALUES(1,1,1,1,'01/01/2019')

	PRINT 'DONE.'
GO

-- This procedure deletes all the rows from TestRunTables% TestRuns
CREATE OR ALTER PROCEDURE my_resetRuns
AS
	PRINT 'Deleting all rows from TestRunTables & TestRuns..'
	DECLARE @times INT = 0
	
	DELETE FROM TestRuns
	DELETE FROM TestRunTables

	while @times < 3
		BEGIN
			DBCC CHECKIDENT('TestRuns', RESEED, 0 )
			SET @times = @times + 1
		END	

	PRINT CHAR(13)
	PRINT 'DONE.'
	PRINT CHAR(13)
GO

CREATE OR ALTER PROCEDURE my_reset
AS
	EXEC my_resetRows
	EXEC my_resetRuns
GO