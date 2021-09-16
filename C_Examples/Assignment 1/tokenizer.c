#include <stdio.h>

char** tokenizer(char* ptr, int str_size) {
    char** ptr_of_ptr;
    int c;
    for(c = 0; c<str_size; c++) {
        ptr++;
    }
    return ptr_of_ptr;
}

int main()
{
    char str[] = "Hello, world!";
    char** tokens = tokenizer(str, sizeof(str));
    return(0);
}