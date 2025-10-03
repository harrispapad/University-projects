:- use_module(library(clpfd)).

% Read grid from file
read_grid(File, Grid, N) :-
    open(File, read, Stream),
    read_line_to_string(Stream, Line),
    number_string(N, Line),
    read_lines(Stream, N, Grid),
    close(Stream).

read_lines(Stream, N, Grid) :-
    length(Grid, N),
    maplist(read_line(Stream), Grid).

read_line(Stream, Line) :-
    read_line_to_string(Stream, LineString),
    split_string(LineString, " ", "", LineStrings),
    maplist(number_string, Line, LineStrings).

% Main moves predicate
moves(File, Path) :-
    read_grid(File, Grid, N),
    length(Grid, N),
    once(bfs([state(0, 0, [])], Grid, N, Path)).

% Breadth-first search algorithm
bfs([state(N1, N1, Path)|_], _, N, Path) :- N1 #= N-1.
bfs([state(R, C, AccPath)|Rest], Grid, N, Path) :-
    findall(state(NewR, NewC, NewAccPath),
            ( move(R, C, NewR, NewC, Dir),
              NewR #>= 0, NewR #< N, NewC #>= 0, NewC #< N,
              nth0(R, Grid, Row), nth0(C, Row, CurrCars),
              nth0(NewR, Grid, NewRow), nth0(NewC, NewRow, NewCars),
              NewCars #< CurrCars,
              \+ member(state(NewR, NewC, _), Rest),
              append(AccPath, [Dir], NewAccPath)
            ),
            NewStates),
    append(Rest, NewStates, NewQueue),
    bfs(NewQueue, Grid, N, Path).
bfs([], _, _, 'IMPOSSIBLE').

% Define possible moves
move(R, C, R1, C1, n)  :- R1 #= R-1, C1 #= C.
move(R, C, R1, C1, s)  :- R1 #= R+1, C1 #= C.
move(R, C, R1, C1, w)  :- R1 #= R, C1 #= C-1.
move(R, C, R1, C1, e)  :- R1 #= R, C1 #= C+1.
move(R, C, R1, C1, nw) :- R1 #= R-1, C1 #= C-1.
move(R, C, R1, C1, ne) :- R1 #= R-1, C1 #= C+1.
move(R, C, R1, C1, sw) :- R1 #= R+1, C1 #= C-1.
move(R, C, R1, C1, se) :- R1 #= R+1, C1 #= C+1.

% Entry point for running the script with swipl -q -s grid_traversal.pl -- f1.txt
main :-
    current_prolog_flag(argv, [File|_]),
    ( moves(File, Path) ->
      maplist(uppercase, Path, UppercasePath),
      format('~w~n', [UppercasePath])
    ; writeln('IMPOSSIBLE')
    ).

uppercase(Lower, Upper) :-
    atom_codes(Lower, [LowerCode]),
    UpperCode is LowerCode - 32,
    atom_codes(Upper, [UpperCode]).

