ilegal('roubo').
ilegal('corrup��o').
legal(X) :- \+ ilegal(X).
