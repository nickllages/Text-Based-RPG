// Text-Based RPG v2
// By: Nicholas Lages
// Fall 2021
// My First Game in C

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "createCharacter.h"
#include "rolls.h"
#include "gameplay.h"

int species = 0;
int class = 0;

int strength;
int dexterity;
int constitution;
int inteligence;
int wisdom;
int charisma;

int health = 1;
int fallDamage = -1;

int basestrength = 1;
int basedexterity = 1;
int baseconstitution = 1;
int baseinteligence = 1;
int basewisdom = 1;
int basecharisma = 1;

int specialAttackCooldown = 0;
int roundsUntilSpecialAttack = 0;
int specialAttackRange = 0;
int specialAttackDamage = 0;
int specialAttackHealing = 0;
int specialAttackActivated = 0;

int bronzeCoins = 1;
int silverCoins = 1;
int goldCoins = 1;

int inebriated = 0;

int baseweapon;
int currWeapon;
int range;
int numOfAttacks;
int numOfDice;
int diceForAttack;

int action;

int encounterNum = 0;

int numOfGoblins = 0;
int goblin1Health = 3;
int goblin2Health = 3;
int goblin3Health = 3;
int goblin4Health = 3;
int goblin5Health = 3;
int damagePerAttack = 0;

int npcEmotion;

int chapter = 1;

void game(void);

void chapter1(void);
void chapter1InitialMessage(void);
void chapter1Choice1(void);
void chapter1Choice2(void);
void chapter1Choice3(int again);
void firstAttack(int playerChoice);
void chapter1Choice3Choice3Choice2(void);
void chapter1Choice3Choice3Choice3(void);

void gameOver(void);
void remainingHealth(int healthChange);

void attackGoblin(int surprise, int *goblinAttacked);
void goblinsMultipleAttacks(void);
void goblinsAttackPlayer(void);

void specialAttackAction(void);


//Character Creation Functions
void createCharacter(void)
{
	int createChoice;
	characterName();
	printf("\nDo you want to create a Character?\n");
	printf("Click 1 for yes and 0 for no\n");
	scanf("%d", &createChoice);
	if(createChoice == 1)
	{
		printf("You chose to create a character.\n");	}
	else if(createChoice == 0)
	{
		printf("You chose to randomize a character.\n");
	}
	else
	{
		printf("You did not input 0 or 1.\nYour Character will be randomized\n");
		createChoice = 0;
	}
	species = characterSpecies(createChoice, &fallDamage, &health, &basestrength, &basedexterity, &baseconstitution, &baseinteligence,
		&basewisdom, &basecharisma);
	class = characterClass(createChoice, &health, &basestrength, &basedexterity, &baseconstitution, &baseinteligence, &basewisdom,
		&basecharisma, &strength, &specialAttackCooldown, &specialAttackRange, &specialAttackHealing, &specialAttackDamage, &damagePerAttack);
	characterRolledStats(&strength, &dexterity, &constitution, &inteligence, &wisdom, &charisma);
	printf("\n");
	characterBaseWeapon(createChoice, species, class, &baseweapon, &currWeapon, &range, &numOfAttacks, &numOfDice, &diceForAttack);
}

