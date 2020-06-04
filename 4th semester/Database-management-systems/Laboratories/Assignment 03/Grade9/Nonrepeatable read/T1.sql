-- T1 nonrepeatable reads 
-- just update a field
USE [DBMS Lab03 - Grade3]
GO

UPDATE ChessTitle SET title_name='ABC' WHERE tid=4
BEGIN TRAN
WAITFOR DELAY '00:00:07'
UPDATE ChessTitle SET title_name='Pro' WHERE tid=4
COMMIT TRAN

--INSERT INTO ChessTitle(tid, title_name) VALUES (4, 'Casual')
--select * from ChessTitle
--DELETE FROM ChessTitle WHERE tid=4