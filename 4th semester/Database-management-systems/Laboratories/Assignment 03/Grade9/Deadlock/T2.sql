-- the two updates will cause the deadlock with the ones in T1
BEGIN TRAN 
UPDATE ChessClub SET club_name='The Queens trans 2' WHERE cid=1
WAITFOR DELAY '00:00:10'
UPDATE ChessTitle SET title_name='GM trans 2' WHERE tid=1
COMMIT TRAN

--CREATE Table ChessClub(
--	cid INT,
--	club_name VARCHAR(30)
--)
--insert into ChessClub VALUES (1,'ALABALA')