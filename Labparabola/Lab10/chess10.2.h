#pragma once
#include <stdio.h>

typedef struct {
    char column;  // from 'a' to 'h'
    int row;      // from 1 to 8
} ChessSquare;

extern void inputSquare(ChessSquare *s);
extern void printSquare(ChessSquare s);
extern int canQueenMove(ChessSquare from, ChessSquare to);
