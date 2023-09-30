//
//  champion.h
//  Project3
//
//  Created by keenan ray on 11/22/22.
//

#ifndef champion_h
#define champion_h

#include <stdio.h>
enum ChampionRole{MAGE, FIGHTER,SUPPORT, TANK};
typedef struct Champion{
   enum ChampionRole role;
    int level;
    struct Champion * next;
    
}Champion;
Champion* createChampion(void);
Champion* addChampion( Champion *head, Champion *c );
Champion* buildChampionList( int n );
void printChampionList( Champion *head );
Champion* removeChampion( Champion *head );
Champion* destroyChampionList( Champion *head );
#endif /* champion_h */
