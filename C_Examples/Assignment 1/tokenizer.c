#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers.h"

int main() {
    
    char str[100];
    printf("\nEnter a word: ");
    fgets(str, 100, stdin);

    char** tokens = tokenize(str);
    return(0);
}
 
char** tokenize(char* str) {

    int num_tokens = count_tokens(str);

    char** tokens = malloc((num_tokens+1) * sizeof(char*));

    int w;

    for(w = 0; w<num_tokens; w++) {
        printf("%d",w);
    }

    return tokens;
}

int count_tokens(char* str) {
    int num_tokens = 0;
    char *ptr = str;
    while ((*ptr) != '\0') {
        if (delim_character((*ptr))) {
            num_tokens++;
        } 
        ptr++;
    }
    return num_tokens+1;
}

bool delim_character(char c) {
    return c == ' ' || c == '\t';
}