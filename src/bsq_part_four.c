/*
** EPITECH PROJECT, 2019
** part four
** File description:
** part four
*/
#include "../include/my.h"

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
    char **final_tab = malloc(sizeof(char*) * width);
    int n = 0;

    for (int o = 0; o < width; o++)
        final_tab[o] = malloc(sizeof(char) * (strlen_two_line(buff) + 2));
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