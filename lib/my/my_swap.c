/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** 
*/

int my_swap(int *a, int *b)
{
    int d;

    d = *a;
    *a = *b;
    *b = d;
    return (0);
}
