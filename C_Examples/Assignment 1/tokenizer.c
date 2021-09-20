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
 
char** tokenize(char* ptr_str) {

    int num_tokens = count_tokens(ptr_str);

    char** tokens = malloc((num_tokens+1) * sizeof(char*));

    int w;

    for(w = 0; w<num_tokens; w++) {
        char* start_char = word_start(ptr_str);
        char* end_char = word_end(start_char);
        int word_size = token_size(start_char, end_char); 
        tokens[w] = copy_str(start_char, word_size);
        printf("%s\n",tokens[w]);
        ptr_str = end_char; 
    }

    return tokens;
}

char* copy_str(char* ptr_str, short str_size) {

    char* token = (char*) malloc(str_size * sizeof(char));

    int c;

    for (c = 0; str_size>0; c++) {
        token[c] = *ptr_str;
        ptr_str++;
        str_size--;
    }

   return token;
}

int token_size(char* ptr_start, char* ptr_end) {
    int size = 0;
    while (ptr_start != ptr_end) {
        size++;
        ptr_start++;
    }
    return size;
}

char* word_start(char* ptr_str) {
    while ((*ptr_str) != '\0' && delim_character((*ptr_str))) { // until there are whitespaces
        ptr_str++;
    }
    return ptr_str;
}

char* word_end(char* ptr_str) {
    while (*(ptr_str+1) != '\0' && !delim_character((*ptr_str))) { // until there are non-whitespaces
        ptr_str++;
    }
    return ptr_str;
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