/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** collisions
*/

#include "my.h"

int move_box3(char *map, int i, int dir, int line)
{
    if (dir == 2) {
        if (map[i + 1] != '#' && map[i + 1] != 'X') {
            map[i] = ' ';
            map[i + 1] = 'X';
            return (0);
        }
    } else if (dir == 3) {
        if (map[i - 1] != '#' && map[i - 1] != 'X') {
            map[i] = ' ';
            map[i - 1] = 'X';
            return (0);
        }
    }
    return (84);
}

int move_box2(char *map, int i, int dir, int line)
{
    if (dir == 0) {
        if (map[i - line] != '#' && map[i - line] != 'X') {
            map[i] = ' ';
            map[i - line] = 'X';
            return (0);
        }
    } else if (dir == 1) {
        if (map[i + line] != '#' && map[i + line] != 'X') {
            map[i] = ' ';
            map[i + line] = 'X';
            return (0);
        }
    }
    return (84);
}

int move_boxe(char *map, int i, int dir)
{
    int line;

    for (int j = i; map[j] != '\n';) {
        j--;
        if (map[j - 1] == '\n') {
            for (line = 1; map[j] != '\n'; j++)
                line++;
            break;
        }
    }
    if (move_box2(map, i, dir, line) == 0)
        return (0);
    if (move_box3(map, i, dir, line) == 0)
        return (0);
    return (84);
}

int collision(char *map, int x, int y, int dir)
{
    int x2 = 0;
    int y2 = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        x2++;
        if (map[i] == '\n') {
            x2 = 0;
            y2++;
        }
        if (x == x2 && y == y2) {
            if (map[i] == '#')
                return (84);
            if (map[i] == 'X') {
                if (move_boxe(map, i, dir) == 84)
                    return (84);
            }
            break;
        }
    }
    return (0);
}