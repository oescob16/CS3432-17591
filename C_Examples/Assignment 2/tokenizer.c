#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tokenizer.h"

char* trim(char* str) {

    /* start and end indices */
    int start = trim_left_pos(str); 
    int end = trim_right_pos(str);

    int len = end - start + 1; 
    char* new_str = (char*) malloc(len); // allocate memory for string without leading spaces
    
    int c = 0;
    while (c < len) {
        new_str[c]= str[start]; // copy str
        c++;
        start++;
    }

    new_str[c] = '\0'; // terminal symbol

    return new_str;
}

int trim_left_pos(char* str) {
    int left = 0;
    while(str[left] == ' ') { // while there are left leading spaces
        left++;
    }
    return left;
}

int trim_right_pos(char* str) {
    int right = str_size(str) - 1;
    while(str[right] == ' ') { // while there are right leading spaces
        right--;
    }
    return right;
}

int str_size(char* str) {
    int size = 0;
    while ((*str) != '\0') {
        size++;
        str++;
    }
    return size;
}

void print_all_tokens(char** tokens) {
    int t;
    for (t=0; (*tokens) != NULL; t++) {
        printf("tokens[%d]: %s\n", t, *tokens);
        tokens++;
    }
}
 
char** tokenize(char* ptr_str, char delim) {

    int num_tokens = count_tokens(ptr_str, delim);

    char** tokens = malloc((num_tokens+1) * sizeof(char*)); // allocate memory's size needed to store words

    int w;

    for(w = 0; w<num_tokens; w++) {
        char* start_char = word_start(ptr_str, delim); 
        char* end_char = word_end(start_char, delim);
        int word_size = token_size(start_char, end_char)-1; 
        tokens[w] = copy_str(start_char, word_size); // // store word in char** at index w
        ptr_str = end_char; // start next word
    }
    tokens[w] = NULL; // end of tokens

    return tokens;
}

char* copy_str(char* ptr_str, short str_size) {

    char* token = (char*) malloc((str_size+1) * sizeof(char)); // allocate memory's size needed to store chars

    int c;

    for (c = 0; str_size+1>0; c++) {
        token[c] = *ptr_str; // store char in char* at index c
        ptr_str++;
        str_size--;
    }
    token[c] = '\0'; // terminator symbol

   return token;
}

int token_size(char* ptr_start, char* ptr_end) {
    int size = 0;
    while (ptr_start != ptr_end) { // until they don't point to same chars
        size++;
        ptr_start++;
    }
    return size;
}

char* word_start(char* ptr_str, char delim) {
    while ((*ptr_str) != '\0' && delim_character((*ptr_str), delim)) { // until there are whitespaces
        ptr_str++;
    }
    return ptr_str;
}

char* word_end(char* ptr_str, char delim) {
    while (*(ptr_str+1) != '\0' && !delim_character((*ptr_str), delim)) { // until there are non-whitespaces
        ptr_str++;
    }
    return ptr_str;
}

int count_tokens(char* str, char delim) {
    int num_tokens = 0;
    char *ptr = str;
    while ((*ptr) != '\0') { // while we are not in the end of string
        if (delim_character((*ptr), delim)) { // if space then we have a word
            num_tokens++;
        } 
        ptr++;
    }
    return num_tokens+1;
}

bool delim_character(char c, char delim) {
    return c == delim;
}