ilegal('Roubo').
ilegal('Latrocínio').
legal(X) :- \+ ilegal(X).
