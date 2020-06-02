-- Your task is to implement a set of stored procedures for running tests and storing their results. The tests must include at least 3 tables:

-- a) a table with a single column primary key and no foreign keys;
CREATE TABLE Singers(
	sid INT,
	name VARCHAR(30),
	genre VARCHAR(30),
	PRIMARY KEY(sid)
)

-- b) a table with a single column primary key and at least one foreign key;
CREATE TABLE Albums(
	aid INT NOT NULL PRIMARY KEY,
	sid INT NOT NULL FOREIGN KEY REFERENCES Singers(sid),
	name VARCHAR(30),
	nrOfSongs INT
)

-- c) a table with a multicolumn primary key,
CREATE TABLE Events(
	eid INT NOT NULL,
	sid INT NOT NULL REFERENCES Singers(sid),
	aid INT NOT NULL REFERENCES Albums(aid),
	price INT,
	date DATE,
	PRIMARY KEY(eid,sid,aid)
)

-- Add an extra column to compute endTime-startTime
ALTER TABLE TestRuns DROP COLUMN TimeOfExecution
ALTER TABLE TestRunTables DROP COLUMN TimeOfExecution
ALTER TABLE TestRuns ADD TimeOfExecution VARCHAR(30)
ALTER TABLE TestRunTables ADD TimeOfExecution VARCHAR(30)
ALTER TABLE TestRunViews ADD TimeOfExecution VARCHAR(30)