#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// This function generates random number between 1 and 100
int generate_rand_no(){
    srand(time(0));
    int number = rand()%100 +1;
    return number;
}

// This function play the game and shows result:
// 1 --> player wins
// 0 --> player lose
int game(){
    printf("WELCOME TO 'GUESS THE NUMBER' GAME\n");
    printf("You have to guess a number between 1-100 in 10 chances.\n");
    printf("Now lets begin.\n\n");
    int i, selected_num, ans = generate_rand_no();
    for (i = 1; i <= 10; i++){
        printf("Guess your number --> ");
        scanf("%d", &selected_num);
        if (selected_num == ans){
            return 1;
        }
        else if (selected_num < ans){
            printf("Higher Number Please.\n");
        }
        else if (selected_num > ans){
            printf("Lower Number Please.\n");
        }
        printf("%d chances left.\n", 10-i);
    }
    return 0;
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
            printf("Sorry! You Lose The Game.\n");
            printf("Do You Want To Try Again.\n");
        };
        printf(" 1 --> for yes\n 0 --> for no\n");
        scanf("%d", &play_game);
    }
    return 0;
}