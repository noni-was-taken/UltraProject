#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct{
    char name[20];
    int damage;
}moves;

typedef struct{
    char name[20];
    int health;
    moves moveset[2];
}monsterInfo;

char displayMenu();

void displayMonsters(monsterInfo*, moves*);

void monsterFight(monsterInfo*, moves*);

int main(){
    //Initialize Move Names
    char *monsterNames[] = {"shrimp", "squid", "whale"};
    char *moveNames[] = {"tickle", "bite", "choke"};

    //Allocate Memory
    monsterInfo *monster = (monsterInfo*)calloc(5, sizeof(monsterInfo));
    
    moves move[3];
   
    //Initialize Moves
    strcpy(move[0].name, moveNames[0]); //tickle
    move[0].damage = 15;

    strcpy(move[1].name, moveNames[1]); //bite
    move[1].damage = 20;
    
    strcpy(move[2].name, moveNames[2]); //choke
    move[2].damage = 25;

    //Initializing Monsters
    strcpy(monster[0].name, monsterNames[0]);
    monster[0].health = 100;
        monster[0].moveset[0] = move[0];
        monster[0].moveset[1] = move[1];

    strcpy(monster[1].name, monsterNames[1]);
    monster[1].health = 75;
        monster[1].moveset[0] = move[1];
        monster[1].moveset[1] = move[2];

    strcpy(monster[2].name, monsterNames[2]);
    monster[2].health = 125;
        monster[2].moveset[0] = move[0];
        monster[2].moveset[1] = move[2];
    //Player Choice
Choice:    
    switch(displayMenu()){
        case 'a':
            monsterFight(monster, move);
            printf("///////////////////////////////////\n           Thanks for Playing\n///////////////////////////////////");
            exit(0);
        case 'b':
           displayMonsters(monster, move);
           goto Choice;
        case 'c':
            printf("\nThere will be two players, which they will be given a choice to pick between 3 monsters\nAfter picking, they will compete with each other.\nFirst monster to faint loses.\n\nHave fun.\n");
            goto Choice;
        case 'd':
            printf("Thank you for checking ts out");
            exit(0);
        default:
            printf("Something went wrong...");
            exit(1);
    }
    
    free(monster);
    return 0;
}

char displayMenu(){
    char input;
Menu:    
    printf("Welcome to ProjectUltra\n\n");
    printf("What do you want to do?\n");
    printf("A.Play B.Display Monsters C.Rules D.Quit\n");
    scanf(" %c", &input);
    if(tolower(input) > 'd' || tolower(input) < 'a'){
        printf("Invalid Input\n\n");
        goto Menu;
    }
    system("cls");
    return input;
}

void displayMonsters(monsterInfo* monster, moves* move){
    //Display all monsters
    printf("Present Monsters:");
    for(int i = 0; i < 3; i++){
        printf("\nMonster %d: %s", i+1, monster[i].name);
        printf("\n\tHealth: %dhp", monster[i].health);
        printf("\n\tMoveset:\n");
        for(int j = 0; j < 2; j++){
            printf("\t\t%s - %d damage\n", monster[i].moveset[j].name, monster[i].moveset[j].damage);
        }
    }
}

void monsterFight(monsterInfo* monster, moves* move){
    monsterInfo *playerOne, *playerTwo;
    char input;
pOnePick:
    printf("Player One, Pick a monster: (a)shrimp (b)squid (c)whale");
    printf("\nPlayer 1>> ");
    scanf(" %c", &input);
 
    switch(tolower(input)){
        case 'a':
            memcpy(playerOne, (monster+0), sizeof(monsterInfo));
            break;
        case 'b':
            memcpy(playerOne, (monster+1), sizeof(monsterInfo));
            break;
        case 'c':
            memcpy(playerOne, (monster+2), sizeof(monsterInfo));
            break;
        default:
            goto pOnePick;
            break;
    }
pTwoPick:
    printf("Player Two, Pick a monster: (a)shrimp (b)squid (c)whale");
    printf("\nPlayer 2>> ");
    scanf(" %c", &input);

    switch(tolower(input)){
        case 'a':
            memcpy(playerTwo, (monster+0), sizeof(monsterInfo));
            break;
        case 'b':
            memcpy(playerTwo, (monster+1), sizeof(monsterInfo));
            break;
        case 'c':
            memcpy(playerTwo, (monster+2), sizeof(monsterInfo));
            break;
        default:
            goto pTwoPick;
            break;
    }
    printf("Lets fight");
}