#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <wrappers.h>

#define OUT 0
#define IN  1
#define MAXWORDLEN  50

// void getword(char *str, char *word) {
//     char *start = str;
//     char *end;

//     // Saltear los primeros espacios vacios
//     while (*start || *start == ' ' || *start == '\t'){
//         start++;
//     }

//     // Encontrar el final de la prueba
//     end = start;
//     while (*end && *end != ' ' && *end != '\t'){
//         end++;
//     }

//     // Copy the word to the output buffer
//     int length = end - start;
//     if (length > MAXWORDLEN - 1){
//         //TODO MANDAR UN ERROR
//     }
//     printf("%i \n", length);
//     // word = (char *) malloc_or_exit(length + 1);
//     word = (char *) malloc(length + 1);
    
//     for (; start < end; start ++){
//         *word++ = *start;
//         printf("%c", *start);
//     }
//     for (int i = 0; i < length; i++){
//         word --;
//     }
//     printf("HOLA %s", word);
// }
int is_separator(char c){
    // Checks is a char is a separator

    if (c == ' ' || c == '\t' || c == '\n' || c == EOF){
        return 1;
    }
    return 0;
}

void getword(char *line, char *word){
    printf("%s \n", line);
    char *temp = word;
    int length;
    for (length = 0; is_separator(*(line + length)) == 0; length++){
        printf("TRUE");
        *temp++ = *(line+length);
    }
    printf("Largo: %i \n", length);
    // printf("%s \n", word);
}
/*
int main() {
    char str[] = "Hello, world! This is a test.";
    char word[100];

    // Extract and print words from the string
    char *ptr = str;
    while (*ptr) {
        getword(ptr, word);
        printf("Word: %s\n", word);
        // ptr += strlen(word) + 1; // Move to the next word
        ptr ++;
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
    return 0;
    
}
 */