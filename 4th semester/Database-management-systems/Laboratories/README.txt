Assignment 1: 
assigned: weeks 1/2; due: weeks 5/6
Create a C# Windows Forms application that uses ADO.NET to interact with the database you developed in the 1st semester. The application must contain a form allowing the user to manipulate data in 2 tables that are in a 1:n relationship (parent table and child table). The application must provide the following functionalities:
– display all the records in the parent table;
– display the child records for a specific (i.e., selected) parent record;
– add / remove / update child records for a specific parent record.

You must use the DataSet and SqlDataAdapter classes. You are free to use any controls on the form.
Obs. If you don’t have a database from the previous semester, imagine a simple application that requires a database. Represent the application data in a relational structure and implement the structure in a SQL Server database. The database must contain at least: 10 tables, two 1:n relationships, one m:n relationship.

Assignment 2:
assigned: weeks 5/6; due: weeks 7/8
Transform your first lab to dynamically create the master-detail windows form. The form caption, stored procedures / queries used to access and manipulate data will be set in a configuration file.
You must prepare at least two different scenarios handling data from two different 1:n relationships.
The form should be generic enough such that switching between scenarios (i.e., updating the application to handle data from another 1:n relationship) comes down to updating the configuration file.
How you define and interpret the configuration file is entirely up to you.
You must use core ADO.NET (data sets, data adapters, data readers, etc). Solutions using LINQ, Entity Framework, or any other ORM framework are not accepted.

assigned: weeks 7/8; due: weeks 13/14
Prepare the following use case scenarios for your database:
create a stored procedure that inserts data in tables that are in a m:n relationship; if one insert fails, all the operations performed by the procedure must be rolled back (grade 3);
create a stored procedure that inserts data in tables that are in a m:n relationship; if an insert fails, try to recover as much as possible from the entire operation: for example, if the user wants to add a book and its authors, succeeds creating the authors, but fails with the book, the authors should remain in the database (grade 5);
create 4 scenarios that reproduce the following concurrency issues under pessimistic isolation levels: dirty reads, non-repeatable reads, phantom reads, and a deadlock; you can use stored procedures and / or stand-alone queries; find solutions to solve / workaround the concurrency issues (grade 9);
create a scenario that reproduces the update conflict under an optimistic isolation level (grade 10).