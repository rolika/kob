#include <stdio.h>


//#define NDEBUG
#define MAX_NUM_OF_SESSIONS 50


void display_usage(char *executable_name) {
    printf("Használat: ");
    printf("%s <opciók>\n", executable_name);
    puts("Opciók:");
    puts("\topció nélkül:\tkijelzi ezt a használati utasítást.");
    printf("\túj:\t\túj köböző lap nyitása. ");
    printf("Egyszerre %d köböző lapod lehet.\n", MAX_NUM_OF_SESSIONS);
    puts("\tad <azonosító> <átmérő>:");
    puts("\t\t\ta köbözőlapon az átmérő mennyiségét növeli eggyel.");
    puts("\tmutat <opcionális azonosító>:");
    puts("\t\t\tazonosítóval kijelzi a teljes köböző lapot");
    puts("\t\t\tazonosító nélkül kijelzi az összes köböző lap fejlécét");
}


int main(int argc, char **argv) {
    #ifndef NDEBUG
        printf("%d argumentum\n", argc);
    #endif
    if (argc < 2) {
        display_usage(argv[0]);
    }
    return 0;
}
