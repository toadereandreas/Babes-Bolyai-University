USE [Lab01-Pharmacy];
/*
Write SQL scripts that:
	a. modify the type of a column;
	b. add / remove a column;
	c. add / remove a DEFAULT constraint;
	d. add / remove a primary key;
	e. add / remove a candidate key;
	f. add / remove a foreign key;
	g. create / remove a table.

For each of the scripts above, write another one that reverts the operation.
*/

-- a) modify the type of a column
CREATE OR ALTER PROCEDURE my_alterColumnVarchar
AS
PRINT 'hasContract column from the table Suppliers becomes varchar.'
ALTER TABLE Suppliers ALTER COLUMN hasContract varchar(30)
GO

CREATE OR ALTER PROCEDURE my_alterColumnInt
AS
PRINT 'hasContract column from the table Suppliers becomes int.'
ALTER TABLE Suppliers ALTER COLUMN hasContract INT
GO

-- b) add / remove a column
CREATE OR ALTER PROCEDURE my_addColumn
AS
PRINT 'Add column hasContract to the table Suppliers.'
ALTER TABLE Suppliers ADD hasContract INT;
GO

CREATE OR ALTER PROCEDURE my_removeColumn
AS
PRINT 'Delete column hasContract from the table Suppliers.'
ALTER TABLE Suppliers DROP COLUMN hasContract;
GO

-- d) add / remove a primary key;
CREATE OR ALTER PROCEDURE my_addConstraint
AS
PRINT 'Change table Suppliers constraint from (sid) to (sid,Name).'
ALTER TABLE Awards DROP CONSTRAINT aid_PK
ALTER TABLE Awards ADD  CONSTRAINT new_PK PRIMARY KEY (aid,name)
GO

CREATE OR ALTER PROCEDURE my_removeConstraint
AS
PRINT 'Change table Suppliers constraint from (sid,Name) to (sid).'
ALTER TABLE Awards DROP CONSTRAINT new_PK
ALTER TABLE Awards ADD  CONSTRAINT aid_PK PRIMARY KEY (aid)
GO

-- g) create / remove a table.
CREATE OR ALTER PROCEDURE my_createTable
AS
PRINT 'Creates the table Awards with primary key aid.'
CREATE TABLE Awards ( 
	aid INT NOT NULL,
	name VARCHAR(50) NOT NULL,
	prize INT NOT NULL,
	sid TINYINT ,
	CONSTRAINT aid_PK PRIMARY KEY (aid),
)
GO

CREATE OR ALTER PROCEDURE my_dropTable
AS
PRINT 'Drops the table Awards.'
DROP TABLE Awards
GO

-- f) add / remove a foreign key;
CREATE OR ALTER PROCEDURE my_addForeignKey
AS
PRINT 'In the table Awards, set sid as foreign key.'
ALTER TABLE Awards ADD CONSTRAINT sid_FK FOREIGN KEY (sid) REFERENCES Suppliers(sid) 
GO

CREATE OR ALTER PROCEDURE my_removeForeignKey
AS
PRINT 'In the table Awards, remove foreign key sid.'
ALTER TABLE Awards DROP CONSTRAINT sid_FK
GO

-- e) add / remove a candidate key;
CREATE OR ALTER PROCEDURE my_addCandidateKey
AS
PRINT 'In the table Awards, set name as candidate key.'
ALTER TABLE Awards ADD CONSTRAINT name_UC UNIQUE (name)
GO

CREATE OR ALTER PROCEDURE my_removeCandidateKey
AS
PRINT 'In the table Awards, remove name as candidate key.'
ALTER TABLE Awards DROP CONSTRAINT name_UC
GO

-- c) add / remove a DEFAULT constraint
CREATE OR ALTER PROCEDURE my_addDefaultConstraint
AS
PRINT 'In the table Awards, add default constraint for prize.'
ALTER TABLE Awards ADD CONSTRAINT prize_DC DEFAULT 0 FOR prize
GO

CREATE OR ALTER PROCEDURE my_removeDefaultConstraint
AS
PRINT 'In the table Awards, remove default constraint for prize.'
ALTER TABLE Awards DROP CONSTRAINT prize_DC
GO