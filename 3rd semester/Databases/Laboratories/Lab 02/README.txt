Extension of Assignment 1

Lab 2. SQL Queries - assigned: week 3; due: week 6
On the relational structure created for the first lab, write SQL statements that:
	- insert data � for at least 4 tables; at least one statement should violate referential integrity constraints;
	- update data � for at least 3 tables;
	- delete data � for at least 2 tables.

In the UPDATE / DELETE statements, use at least once: {AND, OR, NOT},  {<,<=,=,>,>=,<> }, IS [NOT] NULL, IN, BETWEEN, LIKE.

On the same database, write the following SELECT queries:

a. 2 queries with the union operation; use UNION [ALL] and OR;

b. 2 queries with the intersection operation; use INTERSECT and IN;

c. 2 queries with the difference operation; use EXCEPT and NOT IN;

d. 4 queries with INNER JOIN, LEFT JOIN, RIGHT JOIN, and FULL JOIN; one query will join at least 3 tables, while another one will join at least two many-to-many relationships;

e. 2 queries using the IN operator to introduce a subquery in the WHERE clause; in at least one query, the subquery should include a subquery in its own WHERE clause;

f. 2 queries using the EXISTS operator to introduce a subquery in the WHERE clause;

g. 2 queries with a subquery in the FROM clause;                             

h. 4 queries with the GROUP BY clause, 3 of which also contain the HAVING clause; 2 of the latter will also have a subquery in the HAVING clause; use the aggregation operators: COUNT, SUM, AVG, MIN, MAX;

i. 4 queries using ANY and ALL to introduce a subquery in the WHERE clause; 2 of them should be rewritten with aggregation operators, while the other 2 should also be expressed with [NOT] IN.

You need to use:
	- arithmetic expressions in the SELECT clause in at least 3 queries;
	- conditions with AND, OR, NOT, and parentheses in the WHERE clause in at least 3 queries;
	- DISTINCT in at least 3 queries, ORDER BY in at least 2 queries, and TOP in at least 2 queries.