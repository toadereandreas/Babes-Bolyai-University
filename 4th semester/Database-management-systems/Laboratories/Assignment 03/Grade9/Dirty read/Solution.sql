--Solution: iso level=read committed, so we can't read "dirty" anymore
SET TRANSACTION ISOLATION LEVEL READ COMMITTED
BEGIN TRAN
SELECT * FROM ChessTitle
WAITFOR DELAY '00:00:15'
SELECT * FROM ChessTitle
COMMIT TRAN