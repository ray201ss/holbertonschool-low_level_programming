#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
void reset_to_98(int *n);
void swap_int(int *a, int *b);
int _strlen(char *s);
void _puts(char *str);
void print_rev(char *s);
void rev_string(char *s);
void puts2(char *str);
void puts_half(char *str);
void print_array(int *a, int n);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
cd ~/holbertonschool-low_level_programming
git add .
git commit -m "Add 1-strncat.c"
git push origin main
char *_strncat(char *dest, char *src, int n);
#endif
