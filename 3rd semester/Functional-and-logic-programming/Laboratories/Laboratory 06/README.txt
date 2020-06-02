Laboratory 05:
Write recursive Lisp functions for the following problems (optionally, you may use MAP functions):
A binary tree is memorised in the following two ways:
(node no-subtrees list-subtree-1 list-subtree-2 ...) (1)
(node (list-subtree-1) (list-subtree-2) ...) (2)
As an example, the tree
	A   
       / \
      B   C
     / \
    D   E
is represented as follows:
	(A 2 B 0 C 2 D 0 E 0) (1)
	(A (B) (C (D) (E))) (2)

2. Return the list of nodes on the k-th level of a tree of type (1).

Laboratory 06:
3. Define a function to tests the membership of a node in a n-tree represented as (root list_of_nodes_subtree1 ... list_of_nodes_subtreen)
Eg. tree is (a (b (c)) (d) (E (f))) and the node is "b" => true