//Chapter1 Functions
void chapter1InitialMessage(void){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("=========================================================================================\n");
	printf("=========================================================================================\n\n");
	printf("CCCCCCCCCCCCCCCCCCCCCCCC      HHHHHH            HHHHHH                    111111\n");
	printf("CCCCCCCCCCCCCCCCCCCCCCCC      HHHHHH            HHHHHH                 111111111\n");
	printf("CCCCCC                        HHHHHH            HHHHHH              111111111111\n");
	printf("CCCCCC                        HHHHHH            HHHHHH                    111111\n");
	printf("CCCCCC                        HHHHHHHHHHHHHHHHHHHHHHHH                    111111\n");
	printf("CCCCCC                        HHHHHHHHHHHHHHHHHHHHHHHH                    111111\n");
	printf("CCCCCC                        HHHHHHHHHHHHHHHHHHHHHHHH                    111111\n");
	printf("CCCCCC                        HHHHHH            HHHHHH                    111111\n");
	printf("CCCCCC                        HHHHHH            HHHHHH    ......          111111\n");
	printf("CCCCCCCCCCCCCCCCCCCCCCCC      HHHHHH            HHHHHH    ......    111111111111111111\n");
	printf("CCCCCCCCCCCCCCCCCCCCCCCC      HHHHHH            HHHHHH    ......    111111111111111111\n");
	printf("\n=========================================================================================\n");
	printf("=========================================================================================\n\n");
	printf("Welcome to Eobrenon!\nYou have just woken up at Happy Unicorn Tavern.\nYou are Hungover.\n");
	inebriated = 1;
	printf("Your ");
	switch(currWeapon)
	{
		case 1:
			printf("Long Sword");
			break;
		case 2:
			printf("Dagger");
			break;
		case 3:
			printf("Staff");
			break;
		case 4:
			printf("Club");
			break;
		case 5:
			printf("Warhammer");
			break;
		case 6:
		printf("Bow");
			break;
	}
	printf(" is on the floor next to you.\n");
	printf("You pick up your weapon and look around the room.\n\n");
}
void chapter1(void){
	chapter1InitialMessage();
	printf("\nWhat is your next move?\n1: Explore the room\n2: Leave the room\n3: Jump out the window\n4: Kill yourself\n");
	scanf("%d", &action);
	cooldown(&roundsUntilSpecialAttack);
	switch(action)
	{
		case 1:
			printf("========\n");
			chapter1Choice1();
			break;
		case 2:
			printf("========\n");
			chapter1Choice2();
			break;
		case 3:
			printf("========\n");
			chapter1Choice3(0);
			break;
		case 4:
			printf("========\n");
			printf("\nYou Die.\n");
			gameOver();
			break;
		default:
			printf("Invalid Input\n");
			printf("\nWhat is your next move?\n1: Explore the room\n2: Leave the room\n3: Jump out the window\n4: Kill yourself\n");
			scanf("%d", &action);
			switch(action)
			{
				case 1:
					printf("========\n");
					chapter1Choice1();
					break;
				case 2:
					printf("========\n");
					chapter1Choice2();
					break;
				case 3:
					printf("========\n");
					chapter1Choice3(0);
					break;
				case 4:
					printf("========\n");
					printf("\nYou Die.\n");
					gameOver();
					break;
			}
	}
	printf("\nThis is the beggining of a great adventure\n");
	printf("\nEnd of Chapter 1, stay tuned for Chapter 2\n");
}
void chapter1Choice1(void){
	switch(rand() % 4 + 1)
	{
		case 1:
			printf("\nYou found 2 Silver Coins and 1 Bronze Coin\n");
			silverCoins += 2;
			bronzeCoins += 1;
			break;
		case 2:
			printf("You found nothing\n");
			break;
		case 3:
			printf("You found a pair of Swords\n");
			printf("Do you pick them up?\n1: Yes (This will drop your current weapon)\n2: No\n");
			scanf("%d", &action);
			switch(action)
			{
				case 1:
					currWeapon = 7;
					range = 2;
					numOfDice = 4;
					diceForAttack = 4;
					numOfAttacks = 3;
					printf("You picked up the Dual-Wield Swords and dropped your ");
					switch(baseweapon)
					{
						case 1:
							printf("Long Sword\n");
							break;
						case 2:
							printf("Dagger\n");
							break;
						case 3:
							printf("Staff\n");
							break;
						case 4:
							printf("Club\n");
							break;
						case 5:
							printf("Warhammer\n");
							break;
						case 6:
							printf("Bow\n");
							break;
					}
					break;
				case 2:
					printf("You left the swords on the floor\n");
					break;
			}
			break;
		case 4:
			printf("You find a vile with a ");
			switch(rand() % 2 + 1)
			{
				case 1:
					printf("Green liquid\n");
					break;
				case 2:
					printf("Red Liquid\n");
					break;
			}
			printf("Do you drink it?\n1: Yes\n2: No\n");
			scanf("%d", &action);
			switch(action)
			{
				case 1:
					printf("You drink the Liquid\n");
					switch(rand() % 2 + 1)
					{
						case 1:
							printf("The liquid was poison\nYou take 3 damage\n");
							remainingHealth(-3);
							break;
						case 2:
							printf("The liquid was a healing potion\nYou gain +2 health\n");
							remainingHealth(2);
							break;
					}
					break;
				case 2:
					printf("You throw the vile on the floor\nThe liquid quickly evaporates leaving no trace\n");
					break;
			}
			break;
		// case 5:
		// 	break;
	}
	
	printf("\nWhat is your next move?\n1: Leave the room\n2: Jump out the window\n");
	scanf("%d", &action);
	cooldown(&roundsUntilSpecialAttack);
	switch(action)
	{
		case 1:
			printf("========\n");
			chapter1Choice2();
			break;
		case 2:
			printf("========\n");
			chapter1Choice3(0);
			break;
	}
}
void chapter1Choice2(void){
	printf("\nYou open the door and Klaus, the owner of the Tavern, is waiting for you.\n");
	printf("You approach him.\n");
	printf("He looks angrily at you and asks for you to pay 2 Bronze Coins for spending the night.\n");
	printf("\nWhat is your next move?\n1: You attack him\n2: You try to convince him to let you go out without paying (charisma roll of 7 necessary)\n3: You tell him you have no money and ask to work for the stay\n");
	if(bronzeCoins > 1)
	{
		printf("4: You pay him for your stay\n");
	}
	scanf("%d", &action);
	cooldown(&roundsUntilSpecialAttack);
	switch(action)
	{
		case 1:
			printf("========\n");
			printf("As you attack Klaus, everyone at the Tavern sees you attacking him and they kill you.\n");
			gameOver();
			break;
		case 2:
			printf("========\n");
			int charismaChoice;
			charismaChoice = charismaRoll(basecharisma, charisma);
			printf("\nYou got a %d\n", charismaChoice);
			if(charismaChoice >= 7)
			{
				printf("You convince him to let you go without paying\n");
				break;
			}
			else
			{
				printf("You do not convince him to let you go without paying\n");
				printf("\nWhat is your next move?\n1: You attack him\n2: You tell him you have no money and ask to work for the stay\n");
				if(bronzeCoins > 1)
				{
					printf("3: You pay him for your stay\n");
				}
				scanf("%d", &action);
				cooldown(&roundsUntilSpecialAttack);
				switch(action)
				{
					case 1:
						printf("========\n");
						printf("As you attack Klaus, everyone at the Tavern sees you attacking him and kill you.\n");
						gameOver();
						break;
					case 2:
						printf("========\n");
						printf("He allows you to work for the stay.\nYou leave 2 hours later with your debt paid in full\n");
						break;
					case 3:
						printf("========\n");
						bronzeCoins -= 2;
						printf("You pay him for your stay and leave\n");
						printf("You have %d Gold Coins, %d Silver Coins and %d Bronze Coins left\n", goldCoins, silverCoins, bronzeCoins);
						break;
				}
				break;
			}
		case 3:
			printf("========\n");
			printf("He allows you to work for the stay.\nYou leave 2 hours later with your debt paid in full\n");
			break;
		case 4:
			printf("========\n");
			bronzeCoins -= 1;
			printf("You pay him for your stay and leave\n");
			printf("You have %d Gold Coins, %d Silver Coins and %d Bronze Coins left\n", goldCoins, silverCoins, bronzeCoins);
			break;
	}
}
void chapter1Choice3(int again){
	int damageTaken = 0;
	if(fallDamage < 0)
	{
		damageTaken = fallDamage;
	}
	else
	{
		damageTaken = 0;
	}
	if(!again)
	{
		printf("You fall from the second floor of the Tavern and take %d damage.\n", damageTaken);
		remainingHealth(damageTaken);
	}
	printf("\nWhat is your next move\n1: Go into the Tavern as if nothing had happened\n2: Leave the Tavern and head torwards the closest Settlement\n");
	if(goblin5Health > 0)
	{
		printf("3: Walk to the nearby Woods to hunt\n");
	}
	scanf("%d", &action);
	cooldown(&roundsUntilSpecialAttack);
	switch(action)
	{
		case 1:
			printf("========\n");
			chapter1Choice2();
			break;
		case 2:
			printf("========\n");
			printf("You leave the Tavern and head to the closest Settlement\n");
			break;
		case 3:
			if(goblin5Health > 0)
			{
				switch(rand() % 4 + 1){
					default:
					case 3:
						printf("========\n");
						printf("As you look for a prey, a Goblin with a knife jumps 2 meters in front of you, but does not seem to see you\n");
						printf("\nWhat is your next move?\n1: You go closer\n");
						printf("2: You carefully go away\n");
						if(range >= 6)
						{
							printf("3: You attempt an attack(range of 6 needed)(surprise attack +1 damage)\n");
							if(roundsUntilSpecialAttack == 0)
							{
								if(class == 2)
								{
									printf("4: Attack with Flame Arrow\n");
								}
								if(class == 4)
								{
									printf("4: Go Berserk\n");
								}
							}
						}
						if(roundsUntilSpecialAttack == 0)
						{
							if(class == 1)
							{
								printf("4: Attack with Arcana Wave\n");
							}
							if(class == 3)
							{
								printf("4: Use Self Heal\n");
							}
							if(class == 5)
							{
								printf("4: Call Patron\n");
							}
						}
						scanf("%d", &action);
						cooldown(&roundsUntilSpecialAttack);
						firstAttack(action);
						break;
					case 4:
						printf("========\n");
						printf("You spend 1 hour searching for something but find nothing\nYou leave the Woods\n");
						chapter1Choice3(1);
						break;
				}

			}
			break;
	}
}
void chapter1Choice3Choice3Choice2(void){
	if(basewisdom < 2)
	{
		if(numOfGoblins == 5)
		{
			printf("You see that there were actually %d Goblins\n", numOfGoblins);
		}
		else
		{
			printf("You see that there were actually %d Goblins\n", numOfGoblins + 1);
		}
	}
	attackGoblin(1, &goblin1Health);
	if(numOfAttacks > 1 && goblin5Health > 0)
	{
		goblinsMultipleAttacks();
	}
	if(!goblin1Health && !goblin2Health && !goblin3Health && !goblin4Health && !goblin5Health)
	{
		return;
	}
	goblinsAttackPlayer();
}
void chapter1Choice3Choice3Choice3(void){
	if(goblin5Health > 0)
	{
		if(rand() % (dexterity + basedexterity) + rand() % 6 + 1 > 5)
		{
			printf("You leave the Woods and are back to the front of the Tavern\n");
			chapter1Choice3(1);
		}
		else
		{
			printf("You fail to leave and alert the Goblins\n");
			goblinsAttackPlayer();
		}
	}
	else
	{
		printf("You leave the Woods and are back to the front of the Tavern\n");
		chapter1Choice3(1);
	}
}
void firstAttack(int playerChoice){
	switch(playerChoice)
	{
		case 1:
			printf("========\n");
			NPCEnconter(0, &npcEmotion);
			printf("You are now in distance to stike\n");
			if(basewisdom >= 2)
			{
				printf("You see that there are actually %d Goblins all with weapons hunting toghether\n", numOfGoblins);
			}
			printf("\nWhat is your next move?\n1: Make a surprise attack(+1 damage)\n2: You carefully go away\n");
			if(species == 5)
			{
				printf("3: You go speak to the Goblin\n");
			}
			specialAttack(roundsUntilSpecialAttack, class);
			scanf("%d", &action);
			cooldown(&roundsUntilSpecialAttack);
			switch(action)
			{
				case 1:
					printf("========\n");
					chapter1Choice3Choice3Choice2();
					break;
				case 2:
					printf("========\n");
					chapter1Choice3Choice3Choice3();
					break;
				case 3:
					printf("========\n");
					if(species == 5)
					{
						printf("You explain to the goblins that you are also hunting\n");
						printf("They decide to help you and after cathing and eating a couple rabbits, they give you 3 Bronze Coins you leave the Woods\n");
						bronzeCoins += 3;
					}
					else
					{
						printf("Invalid Input\nYou leave the Woods\n");
					}
					chapter1Choice3(1);
					break;
				case 4:
					specialAttackAction();
					break;
			}
			break;
		case 2:
			printf("========\n");
			chapter1Choice3Choice3Choice3();
			break;
		case 3:
			printf("========\n");
			if(range >= 6)
			{
				chapter1Choice3Choice3Choice2();
			}
			else
			{
				printf("Invalid Input\nYou leave the Woods\n");
				chapter1Choice3(1);
			}
			break;
		case 4:
			printf("========\n");
			if(class == 1)
			{
				chapter1Choice3Choice3Choice2();
			}
			if(class == 2)
			{
				chapter1Choice3Choice3Choice2();
			}
			if(class == 3)
			{
				health += specialAttackHealing;
				printf("Healed %d Health\n", specialAttackHealing);
				roundsUntilSpecialAttack = specialAttackCooldown;
				printf("\nWhat is your next move?\n1: You go closer\n");
				printf("2: You carefully go away\n");
				if(range >= 6)
				{
					printf("3: You attempt an attack(range of 6 needed)(surprise attack +1 damage)\n");
				}
				scanf("%d", &action);
				cooldown(&roundsUntilSpecialAttack);
				firstAttack(action);
			}
			if(class == 4)
			{
				chapter1Choice3Choice3Choice2();
			}
			if(class == 5)
			{
				specialAttackActivated = 1;
				roundsUntilSpecialAttack = specialAttackCooldown;
				printf("You call on your Patron\n");
				printf("\nWhat is your next move?\n1: You go closer\n");
				printf("2: You carefully go away\n");
				if(range >= 6)
				{
					printf("3: You attempt an attack(range of 6 needed)(surprise attack +1 damage)\n");
				}
				scanf("%d", &action);
				cooldown(&roundsUntilSpecialAttack);
				firstAttack(action);
			}
			break;
		default:
			printf("Invalid Input\nYou leave the Woods\n");
			chapter1Choice3(1);
	}
}


