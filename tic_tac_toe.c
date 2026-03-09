#include<stdio.h>
#include<stdbool.h>
#define EMPTY ' '
#define BOARD_SIZE 9
#define PLAYER_x 'X'
#define PLAYER_o 'O'


void init_board(char*board){   // fixed name
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

bool make_move(char *board,int pos,char player){   // fixed name
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
        {0,1,2},{3,4,5},{6,7,8},
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

// tie condition
bool is_board_full(char *board){
    for(int i=0;i<BOARD_SIZE;i++){
        if(board[i]==EMPTY){
            return false;
        }
    }
    return true;
}



//  function to print board
void print_board(char *board){
    printf("\n");
    for(int i=0;i<BOARD_SIZE;i++){
        printf(" %c ", board[i]==EMPTY ? '0'+i : board[i]);
        if(i%3!=2) printf("|");
        if(i%3==2 && i!=8) printf("\n---+---+---\n");
    }
    printf("\n\n");
}


//main function to run the game
int main(){

    char board[BOARD_SIZE];
    char current_player = PLAYER_x;
    int pos;

    init_board(board);

    while(true){

        print_board(board);

        printf("Player %c, enter position (0-8): ", current_player);
        scanf("%d",&pos);

        if(!make_move(board,pos,current_player)){
            printf("Invalid move. Try again.\n");
            continue;
        }

        char winner = check_winner(board);

        if(winner!=EMPTY){
            print_board(board);
            printf("Player %c wins!\n",winner);
            break;
        }

        if(is_board_full(board)){
            print_board(board);
            printf("It's a tie!\n");
            break;
        }

        // switch player
        current_player = (current_player==PLAYER_x) ? PLAYER_o : PLAYER_x;
    }

    return 0;
}
