#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int count_bytes(const char* filepath);

void print_filepath(const char* filepath) {
    printf("%s\n", filepath);
}

int main(int argc, char **argv)
{
    int option_c = FALSE;

    while(*++argv != NULL && **argv == '-') {
        switch(*++*argv) {
            case 'c':
                option_c = TRUE;
                break;
        }
    }

    if (*argv == NULL) {
        printf("Please specify a filepath.");
    } else {
        while (*argv != NULL) {
            printf("%d\t", count_bytes(*argv));
            printf("%s\n", *argv++);
        }
    }

    return 0;
}

int count_bytes(const char* filepath) {
    FILE *fp;
    int char_count = 0;

    fp = fopen(filepath, "r");
    if (!fp) {
        printf("Error opening the file: %s", filepath);
        return -1;
    }

    int c;
    while ((c = fgetc(fp)) != EOF) {
        char_count++;
    }

    fclose(fp);
    return char_count;
}

