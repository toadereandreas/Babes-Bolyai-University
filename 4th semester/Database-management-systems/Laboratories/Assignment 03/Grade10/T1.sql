USE [DBMS Lab03 - Grade3]
GO

--ALTER DATABASE [DBMS Lab03 - Grade3] 
--SET ALLOW_SNAPSHOT_ISOLATION ON;

--SET TRANSACTION ISOLATION LEVEL SNAPSHOT;

ALTER DATABASE [DBMS Lab03 - Grade3]  
SET READ_COMMITTED_SNAPSHOT ON WITH NO_WAIT

BEGIN TRAN
SELECT number FROM UpdateConflict WHERE id = 1
WAITFOR DELAY '00:00:10';
UPDATE UpdateConflict SET number = number + 5 WHERE id = 1
SELECT number FROM UpdateConflict WHERE id = 1
COMMIT TRAN