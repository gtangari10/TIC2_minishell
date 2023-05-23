#include <stdio.h>
#include <string.h>

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