% Lab assignment text:
% 3.a. Define a predicate to remove from a list all repetitive elements.
% Eg.: l=[1,2,1,4,1,3,4] => l=[2,3])
% b. Remove all occurrence of a maximum value from a list on integer
% numbers.


% a)

% The predicate determines the number of occurences in a given
% list of a given element.
% numberOfOccurences(E - the given element, L - initial list, R -
% result).
% numberOfOccurences(i,i,o)
% Mathematical model:             { 0, l = []
% numberOfOccurences(e,[l1...ln])={ 1 + numberOfOccurences(e,[l2...ln]),
%                                                             e = l1
%                                 { numberOfOccurences(e,[l2..ln]),
%                                                             e != l1
%
numberOfOccurences(_,[],0).
numberOfOccurences(E,[H|T],A):-H=:=E,
    numberOfOccurences(E,T,A1),
    A is A1+1.
numberOfOccurences(E,[H|T],A):-H=\=E,
    numberOfOccurences(E,T,A).

% The predicate removes all repetitive elements from a list.
% removeRepetitive(L - initial list, P - initial list, O - result list)
% removeRepetitive(i,i,o)
% Mathematical model:
%                            {                              [], l = []
% removeRepetitive([l1..ln])={ l1 U removeRepetitive([l2..ln]),
%                                    numberOfOccurences(l1,[l2..ln]) = 1
%                            { removeRepetitive([l2..ln]), otherwise

removeRepetitive([],_,[]).
removeRepetitive([H|T],P,O):-numberOfOccurences(H,P,R),
                         R>1,
                         removeRepetitive(T,P,O).

removeRepetitive([H|T],P,O):-numberOfOccurences(H,P,R),
    R=1,
    removeRepetitive(T,P,O1),
    O = [H|O1].

% The predicate calls removeRepetitive.
% wrapper(L - list of integers, R - output list)
% wrapper(i,o)
wrapper(L,R):-removeRepetitive(L,L,R).

% b)
%
% The predicate determines the maximum element of a given list.
% determineMaxElement(L - initial list)
% determineMaxElement(i,o)
% Mathematical model:
%                               {                      [], l = []
% determineMaxElement([l1..ln])={                      l1,
%                                     l1 > determineMaxElement([l2..ln])
%                               { determineMaxElement([l2..ln]),
%                                                         otherwise


determineMaxElement([],0).
determineMaxElement([H|T],R):-determineMaxElement(T,O),
    H > O,
    R is H.

determineMaxElement([H|T],R):-determineMaxElement(T,R),
    H < R.

removeMax([],_,[]).

removeMax([H|T],Max,R):-H=\=Max,
    removeMax(T,Max,R1),
    R = [H|R1].

removeMax([H|T],Max,R):-H=:=Max,
    removeMax(T,Max,R).

wrapperRemoveMax(L1,R):-determineMaxElement(L1,Max),
    write(Max),nl,
    removeMax(L1,Max,R).
