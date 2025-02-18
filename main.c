#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cube_perms.h"
#include "cube.h"

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
    int max_depth = 12;

    while(1) {
        for(int i = 0; i <= max_depth; i++) {
            clock_t start, stop;
            printf("Current depth: %d\n", i);

            start = clock();
            int result = solve_cube(cube, i);
            stop = clock();

            float duration = ( float ) ( stop - start ) / CLOCKS_PER_SEC;

            printf("Duration for depth %d: %f seconds\n", i, duration);

            if(result) {
                printf("Cube solved with a depth of %d\n", i);
                break;
            }
        }
        printf("No solution found, trying again...\n");
        reset_cube(cube);
        clear_scramble(scramble);
        curr_scramble_length = create_scramble(cube, scramble);
    }

    return 0;
}