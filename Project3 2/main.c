//
//  main.c
//  Project3
//
//  Created by keenan ray on 11/22/22.
//

#include <stdio.h>
#include "champion.h"
#include <stdlib.h>
#include <time.h>
int main(int argc, const char * argv[])
{
    int round =1; //initialize round at 1
    
 srand((int)time(NULL));
  const char *a = argv[1];
    int num = atoi(a);
    if(argc >= 2){ //checks number of args on commandline
       
        if(num > 0)
        {
          //input is good
        }
        else
        {
            printf("Error"); //input cant be 0 or less
            return - 1;
        }
    }
    else
    {
        printf("Error command line arg does not exist\n");
        return -1;
    }
    Champion*player1 = NULL; ///initializes player one and player two creating two seperate linked list heads
    Champion*player2 = NULL;
   player1 = buildChampionList(num);
    player2 = buildChampionList(num);
    while(player1 != NULL && player2 !=NULL)
    {
        printf("-----Round %d-----\n", round);
        printf("Player 1: ");
        printChampionList(player1);
        printf("Player 2: ");
        printChampionList(player2);
        if(player1 ->role == MAGE && player2 ->role == MAGE)
        { //Mage vs Mage
            if(player1->level > player2->level)
            {
                printf("Player 1 is a MAGE and Player 2 is a MAGE\n");
                printf("Player 1 (MAGE) wins and gains one new champion.\n");
                printf("Player 2 (MAGE) loses one champion.\n");
                player1 = removeChampion(player1);
                player1 = addChampion(player1, createChampion());
                player2 = removeChampion(player2);
                player2 = removeChampion(player2);
                
            }
            else if(player2->level >player1->level)
            {
                printf("Player 1 is a MAGE and Player 2 is a MAGE\n");
                printf("Player 1 (MAGE) loses one champion.\n");
                printf("Player 2 (MAGE) wins and gains one new champion.\n");
                player1 = removeChampion(player1);
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                player2 = addChampion(player2, createChampion());
                
            }
            else
            {
                printf("Player 1 is a MAGE and Player 2 is a MAGE\n");
                printf("Player 1 Tie, No Penalties\n");
                printf("Player 2 Tie, No Penalties\n");
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
            }
        }
        
      else if((player1->role == FIGHTER && player2->role == MAGE))
      { //Fighter vs Mage
            if(player1->level > player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                player2 = removeChampion(player2);
                printf("Player 1 is a FIGHTER and Player 2 is a MAGE\n");
                printf("Player 1 (FIGHTER) wins but gains no reward.\n");
                printf("Player 2 (MAGE) loses one champion.\n");
                
            }
            else if(player2->level > player1->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                player2 = addChampion(player2, createChampion());
                printf("Player 1 is a FIGHTER and Player 2 is a MAGE\n");
                printf("Player 1 (FIGHTER) loses but with no penalty\n");
                printf("Player 2 (MAGE) wins and gains a new champion\n");
            }
            else
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                printf("Player 1 is a FIGHTER and Player 2 is a MAGE\n");
                printf("Nothing happens - no penalty or reward.\n");
                
            }
        }
             else if((player1->role == MAGE && player2->role == FIGHTER))
             { ///Mage vs Fighter
                    if(player1->level > player2->level)
                    {
                        player1 = removeChampion(player1);
                        player2 = removeChampion(player2);
                        player1 = addChampion(player1, createChampion());
                        printf("Player 1 is a MAGE and Player 2 is a FIGHTER\n");
                        printf("Player 1 (MAGE) wins and gains a new champion\n");
                        printf("Player 2 (FIGHTER) loses but with no penalty\n");
                        
                    }
                    else if(player2->level > player1->level)
                    {
                        player1 = removeChampion(player1);
                        player2 = removeChampion(player2);
                        player1 = removeChampion(player1);
                        printf("Player 1 is a MAGE and Player 2 is a FIGHTER\n");
                        printf("Player 1 (MAGE) loses one champion\n");
                        printf("Player 2 (FIGHTER) wins but gains no reward\n");
                    }
                    else
                    {
                        player1 = removeChampion(player1);
                        player2 = removeChampion(player2);
                        printf("Player 1 is a MAGE and Player 2 is a FIGHTER\n");
                        printf("Nothing happens - no penalty or reward.\n");
                        
                    }
                
                }
       else if(player1->role== MAGE && player2->role == SUPPORT)
       { //Mage vs Support
            if(player1->level > player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                player1 = addChampion(player1, createChampion());
                player2 = removeChampion(player2);
                player2 = removeChampion(player2);
                printf("Player 1 is a MAGE and Player 2 is a SUPPORT\n");
                printf("Player 1 (MAGE) wins and gains a new champion\n");
                printf("Player 2 (SUPPORT) loses two champions\n");
                
            }
            else if(player2->level > player1->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                player2 = addChampion(player2, createChampion());
                player2 = addChampion(player2, createChampion());
                player1 = removeChampion(player1);
                printf("Player 1 is a MAGE and Player 2 is a SUPPORT\n");
                printf("Player 1 (MAGE) loses one champion\n");
                printf("Player 2 (SUPPORT) gains two champions\n");
                
            }
            else
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                printf("Player 1 is a MAGE and Player 2 is a SUPPORT\n");
                printf("Nothing happens - no penalty or reward.\n");
                
            }
            
        }
      else if(player1->role== SUPPORT && player2->role == MAGE)
      { //Support vs Mage
            if(player1->level > player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                player1 = addChampion(player1, createChampion());
                player1 = addChampion(player1, createChampion());
                player2 = removeChampion(player2);
                printf("Player 1 is a SUPPORT and Player 2 is a MAGE\n");
                printf("Player 1 (SUPPORT) wins and gains two champions\n");
                printf("Player 2 (MAGE) loses one champion\n");
            }
            else if(player1->level < player2->level)
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                player2 = addChampion(player2, createChampion());
                player1 = removeChampion(player1);
                player1 = removeChampion(player1);
                printf("Player 1 is a SUPPORT and Player 2 is a MAGE\n");
                printf("Player 1 (SUPPORT) loses two champions\n");
                printf("Player 2 (MAGE) wins and gains a new champion\n");
            }
            else
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                printf("Nothing happens - no penalty or reward.\n");
            }
            
        }
      else if(player1->role == MAGE && player2->role==TANK)
      { //Mage vs Tank
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            player2 = removeChampion(player2);
            player1 = addChampion(player1, createChampion());
            printf("Player 1 is a MAGE and Player 2 is a TANK\n");
            printf("Player 1 (MAGE) wins and gains a new champion\n");
            printf("Player 2 (TANK) loses a champion\n");
        }
      else  if(player1->role == TANK && player2->role==MAGE)
      { //Trank vs mage
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            player1 = removeChampion(player1);
            player2 = addChampion(player2, createChampion());
            printf("Player 1 is a TANK and Player 2 is a MAGE\n");
            printf("Player 1 (TANK) loses a champion\n");
            printf("Player 2 (MAGE) wins and gains a new champion\n");
        }
      else  if(player1->role == FIGHTER && player2->role == FIGHTER)
      { //Fighter vs Fighter
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            player1 = addChampion(player1, createChampion());
            player2 = addChampion(player2, createChampion());
            printf("Player 1 is a FIGHTER and Player 2 is a FIGHTER\n");
            printf("Player 1 (FIGHTER) gains a new champion\n");
            printf("Player 2 (FIGHTER) gains a new champion\n");
            
        }
      else  if(player1->role == SUPPORT && player2->role == FIGHTER)
      { //Support vs Fighter
            if(player1->level > player2->level){ // support wins
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                player1= addChampion(player1, createChampion());
                printf("Player 1 is a SUPPORT and Player 2 is a FIGHTER\n");
                printf("Player 1 (SUPPORT) wins and gains a new champion\n");
                printf("Player 2 (FIGHTER) loses but with no penalty\n");
            }
            else if(player1->level < player2->level)
            { //fighter wins
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                player1 = removeChampion(player1);
                printf("Player 1 is a SUPPORT and Player 2 is a FIGHTER\n");
                printf("Player 1 (SUPPORT) loses a champion\n");
                printf("Player 2 (FIGHTER) wins but gains no reward\n");
                
            }
            else
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                printf("Nothing happens - no penalty or reward.\n");
            }
        }
      else if(player1->role == FIGHTER && player2->role ==SUPPORT)
      { //Fighter vs Support
            if(player1->level > player2->level){ //fighter wins
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                player2 = removeChampion(player2);
                printf("Player 1 is a FIGHTER and Player 2 is a SUPPORT\n");
                printf("Player 1 (FIGHTER) wins but gains no reward\n");
                printf("Player 2 (SUPPORT) loses a champion\n");
                }
            else if (player1->level < player2->level)
            { //support wins
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                player2= addChampion(player2, createChampion());
                printf("Player 1 is a FIGHTER and Player 2 is a SUPPORT\n");
                printf("Player 1 (FIGHTER) loses but with no penalty\n");
                printf("Player 2 (SUPPORT) wins and gains a new champion\n");
                }
            else
            {
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                printf("Nothing happens - no penalty or reward.\n");
            }
        }
       else if(player1->role == SUPPORT && player2->role ==SUPPORT)
       { //Support vs Support
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            printf("Player 1 is a SUPPORT and Player 2 is a SUPPORT\n");
            printf("Both players lose the next champion.\n");
        }
       else if(player1->role ==TANK && player2->role == FIGHTER)
       { /// Tank vs Fighter
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            player2 = addChampion(player2, createChampion());
            printf("Player 1 is a TANK and Player 2 is a FIGHTER\n");
            printf("Player 1 (TANK) loses but with no penalty\n");
            printf("Player 2 (FIGHTER) wins and gains a new champion.\n");
        }
       else if(player1->role ==FIGHTER && player2->role == TANK)
       { /// Fighter vs Tank
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            player1 = addChampion(player1, createChampion());
            printf("Player 1 is a FIGHTER and Player 2 is a TANK\n");
            printf("Player 1 (FIGHTER) wins and gains a new champion\n");
            printf("Player 2 (TANK) loses but with no penalty\n");
        }
       else if(player1->role == TANK && player2->role == SUPPORT)
       { //Tank vs Support
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            player1 = addChampion(player1, createChampion());
            printf("Player 1 is a TANK and Player 2 is a SUPPORT\n");
            printf("Player 1 (TANK) wins and gains a new champion\n");
            printf("Player 2 (SUPPORT) loses but with no penalty.\n");
        }
       else if(player1->role== SUPPORT && player2->role == TANK)
       { //Support vs Tank
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            player2 = addChampion(player2, createChampion());
            printf("Player 1 is a SUPPORT and Player 2 is a TANK\n");
            printf("Player 1 (SUPPORT) loses but with no penalty.\n");
            printf("Player 2 (TANK) wins and gains a new champion\n");
            }
        
       else if(player1->role ==TANK && player2->role == TANK)
       { //Tank vs Tank
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
            printf("Player 1 is a TANK and Player 2 is a TANK\n");
            printf("Nothing happens - no penalty or reward.\n");
        }
        round++;
        printf("\n");
        
    }
    printf("Player 1 ending champions list :");
    printChampionList(player1);
    printf("Player 2 ending champions list :");
    printChampionList(player2);
    printf("\n");
    
    if(player1 == NULL && player2 == NULL)
    {
        printf("TIE -- both players ran out of champions.\n");
    }
    else if(player1 == NULL)
    {
        printf("Player 2 Wins\n");
    }
    else
    {
        printf("Player 1 Wins\n");
    }
    return 0;
}
