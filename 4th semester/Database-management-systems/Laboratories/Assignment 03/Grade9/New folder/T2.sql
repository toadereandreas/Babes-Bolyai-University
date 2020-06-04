-- phantom problem T2 - initial iso level set to repeatable read
-- in the second select we will see the "phantom", i.e. the record which shouldn't be there
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ
BEGIN TRAN
SELECT * FROM ChessTitle
WAITFOR DELAY '00:00:05'
SELECT * FROM ChessTitle
COMMIT TRAN