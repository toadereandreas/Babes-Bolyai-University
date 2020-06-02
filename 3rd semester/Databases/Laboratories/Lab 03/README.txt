Extension of assignment 2

Lab 3. Altering the Database - assigned: week 6; due: week 8
Sometimes, after you design a database, you need to change its structure. 
Unfortunately, the changes aren�t correct every time, so they must be reverted. 
Your task is to create a versioning mechanism that allows you to easily move from one version of the database to another.

Write SQL scripts that:

a. modify the type of a column;
b. add / remove a column;
c. add / remove a DEFAULT constraint;
d. add / remove a primary key;
e. add / remove a candidate key;
f. add / remove a foreign key;
g. create / remove a table.

For each of the scripts above, write another one that reverts the operation. 
Create a new table that holds the current version of the database schema. 
For simplicity, the version is assumed to be an integer number.
Place each of the scripts in a stored procedure. 
Use a simple, intuitive naming convention.
Write another stored procedure that receives as a parameter a version number and brings the database to that version.