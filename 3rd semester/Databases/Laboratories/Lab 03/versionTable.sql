USE [Lab01-Pharmacy];

CREATE TABLE Versions( 
	Number INT NOT NULL, 
	do VARCHAR(50),
	undo VARCHAR(50),
	Description VARCHAR(100),
	Current_version INT,
	PRIMARY KEY (Number)
);

INSERT INTO Versions VALUES (0,''                       ,''                          ,'Current version'									   ,1 );
INSERT INTO Versions VALUES (1,' '                      ,' '                         ,'Original database.'								   ,'');
INSERT INTO Versions VALUES (2,'my_addColumn'           ,'my_removeColumn'           ,'Database with the contract column.'                 ,'');
INSERT INTO Versions VALUES (3,'my_alterColumnVarchar'  ,'my_alterColumnInt'         ,'Suppliers.hasContract becomes VARHCAR(30) '         ,'');
INSERT INTO Versions VALUES (4,'my_createTable'         ,'my_dropTable'              ,'Creates Award'                                      ,'');
INSERT INTO Versions Values (5,'my_addConstraint'       ,'my_removeConstraint'       ,'Suppliers constraint'                               ,'');
INSERT INTO Versions VALUES (6,'my_addForeignKey'       ,'my_removeForeignKey'       ,'Set sid from Award table as foreign key.'           ,'');
INSERT INTO Versions VALUES (7,'my_addCandidateKey'     ,'my_removeCandidateKey'     ,'Set name from Award table as candidate key.'        ,'');
INSERT INTO Versions VALUES (8,'my_addDefaultConstraint','my_removeDefaultConstraint','Set default constraint for name in the table Award.','');