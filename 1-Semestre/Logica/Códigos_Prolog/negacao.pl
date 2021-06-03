ilegal('roubo').
ilegal('corrupção').
legal(X) :- \+ ilegal(X).
