CREATE TABLE Students(
   StudentID INT NOT NULL,
   StudentName CHAR(100) NOT NULL,
   StudentAddress CHAR(100) NOT NULL,
   Record CHAR(185) NOT NULL,
   Number INT NOT NULL
)

-- Populate table with 80000 records
DECLARE @id INT = 1
WHILE @id <= 80000
	BEGIN
		INSERT INTO Students VALUES(@id,'Default_name', 'Default_Address', 'Default_Record', @id)
		SET @id = @id + 1
	END
-- A record is 400 bytes long
-- A page has 8kb
--	   => A page will contain 20 records ( aprox )
--     => 80 000 records / 20 regords/page = 4000 pages ( aprox )

-- We confirm that by selecting all the rows in the table
SELECT *
FROM Students
-- IO Statistics: Table 'Students'. Scan count 1, logical reads 4016...

-- We create the indexes that we will work with
CREATE UNIQUE CLUSTERED INDEX idx_Students ON Students(StudentID)

CREATE UNIQUE NONCLUSTERED INDEX idx_NC_Number ON Students(Number)

-- We check that the indexes have been created
SELECT object_id, name, type_desc, index_id 
FROM sys.indexes 
WHERE name = 'idx_Students' OR name = 'idx_NC_Number'

-- To see how many logical reads are performed
SET STATISTICS IO ON

SELECT * FROM Students 
WHERE Number < 1064

SELECT * FROM Students
WHERE Number < 1063


PRINT 'SCAN:'
SET STATISTICS TIME ON
SELECT * FROM Students 
WHERE Number < 1064
SET STATISTICS TIME OFF

PRINT 'SEEK:'
SET STATISTICS TIME ON
SELECT * FROM Students
WHERE Number < 1063
SET STATISTICS TIME OFF