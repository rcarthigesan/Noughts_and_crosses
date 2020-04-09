//
// Created by raman on 08/04/2020.
//

#include<iostream>
#include<vector>
#include <algorithm>
#include <string>

int isFull(char board[9]);

bool win_checker(char board[9], char symbol);

void draw_board(const char board[9]);

int minimax(bool flag, char board[9], int &index1);
