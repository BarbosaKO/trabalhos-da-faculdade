ministra('Bruna', 'Fundamentos de Matem�tica').
ministra('Bruno', 'Sistemas Digitais').
ministra('Filipe', 'Comunica��o e Express�o').
ministra('Giovana', 'Algoritmos e L�gica de Programa��o I').
ministra('Giovana', 'Laborat�rio de Programa��o de Computadores').
ministra('Leonardo', 'Cidadania e Direitos Humanos').
ministra('Sacchi','L�gica Aplicada').
matriculadoEm('Ana', 'Sistemas Digitais').
matriculadoEm('Ana', 'Comunica��o e Express�o').
matriculadoEm('Carlos','Sistemas Digitais').
matriculadoEm('Beatriz','Comunica��o e Express�o').
matriculadoEm('Beatriz','Comunica��o e Express�o').
ensinaPara(P,E) :- ministra(P,D), matriculadoEm(E,D).
