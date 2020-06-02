-- This procedure executes the given test on the given table
CREATE OR ALTER PROCEDURE my_test @tableID TINYINT, @testID TINYINT
AS
	DECLARE @tableName VARCHAR(10) = (SELECT Tables.Name FROM Tables WHERE Tables.TableID = @tableID)
	DECLARE @testName  VARCHAR(30) = (SELECT Tests.Name  FROM Tests  WHERE Tests.TestID   = @testID )

	PRINT 'Running ' + @testName + '..'

	-- Now "log" the test that will run: set StartAt to current datetime, EndAt is null, TimeOfExecution is null
	INSERT INTO TestRuns VALUES('Results for ' + @testName + ' on table ' + @tableName, GETDATE(), null, null)
	
	-- Determine the id for the test which will run
	DECLARE @currentTestRun INT = (SELECT MAX(TestRuns.TestRunID) FROM TestRuns)

	-- Determine which procedure to execute
	DECLARE @procedureName VARCHAR(12) = 'my_runTest' + CAST(@testID AS VARCHAR(1))

	-- Execute procedure coresponding to the given testID
	EXEC @procedureName @tableID = @tableID, @testID = @testID, @testRunID = @currentTestRun

	-- The test finished: now we update the "log": set EndAt to current datetime
	UPDATE TestRuns SET EndAt = GETDATE() WHERE TestRunID = @currentTestRun

	-- Store the StartAt and EndAt in variables
	DECLARE @start DATETIME = (SELECT TestRuns.StartAt FROM TestRuns WHERE TestRuns.TestRunID = @currentTestRun)
	DECLARE @end   DATETIME = (SELECT TestRuns.EndAt   FROM TestRuns WHERE TestRuns.TestRunID = @currentTestRun)

	-- Determine the time of the execution as SS:MS
	DECLARE @TimeOfExecutionChar VARCHAR(6) = (SELECT dbo.computeDATEDIFF(@start,@end))

	-- Update the TimeOfExecution
	UPDATE TestRuns SET TimeOfExecution = @TimeOfExecutionChar WHERE TestRunID = @currentTestRun

	IF @testID = 1 OR @testID = 2 OR @testID = 3 OR @testID = 4
	BEGIN
		-- Now we "log" again the test run
		INSERT TestRunTables VALUES (@currentTestRun,@tableID,@start,@end,@TimeOfExecutionChar)
	END

	EXEC my_resetRows
GO

-- This procedure runs the test with the given id on all compatible tables
CREATE OR ALTER PROCEDURE my_testAllTables @testID INT
AS
	DECLARE @tableID INT = 1
	WHILE @tableID <= ( SELECT MAX(Tables.TableID) FROM Tables )
		BEGIN
			IF NOT EXISTS ( SELECT * FROM Tables WHERE TableID = @tableID )
				BEGIN
					PRINT 'Test ' + CAST(@testID AS VARCHAR(2)) + ' is not compatible with the table for id = ' + CAST(@tableID AS VARCHAR(2)) + '.' 
				END -- end-if
			ELSE
				BEGIN
					EXEC my_test @tableID = @tableID, @testID = @testID
				END -- end-else
			SET @tableID = @tableID + 1
		END --- end-while
GO

-- This procedure runs all the tests
CREATE OR ALTER PROCEDURE my_testALL
AS
	DECLARE @testID INT = 1
	WHILE @testID <= ( SELECT MAX(Tests.TestID) FROM Tests )
		BEGIN
			EXEC my_testAllTables @testID = @testID
			SET @testID = @testID + 1
		END -- end-while
GO


-- This function computes the difference of two datetimes and return it as a string with format SS:MS
-- input : @start - DATETIME, @end DATETIME
-- output: @TimeOfExecutionChar - VARCHAR(10)
CREATE OR ALTER FUNCTION computeDATEDIFF (@start DATETIME, @end DATETIME)
RETURNS VARCHAR(10)
BEGIN
	DECLARE @TimeOfExecution INT = DATEDIFF(ms, @start, @end)
	DECLARE @secOfExe INT = @TimeOfExecution / 1000
	DECLARE @msOfExe  INT = @TimeOfExecution % 1000
	DECLARE @TimeOfExecutionChar VARCHAR(7) = CAST(@secOfExe AS VARCHAR(3)) + ':' + CAST(@msOfExe AS VARCHAR(3))
	RETURN @TimeOfExecutionChar
END
GO

-- This function calculates the average time of execution for each test
CREATE OR ALTER PROCEDURE my_calculateAverage
AS
	SELECT TestRuns.Description, AVG(DATEDIFF(ms,TestRuns.StartAt,TestRuns.EndAt)) AS AverageTimeInMS, MIN(DATEDIFF(ms,TestRuns.StartAt,TestRuns.EndAt)) AS MinimumTime, MAX(DATEDIFF(ms,TestRuns.StartAt,TestRuns.EndAt)) MaximumTime
	FROM TestRuns
	INNER JOIN TestRunTables
	ON TestRuns.TestRunID = TestRunTables.TestRunID
	GROUP BY TestRuns.Description
GO

EXEC my_test @tableID = 1, @testID = 1