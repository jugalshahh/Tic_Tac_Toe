#include<stdio.h>
#include<stdbool.h>
#define EMPTY ' '
#define BOARD_SIZE 9
#define PLAYER_x 'X'
#define PLAYER_o 'O'


void int_board(char*board){
    for(int i=0;i<BOARD_SIZE;i++){
        board[i]=EMPTY;

    }

}

bool is_valid_move(char *board,int pos){
    if(pos>=BOARD_SIZE || pos<0){
        return false;
    }
    return board[pos]==EMPTY;
}

bool wake_move(char *board,int pos,char player){
    if(player!=PLAYER_x && player!=PLAYER_o){
        return false;
    }
    if(!is_valid_move(board,pos)){
        return false;
    }
    board[pos]=player;
    return true;
}

char check_winner(char *board){
    int win_pattern[8][3]={
        {0,1,2},{3,4,5,},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };

    for(int i=0;i<8;i++){
        int a=win_pattern[i][0];
        int b=win_pattern[i][1];
        int c=win_pattern[i][2];
        if(board[a]!=EMPTY && board[a]==board[b] && board[b]==board[c]){
            return board[a];

        }
    }
    return EMPTY;
}

//tie condition

bool is_board_full(char *board){
    for(int i=0;i<BOARD_SIZE;i++){
        if(board[i]==EMPTY){
            return false;
        }
    }
    return true;
}