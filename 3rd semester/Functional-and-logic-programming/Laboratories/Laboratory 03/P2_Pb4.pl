% 4.
% a. Write a predicate to determine the sum of two numbers written in
% list representation.
% b. For a heterogeneous list, formed from integer numbers and list of
% digits, write a predicate to compute the sum of all numbers
% represented as sublists.
%
% a)
% The predicate reverses the given list.
% reverseList(L - list of integers, X - output, Z - auxiliary list)
% reverseList(i,o,i)
% reverseList([l1..ln]) = { [], l is empty
%                         { reverseList([l2..ln]) U l1, otherwise
reverseList([],Z,Z).
reverseList([H|T],X,Rest):- reverseList(T,X,[H|Rest]).

% The predicate returns the reverse list of the given list.
% wrapperReverseList(L - list of integers, R - output list).
% wrapperReverseList(i,o)
wrapperReverseList(L,R):- !,reverseList(L,R,[]).

% The predicate adds two numbers represented as lists.
% sum(L1 - first number as list, L2 - second number as list,
%              T - transport integer, R - result list)
% sum(i,i,i,o).
% sum([l1..ln],[L1..LN],T,)=
%    {   T, list is empty & LIST is empty & T != 0
%    {  [], list is empty & LIST is empty & T = 0
%    { [list], LIST is empty & T = 0
%    { [LIST], list is empty & T = 0
%    { sum([T],LIST,0), list is empty & T != 0
%    { sum(list,[T],0), LIST is empty & t != 0
%    { {(T + l1 + L1)%10 } U sum([l2..ln],[L2..LN],( T + l1 + L1 ) / 10)
%                                                     otherwise
sum([],[],T,[T]):-T=\=0,!.
sum([],[],_,[]):-!.
sum([],[L],T,[L]):-T=:=0,!.
sum([L],[],T,[L]):-T=:=0,!.
sum([H1|T1],[H2|T2],T,[Hs|Ts]):-
      S is H1+H2+T,
      Tn is S div 10,
      Hs is S mod 10,
      sum(T1,T2,Tn,Ts).

% The predicate adds two number represented as lists.
% wrapperSum(L1 - first number as list, L2 - second number as list, R -
%                                                          result list )
% wrapperSum(i,i,o)
wrapperSum(L1,L2,Ls):-
    wrapperReverseList(L1,L1i),
    wrapperReverseList(L2,L2i),
    sum(L1i,L2i,0,LAux),
    wrapperReverseList(LAux,Ls).

%b)

printList([]).
printList([X]):-write(X),nl,!.
printList([X|List]) :-
    write(X),nl,
    printList(List),!.

% The predicate adds the numbers represented as lists in a list.
% addList(L - initial list, R - auxiliary sum, R1 - output
% addList(i,i,o).
% addList([l1..ln],R)={ addList([l2..ln],R), l1 not list
%                     { addList([l2..ln],wrapperSum(l1,R)), otherwise
%addLists([],_,_).
addLists([],X,X).
addLists([H|T],R,R1):-
    is_list(H),
    %write('List number:'),printList(H),
    %printList(R),
    wrapperSum(H,R,Aux),
    %write('R='),printList(R),
    %write('R1='),printList(Aux),
    addLists(T,Aux,R1).

addLists([H|T],R,RF):-number(H),
    %write('Number:'),write(H),nl,
    addLists(T,R,RF).

% The predicate returns the sum of the numbers represented as lists.
% wrapperAddList(L - input list, R- output list ).
% wrapperAddList(i,o).
wrapperAddLists(L,R):-addLists(L,[0],R).


