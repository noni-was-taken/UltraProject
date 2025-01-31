#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct{
    char name[20];
    int damage;
}moves;

typedef struct{
    int health;
    moves moveset[2];
}monsterInfo;

char displayMenu();

void displayMonsters(monsterInfo*, moves*);

int main(){
    //Initialize Move Names
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
    monster[0].health = 100;
        monster[0].moveset[0] = move[0];
        monster[0].moveset[1] = move[1];

    monster[1].health = 75;
        monster[1].moveset[0] = move[1];
        monster[1].moveset[1] = move[2];

    //Player Choice
Choice:    
    switch(displayMenu()){
        case 'a':
        case 'b':
           displayMonsters(monster, move);
           goto Choice;
        case 'c':
        //  displayRules();
            printf("Mura rag Pokemon uy\n\n");
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
    return input;
}

void displayMonsters(monsterInfo* monster, moves* move){
    //Display all monsters
    printf("Present Monsters:");
    for(int i = 0; i < 2; i++){
        printf("\nMonster %d:", i+1);
        printf("\n\tHealth: %dhp", monster[i].health);
        printf("\n\tMoveset:");
        for(int j = 0; j < 2; j++){
            printf("\n\t\t%s - %d damage", monster[i].moveset[j].name, monster[i].moveset[j].damage);
        }
    }
}

