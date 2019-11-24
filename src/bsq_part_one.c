/*
** EPITECH PROJECT, 2019
** fill_tab
** File description:
** fill the tab
*/
#include "../include/my.h"

void disp_final(char **buff, char *buf)
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
    int i = skip_first_line(buff);
    int x = 0;
    int width = backslash_n_counter(buff) - 1;

    tab = fill_tab(buff, width, x, i);
    tab = find_square(tab, buff);
    final_tab = final_tab_whitout_number(tab, buff);
    final_tab = final_tab_with_number(final_tab, find_square_col(tab),
    find_square_line(tab), find_square_size(tab));
    disp_final(final_tab, buff);
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