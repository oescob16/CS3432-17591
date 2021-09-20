#ifndef HEADERS_H
#define HEADERS_H

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
bool delim_character(char c);

/* Returns a pointer to the first character of the next
   space-separated word*/
char* word_start(char* str); 

/* Returns a pointer to the first space character of the zero
terminated string*/
char* word_end(char* str);

/* Returns an integer with the size of the token */
int token_size(char* ptr_start, char* ptr_end);

// counts the number of words or tokens
int count_tokens(char* str);

/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.
   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char* copy_str(char *inStr, short len);

char** tokenize(char* str);

void print_all_tokens(char** tokens);

#endif