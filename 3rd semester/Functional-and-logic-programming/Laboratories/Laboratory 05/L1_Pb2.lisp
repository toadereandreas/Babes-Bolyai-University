;a) Write a function to return the product of two vectors.

; Solution 1
; The predicate DOTPRODUCT determines the dot product of two given vectors
; DOTPRODUCT(LIST1 - a list, LIST2 - a list)
; Flow model: DOTPRODUCT(i,i), output: an integer
(DEFUN DOTPRODUCT (LIST1 LIST2) (APPLY '+ (MAPCAR '* LIST1 LIST2)))

; Solution 2
; The predicate DOTPRD determines the dot product of the two given vectors
; DOTPRD(LIST1 - a list, LIST2 - a list)
; Flow model: DOTPROD(i,i), output: a number
; DOTPRD([l1..ln],[L1..LN]) = { 0, l = [] or L = [] although we reach the end simoultaneously
;                             { l1*L1 + DOTPRD([l2..ln],[L2..LN]), otherwise
(DEFUN DOTPRD (LIST1 LIST2)
  (COND
   ((NULL LIST1) 0)
   ((NULL LIST2) 0)
   ( T (+ (* (CAR LIST1) (CAR LIST2)) (DOTPRD (CDR LIST1) (CDR LIST2))))
  )
)

;b) Write a function to return the depth of a list
; example: the depth of a linear list is 1
;
; The predicate DEPTH determines the depth of the given list.
; DEPTH(LIST - a list)
; Flow model: DEPTH(i)
; depth([l1..ln]) = { 1 + max(depth(l1),depth(l2),..,depth(ln)), l1 is list
;                   { 0, list is not a list
(DEFUN DEPTH (LIST)
  ( IF (LISTP LIST) (+ 1 (REDUCE #'MAX (MAPCAR #'DEPTH LIST)))
                     0
  )
)

;c) Write a function to sort a linear list without keeping the double values.

; The predicate MYMEMBER check whether the given atom a exists in given list LAT.
; MYMEMBER(A - an atom, LAT - a list )
; Flow model: MYMEMBER(i,i), output: T or NIL
; MYMEMBER(a,(l1..ln)) = { NIL, LAT = NIL
;                        {   T, a = l1
;                        {MYMEMBER(a,(l2..ln)), otherwise
(DEFUN MYMEMBER (A LAT)
  (COND
   ((NULL LAT)   NIL)
   ((EQ A (CAR LAT))   T)
   ( T (MYMEMBER A (CDR LAT))) 
  ) 
)

; The prdicate eliminateDuplicates removes the duplicates from a list
; eliminateDuplicates(L - a list of numbers)
; Flow model: eliminateDuplicates(i), output: a list
; eliminateDuplicates = { [], L = []
;                       { eliminateDuplicates([l2..ln]), l1 in (l2..ln)
;                       { cons(l1,eliminateDuplicates(l2..ln), otherwise
(DEFUN ELIMINATEDUPLICATES (LIST)
  (COND 
     ((NULL LIST) LIST)
     ((MYMEMBER (CAR LIST) (CDR LIST)) (ELIMINATEDUPLICATES (CDR LIST)))
     (T (CONS (CAR LIST) (ELIMINATEDUPLICATES (CDR LIST))))
  )
)

; The predicate REMSORT sorts a linear list without keeping the repeating values.
; REMSORT(LIST - a list)
; Flow model: REMSORT(i), output: an integer
(DEFUN REMSORT(LIST) (SORT (ELIMINATEDUPLICATES LIST) #'<))

;d) Write a function to return the intersection of two sets.

; Solution 1:
; The predicate INTERSET determines the intersection of two sets.
; INTERSET(LIST1 - a list, LIST2 - a list)
; Flow model: INTERSET(i,i), outut: a list
(DEFUN INTERSET(LIST1 LIST2) (INTERSECTION LIST1 LIST2))

; Solution 2:
; The predicate PRESENTP checks whether the given atom a exists in the given list l
; PRESENTP(a - an atom, l - a list)
; Flow model: PRESENTP(i,i), output: T or NIL
; PRESENTP(a,(l1..ln)) = { NIL, l = []
;                        {   T, l1 is atom & l1 = a
;                        { PRESENTP(a,l1), l1 is not atom
;                        { PRESENTP(a,(l2..ln)), otherwise
(DEFUN PRESENTP (A LIST)
  (COND ((NULL LIST) NIL)
        ((AND (ATOM(CAR LIST)) (EQUAL A (CAR LIST))) T)
        ((NOT (ATOM(CAR LIST))) (PRESENTP A (CAR LIST)))
        (T (PRESENTP A (CDR LIST)))))

; The predicate REMOVEFIRST removes the first occurence of the given atom a from the given list LIST
; REMOVEFIRST(A - an atom, LIST - a list)
; Flow model: REMOVEFIRST(i,i), output: LIST \ {A} or NIL
; REMOVEFIRST(A, (l1..ln)) = { NIL, LIST = []
;                            { (l2..ln), A = l1
;                            { l1 U REMOVEFIRST(A,(l2..ln)), otherwise
(DEFUN REMOVEFIRST(A LIST)
  (COND
   ((NULL LIST) NIL)
   ((EQ A (CAR LIST)) (CDR LIST))
   ( T (CONS (CAR LIST) (REMOVEFIRST A (CDR LIST))))
  )
)

; The predicate MYINTERSECTION intersects the given sets.
; MYINTERSECTION(SET1 - a set, SET2 - a set)
; Flow model(i,i), output: a set or NIL
; MYINTERSECTION((l1..ln),(L1..LN)) = { NIL, a = b = []
;                                     { l1 U MYINTERSECTION((l2..ln),REMOVEFIRST(l1,SET2)), PRESENTP(l1,(L1..LN)) is true
;                                     { MYINTERSECTION((l2..ln),(L1..LN)), otherwise
(DEFUN MYINTERSECTION (SET1 SET2)
  (COND ((NOT (AND SET1 SET2)) NIL)
        ((PRESENTP (CAR SET1) SET2) (CONS (CAR SET1) (MYINTERSECTION (CDR SET1) (REMOVEFIRST (CAR SET1) SET2))))
        (T (MYINTERSECTION (CDR SET1) SET2))
  )
)
