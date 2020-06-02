; Sau: Cerinta minimala pentru 5: Stergerea unui element E dintr-o lista L.

; mathematical model deletea(l1..ln,a) = { (), l is null
;                                        { deletea(l2..ln), l1 = a
;                                        { l1 U deletea(l2..ln), otherwise
; deletea(A - an atom, L - a list)
; deletea(i,i) - output is a list
(defun deletea (A L)
   (cond
      ((null L) ())
      ((EQ (car L) A) (deletea A (cdr L)))
      (T (cons (car L)(deletea A (cdr L))))
))

; LISP 1 Dandu-se o lista liniara, sa se stearga toate secventele de valori numerice NEconsecutive crescatoare. De exemplu:
; (1 2 c 4 6 7 8 i 10 j) -> ( 1 2 c 6 7 8 i j)

; removecons(l1..ln) = { (), l is null
;                      { l1 U removecons(l2..ln), l2 - l1 = 1 && l1 is number && l2 is number
;                      { l1, l1 is number && l1 is last element
;                      { l1 U removecons(l2..ln), l1 is number && l2 is not number
;                      { removecons(l2..ln), otherwise
; removecons(L - a list)
; flow model: removecons(i) - output is a list
(defun removecons (l)
  (cond
      ( (null l) ()) ; list is null
      ( (and (numberp (car l)) (numberp (car (cdr l))) (= (- (car (cdr l)) (car l) ) 1 )) (append (car l) (removecons (cdr l)))  )
      ( (and (numberp (car l)) (null (numberp (car (cdr l))))) (append (car l) (removecons (cdr l))))
      ( (and (numberp (car l)) (null (cdr l))) (car l) ) ; last element and number
      ( T (removecons (cdr l)))
  )
)