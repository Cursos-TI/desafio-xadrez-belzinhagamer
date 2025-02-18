#include <stdio.h>

#define SIZE 8  

void moveBishop(int x, int y) {
    for (int i = 1; i < SIZE; i++) {
        printf("Bispo pode se mover para (%d, %d)\n", x + i, y + i); 
        printf("Bispo pode se mover para (%d, %d)\n", x - i, y - i);  
        printf("Bispo pode se mover para (%d, %d)\n", x + i, y - i);  
        printf("Bispo pode se mover para (%d, %d)\n", x - i, y + i);  
    }
}

    void moveRook(int x, int y) {
    for (int i = 0; i < SIZE; i++) {
        if (i != x) printf("Torre pode se mover para (%d, %d)\n", i, y);
    }
    for (int j = 0; j < SIZE; j++) {
        if (j != y) printf("Torre pode se mover para (%d, %d)\n", x, j);
    }
}

    void moveQueen(int x, int y) {
    for (int i = 1; i < SIZE; i++) {
        printf("Rainha pode se mover para (%d, %d)\n", x + i, y + i);  
        printf("Rainha pode se mover para (%d, %d)\n", x - i, y - i);  
        printf("Rainha pode se mover para (%d, %d)\n", x + i, y - i);  
        printf("Rainha pode se mover para (%d, %d)\n", x - i, y + i);  
    }
   
    for (int i = 0; i < SIZE; i++) {
        if (i != x) printf("Rainha pode se mover para (%d, %d)\n", i, y);
    }
    for (int j = 0; j < SIZE; j++) {
        if (j != y) printf("Rainha pode se mover para (%d, %d)\n", x, j);
    }
}

    void moveKnight(int x, int y) {
    int moves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    
    for (int i = 0; i < 8; i++) {
        int newX = x + moves[i][0];
        int newY = y + moves[i][1];
        if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
            printf("Cavalo pode se mover para (%d, %d)\n", newX, newY);
        }
    }
}

    void moveBishopRec(int x, int y, int deltaX, int deltaY) {
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
        printf("Bispo pode se mover para (%d, %d)\n", x, y);
        moveBishopRec(x + deltaX, y + deltaY, deltaX, deltaY);
    }
}

    int main() {
   
    int bishopX = 3, bishopY = 3;
    int rookX = 3, rookY = 3;
    int queenX = 3, queenY = 3;
    int knightX = 3, knightY = 3;

    moveBishop(bishopX, bishopY);
    moveRook(rookX, rookY);
    moveQueen(queenX, queenY);
    moveKnight(knightX, knightY);
    moveBishopRec(bishopX, bishopY, 1, 1);  
    moveBishopRec(bishopX, bishopY, -1, -1);  
    moveBishopRec(bishopX, bishopY, 1, -1);  
    moveBishopRec(bishopX, bishopY, -1, 1);  
    
    return 0;
}
