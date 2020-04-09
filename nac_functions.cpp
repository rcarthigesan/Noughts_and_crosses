//
// Created by raman on 08/04/2020.
//

#include "nac_functions.h"
#include<iostream>
#include<vector>
#include <algorithm>
#include <string>

int isFull(char board[9])// Board is full
{
    for(int i =0;i<9;i++)
    {
        if(board[i]!='X')
        {
            if(board[i]!='O')
            {
                return 0;
            }
        }
    }
    return 1;
}

bool win_checker(char board[9], char symbol) {

    std::vector<int> magic_values = {4, 3, 8, 9, 5, 1, 2, 7, 6};
    std::vector<int> player_scores = {-1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000};
    std::vector<std::string> win_vector = {"Win!"};

    for (int i = 0; i < 9; i++) {
        if (board[i] == symbol) {
            player_scores[i] = magic_values[i];
        }
    }

    //Check if any three of score values add up to 15
    std::sort(player_scores.begin(), player_scores.end());

    for (int k = 0; k < player_scores.size() - 2; k++) {

        int left = k + 1;
        unsigned long right = player_scores.size() - 1;

        while (left < right) {

            if (player_scores[k] + player_scores[left] + player_scores[right] == 15) {
                return true;
            } else if (player_scores[k] + player_scores[left] + player_scores[right] < 15) {
                left++;
            } else {
                right--;
            }

        }

    }

    return false;

}

void draw_board(const char board[9]) //display tic-tac-toe board
{
    char display_board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 9; i++) {
        if (board[i] != '*') {
            display_board[i] = board[i];
        }
    }
    
    std::cout<<std::endl;
    std::cout << "     |     |      \n";
    std::cout << "  " << display_board[0] << "  |  " << display_board[1] << "  |  " << display_board[2] << "   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  " << display_board[3] << "  |  " << display_board[4] << "  |  " << display_board[5] << "   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  " << display_board[6] << "  |  " << display_board[7] << "  |  " << display_board[8] << "   \n";
    std::cout << "     |     |      \n\n";
}

int minimax(bool flag, char board[9], int &index1)// The minimax function
{

    int max_val=-1000,min_val=1000;
    int value;
    if(win_checker(board, 'X'))
    {return 10;}
    else if(win_checker(board, 'O'))
    {return -10;}
    else if(isFull(board)== 1)
    {return 0;}
    int score[9] = {1,1,1,1,1,1,1,1,1};//if score[i]=1 then it is empty

    for(int i=0;i<9;i++)
    {
        if(board[i] == '*')
        {
            if(min_val>max_val) // reverse of pruning condition.....
            {
                if(flag)
                {
                    board[i] = 'X';
                    value = minimax(false, board, index1);
                }
                else
                {
                    board[i] = 'O';
                    value = minimax(true, board, index1);
                }
                board[i] = '*';
                score[i] = value;
            }
        }
    }

    if(flag)
    {
        max_val = -1000;
        for(int j=0;j<9;j++)
        {
            if(score[j] > max_val && score[j] != 1)
            {
                max_val = score[j];
                index1 = j;
            }
        }
        return max_val;
    }
    min_val = 1000;
    for (int j = 0; j < 9; j++) {
        if (score[j] < min_val && score[j] != 1) {
            min_val = score[j];
            index1 = j;
        }
    }
    return min_val;
}
