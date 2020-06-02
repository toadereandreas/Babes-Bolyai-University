% Test: Problem 3
%
% The predicate determines the minimum element in a list.
% min(L-input list,M - minimum, X-output list)
% min(i,i,o).
% min([l1..ln], min)={ min([l2..ln],min), min < l1
%               { min([l2..ln],l1) , l1 < min
%               { l1, l1 - last element
min([],X,X).
min([H|T],M,X) :- H =< M, min(T,H,X).
min([H|T],M,X) :- M < H, min(T,M,X).

%wrapper function: determines the minimum of the given list.
%wrapper(L - list o f integers, X - minimum of the list)
%flow model: min(i,o).
min([H|T],X) :- min(T,H,X).

% The function inserts on the even position the difference of the
% element on that position and the minimum of the list.
% insertMin(L - list of integers, E - minimum of the list, R - output
% list).
% flow model: insertMin(i,i,o).
% insert([l1..ln],Min) = { l1 U {l2-Min} U insert([l3..ln]), if list has
%                                                    2 or more el
%                        { l1, if the list = [l1] ( only one element )
%                        { [], if the list is empty
insertMin([],_,[]).
insertMin([X],_,[X]).
insertMin([H1,H2|T],E,R):-
    insertMin(T,E,R1),
    X is H2-E,
    R = [H1,X|R1].

% wrapper( L - input list, R -  result list  ).
% flow mmodel: wrapper wrapper(i,o)
wrapper(L,R):-
    min(L,Y),
    insertMin(L,Y,R).

% special examples: [1,2,3] => [1,1,3]
%                   [1,2,3,4] => [1,1,3,3]
%                   [3,3,3] = > [3,0,3]
% given example : [6,10,3,4,7,11,3,11,34,6,9,3] =>
%                                     [6,7,3,1,7,8,3,8,34,3,9,0]
