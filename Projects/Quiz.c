#include <stdio.h>
#include <ctype.h>

int main()
{
    int score = 0;
    char questions[][100]= {"1. What year did the C language debut?: ",
                            "2. Who is credited with creating C?:",
                            "3. What is the predecessor of C?: "};
                            
    char options[][100] = {"A. 1969","B. 1972","C. 1975","D. 1999",
                           "A. Dennis Ritchie", "B. Nikola Tesla", "C. John Carmack", "D. Doc Brown",
                           "A. Objective C", "B. B", "C. C++", "D. C#"};
                          
    char answers[] = {'B', 'A', 'B'};

    char guess;

    for ( int i = 0; i< sizeof(questions)/sizeof(questions[0]); i++){
        printf(" %s\n", questions[i]);
        for ( int j = ( i * 4 ); j < ( i * 4 ) + 4 ; j++){
        printf(" %s\n", options[j]);
        }
        printf("Enter your guess:\n");
        scanf(" %c", &guess);
        char capital = toupper(guess);
        if (capital == answers[i]){
            printf("Bingo !\n");
            score ++;
        }
        else{
            printf("Nope !\n");
        }
    }
    printf("You answered %d/3 questions correctly, your score is", score );
}