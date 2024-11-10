all: geraos principal

principal: principal.o calculadora.o
   gcc principal.o calculadora.o -o principal

geraos: principal.c calculadora.c
   gcc -c principal.c calculadora.c

clean:
   rm -rf *.o principal
