#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int NUM_MOVES = 18;

const char *faces[] = { "U", "D", "F", "B", "L", "R",
                        "U\'", "D\'", "F\'", "B\'", "L\'", "R\'",
                        "U2", "D2", "F2", "B2", "L2", "R2" };

/* NOTATION
** Right moves never follow Left (RL allowed, LR not)
** Up never follows down (UD allowed, DU not)
** Front never follows back (FB allowed, BF not)
** After an UP turn, we are allowed: D L R F B D' L' R' F' B' D2 L2 R2 F2 B2
** AFTER a DOWN turn, we are allowed: F B L R F' B' L' R' L2 R2 F2 B2
** After a FRONT turn, we are allowed: U D L R B
*/
int transition_table[7][18] = {
    {1,2,3,4,5,7,8,9,10,11,13,14,15,16,17,0,0,0},
    {2,3,4,5,8,9,10,11,14,15,16,17,0,0,0,0,0,0},
    {0,1,3,4,5,6,7,9,10,11,12,13,15,16,17,0,0,0},
    {0,1,4,5,6,7,10,11,12,13,16,17,0,0,0,0,0,0},
    {0,1,2,3,5,6,7,8,9,11,12,13,14,15,17,0,0,0},
    {0,1,2,3,6,7,8,9,12,13,14,15,0,0,0,0,0,0},
    {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17}
};


void clear_scramble(int * scramble) {
    for(int i = 0; i < 64; i++) {
        scramble[i] = 0;
    }
}

void reset_cube(int * cube) {
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 9; j++) {
            cube[i * 9 + j] = i;
        }
    }
}

int create_scramble(int * cube, int * scramble) {
    int scramble_length = (int)(((double)rand() / ((double)RAND_MAX + 1.0) * 32.0) + 32.0);

    for(int i = 0; i < scramble_length; i++) {
        int direction = (int)((double)rand() / ((double)RAND_MAX + 1.0) * ((double)NUM_MOVES - 1.0));
        turn(direction, cube);
        scramble[i] = direction;
    }

    return scramble_length;
}

void print_cube(int * cube) {
    for(int face = 0; face < 6; face++) {
        printf("%s: \n", faces[face]);
        for(int row = 0; row < 3; row++) {
            for(int col = 0; col < 3; col++) {
                printf("%d ", cube[face * 9 + row * 3 + col]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return;
}

void print_scramble(int scramble_length, int * scramble) {
    for(int i = 0; i < scramble_length; i++) {
        printf("%s ", faces[scramble[i]]);
    }

    printf("\n");
}

int is_solved(int * cube) {
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 9; j++) {
            if(cube[i * 9 + j] == i) {
                continue;
            }
            else {
                return 0;
            }
        }
    }
    return 1;
}

int solve_cube(int * cube, int depth, int last_turn) {
    int result = 0;

    if(is_solved(cube)) {
        return 1;
    }

    else if(depth > 0) {
        int num_of_moves = 0;
        if(last_turn == 6) {
            num_of_moves = 18;
        }
        else {
            num_of_moves = (last_turn % 2 == 0) ? 15 : 12;
        }
        for(int i = 0; i < num_of_moves; i++) {
            int cube_copy[54];
            memcpy(cube_copy, cube, sizeof(int) * 54);
            turn(transition_table[last_turn][i], cube_copy);
            result = (result || solve_cube(cube_copy, depth - 1, i % 6));
        }
    }

    return result;
}

