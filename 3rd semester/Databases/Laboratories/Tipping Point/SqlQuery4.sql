CREATE TABLE Runners3(
   RunnerID TINYINT NOT NULL,
   Position TINYINT NOT NULL,
   Age TINYINT
)

SET STATISTICS IO ON
SELECT * FROM Runners3

CREATE CLUSTERED INDEX idx_runners3 ON Runners3(RunnerID)
CREATE NONCLUSTERED INDEX idx_b ON Runners3(Position)

DROP INDEX idx_runners3 ON Runners3
DROP INDEX idx_b ON Runners3

SELECT TOP 5 * 
FROM Runners3
WHERE Position < 1

SELECT * 
FROM Runners3
WHERE Position < 999999


