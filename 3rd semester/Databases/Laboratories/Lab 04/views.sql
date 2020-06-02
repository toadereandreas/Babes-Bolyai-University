CREATE OR ALTER VIEW my_viewAllSingers
AS
	SELECT *
	FROM Singers
GO

CREATE OR ALTER VIEW my_viewAllAlbums
AS
	SELECT *
	FROM Albums
GO

CREATE OR ALTER VIEW my_viewAllEvents
AS
	SELECT *
	FROM Events
GO

CREATE OR ALTER VIEW my_viewSingerAlbums
AS
	SELECT Singers.name AS SingerName, Albums.name AS AlbumName
	FROM Singers
	INNER JOIN Albums
	ON Albums.sid = Singers.sid
GO

CREATE OR ALTER VIEW my_viewGroupBy
AS
	SELECT AVG(Events.price) AS AveragePrice, Singers.name
	FROM Singers
	INNER JOIN Events
	ON Singers.sid = Events.sid
	GROUP BY Singers.name
GO

SELECT *
FROM my_viewGroupBy