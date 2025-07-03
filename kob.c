#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
kobozo.dat fileformat:
1000                                    // first line: precision
species                                 // without indentation: wood species
 length: volumes separated by commas    // after one indentation
 length: ...
 ...
species2
 ...
indentation is just one space
*/

/*
session_xx.dat
xx is the session id with leading zero if necessary
header:
company
person
city
site
species
length
and the count per volume spearated by new lines
*/


#define MAX_NUM_OF_SESSIONS 50
#define MAX_NAME_LEN 40
#define MAX_SPEC_LEN 20
#define MIN_DIAMETER 16
#define MAX_DIAMETER 99
#define NUM_OF_DIAMETERS MAX_DIAMETER - MIN_DIAMETER + 1
#define DATAFILE "kobozo.dat"
#define SESSIONFILE_FMT "session_%d.dat"


typedef struct {
    int id;
    char company[MAX_NAME_LEN];
    char person[MAX_NAME_LEN];
    char city[MAX_NAME_LEN];
    char site[MAX_SPEC_LEN];
    char species[MAX_SPEC_LEN];
    float length;
    int volumes[NUM_OF_DIAMETERS];
    int count[NUM_OF_DIAMETERS];
} Session;

Session sessions[MAX_NUM_OF_SESSIONS];
FILE *session_files[MAX_NUM_OF_SESSIONS];


void clear_input_buffer(void);
void display_usage(void);
void load_all_sessions(Session *sessions);
void display_all_session_brief(void);

int new_session(void);
void load_session(int id)
void add_diameter(Session *session);
int save_session(Session *session);
int remove_session(Session *session);
void display_session_detail(Session session);


void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Consume characters until newline or end-of-file.
    }
}

void display_usage(char *executable) {
    printf("Használat:\n");
    printf("%s <opciók>\n", executable);
    printf("Opciók:\n")
    printf("\tOpció nélkül:\tKijelzi ezt a használati utasítást.");
    printf("\túj:\túj köböző lap nyitása\n");
    printf("\t\tEgyszerre %d köböző lapod lehet.\n", MAX_NUM_OF_SESSIONS);
    printf("\tad <azonosító> <átmérő>:\n");
    printf("\t\ta köbözőlapon az átmérő mennyiségét növeli eggyel.\n");
    printf("\tmutat <opcionális azonosító>:\n");
    printf("\t\tazonosítóval kijelzi a teljes köböző lapot\n");
    printf("\t\tazonosító nélkül kijelzi az összes köböző lap fejlécét\n");
    printf("\ttui: használat terminál menürendszerben");

