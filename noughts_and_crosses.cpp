#include<iostream>
#include "nac_functions.h"

int main() //The main function
{
    int index1;
    char board[9] = {'*','*','*','*','*','*','*','*','*'};
    int move;
    char choice;
    std::cout<<"===============================\n";
    std::cout<<"Welcome to Noughts and Crosses!\n";
    std::cout<<"===============================\n\n";
    std::cout<<"Your symbol: O\n";
    std::cout<<"CPU symbol: X\n\n";
    std::cout<<"Would you like to go first? [y/n] ";
    std::cin>>choice;
    if(choice == 'y')
    {
        draw_board(board);
        up: std::cout<<std::endl<<"Choose a box by entering its label: ";
        std::cin>>move;
        if(board[move-1]=='*')
        {
            board[move-1] = 'O';
            draw_board(board);
        }
        else
        {
            std::cout<<std::endl<<"Invalid move. Try again: ";
            goto up;
        }
    }

    while(true)
    {

        std::cout<<std::endl<<"CPU MOVE....";
        minimax(true, board, index1);
        board[index1] = 'X';
        draw_board(board);
        if(win_checker(board, 'X'))
        {
            std::cout<<std::endl<<"CPU wins!";
            break;
        }
        if(isFull(board)==1)
        {
            std::cout<<std::endl<<"Draw....";
            break;
        }
again:  std::cout<<std::endl<<"Choose a box by entering its label: ";
        std::cin>>move;
        if (board[move - 1] != '*') {
            std::cout << std::endl << "Invalid move. Try again: \n";
            goto again;
        } else {
            board[move - 1] = 'O';
            draw_board(board);
        }
        if(win_checker(board, 'O'))
        {
            std::cout<<std::endl<<"You won!";
            break;
        }
        if(isFull(board) == 1)
        {
            std::cout<<std::endl<<"It's a draw!";
            break;
        }
    }

    std::cout << "\n\nGame over!";

}
