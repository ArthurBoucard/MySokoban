/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int is_win(char *map)
{
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'O')
        return (84);
    }
    return (0);
}

int print_map(char *map, int x, int y, char *mem_map)
{
    initscr();
    curs_set(FALSE);
    int key;
    keypad(stdscr, TRUE);
    int mem_x = x;
    int mem_y = y;

    while (1) {
        printw(map);
        mvaddch(y, x, 'P');
        refresh();
        key = getch();
        clear();
        if (key == KEY_UP)
            if (collision(map, x + 1, y - 1, 0) == 0)
                y--;
        if (key == KEY_DOWN)
            if (collision(map, x + 1, y + 1, 1) == 0)
                y++;
        if (key == KEY_RIGHT)
            if (collision(map, x + 2, y, 2) == 0)
                x++;
        if (key == KEY_LEFT)
            if (collision(map, x, y, 3) == 0)
                x--;
        if (key == ' ') {
            map = my_strcpy(map, mem_map);
            x = mem_x;
            y = mem_y;
        } else if (key == 27)
            break;
        if (is_win(map) == 0) {
            printw(map);
            mvaddch(y, x, 'P');
            refresh();
            sleep(1);
            endwin();
            return (0);
        }
    }
    endwin();
}

int find_player(char *map, char *mem_map)
{
    int i;
    int x = 0;
    int y = 0;

    for (i = 0; map[i] != 'P'; i++) {
        x++;
        if (map[i] == '\n') {
            x = 0;
            y++;
        }
    }
    map[i] = ' ';
    mem_map[i] = ' ';
    print_map(map, x, y, mem_map);
    return (0);
}

void help()
{
    my_printf("USAGE\n");
    my_printf("     ./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("     map file representing the warehouse map, containing");
    my_printf(" '#' for walls,\n");
    my_printf("         'P' for the players 'X' for boxes and 'O' for ");
    my_printf("storage locations.\n");
}

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    char buff[1];
    char *map;
    char *mem_map;
    int len = 0;

    if (exist(av[1]) == 84)
        return (84);
    if (ac != 2)
        return (84);
    else if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        help(av[1]);
        return (0);
    }
    for (int test = 1; test != 0; len++)
        test = read(fd, buff, 1);
    map = map_malloc(av[1], fd, len);
    mem_map = map_malloc(av[1], fd, len);
    if (verif(map) == 84)
        return (84);
    find_player(map, mem_map);
    return (0);
}
