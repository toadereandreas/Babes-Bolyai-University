USE [DBMS Lab03 - Grade3]
GO

BEGIN TRAN
UPDATE UpdateConflict SET number = number + 2 WHERE id = 1

WAITFOR DELAY '00:00:05';

COMMIT TRAN