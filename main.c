#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cube_perms.h"
#include "cube.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


int main()
{
    system("cls");
    srand ( time(NULL) );
    
    int cube[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   1, 1, 1, 1, 1, 1, 1, 1, 1,
                   2, 2, 2, 2, 2, 2, 2, 2, 2,
                   3, 3, 3, 3, 3, 3, 3, 3, 3, 
                   4, 4, 4, 4, 4, 4, 4, 4, 4,
                   5, 5, 5, 5, 5, 5, 5, 5, 5 };

    const char *faces[] = { "U", "D", "F", "B", "L", "R",
                        "U\'", "D\'", "F\'", "B\'", "L\'", "R\'",
                        "U2", "D2", "F2", "B2", "L2", "R2" };

    int scramble[64];
    int solve[64];

    clear_scramble(solve);
    clear_scramble(scramble);

    int curr_scramble_length = create_scramble(cube, scramble);
    print_cube(cube);

    for(int i = 0; i < curr_scramble_length; i++) {
        turn(scramble[i], cube);
        system("cls");
        print_cube(cube);
        Sleep(150);
    }

    printf("Scrambled!\n\n");

    char t[2];

    while(1) {
        printf("Enter turn: ");
        scanf("%s", &t);
        printf("\n");
        int next_turn = -1;

        while(next_turn == -1) {
            for(int i = 0; i < 18; i++) {
                if(strcmp(faces[i], t) == 0) {
                    next_turn = i;
                }
            }

            if(next_turn == -1) {
                printf("Not a valid turn, please enter a valid turn: ");
                scanf("%s", &t);
                printf("\n");
            }
        }

        turn(next_turn, cube);
        system("cls");
        print_cube(cube);

        if(is_solved(cube)) {
            printf("Solved!");
        }
    }

    return 0;
}