//Game Functions
void gameOver(void){
	printf("\nGAME OVER\n\n");
	printf("Do you wish to restart?\n");
	printf("For YES click 1, for NO click 0\n");
	int restart;
	scanf("%d", &restart);
	if(restart)
	{
		game();
	}
}
void remainingHealth(int healthChange){
	printf("You have %d health left\n", health += healthChange);
	if(health <= 0)
	{
		printf("You Die");
		gameOver();
	}
}
void attackGoblin(int surprise, int *goblinAttacked){
	damagePerAttack = damageRoll(numOfDice, diceForAttack, strength, basestrength);
	if(surprise)
	{
		damagePerAttack += 1;
		if(class == 6)
		{
			damagePerAttack *= 2;
		}
	}
	if(roundsUntilSpecialAttack == 0 && action == 4)
	{
		if(class == 1)
		{
			damagePerAttack = rand()%6 + 1 + rand()%6 + 1 + basestrength + strength;
			printf("You hit all Goblins for %d damage\n", damagePerAttack);
			if(damagePerAttack >= 3)
			{
				printf("You killed all the Goblins\n");
				if(chapter == 1)
				{
					goblin1Health = 0;
					goblin2Health = 0;
					goblin3Health = 0;
					goblin4Health = 0;
					goblin5Health = 0;
				}
				roundsUntilSpecialAttack = specialAttackCooldown;
				cooldown(&roundsUntilSpecialAttack);
				chapter1Choice3Choice3Choice3();
				return;
			}
			else
			{
				if(chapter == 1)
				{
					goblin1Health -= damagePerAttack;
					goblin2Health -= damagePerAttack;
					goblin3Health -= damagePerAttack;
					goblin4Health -= damagePerAttack;
					goblin5Health -= damagePerAttack;
				}
				cooldown(&roundsUntilSpecialAttack);
				return;
			}
			
		}
		else if(class == 2)
		{
			damagePerAttack += rand()%6 + 1 + rand()%6 + 1;
			roundsUntilSpecialAttack = specialAttackCooldown;
			cooldown(&roundsUntilSpecialAttack);
		}
		else if(class == 4)
		{
			damagePerAttack += health;
			roundsUntilSpecialAttack = specialAttackCooldown;
			cooldown(&roundsUntilSpecialAttack);
		}
	}
	else
	{

	}
	printf("You hit the closest Goblin for %d damage\n", damagePerAttack);
	if(damagePerAttack >= 3)
	{
		*goblinAttacked = 0;
		printf("You kill the Goblin\n");
		numOfGoblins--;
	}
	else
	{
		*goblinAttacked -= damagePerAttack;
		printf("The Goblin has %d health left", *goblinAttacked);
	}
}
void specialAttackAction(void){
	printf("========\n");
	if(class == 1)
	{
		chapter1Choice3Choice3Choice2();
	}
	if(class == 2)
	{
		chapter1Choice3Choice3Choice2();
	}
	if(class == 3)
	{
		health += specialAttackHealing;
		printf("Healed %d Health\n", specialAttackHealing);
		roundsUntilSpecialAttack = specialAttackCooldown;
		printf("\nWhat is your next move?\n1: You go closer\n");
		printf("2: You carefully go away\n");
		if(range >= 6)
		{
			printf("3: You attempt an attack(range of 6 needed)(surprise attack +1 damage)\n");
		}
		scanf("%d", &action);
		cooldown(&roundsUntilSpecialAttack);
		firstAttack(action);
	}
	if(class == 4)
	{
		chapter1Choice3Choice3Choice2();
	}
	if(class == 5)
	{
		specialAttackActivated = 1;
		roundsUntilSpecialAttack = specialAttackCooldown;
		printf("You call on your Patron\n");
		printf("\nWhat is your next move?\n1: You go closer\n");
		printf("2: You carefully go away\n");
		if(range >= 6)
		{
			printf("3: You attempt an attack(range of 6 needed)(surprise attack +1 damage)\n");
		}
		scanf("%d", &action);
		cooldown(&roundsUntilSpecialAttack);
		firstAttack(action);
	}
}
void goblinsAttackPlayer(void){
	int goblinDamage;
	if(!specialAttackActivated)
	{
		if(numOfGoblins > 1)
		{
			printf("The Goblins attack you for %d damage each\n", goblinDamage = -(rand() % 2));
		}
		else if(numOfGoblins == 1)
		{
			printf("The Goblin attacks you for %d damage\n", goblinDamage = -(rand() % 2));
		}
		if(goblinDamage < 0)
		{
			if(goblin1Health)
			{
				remainingHealth(goblinDamage);
			}
			if(goblin2Health)
			{
				remainingHealth(goblinDamage);	
			}
			if(goblin3Health)
			{
				remainingHealth(goblinDamage);	
			}
			if(goblin4Health)
			{
				remainingHealth(goblinDamage);
			}
			if(goblin5Health)
			{
				remainingHealth(goblinDamage);
			}
		}
	}
	else
	{
		printf("You took 0 damage thanks to your patron\n");
		specialAttackActivated = 0;
	}
	printf("You survive the Goblins' attacks\n");
	printf("\nWhat is your next move?\n1: Make an attack\n2: You carefully go away\n");
	specialAttack(roundsUntilSpecialAttack, class);
	scanf("%d", &action);
	cooldown(&roundsUntilSpecialAttack);
	switch(action)
	{
		case 1:
			printf("========\n");
			if(goblin1Health > 0)
			{
				attackGoblin(0, &goblin1Health);
			}
			else if(goblin2Health > 0)
			{
				attackGoblin(0, &goblin2Health);
			}
			else if(goblin3Health > 0)
			{
				attackGoblin(0, &goblin3Health);
			}
			else if(goblin4Health > 0)
			{
				attackGoblin(0, &goblin4Health);
			}
			else if(goblin5Health > 0)
			{
				attackGoblin(0, &goblin5Health);
				if(goblin5Health <= 0)
				{
					printf("You killed all the Goblins\n");
					chapter1Choice3Choice3Choice3();
					break;
				}
			}
			goblinsMultipleAttacks();
			if(goblin1Health > 0 || goblin2Health > 0 || goblin3Health > 0 || goblin4Health > 0 || goblin5Health > 0)
			{
				goblinsAttackPlayer();
			}
			break;
		case 2:
			printf("========\n");
			chapter1Choice3Choice3Choice3();
			break;
		case 4:
			specialAttackAction();
			break;

	}
}
void goblinsMultipleAttacks(void){
	for(int i = 1; i < numOfAttacks; i++)
		{
			printf("\nWhat is your next move?\n1: You attack again\n2: You do nothing\n");
			scanf("%d", &action);
			cooldown(&roundsUntilSpecialAttack);
			switch(action)
			{
				case 1:
					printf("========\n");
					if(goblin1Health > 0)
					{
						attackGoblin(0, &goblin1Health);
					}
					else if(goblin2Health > 0)
					{
						attackGoblin(0, &goblin2Health);
					}
					else if(goblin3Health > 0)
					{
						attackGoblin(0, &goblin3Health);
					}
					else if(goblin4Health > 0)
					{
						attackGoblin(0, &goblin4Health);
					}
					else if(goblin5Health > 0)
					{
						attackGoblin(0, &goblin5Health);
						if(goblin5Health <= 0)
						{
							printf("You killed all the Goblins\n");
							if(chapter == 1)
							{
								chapter1Choice3Choice3Choice3();
							}
							i = numOfAttacks;
						}
					}
					break;
				case 2:
					printf("========\n");
					i = numOfAttacks;
					break;
			}
		}
}
void game(void){
	restart(&species, &class, &health, &basestrength, &basedexterity, &baseconstitution,
	&baseinteligence, &basewisdom, &basecharisma, &bronzeCoins, &silverCoins, &goldCoins,
	&inebriated, &action, &encounterNum, &numOfGoblins, &chapter, &fallDamage);
	createCharacter();
	chapter1();
	return;
}

int main(void)
{
	srand(time(0));
	game();
	return 0;
}