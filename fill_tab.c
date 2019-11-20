/*
** EPITECH PROJECT, 2019
** fill_tab
** File description:
** fill the tab
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int my_strlen(char *str)
{
    int x = 0;

    while (str[x])
        x++;
    return (x);
}

void my_putstr(char *str)
{
    write(1 , str, my_strlen(str));
}

void my_putchar(char c)
{
    write (1, &c ,1);
}

int my_strlen_second_line(char *str)
{
    int i = 0;
    int n = 0;

    for (; str[i] != '\n'; i++);
    i++;
    while (str[i] != '\n') {
        n++;
        i++;
    }
    return (n);
}

int backslash_n_counter(char *buff)
{
    int i = 0;
    int n = 0;

    while (buff[i] != '\0'){
        if (buff[i] == '\n')
            n++;
        i++;
    }
    return (n);
}

int skip_first_line(char *str)
{
    int i = 0;
    for (; str[i] != '\n'; i++);
    i++;
    return (i);
}

int **fill_tab(char *buff)
{
    int **tab;
    int n = 0;
    int i = skip_first_line(buff);
    int x = 0;
    int width = backslash_n_counter(buff) - 1;
    tab = malloc(sizeof(int*) * (width + 1));

    for (int o = 0;o < width + 1; o++)
        tab[o] = malloc(sizeof(int) * (my_strlen_second_line(buff) + 1));
    for (; buff[i] != '\0'; i++) {
        for (; buff[i] != '\n' && buff[i] != '\0'; i++) {
            if (buff[i] == 'o')
                tab[n][x] = 0;
            else if (buff[i] == '.')
                tab[n][x] = 1;
            x++;
        }
        tab[n][x] = -1;
        x = 0;
        n++;
    }
    tab[n][0] = -2;
    return (tab);
}

int lower_number(int i, int x, int y)
{
    int temp = 0;

    if (i <= x && i <= y)
        temp = i + 1;
    else if (x <= i && x <= y)
        temp = x + 1;
    else
        temp = y + 1;
    return (temp);
}

int **find_square(int **matrix, char* buff)
{
    int **find_square;
    int n = 0;
    int x = 0;
    int width = backslash_n_counter(buff) - 1;
    find_square = malloc(sizeof(int*) * width + 1);

    for (int o = 0; o < width + 1; o++)
        find_square[o] = malloc(sizeof(int) * (my_strlen_second_line(buff) + 2));
    while (matrix[x][n] != -2) {
        while (matrix[x][n] != -1) {
            if (matrix[x][n] == 0)
                find_square[x][n] = 0;
            else if (matrix[x][n] != 0) {
                if (x == 0 || n == 0) {
                    find_square[x][n] = lower_number(0,0,0);
                } else {
                    find_square[x][n] = lower_number(find_square[x][n - 1], find_square[x - 1][n], find_square[x - 1][n - 1]);
                }
            }
            n++;
        }
            find_square[x][n] = -1;
            n = 0;
            x++;
    }
    find_square[x][n] = -2;
    return(find_square);
}

int find_square_col(int **matrix)
{
    int **find_square = matrix;
    int n = 0;
    int temp = 0;
    int tempy = 0;

    for (int x = 0; matrix[x][n] != -2; x++) {
        while (matrix[x][n] != -1) {
            if (matrix[x][n] > temp) {
                temp = matrix[x][n];
                tempy = x;
            }
            n++;
        }
        n = 0;
    }
    return (tempy);
}

int find_square_size(int **matrix)
{
    int **find_square = matrix;
    int n = 0;
    int temp = 0;
    int tempx = 0;

    for (int x = 0; matrix[x][n] != -2; x++) {
        while (matrix[x][n] != -1) {
            if (matrix[x][n] > temp) {
                temp = matrix[x][n];
                tempx = x;
            }
            n++;
        }
        n = 0;
    }
    return (temp);
}

int find_square_line(int **matrix)
{
    int **find_square = matrix;
    int n = 0;
    int temp = 0;
    int tempx = 0;

    for (int x = 0; matrix[x][n] != -2; x++) {
        while (matrix[x][n] != -1) {
            if (matrix[x][n] > temp) {
                temp = matrix[x][n];
                tempx = n;
            }
            n++;
        }
        n = 0;
    }
    return (tempx);
}

char **final_tab_whitout_number(int **tab,char *buff)
{
    int width = backslash_n_counter(buff) - 1;
    char **final_tab = malloc(sizeof(char*) * width );
    int n = 0;

    for (int o = 0; o < width; o++)
        final_tab[o] = malloc(sizeof(char) * (my_strlen_second_line(buff) + 2));
    for (int x = 0; tab[x][n] != -2; x++) {
        while (tab[x][n] != -1) {
            if (tab[x][n] == 0)
                final_tab[x][n] = 'o';
            else 
                final_tab[x][n] = '.';
            n++;
        }
    final_tab[x][n] = '\0';
    n = 0;
    }
    return (final_tab);
}

char **final_tab_with_number(char **buff, int line, int col, int size)
{
    int temp3 = col;
    int temp = size;
    int temp2 = size;
    char **final = buff;

    while (temp2 > 0) {
        while (temp > 0) {
            final[line][col] = 'x';
            col--;
            temp--;
        }
        col = temp3;
        temp = size;
        temp2--;
        line--;
        }
    return (final);
}

void disp_final(char **buff,char *buf)
{
    int width = backslash_n_counter(buf) - 1;
    int x = 0;


    while (width > 0) {
        my_putstr(buff[x]);
        my_putchar('\n');
        x++;
        width--;
    }
}

void end_tab_disp(char *buff, int **tab, char **final_tab)
{
    tab = fill_tab(buff);
    tab = find_square(tab,buff);
    final_tab = final_tab_whitout_number(tab,buff);
    final_tab = final_tab_with_number(final_tab, find_square_col(tab), find_square_line(tab), find_square_size(tab)); // add final tab
    disp_final(final_tab,buff);
    free(tab);
    free(final_tab);
}

int size_buff(char *filepath)
{   
    int size;
    struct stat st;

    stat(filepath, &st);
    size = st.st_size;
    return (size);
}

int open_and_read(char *filepath)
{
    int fd;
    char *buff;
    char **final_tab;
    int **tab;
    int size = size_buff(filepath);

    if (size < 1)
        return (84);
    buff = malloc(sizeof(char) * size + 1);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    read(fd, buff, size);
    buff[size] = '\0';
    end_tab_disp(buff, tab, final_tab);
    free(buff);
    close (fd);
    return (0);
}
