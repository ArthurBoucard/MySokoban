/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** verif
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int verif(char *map)
{
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != ' ' && map[i] != '#' && map[i] != 'P' \
            && map[i] != 'O' && map[i] != 'X' && map[i] != '\n')
                return (84);
        }
    return (0);
}

char *map_malloc(char *av, int fd, int len)
{
    char *map = malloc(sizeof(char) * len);

    close(fd);
    fd = open(av, O_RDWR);
    read(fd, map, len);
    return (map);
}

int exist(const char *fd)
{
    FILE *file;

    if ((file = fopen(fd, "r")) != NULL)
        return (0);
    return (84);
}