% 9. Generate all permutation of N (N - given) respecting the property:
% for every 2<=i<=n exists an 1<=j<=i, so |v(i)-v(j)|=1.


% candidate returns each number from the list and the list without it
% candidate(L - list, R - integer, L1 - list)
% flow(i,o,o)
% candidate(l1...ln)= - l1,l2...ln
%                     - (e,l1 U L), (e,L) = candidate(l2...ln)

candidate([H|T],H,T).
candidate([H|T],R,[H|T1]):-candidate(T,R,T1).


%candidate2(L,_P,_X,_R):-test2(L,L).
%candidate2([H|L],N,X,[H|T]):-candidate2(L,N,X,T).

%build(N - integer, L - list)
%flow(i,o)
%build(l1...ln,n) = - [], n = 0 or 1
%                   - build(l2...ln,n-1), n>1

build(0,[]).
build(1,[]).
build(N1,[N|L]) :- N1 > 1, N is N1 - 1, build(N,L).


%reverse(L - input list, Z - list, R - list)
%flow(i,o,i)
%reverse(l1...ln) = - [], list is empty
%                   - l1 U reverse(l2...ln)
reverse([],Z,Z).
reverse([H|T],Z,Acc) :- reverse(T,Z,[H|Acc]).

%buildReverse(N - integer, R - list)
%flow(i,o)
buildReverse(N1,R):-build(N1+1,R1),reverse(R1,R,[]).

%wrapper(N1,A,R1):-buildReverse(N1,R),candidate(R,A,R1).

%checks whether the condition in the requirement
%nrTest(L - list, R - int, I - int)
%nrTest(i,i,o)
%nrTest(l1...ln,r,i) = - false, l1 = r, i = 1
%                      - true, abs(l1-r)= 1, list length is 1
%                      - true, abs(l1-r)= 1
%                      - nrTest(l2...ln,r,1)
%                      - nrTest(l2...ln,r,1), i = 0, l1 = r
nrTest([],0,_).
nrTest([R|T],R,0):-nrTest(T,R,1).
nrTest([R|_T],R,1):-!,fail.
nrTest([H],R,_):-1 is abs(H-R),true,!.
nrTest([H|_T],R,_):-1 is abs(H-R),true,!.
nrTest([_H|T],R,_I):-nrTest(T,R,1).


% checks if for every element of the list the condition in the
% requirement is met
% test2(L - list, R - list)
% flow(i,i)
% test2(l1...ln,r1...rn) = - false, lists are empty
%                          - true, first list is empty
%                          - true, lists have one element each
%                          - test2(l2...ln,r1...rn), if
%                          nrTest(r1...rn,l1,0)
test2([],[]):-false.
test2([],_):-true.
test2([_],[_]):-true.
test2([H|T],R):-nrTest(R,H,0),test2(T,R),!.


%wrapper for test2
%test2Wrap(R - list)
%flow(i)
test2Wrap([]):-false.
test2Wrap([_]):-true.
test2Wrap(R):-test2(R,R).


%perm([],_,[]).
%perm(L,O,[H|T]):-candidate2(L,O,H,R),perm(R,H,T).
%perm([],[]).
%perm(L,[H|T]):-candidate(L,H,R),perm(R,H,T).

%dif([_]).
%dif([H|T]):-test2([H|T],[H|T]).


%perm2(L - list, R - list)
%flow(i,o)
%perm2(l1...ln,r1...rn) = - [], list is empty
%                         - perm2(candidate(l1...ln,r1),r2...rn),
%                         otherwise
perm2([],[]).
perm2(L,[E|T]):-candidate(L,E,R),perm2(R,T).

%perm3(L - list, R - list)
%flow(i,o)
%perm3(l1...ln,r1...rn) = - perm3(l1...ln,r1...rn), test2Wrap(r1...rn)
perm3(L,R):-perm2(L,R),test2Wrap(R).

%wrapper(N - int, R - list)
%flow(i,o)
wrapper(0,[]).
wrapper(N,R):-buildReverse(N,R1),perm3(R1,R).











