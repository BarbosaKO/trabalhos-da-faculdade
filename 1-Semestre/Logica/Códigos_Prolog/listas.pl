contem(V, []) :- false.
contem(V, [V|_]) :- true.
contem(V, [_|T]) :- contem(V, T).

contemCorte(V, []) :- false.
contemCorte(V, [V|_]) :- true.
contemCorte(V, [_|T]) :- contem(V, T),!.

inverte(Xs, Ys) :- inverte_worker(Xs, [], Ys).
inverte_worker([], R, R). 
inverte_worker([X|Xs], T, R) :- inverte_worker(Xs, [X|T], R).
