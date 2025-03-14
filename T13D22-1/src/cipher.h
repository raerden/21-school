#ifndef CIPHER_H
#define CIPHER_H
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_file(const char *filename);
void clear_input_buffer();
void append_to_file(char *filename, FILE *log_file);
char caesar_encode_char(char ch, int shift);
void clean_files(char *dirname, char *mask);
void caesar_encode(char *dirname, int shift, FILE *log_file);
void encode_caesar_cfile(char *fname, int shift);
void switch_menu_option(int menu_option, char *fname, FILE *log_file);

#endif
