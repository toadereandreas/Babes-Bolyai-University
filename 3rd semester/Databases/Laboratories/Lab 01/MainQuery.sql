CREATE TABLE Addresses(
	aid TINYINT PRIMARY KEY NOT NULL,
	street CHAR(30),
	number TINYINT,
	city CHAR(30),
	county CHAR(30),
	country CHAR(30),
	zip CHAR(6)
)

CREATE TABLE Customers(
	cid TINYINT PRIMARY KEY NOT NULL,
	aid TINYINT FOREIGN KEY REFERENCES Addresses(aid),
	firstName CHAR(35) NOT NULL,
	lastName CHAR(35) NOT NULL,
	phoneNumber CHAR(10)
)

CREATE TABLE Doctors ( 
	did TINYINT PRIMARY KEY NOT NULL,
	aid TINYINT FOREIGN KEY REFERENCES Addresses(aid),
	name CHAR(35) NOT NULL,
	position CHAR(15) NOT NULL,
	salary INT
)
	
CREATE TABLE Managers (
	mid TINYINT PRIMARY KEY NOT NULL,
	did TINYINT FOREIGN KEY REFERENCES Doctors(did) 
)

CREATE TABLE Subordinates(
	sid TINYINT PRIMARY KEY NOT NULL,
	mid TINYINT FOREIGN KEY REFERENCES Managers(mid)
)

CREATE TABLE Supervises(
	mid TINYINT NOT NULL FOREIGN KEY REFERENCES Managers(mid),
	sid TINYINT NOT NULL FOREIGN KEY REFERENCES Subordinates(sid),
	surveyScore INT,
	dateOfSurvey date,
	PRIMARY KEY (mid,sid)
)


CREATE TABLE Prescriptions(
	pid TINYINT NOT NULL,
	did TINYINT NOT NULL FOREIGN KEY REFERENCES Doctors(did),
	cid TINYINT NOT NULL FOREIGN KEY REFERENCES Customers(cid),
	dateOfPrescription DATE,
	PRIMARY KEY(pid,did,cid)
)

CREATE TABLE Suppliers(
	sid TINYINT NOT NULL PRIMARY KEY,
	name CHAR(30)
)

CREATE TABLE Medications(
	mid TINYINT NOT NULL PRIMARY KEY,
	sid TINYINT NOT NULL FOREIGN KEY REFERENCES Suppliers(sid),
	ref CHAR(10),
	name CHAR(10),
	cost INT,
	description CHAR(500)
)

CREATE TABLE Prescribed_Medications(
	pid TINYINT, 
	did TINYINT, 
	cid TINYINT,
	mid TINYINT NOT NULL FOREIGN KEY REFERENCES Medications(mid),
	quantity INT,
	description CHAR(500),
	FOREIGN KEY (pid,did,cid) REFERENCES Prescriptions(pid,did,cid)
)

ALTER TABLE Doctors ADD phoneNumber CHAR(10);