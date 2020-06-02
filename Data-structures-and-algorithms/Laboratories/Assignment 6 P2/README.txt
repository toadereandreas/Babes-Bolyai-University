Lab 6: Hashtable
Implement in C++ the given container (ADT) using a given representation and a hashtable with a given collision resolution (separate chaining, coalesced chaining, open addressing) as a data structure. You are not allowed to use any container or data structure from STL or from any other library.
Do not implement a separate class for the hashtable (or dynamic array, or anything), implement the container directly!
The hashtable has to be dynamic: no matter what collision resolution has to be used, set a threshold for α and resize and rehash the table when the actual load factor is higher than α.
 
2. ADT Matrix – represented as a sparse matrix where <line, column, value> triples (value ≠ 0) are memorized, ordered lexicographically considering the line and column of every element. The elements are stored in a hashtable with coalesced chaining.