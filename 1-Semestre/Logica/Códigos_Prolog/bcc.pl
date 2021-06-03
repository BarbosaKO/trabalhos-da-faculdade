ministra('Bruna', 'Fundamentos de Matemática').
ministra('Bruno', 'Sistemas Digitais').
ministra('Filipe', 'Comunicação e Expressão').
ministra('Giovana', 'Algoritmos e Lógica de Programação I').
ministra('Giovana', 'Laboratório de Programação de Computadores').
ministra('Leonardo', 'Cidadania e Direitos Humanos').
ministra('Sacchi','Lógica Aplicada').
matriculadoEm('Ana', 'Sistemas Digitais').
matriculadoEm('Ana', 'Comunicação e Expressão').
matriculadoEm('Carlos','Sistemas Digitais').
matriculadoEm('Beatriz','Comunicação e Expressão').
matriculadoEm('Beatriz','Comunicação e Expressão').
ensinaPara(P,E) :- ministra(P,D), matriculadoEm(E,D).
