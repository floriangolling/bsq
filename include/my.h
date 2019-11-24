/*
** EPITECH PROJECT, 2019
** my_h_bsq
** File description:
** my_h_bsq
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef my_h_bsq
#define my_h_bsq

void end_tab_disp(char *buff, int **tab, char **final_tab);
int my_strlen(char *str);
void my_putstr(char *str);
void my_putchar(char c);
int lower_number(int i, int x, int y);
int **find_square(int **matrix, char* buff);
int find_square_col(int **matrix);
int find_square_size(int **matrix);
int find_square_line(int **matrix);
char **final_tab_whitout_number(int **tab,char *buff);
char **final_tab_with_number(char **buff, int line, int col, int size);
void disp_final(char **buff,char *buf);
int open_and_read(char *filepath);
int main(int ac, char **av);
int **fill_tab(char *buff, int width, int x, int i);
int skip_first_line(char *str);
int backslash_n_counter(char *buff);
int strlen_two_line(char *str);



#endif /* !my_h_bsq */
