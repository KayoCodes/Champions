//
//  champion.c
//  Project3
//
//  Created by keenan ray on 11/22/22.
//

#include "champion.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
Champion* createChampion(void){
    Champion * champ =(Champion*) malloc(sizeof(Champion)); //allocates memory for the objects
    int chance = 0;
    
    chance = rand() % 4; ///four outcomes making the chance of either 0,1,2,3 a 1/4 chance
    
    switch(chance)
    {
        case 0:
            
            champ -> role = MAGE;
            int l = (rand() % ///randomly generates level between 1 and 5
            (4) + 5);
            champ->level = l;
            champ ->next = NULL;
            
            break;
        case 1:
            
            champ -> role = FIGHTER;
            int a = (rand() % //randomly generated number between 1 and 4
            (4) + 1);
            champ ->level = a;
            champ->next = NULL;
            break;
        case 2:
            
            champ -> role = SUPPORT;
            int b = (rand() % //randomly generates number between 3 and 6
            (4) + 3);
            champ->level = b;
            champ ->next = NULL;
            break;
        case 3:
            
            champ ->role = TANK;
            int c = (rand() % //randomly generates number between 1 and 8
            (8) + 1);
            champ->level= c;
            champ -> next = NULL;
            break;
            
    }
    return champ;
    
}
Champion* addChampion(Champion*head, Champion*c) ///adds node to the front of the linked list
{
    Champion* cur = head;
    Champion * prev = NULL;
    while(cur != NULL && cur->level > c->level)
    {
        prev = cur;
        cur = cur ->next;
    }
    if(prev == NULL)
    {
        c -> next = cur;
        return c;
    }
    prev -> next = c;
    c->next = cur;
    return head;
}

Champion* buildChampionList(int n)
{
    Champion* head = NULL;
    Champion*temp;
    int i = 0;
    for(i = 0; i<n; i++){ //takes in user input (n) and created that many champion nodes;
        temp = createChampion();
        head = addChampion(head, temp);
    }
    return head;
    }
void printChampionList(Champion*head)
{
    Champion* t = head;
    while(t !=NULL){
        switch(t->role){ //prints out output for each of the different champion roles
            case 0:
                printf("M%d ",t->level); //output for mage
                break;
            case 1:
                printf("F%d ",t->level); //output for fighter
                break;
            case 2:
                printf("S%d ",t->level); //output for support
                break;
            case 3:
                printf("T%d ",t->level); //output for tank
                break;
                }
        
        t=t->next;
    }
    printf("\n");
}
Champion * removeChampion(Champion*head) //removes champion from head of the list
{
    Champion * cur = head;
    if(head == NULL){
        return NULL;
    }
    
    head = head->next;
    free(cur);
    return head;
}
Champion* destroyChampionList( Champion *head ) //destroys the linked list
{
    while(head != NULL)
    {
        Champion*t = head;
        head = head->next;
        free(t); //deallocate memory freeing the space
    }
    return NULL;
}
