#ifndef CUBE_H
#define CUBE_H

void clear_scramble(int * scramble);
int create_scramble(int * cube, int * scramble);
void print_cube(int * cube);
void print_scramble(int scramble_length, int * scramble);
int is_solved(int * cube);
int solve_cube(int * cube, int depth);

#endif