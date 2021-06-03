/* brasil(AC, AL, AM, AP, BA, CE, DF, ES, GO, MA, MG, MS, MT, PA, PB, PE, PI, PR, RJ, RN, RO, RR, RS, SC, SE, SP, TO). */
cor('amarelo').
cor('azul').
cor('vermelho').
cor('verde').

semConflito(CorEstadoA, CorEstadoB) :- cor(CorEstadoA), 
								       cor(CorEstadoB), 
								       CorEstadoA \= CorEstadoB.

brasil(AC, AL, AM, AP, BA, 
       CE, DF, ES, GO, MA, 
	   MG, MS, MT, PA, PB, 
	   PE, PI, PR, RJ, RN, 
	   RO, RR, RS, SC, SE, 
	   SP, TO) :- semConflito(AC, AM), semConflito(AC, RO),
				  semConflito(AL, PE), semConflito(AL, SE), semConflito(AL, BA),
                  semConflito(AM, RO), semConflito(AM, RR), semConflito(AM, PA), semConflito(AM, MT),
				  semConflito(AP, PA),
			      semConflito(BA, SE), semConflito(BA, PE), semConflito(BA, PI), semConflito(BA, MG), semConflito(BA, ES), semConflito(BA, GO), semConflito(BA, TO),
				  semConflito(CE, RN), semConflito(CE, PB), semConflito(CE, PE), semConflito(CE, PI),	
                  semConflito(DF, GO), semConflito(DF, MG),
                  semConflito(ES, MG), semConflito(ES, RJ),	
                  semConflito(GO, MT), semConflito(GO, TO), semConflito(GO, MG), semConflito(GO, MS),	
                  semConflito(MA, PA), semConflito(MA, TO), semConflito(MA, PI),
                  semConflito(MG, SP), semConflito(MG, RJ), semConflito(MG, MS), 
                  semConflito(MS, MT), semConflito(MS, SP), semConflito(MS, PR),
				  semConflito(MT, RO), semConflito(MT, PA), semConflito(MT, TO),
                  semConflito(PA, RR), semConflito(PA, TO),	
                  semConflito(PB, RN), semConflito(PB, PE),
                  semConflito(PE, PI), 				  
                  semConflito(PI, TO),
			      semConflito(PR, SP), semConflito(PR, SC),
			      semConflito(RJ, SP),
			      semConflito(RS, SC).