all:inicio compila fim
inicio:
	@echo "Comecando"
compila:cgSolver.o funcoes.o utils.o
	gcc cgSolver.o utils.o funcoes.o -o cgSolver
funcoes.o: funcoes.h funcoes.c
	gcc -c funcoes.c
utils.o: utils.h utils.c
	gcc -c utils.c
cgSolver.o: cgSolver.c funcoes.h
	gcc -c cgSolver.c
clear:
	rm -f *.o
dbg: cgSolver.o utils.o funcoes.o
	gcc -o teste cgSolver.o utils.o funcoes.o -g && gdb teste
run: compila
	clear && ./cgSolver -n 26 -k 5 -p 0.0 -i 333 -e 1.0 -o arquivo_saida

fim:
	@echo "Terminando"
	@rm -rf *.o
