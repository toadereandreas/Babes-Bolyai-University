assigned: weeks 7/8; due: weeks 11/12
Prepare the following use case scenarios for your database:

create a stored procedure that inserts data in tables that are in a m:n relationship; if one insert fails, all the operations performed by the procedure must be rolled back (grade 3);
create a stored procedure that inserts data in tables that are in a m:n relationship; if an insert fails, try to recover as much as possible from the entire operation: for example, if the user wants to add a book and its authors, succeeds creating the authors, but fails with the book, the authors should remain in the database (grade 5);
create 4 scenarios that reproduce the following concurrency issues under pessimistic isolation levels: dirty reads, non-repeatable reads, phantom reads, and a deadlock; you can use stored procedures and / or stand-alone queries; find solutions to solve / workaround the concurrency issues (grade 9);
create a scenario that reproduces the update conflict under an optimistic isolation level (grade 10).
Obs.

* Prepare test cases covering both the happy scenarios and the ones with errors (this applies to stored procedures). Be prepared to explain all your scenarios and implementations.

* Don’t use IDs as input parameters for your stored procedures. Validate all parameters (try to use functions when needed).

* Setup a logging system to track executed actions for all scenarios.

It’s recommended to use TRY…CATCH to handle errors.