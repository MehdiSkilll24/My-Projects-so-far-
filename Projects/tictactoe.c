#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

bool Check_Win(char grid[3][3], char symbol){
    for(int i = 0; i<3; i++){
        if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) {
            return true;
        }
    }
    for(int j = 0; j<3; j++){
         if (grid[0][j] == symbol && grid[1][j] == symbol && grid[2][j] == symbol) {
            return true;
        }
    }
    if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) {
        return true;
    }
    if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol) {
        return true;
    }
    return false;
} 

void grid_fct(char grid[3][3]){
    for (int i = 0; i<3; i++){
        for (int j= 0; j<3; j++){
            printf(" %c", grid[i][j]);
            if (j < 2){
            printf(" | ");
            }   
        }
        printf("\n");
        if  ( i < 2 ){
            printf("-----------\n");
        }
    }
}
bool Play_Again(bool *Game){
    printf("Play Again ? ( Y/N )\n");
    char answer;
    scanf(" %c", &answer);
    answer = toupper(answer);
    while (answer != 'Y' && answer != 'N'){
        printf("Enter Y or N only\n");
        scanf(" %c", &answer);
        answer = toupper(answer);}
    if (answer == 'N'){
        *Game = false;
        }
    return *Game;
}
int main(){
    srand(time(0));
    int choice_AI_i;
    int choice_AI_j;
    int choice_i;
    int choice_j;
    bool Game = true;
    int counter = 0;

    char grid[][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    grid_fct(grid);
    do{
        printf("Choose coordinate for i:\n");
        scanf("%d", &choice_i);

        while (choice_i < 0 || choice_i > 2){
        printf("Invalid,choose i between 0-2:\n");
        scanf("%d", &choice_i);
        }

        printf("Choose coordinate for j:\n");
        scanf("%d", &choice_j);

        while (choice_j<0 || choice_j >2){
        printf("j must be between 0 and 2 !\n");
        scanf("%d", &choice_j);
        }

        while(grid[choice_i][choice_j] != ' '){
        printf("Full ! Choose again\n");
        scanf("%d", &choice_i);
        scanf("%d", &choice_j);
        }

        grid[choice_i][choice_j] = 'X';

        if (Check_Win(grid,'X')){
            printf("Player wins !\n");
            grid_fct(grid);
            Game = Play_Again(&Game);
            if (Game){
                counter = 0;
                for ( int i = 0; i<3; i++){
                    for ( int j =0; j< 3; j++){
                        grid[i][j] = ' ';
                    }
                }
            }
        }

        if (counter == 5){
            grid_fct(grid);
            printf("Game over!");
            counter = 0;
            Game = Play_Again(&Game);
            if(Game){
                for ( int i = 0; i<3; i++){
                    for ( int j =0; j< 3 ; j++){
                        grid[i][j] = ' ';
                    }
                }
                grid_fct(grid);
            }
        }
        
        choice_AI_i = rand() % 3;
        choice_AI_j = rand() % 3;
        while(grid[choice_AI_i][choice_AI_j] != ' '){
            choice_AI_i = rand() % 3;
            choice_AI_j = rand() % 3;}
        grid[choice_AI_i][choice_AI_j] = 'O';
        printf("\n");
        grid_fct(grid);
        if (Check_Win(grid,'O')){
            printf("AI wins!\n");
            counter = 0;
            grid_fct(grid);
            Game = Play_Again(&Game);
            if(Game){
                for ( int i = 0; i<3; i++){
                    for ( int j =0; j< 3 ; j++){
                        grid[i][j] = ' ';
                    }
                }grid_fct(grid);
            }
        }
    } while(Game);
    return 0;
}