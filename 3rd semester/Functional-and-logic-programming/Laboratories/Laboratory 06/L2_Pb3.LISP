; Write recursive Lisp functions for the following problems (optionally, you may use MAP functions):
; A binary tree is memorised in the following two ways:
;   (node no-subtrees list-subtree-1 list-subtree-2 ...) (1)
;   (node (list-subtree-1) (list-subtree-2) ...) (2)
; As an example, the tree:
;      A
;    /   \
;   B     C
;  / \
; D   E
; is represented as follows:
; (A 2 B 0 C 2 D 0 E 0)  (1)
; (A (B) (C (D) (E)))    (2)

;3. Return the number of levels of a tree of type (1).

; The predicate determines the depth of a tree
; DEPTH-REC(tree - a list determing a tree)
; Flow model DEPTH-REC(i), output: an integer
; DEPTH-REC(tree) = { depth, tree = []
;                   { 1 + depth, n = 0
;                   { depth-rec-aux(1+depth), n = 1
;                   { max(depth-rec-aux(1+depth),depth-rec-aux(1+depth)), n = 2
(DEFUN DEPTH-REC (TREE)
  (LABELS ((DEPTH-REC-AUX (DEPTH)             ; self-recursive function
             (IF (NULL TREE) DEPTH            ; if no more nodes  -> return the current depth
               (LET ((N (SECOND TREE)))       ; else, n = number of subnodes
                 (POP TREE) (POP TREE)        ; remove the current node 
                 (CASE N
                   (0 (1+ DEPTH))                     ; no subnode   (n=0),  1+depth
                   (1 (DEPTH-REC-AUX (1+ DEPTH)))     ; one subnode  (n=1), its depth+1
                   (2 (MAX (DEPTH-REC-AUX (1+ DEPTH)) (depth-rec-aux (1+ depth))))
                 );end-case
               );end-let
             );end-if
            )
           );end-label
    (DEPTH-REC-AUX 0) ; start depth is 0
  )
)                     
