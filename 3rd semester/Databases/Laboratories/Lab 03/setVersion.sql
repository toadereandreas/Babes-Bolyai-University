USE [Lab01-Pharmacy];

/* ALTERING THE DATABASE
Sometimes, after you design a database, you need to change its structure. Unfortunately, the changes aren’t correct every time, so they must be reverted. 
Your task is to create a versioning mechanism that allows you to easily move from one version of the database to another.
Create a new table that holds the current version of the database schema. For simplicity, the version is assumed to be an integer number.
Place each of the scripts in a stored procedure. Use a simple, intuitive naming convention.
Write another stored procedure that receives as a parameter a version number and brings the database to that version.
*/

CREATE OR ALTER PROCEDURE my_setVersionUpgrade @goToVersion INT
AS
	DECLARE @result VARCHAR(100)
	SET @result = (SELECT Versions.do FROM Versions WHERE Versions.Number = @goToVersion);
	EXEC @result
GO

CREATE OR ALTER PROCEDURE my_setVersionDowngrade @goToVersion INT
AS
	DECLARE @result VARCHAR(100)
	SET @result = (SELECT Versions.undo FROM Versions WHERE Versions.Number = @goToVersion);
	EXEC @result
GO

CREATE OR ALTER PROCEDURE my_setVersion @goToVersion INT
AS
	-- get current version of the database
	DECLARE @currentVersion INT
	SET @currentVersion = (SELECT Versions.Current_version FROM Versions WHERE Versions.Number = 0);

	PRINT 'Current version is ' +  CAST(@currentVersion AS VARCHAR(10)) +'. Setting version to ' + CAST(@goToVersion AS VARCHAR(10)) +'.'

	IF @goToVersion > @currentVersion -- => we have to upgrade 
		BEGIN

			DECLARE @nextVersionUp INT
			SET @nextVersionUp = @currentVersion + 1

			WHILE @nextVersionUp <= @goToVersion
				BEGIN
					PRINT 'UPGRADE'
					EXEC my_setVersionUpgrade @goToVersion = @nextVersionUp
					SET @nextVersionUp = @nextVersionUp + 1
				END -- end-while

			-- update version variable
			UPDATE Versions SET Versions.Current_version = @goToVersion WHERE Versions.Number = 0
		END -- end-if

	IF @goToVersion < @currentVersion -- => we have to downgrade 
		BEGIN

			DECLARE @nextVersionDown INT
			SET @nextVersionDown = @currentVersion

			WHILE @nextVersionDown > @goToVersion
				BEGIN
					PRINT 'DOWNGRADE'
					EXEC my_setVersionDowngrade @goToVersion = @nextVersionDown
					SET @nextVersionDown = @nextVersionDown - 1
				END -- end-while

			-- update version variable
			UPDATE Versions SET Versions.Current_version = @goToVersion WHERE Versions.Number = 0
		END -- end-else

	IF @goToVersion = @currentVersion
	BEGIN
		PRINT 'The database version is already ' + CAST(@currentVersion AS VARCHAR(10)) + '.'
	END -- end-if
GO

EXEC my_setVersion @goToVersion = 8

UPDATE Versions 
SET Versions.Current_version = 5
WHERE Versions.Number = 0