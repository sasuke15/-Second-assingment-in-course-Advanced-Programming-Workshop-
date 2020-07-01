
/*
Assigend by:
Shay Bach #204263842,:61108
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Declarations of other functions */

/* ------------------------------- */
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();

/* Function definitions */

/* ------------------- */

/* Exercise1 */
char** funck(char letter, char* str, int* size)
{

    int i, j;
    int n = 0, m = 0;
    char **arr, curr;

    for (i = 0; str[i] != '\0'; i++) {

        if (i == 0) {
        }

        else if (str[i - 1] != ' ')
            continue;

        if (str[i] == letter || str[i] == letter - 32)
            n++;
    }

    arr = (char**)malloc(n * sizeof(char*));

    n = 0;

    for (i = 0; str[i] != '\0'; i++) {

        if (i == 0) {
        }

        else if (str[i - 1] != ' ')
            continue;

        if (str[i] == letter || str[i] == letter - 32) {

            for (j = i; str[j] != ' ' && str[j] != '\0'; j++)
                m++;

            arr[n] = (char*)malloc((m + 1) * sizeof(char));

            arr[n][m] = '\0';

            m = 0;

            for (j = i; str[j] != ' ' && str[j] != '\0'; j++) {

                arr[n][m] = str[j];
                m++;
            }

            n++;

            m = 0;
        }
    }

    *size = n;

    return arr;
}
void print_arr(char** arr, int size)
{

    int i;

    printf("the  words are:\n");

    for (i = 0; size > i; i++)
        printf("%s\n", arr[i]);

    printf("\n");
}
void Free(char** arr, int size)
{

    int i;

    for (i = 0; size > i; i++)
        free(arr[i]);

    free(arr);
}
void Ex1()
{

    int size, i;
    char letter;
    char* str;
    char** arr;

    printf("please enter the letter\n");
    rewind(stdin);
    scanf("%c", &letter);

    printf("please enter the size of the string\n");
    scanf("%d", &size);

    str = (char*)malloc((size + 1) * sizeof(char));

    str[size] = '\0';

    printf("pleas enter the string\n");
    rewind(stdin);
    gets(str);

    arr = funck(letter, str, &size);

    print_arr(arr, size);

    Free(arr, size);

    free(str);
}
/* Exercise2 */
char* funk(char* string)
{

    char* new_string;
    int n = 0, i;

    for (i = 0; string[i] != '\0'; i++)
        if ((string[i] > '9' || string[i] < '0') && string[i] != ' ')
            n++;

    new_string = (char*)malloc((n + 1) * sizeof(char));

    new_string[n] = '\0';

    n = 0;

    for (i = 0; string[i] != '\0'; i++)
        if ((string[i] > '9' || string[i] < '0') && string[i] != ' ') {

            new_string[n] = string[i];
            n++;
        }

    return new_string;
}
void Ex2()
{

    char* string;
    char* new_string;
    int n;

    printf("please enter the size of the string\n");
    scanf("%d", &n);

    string = (char*)malloc((n + 1) * sizeof(char));

    string[n] = '\0';

    printf("please enter the string\n");
    rewind(stdin);
    gets(string);

    new_string = funk(string);

    printf("the new string is: %s\n", new_string);

    free(string);

    free(new_string);
}
/* Exercise3 */
void create_file(char* filename)
{
    char ch = 1;
    FILE* f = fopen(filename, "w");
    printf("start writing the file ( to stop press 'ctrl z' and than 'enter')\n");
    while ((ch = getchar()) != EOF)
        fputc(ch, f);

    fclose(f);
}
char commonestLetter(char* filename)
{

    char ch;
    int counting[26] = { 0 };
    int max = 0, i;

    FILE* f = fopen(filename, "r");

    if (f == NULL)
        return '\0';

    while ((ch = fgetc(f)) != EOF) {

        if ('z' >= ch && ch >= 'a')
            counting[ch - 32 - 'A']++;

        if ('Z' >= ch && ch >= 'A')
            counting[ch - 'A']++;
    }

    fclose(f);

    for (i = 0; 26 > i; i++)
        if (counting[i] >= max) {

            max = counting[i];

            ch = i + 'A';
        }

    return ch;
}
void Ex3()
{

    FILE* f;
    char* filename = "input.txt";
    char ch;

    create_file(filename);

    ch = commonestLetter("input.txt");

    if (ch)
        printf("the commonest letter is: %c\n\n", ch);
}
/* Exercise4 */
void chek_string(char* string)
{

    int i, j = 1;

    for (i = 0; string[i] != '\0'; i++)
        if (string[i] != ' ') {

            string[i] -= j;
            j++;
        }
        else
            j = 1;
}
void Ex4()
{

    int n;
    char* string;

    printf("please enter the size of the string\n");
    scanf("%d", &n);

    string = (char*)malloc((n + 1) * sizeof(char));

    string[n] = '\0';

    printf("please enter the string\n");
    rewind(stdin);
    gets(string);

    chek_string(string);

    printf("the new string is: %s\n", string);

    free(string);
}
/* Exercise5 */
void Funk(char* filename, char* declaration)
{

    FILE* f = fopen(filename, "w");
    char count[10] = { 0 };
    int i, j = 0, size = 0, num = 0, condition = 0;

    for (i = 0; declaration[i] == ' '; i++) {
    }

    for (i; declaration[i] != ' ' && declaration[i] != '\0' && declaration[i] != '*' && declaration[i] != ',' && declaration[i] != ';'; i++) {

        count[j] = declaration[i];
        j++;
    }

    if (strcmp("char", count) == 0)
        size = sizeof(char);

    if (strcmp("short", count) == 0)
        size = sizeof(short);

    if (strcmp("int", count) == 0)
        size = sizeof(int);

    if (strcmp("long", count) == 0)
        size = sizeof(long);

    if (strcmp("long long", count) == 0)
        size = sizeof(long long);

    if (strcmp("float", count) == 0)
        size = sizeof(float);

    if (strcmp("double", count) == 0)
        size = sizeof(double);

    for (i; declaration[i] != '\0'; i++)
        if (declaration[i] != ',' && declaration[i] != ';') {

            if (declaration[i] != '*' && declaration[i] != ' ')
                fprintf(f, "%c", declaration[i]);

            if (declaration[i] == ']')
                condition = 0;

            if (condition == 1) {

                num += declaration[i] - 48;
                num *= 10;
            }

            if (declaration[i] == '[')
                condition = 1;
        }
        else {

            num /= 10;

            fprintf(f, " requires");

            if (num == 0) {

                fprintf(f, " %d", size);

                if (size == 1)
                    fprintf(f, " byte\n");
                else
                    fprintf(f, " bytes\n");
            }
            else {

                fprintf(f, " %d", num * size);

                if (num * size == 1)
                    fprintf(f, " byte\n");
                else
                    fprintf(f, " bytes\n");
            }

            num = 0;
        }

    fclose(f);
}
void print(char* filename)
{

    char ch;

    FILE* f = fopen(filename, "r");

    if (f == NULL) {
    }
    else {
        printf("the amount of memory is:\n");
        while (!feof(f)) {

            fscanf(f, "%c", &ch);
            printf("%c", ch);
        }
    }

    printf("\n");
    fclose(f);
}
void Ex5()
{

    FILE* f;
    char *filename = "name", *declaration;
    int n;

    printf("please enter the size of the string\n");
    scanf("%d", &n);

    declaration = (char*)malloc((n + 1) * sizeof(char));

    declaration[n] = '\0';

    printf("please enter the string\n");
    rewind(stdin);
    gets(declaration);

    Funk(filename, declaration);

    print(filename);

    free(declaration);
}

int main()
{
    int select = 0, i, all_Ex_in_loop = 0;
    printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
    if (scanf("%d", &all_Ex_in_loop) == 1)
        do {
            for (i = 1; i <= 5; i++)
                printf("Ex%d--->%d\n", i, i);
            printf("EXIT-->0\n");
            do {
                select = 0;
                printf("please select 0-5 : ");
                scanf("%d", &select);
            } while ((select < 0) || (select > 5));
            switch (select) {
            case 1:
                Ex1();
                break;
            case 2:
                Ex2();
                break;
            case 3:
                Ex3();
                break;
            case 4:
                Ex4();
                break;
            case 5:
                Ex5();
                break;
            }
        } while (all_Ex_in_loop && select);
    return 0;
}


