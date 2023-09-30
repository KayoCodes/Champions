# Champions
The project is to create a turn-based role-playing game between two (computer) players in which they battle each other with a list of champions. 
The game starts with 2 players having a list of random number of champions, as decided by the user. Each champion will be assigned a “role” and “level” based on some random probability. Each player has the same number of champions in the beginning. For both players, all the champions will always (at the start or any point in the gameplay) be sorted in the descending order of their “level”. In each turn, both the players will battle each other by deploying in their arena their best champion who is in the front of the list sorted according to the “level”. The outcome of the battle will be determined by the “role” and “level” of the two champions currently in the arena. After each turn, the current champion will be discarded from their list of champions and play the next champion. The battle can have different outcomes such as one or both players may gain extra (one or two) champions, or one or both players may lose extra (one or two) champions. Please see the table below on what the outcome is for a battle with two champions of the same or different “role”. The game continues until one player has lost all their champions. The player with any remaining champion wins.

Roles and Levels will be included in another file.

Sample Output
============= PLAYER 1 V PLAYER 2 SHOWDOWN ============

----- ROUND 1 -----
Player 1: M5 F4 F2 F2 F2
Player 2: M6 T5 T3 F2 T1
Player 1 is a MAGE and Player 2 is a MAGE
Player 1 (MAGE) loses one champion.
Player 2 (MAGE) wins and gains one new champion.

----- ROUND 2 -----
Player 1: F2 F2 F2
Player 2: T5 T3 S3 F2 T1
Player 1 is a FIGHTER and Player 2 is a TANK
Player 1 (FIGHTER) wins and gains a new champion.
Player 2 (TANK) loses but with no penalty.

----- ROUND 3 -----
Player 1: F2 F2 T2
Player 2: T3 S3 F2 T1
Player 1 is a FIGHTER and Player 2 is a TANK
Player 1 (FIGHTER) wins and gains a new champion.
Player 2 (TANK) loses but with no penalty.

----- ROUND 4 -----
Player 1: F4 F2 T2
Player 2: S3 F2 T1
Player 1 is a FIGHTER and Player 2 is a SUPPORT
Player 1 (FIGHTER) wins but gains no reward.
Player 2 (SUPPORT) loses one champion.

----- ROUND 5 -----
Player 1: F2 T2
Player 2: T1
Player 1 is a FIGHTER and Player 2 is a TANK
Player 1 (FIGHTER) wins and gains a new champion.
Player 2 (TANK) loses but with no penalty.

============ GAME OVER  =============

Player 1 ending champion list: M7 T2
Player 2 ending champion list:	

Player 2 ran out of champions. Player 1 wins.



