/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/
#include "../include/my.h"

int main(int ac, char **av)
{
    if (open_and_read(av[1]) == 84)
        return (84);
    return (0);
}