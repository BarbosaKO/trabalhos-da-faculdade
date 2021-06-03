soma(X, Y, Z) :- Z is X + Y.
max(X, Y, Z) :- (  X =< Y
                  -> Z = Y
                  ;  Z = X
                ).