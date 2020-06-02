Lab 1: Dynamic Array
Implement in C++ the given container (ADT) using a given representation and a dynamic array as a data structure. You are not allowed to use the vector from STL or from any other library.
Obs:
- Since your implementation will use dynamic allocation, it is a good practice to implement a destructor, copy constructor and assignment operator as well (even if they are not on the interface).
- You are allowed to use the function memcpy and realloc, but you should know that it is not safe to use memcpy and realloc on memory that was allocated with new. Also, if the memory location contains objects, undefined behavior can occur. You implementation might still work with these functions, but it is not a good practice to use them.

12. ADT Set – represented as a dynamic array of Boolean values.