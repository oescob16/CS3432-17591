#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char** tokenizer(char* ptr, int str_size);
_Bool is_delimiter(char* c);

int main()
{
    char str[] = "Hello, world!";
    char** tokens = tokenizer(str, sizeof(str));
    return(0);
}

char** tokenizer(char* ptr, int str_size) {

    char** ptr_of_ptr;
    int c;

    for(c = 0; c<str_size; c++) {
        bool isspace = is_delimiter(ptr);
        ptr++; 
    }

    return ptr_of_ptr;
}

bool is_delimiter(char* c) {
    return (*c) == ' ';
}