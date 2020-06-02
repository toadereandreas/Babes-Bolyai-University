CREATE OR ALTER PROCEDURE my_runTest6 @tableID INT, @testID INT, @testRunID INT
AS

	--INSERT INTO TestRuns VALUES('
	EXEC my_runTest4 @tableID = 1, @testID = 4, @testRunID = @testRunID
	EXEC my_runTest4 @tableID = 2, @testID = 4, @testRunID = @testRunID

	INSERT INTO TestRunViews VALUES(@testRunID,1,GETDATE(),GETDATE(),null)
	SELECT *
	FROM my_viewSingerAlbums
	UPDATE TestRunViews SET EndAt = GETDATE() WHERE TestRunID = @testRunID
	UPDATE TestRunViews SET TimeOfExecution = dbo.computeDATEDIFF(TestRunViews.StartAt,TestRunViews.EndAt) WHERE TestRunID = @testRunID

	EXEC my_resetRows
GO

EXEC my_test @tableID = 1, @testID = 1