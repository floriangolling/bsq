/*
** EPITECH PROJECT, 2019
** part_two
** File description:
** part_two
*/
#include "../include/my.h"

int my_strlen(char *str)
{
    int x = 0;

    while (str[x])
        x++;
    return (x);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_putchar(char c)
{
    write (1, &c ,1);
}

int strlen_two_line(char *str)
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