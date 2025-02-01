#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
char key[50];
char code[10];
int value;
}Clients;

Clients dict[10];
int count = 0;

void checker(char* code){
    while(1){
        int found = 0;
        for (int i = 0; i < count ; i++){
            if ((strcmp(dict[i].code, code) == 0)){
                printf("Code taken, try a different one\n");
                found = 1;
                break;
            }
        }
        if (!found){
            break;
        }
        else{
            fgets(code, 10, stdin);
            code[strcspn(code, "\n")] = 0;
        }
    }
}
int deposit(int value);

int withdraw(int value);

char Auth(char *name, char* code)
{
    char answer;

    printf("Welcome ! Are you new ? ( Y / N )\n");
    scanf(" %c" , &answer);
    answer = toupper(answer);
    while ( answer != 'Y' && answer != 'N'){
        printf("Sorry, try again using either Y or N\n");
        scanf(" %c" , &answer);
        answer = toupper(answer);
    }
    getchar();

    if (answer == 'Y'){
        printf("Welcome ! Enter your name please:\n");
        fgets(name, 100, stdin);
        name[strcspn(name, "\n")] = 0;

        while(strlen(name) == 0){
            printf("Enter a valid name please:\n");
            fgets(name, 100, stdin);
            name[strcspn(name, "\n")] = 0;
        }

        printf("Enter a 4 digit ID card code:\n");
        fgets(code, 10, stdin);
        code[strcspn(code, "\n")] = 0;

        while (strlen(code) != 4 || !isdigit(code[0]) || !isdigit(code[1]) || !isdigit(code[2]) || !isdigit(code[3])){
            printf("Invalid, enter 4 numerical digits: ");
            fgets(code, 10, stdin);
            code[strcspn(code, "\n")] = 0;
        }
        checker(code);
        printf("Welcome %s:%s\n", name, code);
    }else{
        printf("Enter your ID card's code please\n");
        fgets(code, 10, stdin);
        code[strcspn(code,"\n")] = 0;
        while (strlen(code) != 4 || !isdigit(code[0]) || !isdigit(code[1]) || !isdigit(code[2]) || !isdigit(code[3])){
            printf("Invalid, enter 4 numerical digits: ");
            fgets(code, 10, stdin);
            code[strcspn(code, "\n")] = 0;
        }
    }

    return answer;

}

int find_client(Clients *dict, int count, char *code){
    while(1){
        for ( int i = 0; i < count ; i++){
            if (strcmp(dict[i].code, code) == 0){
                printf("Welcome, %s !\n", dict[i].key);
                return i;
            }
        }
            printf("Nothing found, try again or enter `exit` to exit:\n");
            fgets(code, 10, stdin);
            code[strcspn(code, "\n")] = 0;
            if (strcmp(code, "exit") == 0 ){
                printf("Exiting...\n");
                exit(0);
            }
            while (strlen(code) != 4 || !isdigit(code[0]) || !isdigit(code[1]) || !isdigit(code[2]) || !isdigit(code[3])){
                printf("Invalid, enter 4 numerical digits or enter `exit` to exit:\n");
                fgets(code, 10, stdin);
                code[strcspn(code, "\n")] = 0;
            if (strcmp(code, "exit") == 0 ){
                printf("Exiting...\n");
                exit(0);
            }
            }
    }
}

void check_balance(int value){
    int option;
    printf("Your current balance is %d $\n", value);
    printf("Would you like to deposit(1), withdraw(2), or exit(3) ?\n");
    scanf("%d", &option);
    getchar();
    switch(option){
        case 1:
            deposit(value);
            break;
        case 2:
            withdraw(value);
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
            break;
    }
}

int withdraw(int value){
    int Withdraw;
    int option;
    printf("Enter the amount to withdraw\n");
    scanf("%d", &Withdraw);
    while(Withdraw > value){
        printf("Insufficient funds\n");
        scanf("%d", Withdraw);
    }
    value-= Withdraw;
    printf("Withdrawal successful, would you like to check balance(1), deposit(2) or exit(3) ?");
    scanf("%d", &option);
    getchar();
    while(option != 1 && option != 2 && option != 3){
        printf("Invalid, try again\n");
        scanf("%d", &option);
        getchar();
    }
    switch(option){
        case 1:
            check_balance(value);
            break;
        case 2:
            deposit(value);
            break;
        case 3:
            printf("Exiting...");
            exit(0);
            break;
    }
}

int deposit(int value){
    char input[100];
    int deposit;
    int option;
    printf("How much would you like to deposit ?\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    while(strlen(input) == 0){
        printf("Amount cannot be empty, try again\n");
        fgets(input, sizeof(input), stdin);
    }
    deposit = atoi(input);
    while(deposit < 0){
        printf("You can't deposit such a value, try again \n");
        fgets(input, sizeof(input), stdin);
        deposit = atoi(input);
        getchar();
    }
    value+= deposit;
    printf("Deposit successful\nWould you like to exit (4), check balance(1), or withdraw(3) ?\n");
    scanf("%d", &option);
    switch(option){
        case 1:
            check_balance(value);
            break;
        case 3:
            withdraw(value);
            break;
        case 4:
            exit(0);
            break;
    }
    return value;
}


void options(int value){
    int option;
    printf("To check the balance, enter 1:\nTo deposit, enter 2:\nTo withdraw, enter 3:\nTo exit, enter 4:");
    scanf("%d", &option);
    while (option != 1 && option != 2 && option != 3 && option != 4 ){
        printf("Invalid choice, try again :");
        scanf("%c", &option);
    }
    switch(option){
        case 1:
        check_balance(value);
        break;
        case 2:
        deposit(value);
        break;
        case 3:
        withdraw(value);
        break;
        case 4:
        exit(0);
        break;
    }
}

int main (){



strcpy(dict[count].key, "Milton");
strcpy(dict[count].code, "1234");
dict[count].value = 10000;
count++;
strcpy(dict[count].key, "Micah");
strcpy(dict[count].code, "0917");
dict[count].value = -100000;
count++;
strcpy(dict[count].key, "Trelawny");
strcpy(dict[count].code, "1591");
dict[count].value =1000000;
count++;
strcpy(dict[count].key, "Arthur");
strcpy(dict[count].code, "1372");
dict[count].value =10000;
count++;
strcpy(dict[count].key, "John");
strcpy(dict[count].code, "3671");
dict[count].value =10;
count++;
strcpy(dict[count].key, "Dutch");
strcpy(dict[count].code, "1920");
dict[count].value = 100000;
count++;

    char name[100];
    char code[10];
    char answer;
    answer = Auth(name, code);
    if (answer == 'N'){
    int Client_index = find_client(dict, count, code);
    options(dict[Client_index].value);
    }
    else{
        options(0);
    }
}