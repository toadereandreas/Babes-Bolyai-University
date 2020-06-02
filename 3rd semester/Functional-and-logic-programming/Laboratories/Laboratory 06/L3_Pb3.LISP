; Solve the following problems using MAP functions

;3. Define a function to tests the membership of a node in a n-tree represented as (root
;   list_of_nodes_subtree1 ... list_of_nodes_subtreen)
;   eg: tree is (a (b (c)) (d) (E (f))) and the node is "b" => true

;   (CHECK-NODE '(A (B (C)) (D) (E(F))) 'F)

; The predicate CHECK-NODE checks whether the given node is in the given n-tree
; CHECK-NODE(LIST - a n-tree, NODE - a node)
; flow model CHECK-NODE(i,i), output: 0 if NODE is not in LIST
;                                     != 0 if NODE is in LIST
; CHECK-NODE(l1..ln,node)={ 0, if l1 = []
;                         { 1, if l1 = node
;                         { SUM(CHECK-NODE(li,node)) i = 2,n, otherwise

(DEFUN CHECK-NODE (LIST NODE)
   (COND 
    ( (NULL (CAR LIST)) 0)
    ( (EQUAL (CAR LIST) NODE) 1)
    (  T (APPLY #'+ (MAPCAR #'(LAMBDA (A) (CHECK-NODE A NODE )) (CDR LIST))  ))
   )
)
