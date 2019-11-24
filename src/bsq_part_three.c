/*
** EPITECH PROJECT, 2019
** part three
** File description:
** part three
*/
#include "../include/my.h"

int skip_first_line(char *str)
{
    int i = 0;
    for (; str[i] != '\n'; i++);
    i++;
    return (i);
}

int **fill_tab(char *buff, int width, int x, int i)
{
    int n = 0;
    int **tab = malloc(sizeof(int*) * (width + 1));

    for (int o = 0;o < width + 1; o++)
        tab[o] = malloc(sizeof(int) * (strlen_two_line(buff) + 1));
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

int **find_square(int **matrix, char* buff, int n, int x)
{
    int **find_square;
    int width = backslash_n_counter(buff) - 1;
    find_square = malloc(sizeof(int*) * width + 1);

    for (int o = 0; o < width + 1; o++)
        find_square[o] = malloc(sizeof(int) * (strlen_two_line(buff) + 2));
    while (matrix[x][n] != -2) {
        while (matrix[x][n] != -1) {
            if (matrix[x][n] == 0)
                find_square[x][n] = 0;
            else if (matrix[x][n] != 0) {
                if (x == 0 || n == 0) {
                    find_square[x][n] = lower_number(0,0,0);
                } else {
                    find_square[x][n] = lower_number(find_square[x][n - 1],
                    find_square[x - 1][n], find_square[x - 1][n - 1]);
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