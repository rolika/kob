#include <stdio.h>


//#define NDEBUG
#define MAX_NUM_OF_SESSIONS 50
#define DATAFILE "data/kobozo.dat"
#define MIN_DIAMETER 16
#define MAX_DIAMETER 24
#define NUM_OF_DIAMETERS (MAX_DIAMETER - MIN_DIAMETER + 1)

#define skip_to_next_line(file) \
    do { \
        int ch; \
        while ((ch = fgetc(file)) != '\n' && ch != EOF) { \
            /* skip until end of line */ \
        } \
    } while (0)

#ifndef NDEBUG
#include <assert.h>
void test_read_datafile(void);
void test_read_line_by_line(void);
void test_read_exact_data(void);
#endif


void display_usage(char*);


int main(int argc, char **argv) {
    #ifndef NDEBUG
    printf("%d argumentum\n", argc);
    test_read_datafile();
    test_read_line_by_line();
    test_read_exact_data();
    #endif
    if (argc < 2) {
        display_usage(argv[0]);
    }
    return 0;
}


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


/* TESTS */
#ifndef NDEBUG
void test_read_datafile(void) {
    FILE *file = fopen(DATAFILE, "r");
    assert(file != NULL);
    char line[40];
    while (fgets(line, 40, file) != NULL) {
        printf(line);
    }
    puts("");
}

void test_read_line_by_line(void) {
    FILE *file = fopen(DATAFILE, "r");
    assert(file != NULL);
    char line[40];
    // read and print the first 3 lines
    fgets(line, 40, file);
    printf(line);
    fgets(line, 40, file);
    printf(line);
    fgets(line, 40, file);
    printf(line);
    puts("");
}

void test_read_exact_data(void) {
    FILE *file = fopen(DATAFILE, "r");
    assert(file != NULL);
    // read first line which is the precision, convert to float
    float precision;
    assert (fscanf(file, "%f\n", &precision) == 1);
    printf("Data precision is: %.2f\n", precision);
    // read word until colon in the next line and check it is not indented
    char word[20];
    assert (fscanf(file, "%19[^:]", word) == 1);
    printf("First woodtype is: %s\n", word);
    skip_to_next_line(file);
    float length;
    int volume;
    int count = fscanf(file, " %f: %d", &length, &volume);
    printf("%d data read.\n", count);
    assert(count == 2);
    printf("First length is: %.2f\n", length);
    printf("First volume data is: %d\n", volume);
    printf("Volume taking precision in account: %.2f m3\n", volume * precision);
}
#endif
