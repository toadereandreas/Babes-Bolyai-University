Lab 5. Indexes - assigned: week 11; due: week 12
Work on 3 tables of the form Ta(aid, a2, …), Tb(bid, b2, …), Tc(cid, aid, bid, …), where:
	- aid, bid, cid, a2, b2 are integers;
	- the primary keys are underlined;
	- a2 is UNIQUE in Ta;
	- aid and bid are foreign keys in Tc, referencing the corresponding primary keys in Ta and Tb, respectively.

a. Write queries on Ta such that their execution plans contain the following operators:
	- clustered index scan;
	- clustered index seek;
	- nonclustered index scan;
	- nonclustered index seek;
	- key lookup.

b. Write a query on table Tb with a WHERE clause of the form WHERE b2 = value and analyze its execution plan. 
Create a nonclustered index that can speed up the query. 
Recheck the query’s execution plan (operators, SELECT’s estimated subtree cost).

c. Create a view that joins at least 2 tables. 
Check whether existing indexes are helpful; if not, reassess existing indexes / examine the cardinality of the tables.