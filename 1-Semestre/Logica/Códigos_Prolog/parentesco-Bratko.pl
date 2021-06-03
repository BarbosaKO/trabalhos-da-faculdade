genitor('Pam', 'Bob').
genitor('Tom', 'Bob').
genitor('Tom', 'Liz').
genitor('Bob', 'Ann').
genitor('Bob', 'Pat').
genitor('Pat', 'Jim').
avo(X, Z) :- genitor(X, Y), genitor(Y, Z).

% ----------- Pred  ----------------
pred(X, Z) :- genitor(X, Z).
pred(X, Z) :- genitor(X, Y), pred(Y, Z).

% ----------- Pred2 ----------------
pred2(X, Z) :- genitor(X, Y), pred2(Y, Z).
pred2(X, Z) :- genitor(X, Z).

% ----------- Pred3 ----------------
pred3(X, Z) :- genitor(X, Z).
pred3(X, Z) :- pred3(Y, Z), genitor(X, Y).

% ----------- Pred4 ----------------
pred4(X, Z) :- pred4(Y, Z), genitor(X, Y).
pred4(X, Z) :- genitor(X, Z).