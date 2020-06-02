Lab 4. Testing the Database - assigned: week 8; due: week 11
After you finished designing your database, the development team is interested in assessing the performance of your design. 
To record different test configurations and results, you create the following relational structure:

Tests � holds data about different test configurations;
Tables � holds data about tables that might take part in a test;
TestTables � link table between Tests and Tables (which tables take part in which tests);
Views � holds data about a set of views from the database, used to assess the performance of certain select queries;
TestViews � link table between Tests and Views (which views take part in which tests);
TestRuns � contains data about different test runs; each test run involves:

deleting data from tables (all tables associated with the test) � in the order specified by the Position field (table TestTables);
inserting data into tables � reverse deletion order; the number of records to insert is stored in the NoOfRows field (table TestTables);
evaluating views;
TestRunTables � contains performance data for all the tables affected by insert operations;
TestRunViews � contains performance data for every view in every test.

Your task is to implement a set of stored procedures for running tests and storing their results. The tests must include at least 3 tables:
	- a table with a single column primary key and no foreign keys;
	- a table with a single column primary key and at least one foreign key;
	- a table with a multicolumn primary key,
and 3 views:
	- a view with a SELECT statement operating on one table;
	- a view with a SELECT statement operating on at least 2 tables;
	- a view with a SELECT statement that has a GROUP BY clause and operates on at least 2 tables.
Obs. The way you implement the stored procedures and / or functions is up to you. 

Results which allow the system to be extended to new tables / views with minimal or no code at all will be more appreciated. 
The script for creating the above relational structure can be downloaded here: Script_lab4.