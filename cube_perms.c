#include "cube_perms.h"

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

void rotate_face_ccw(int face, int * cube) {
    int idx = face * 9;
    int cpy = cube[idx];

    cube[idx] = cube[idx + 2];
    cube[idx + 2] = cube[idx + 8];
    cube[idx + 8] =  cube[idx + 6];
    cube[idx + 6] = cpy;

    cpy = cube[idx + 3];
    cube[idx + 3] = cube[idx + 1];
    cube[idx + 1] = cube[idx + 5];
    cube[idx + 5] = cube[idx + 7];
    cube[idx + 7] = cpy;
}

void turn(int dir, int * cube) {
    if(dir < 6) {
        rotate_face(dir, cube);
    }

    else if(dir >= 6 && dir < 12) {
        rotate_face_ccw(dir % 6, cube);
    }

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

    else if(dir == 6) {
        int face_cpy = cube[18];
        int face_cpy_2 = cube[19];
        int face_cpy_3 = cube[20];

        cube[18] = cube[36];
        cube[19] = cube[37];
        cube[20] = cube[38];

        cube[36] = cube[27];
        cube[37] = cube[28];
        cube[38] = cube[29];

        cube[27] = cube[45];
        cube[28] = cube[46];
        cube[29] = cube[47];

        cube[45] = face_cpy;
        cube[46] = face_cpy_2;
        cube[47] = face_cpy_3;
    }

    else if(dir == 7) {
        int face_cpy = cube[24];
        int face_cpy_2 = cube[25];
        int face_cpy_3 = cube[26];

        cube[24] = cube[51];
        cube[25] = cube[52];
        cube[26] = cube[53];

        cube[51] = cube[33];
        cube[52] = cube[34];
        cube[53] = cube[35];

        cube[33] = cube[42];
        cube[34] = cube[43];
        cube[35] = cube[44];

        cube[42] = face_cpy;
        cube[43] = face_cpy_2;
        cube[44] = face_cpy_3;
    }

    else if(dir == 8) {
        int face_cpy = cube[6];
        int face_cpy_2 = cube[7];
        int face_cpy_3 = cube[8];

        cube[6] = cube[45];
        cube[7] = cube[48];
        cube[8] = cube[51];

        cube[45] = cube[11];
        cube[48] = cube[10];
        cube[51] = cube[9];

        cube[9] = cube[38];
        cube[10] = cube[41];
        cube[11] = cube[44];

        cube[38] = face_cpy_3;
        cube[41] = face_cpy_2;
        cube[44] = face_cpy;
    }

    else if(dir == 9) {
        int face_cpy = cube[0];
        int face_cpy_2 = cube[1];
        int face_cpy_3 = cube[2];

        cube[0] = cube[42];
        cube[1] = cube[39];
        cube[2] = cube[36];

        cube[36] = cube[15];
        cube[39] = cube[16];
        cube[42] = cube[17];

        cube[15] = cube[53];
        cube[16] = cube[50];
        cube[17] = cube[47];

        cube[47] = face_cpy;
        cube[50] = face_cpy_2;
        cube[53] = face_cpy_3;  
    }

    else if(dir == 10) {
        int face_cpy = cube[0];
        int face_cpy_2 = cube[3];
        int face_cpy_3 = cube[6];

        cube[0] = cube[18];
        cube[3] = cube[21];
        cube[6] = cube[24];

        cube[18] = cube[9];
        cube[21] = cube[12];
        cube[24] = cube[15];

        cube[9] = cube[35];
        cube[12] = cube[32];
        cube[15] = cube[29];

        cube[29] = face_cpy_3;
        cube[32] = face_cpy_2;
        cube[35] = face_cpy;
    }

    else if(dir == 11) {
        int face_cpy = cube[2];
        int face_cpy_2 = cube[5];
        int face_cpy_3 = cube[8];

        cube[2] = cube[33];
        cube[5] = cube[30];
        cube[8] = cube[27];

        cube[27] = cube[17];
        cube[30] = cube[14];
        cube[33] = cube[11];

        cube[11] = cube[20];
        cube[14] = cube[23];
        cube[17] = cube[26];

        cube[20] = face_cpy;
        cube[23] = face_cpy_2;
        cube[26] = face_cpy_3;
    }

    else if(dir >= 12) {
        int f = dir % 12;
        for(int i = 0; i < 2; i++) {
            turn(f, cube);
        }
    }
}