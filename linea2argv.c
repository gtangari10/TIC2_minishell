#include <stdio.h>
#include <string.h>

#define OUT 0
#define IN  1
#define MAXWORDLEN  50

void getword(const char *str, char *word) {
    char *start = str;
    char *end;

    // Saltear los primeros espacios vacios
    while (*start && *start != ' ' && *start != '\tab'){
        start++;
    }

    // Encontrar el final de la prueba
    end = start;
    while (*end && *end != ' ' && *end != '\tab')
        end++;

    // Copy the word to the output buffer
    int length = end - start;
    if (length > MAXWORDLEN - 1)
        //TODO MANDAR UN ERROR
    word = strdup_or_exit(start);
    word[length] = '\0';
}


void getword(char *str, char *word) {
    int c;              // el valor de retorno de getchar() es un int !!!
    int state;          // estado dentro o fuera de una palabra (IN/OUT)
    int wordcount;      // cuenta palabras

    wordcount = 0;
    state = OUT;        // estado inicial es OUT

    while ( (c=getchar()) != EOF) {

        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            wordcount++; // cada vez que empieza una palabra se incrementa el contador
        }
    }


    printf("%d \n", wordcount);
    return 0;
}

int main() {
    char str[] = "Hello, world! This is a test.";
    char word[100];

    // Extract and print words from the string
    const char *ptr = str;
    while (*ptr) {
        getword(ptr, word);
        printf("Word: %s\n", word);
        ptr += strlen(word) + 1; // Move to the next word
    }

    return 0;
}


int linea2argv (char *linea, int argc, char **argv){
    // Recibe una línea (texto con un \n final) y hace apuntar argv[0] a la primera
    // palabra, argv[1] a la segunda, etc.
    // ▪ argc+1 es el tamaño con el cual está definido argv en el invocador a esta
    // función.
    // ▪ Retorna la cantidad N de palabras encontradas y argv[N] deberá ser
    // NULL. Se sobreentiende que N debe ser inferior a argc. Pueden
    // descartarse las palabras “sobrantes”.
    // ▪ Una palabra es un texto entre espacios o tabuladores.
    // ▪ El objetivo de esta función es armar argv para invocar a las funciones
    // anteriores.
    // ▪ Debe funcionar perfectamente aún si la línea está “vacía” o contiene solo
    // espacios. Retorna 0 en este caso.
    // ▪ Los strings apuntados por argv[0], argv[1], etc. se mallocarán. Es
    // responsabilidad de quien invoca a linea2argv, de hacer los free
    // correspondientes.

    
}
 