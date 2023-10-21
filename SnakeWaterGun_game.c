#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// This function play the game and shows result:
// 1 --> player wins
// 0 --> computer wins
int game(){
    printf("WELCOME TO 'Snake Water Gun' GAME\n");
    printf("Enter 's' for snake, 'w' for water and 'g' for gun\n");
    printf("1 game = 5 matches\n");
    printf("Now lets begin.\n\n");

    char components[3] = {'s','w','g'};
    int match_num, player_score=0, computer_score=0;

    for (match_num = 1; match_num <= 5; match_num++){
        char player, computer;
        printf("Match %d.\n",match_num);
        printf("Your chance --> ");
        scanf(" %c", &player);
        
        srand(time(0));
        int number = rand()%3;
        computer = components[number];
        printf("Computer chose --> %c\n", computer);

        if(player == computer){
            printf("Draw\n");
            match_num--;
        }
        
        if(player=='s' && computer=='g'){
            printf("Computer Scores\n");
            computer_score++;
        }
        else if(player=='g' && computer=='s'){
            printf("Player Scores\n");
            player_score++;
        }

        if(player=='s' && computer=='w'){
            printf("Player Scores\n");
            player_score++;
        }
        else if(player=='w' && computer=='s'){
            printf("Computer Scores\n");
            computer_score++;
        }

        if(player=='g' && computer=='w'){
            printf("Computer Scores\n");
            computer_score++;
        }
        else if(player=='w' && computer=='g'){
            printf("Player Scores\n");
            player_score++;
        }
        printf("Player = %d\n", player_score);
        printf("Computer = %d\n\n", computer_score);
    }
    if (player_score > computer_score) return 1;
    else if (player_score < computer_score) return 0;
}

int main(){
    int play_game = 1;
    while (play_game==1){    
        int result = game();
        if (result == 1){
            printf("Congratulations! You Win The Game.\n");
            printf("Do you want to play again.\n");
        }
        else if (result == 0){
            printf("Computer Win The Game.\n");
            printf("Do you Want To Try Again.\n");
        };
        printf(" 1 --> for yes\n 0 --> for no\n");
        scanf("%d", &play_game);
    }
    return 0;
}