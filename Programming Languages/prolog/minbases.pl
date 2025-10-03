conv(0, _, []) :- !.
conv(X, Y, Digits) :-
    A1 is X div Y,
    A2 is X mod Y,
    conv(A1, Y, Rest),
    append(Rest, [A2], Digits).

same([]).
same([_]).
same([X, X | T]) :- same([X | T]).

check(X, K, K) :-
    conv(X, K, Digits),
    same(Digits), !.
check(X, K, Base) :-
    K1 is K + 1,
    check(X, K1, Base).

minbases([], []).
minbases([X | T], [Base | BT]) :-
    check(X, 2, Base),
    minbases(T, BT).


