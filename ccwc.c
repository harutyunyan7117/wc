#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

int count_bytes(const char* filepath);
int count_lines(const char* filepath);
int count_words(const char* filepath);

void print_filepath(const char* filepath) {
    printf("%s\n", filepath);
}

int 
main(int argc, char **argv)
{
    int option_c = FALSE;
    int option_l = FALSE;
    int option_m = FALSE;

    while(*++argv != NULL && **argv == '-') {
        switch(*++*argv) {
            case 'c':
                option_c = TRUE;
                break;
            case 'l':
                option_l = TRUE;
                break;
            case 'm':
                option_m = TRUE;
                break;
        }
    }

    if (*argv == NULL) {
        printf("Please specify a filepath.");
    } else {
        while (*argv != NULL) {
            printf("%d\t", count_bytes(*argv));
            printf("%d\t", count_lines(*argv));
            printf("%d\t", count_words(*argv));
            printf("%s\n", *argv++);
        }
    }

    return 0;
}

int 
count_bytes(const char* filepath) {
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

int 
count_lines(const char* filepath)
{
    FILE *fp;
    int line_count = 0;

    fp = fopen(filepath, "r");
    if (!fp) {
        printf("Error opening the file: %s\n", filepath);
        return -1;
    }

    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            line_count++;
        }
    }

    fclose(fp);
    return line_count;
}

int 
count_words(const char* filepath)
{
    FILE *fp;
    int word_count = 0;

    fp = fopen(filepath, "r");
    if (!fp) {
        printf("Error opening the file: %s\n", filepath);
        return -1;
    }

    int c;
    int word_counted = FALSE;
    while((c = fgetc(fp)) != EOF) {
        if (isalnum(c) && !word_counted) {
            word_count++;
            word_counted = TRUE;
        }
        if (isspace(c) && word_counted) {
            word_counted = FALSE;
        }
    }

    fclose(fp);
    return word_count;
}
