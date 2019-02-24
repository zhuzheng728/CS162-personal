#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

int ccount = 0;
int wcount = 0;
int lcount = 0;

static int isword(unsigned char c) {
    return isalpha(c);
}

void report(char *file, int ccount, int wcount, int lcount) {
    printf("%d %d %d %s\n",lcount, wcount, ccount, file);
}

void count(int c) {
    ccount++;
    if (c == '\n') {
        lcount++;
    }
}

int getword(FILE * fp) {
    int c;

    if (feof(fp)) {
        return 0;
    }

    while ((c = getc(fp)) != EOF) {
        if (isword(c)) {
            wcount++;
            break;
        }
        count(c);
    }

    for (; c != EOF; c = getc(fp)) {
        count(c);
        if (!isword(c)) {
            break;
        }
    }

    return c != EOF;
}

void counter(char *file) {
    FILE *fp = fopen(file, "r");

    if (!fp) {
        printf("Cannot open file: %s", file);
    }
    while (getword(fp)) {
        ;
    }
    fclose(fp);
    report(file, ccount, wcount, lcount);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("You need to add a file to wc");
    } else if (argc > 2) {
        printf("We cannot handle more than one file");
    } else {
        counter(argv[1]);
    }

    return 0;
}