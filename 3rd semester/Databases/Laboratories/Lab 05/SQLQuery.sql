-- Work on 3 tables of the form Ta(aid, a2, …), Tb(bid, b2, …), Tc(cid, aid, bid, …), where:
--	- aid, bid, cid, a2, b2 are integers;
--	- the primary keys are underlined;
--	- a2 is UNIQUE in Ta;
--	- aid and bid are foreign keys in Tc, referencing the corresponding primary keys in Ta and Tb, respectively.

CREATE TABLE Singers(
	sid INT PRIMARY KEY NOT NULL,
	MTVranking INT UNIQUE NOT NULL,
	name CHAR(20)
)

CREATE TABLE Arenas(
	aid INT PRIMARY KEY NOT NULL,
	capacity INT NOT NULL,
	address CHAR(100)
)

CREATE TABLE Events(
	eid INT PRIMARY KEY NOT NULL,
	sid INT FOREIGN KEY REFERENCES Singers(sid) NOT NULL,
	aid INT FOREIGN KEY REFERENCES Arenas(aid) NOT NULL,
	price INT
)

-- a) Write queries on Ta such that their execution plans contain the following operators:
--	clustered index scan;
SELECT *
FROM Singers

--	clustered index seek;
SELECT *
FROM Singers
WHERE Singers.sid = 3

--	nonclustered index scan;
SELECT Singers.MTVranking
FROM Singers

--	nonclustered index seek;
SELECT Singers.MTVranking
FROM Singers
WHERE Singers.MTVranking > 3

--	key lookup.
SELECT *
FROM Singers
WHERE Singers.MTVranking = 4

-- b) Write a query on table Tb with a WHERE clause of the form WHERE b2 = value and analyze its execution plan.
-- Create a nonclustered index that can speed up the query. 
-- Recheck the query’s execution plan (operators, SELECT’s estimated subtree cost).

SELECT Arenas.capacity
FROM Arenas
WHERE Arenas.capacity > 23000

-- initially => clustered index scan with estimated subtree cost 0,0032968
CREATE NONCLUSTERED INDEX idx_nc_Arenas_capacity ON Arenas(capacity)
-- after creating index => nonclustered index seek with estimated subtree cost 0,0032842 
DROP INDEX idx_nc_Arenas_capacity ON Arenas

-- c) Create a view that joins at least 2 tables. 
-- Check whether existing indexes are helpful; if not, reassess existing indexes / examine the cardinality of the tables.
GO
CREATE OR ALTER VIEW my_view
AS
	SELECT Singers.name, Events.eid
	FROM Singers
	RIGHT JOIN Events 
	ON Singers.sid = Events.sid
GO

SELECT *
FROM my_view

DROP INDEX idx_nc_Events_sid ON Events
-- DROP INDEX idx_nc_Singers_sid ON Singers
-- DROP INDEX idx_nc_Singers_name ON Singers

CREATE NONCLUSTERED INDEX idx_nc_Events_sid ON Events(sid)
-- CREATE NONCLUSTERED INDEX idx_nc_Singers_sid ON Singers(sid)
-- CREATE NONCLUSTERED INDEX idx_nc_Singers_name ON Singers(name)
