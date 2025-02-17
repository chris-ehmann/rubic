#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
** Notation: Up = 0; Down = 1, Front = 2; Back = 3; Left = 4; Right = 5;
*/

const char *faces[] = { "Up", "Down", "Front", "Back", "Left", "Right" };

void rotate_face(int face, int * cube) {
    int idx = face * 9;
    int cpy = cube[idx];
    cube[idx] = cube[idx + 6];
    cube[idx + 6] = cube[idx + 8];
    cube[idx + 8] = cube[idx + 2];
    cube[idx + 2] = cpy;

    cpy = cube[idx + 3];
    cube[idx + 3] = cube[idx + 7];
    cube[idx + 7] = cube[idx + 5];
    cube[idx + 5] = cube[idx + 1];
    cube[idx + 1] = cpy;
}

void turn(int dir, int * cube) {
    rotate_face(dir, cube);

    if(dir == 0) {
        int face_cpy = cube[18];
        int face_cpy_2 = cube[19];
        int face_cpy_3 = cube[20];

        cube[18] = cube[45];
        cube[19] = cube[46];
        cube[20] = cube[47];

        cube[45] = cube[27];
        cube[46] = cube[28];
        cube[47] = cube[29];

        cube[27] = cube[36];
        cube[28] = cube[37];
        cube[29] = cube[38];

        cube[36] = face_cpy;
        cube[37] = face_cpy_2;
        cube[38] = face_cpy_3;
    }

    else if(dir == 1) {
        int face_cpy = cube[24];
        int face_cpy_2 = cube[25];
        int face_cpy_3 = cube[26];

        cube[24] = cube[42];
        cube[25] = cube[43];
        cube[26] = cube[44];

        cube[42] = cube[33];
        cube[43] = cube[34];
        cube[44] = cube[35];

        cube[33] = cube[51];
        cube[34] = cube[52];
        cube[35] = cube[53];

        cube[51] = face_cpy;
        cube[52] = face_cpy_2;
        cube[53] = face_cpy_3;
    }

    else if(dir == 2) {
        int face_cpy = cube[6];
        int face_cpy_2 = cube[7];
        int face_cpy_3 = cube[8];

        cube[6] = cube[44];
        cube[7] = cube[41];
        cube[8] = cube[38];

        cube[38] = cube[9];
        cube[41] = cube[10];
        cube[44] = cube[11];

        cube[9] = cube[51];
        cube[10] = cube[48];
        cube[11] = cube[45];

        cube[45] = face_cpy;
        cube[48] = face_cpy_2;
        cube[51] = face_cpy_3;
    }

    else if(dir == 3) {
        int face_cpy = cube[0];
        int face_cpy_2 = cube[1];
        int face_cpy_3 = cube[2];

        cube[0] = cube[47];
        cube[1] = cube[50];
        cube[2] = cube[53];

        cube[47] = cube[17];
        cube[50] = cube[16];
        cube[53] = cube[15];

        cube[15] = cube[36];
        cube[16] = cube[39];
        cube[17] = cube[42];

        cube[42] = face_cpy;
        cube[39] = face_cpy_2;
        cube[36] = face_cpy_3;  
    }

    else if(dir == 4) {
        int face_cpy = cube[0];
        int face_cpy_2 = cube[3];
        int face_cpy_3 = cube[6];

        cube[0] = cube[35];
        cube[3] = cube[32];
        cube[6] = cube[29];

        cube[29] = cube[15];
        cube[32] = cube[12];
        cube[35] = cube[9];

        cube[9] = cube[18];
        cube[12] = cube[21];
        cube[15] = cube[24];

        cube[18] = face_cpy;
        cube[21] = face_cpy_2;
        cube[24] = face_cpy_3;  
    }

    else if(dir == 5) {
        int face_cpy = cube[2];
        int face_cpy_2 = cube[5];
        int face_cpy_3 = cube[8];

        cube[2] = cube[20];
        cube[5] = cube[23];
        cube[8] = cube[26];

        cube[20] = cube[11];
        cube[23] = cube[14];
        cube[26] = cube[17];

        cube[11] = cube[33];
        cube[14] = cube[30];
        cube[17] = cube[27];

        cube[27] = face_cpy_3;
        cube[30] = face_cpy_2;
        cube[33] = face_cpy;  
    }
    return;
}

void clear_scramble(int * scramble) {
    for(int i = 0; i < 64; i++) {
        scramble[i] = 0;
    }
}

int create_scramble(int * cube, int * scramble) {
    int scramble_length = (int)(((double)rand() / ((double)RAND_MAX + 1.0) * 32.0) + 32.0);

    for(int i = 0; i < scramble_length; i++) {
        int direction = (int)((double)rand() / ((double)RAND_MAX + 1.0) * 5.0);
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
int main()
{
    int cube[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   1, 1, 1, 1, 1, 1, 1, 1, 1,
                   2, 2, 2, 2, 2, 2, 2, 2, 2,
                   3, 3, 3, 3, 3, 3, 3, 3, 3, 
                   4, 4, 4, 4, 4, 4, 4, 4, 4,
                   5, 5, 5, 5, 5, 5, 5, 5, 5 };

    int scramble[64];
    int solve[64];

    clear_scramble(solve);
    clear_scramble(scramble);

    int curr_scramble_length = create_scramble(cube, scramble);

    print_cube(cube);
    print_scramble(curr_scramble_length, scramble);

    return 0;
}