

void NPCEnconter(int friendly, int *npcEmotion)
{
	if(friendly)
	{
		printf("You approach him.\n");
		int randomEmotion = rand() % 4 + 1;
		switch(randomEmotion)
		{
			case 1:
				printf("He looks Happy\n");
				break;
			case 2:
				printf("He looks Confused\n");
				break;
			case 3:
				printf("He looks Impatient\n");
				break;
			case 4:
				printf("He looks Indifferent\n");
				break;
		}
		*npcEmotion = randomEmotion;
	}
	else
	{
		printf("You approach with caution.\n");
	}
}
void restart(int *species, int *class, int *health, int *basestrength, int *basedexterity, int *baseconstitution,
	int *baseinteligence, int *basewisdom, int *basecharisma, int *bronzeCoins, int *silverCoins, int *goldCoins,
	int *inebriated, int *action, int *encounterNum, int *numOfMobs, int *chapter, int *fallDamage)
{
	*species = 0;
	*class = 0;
	*health = 0;
	*basestrength = 1;
	*basedexterity = 1;
	*baseconstitution = 1;
	*baseinteligence = 1;
	*basewisdom = 1;
	*basecharisma = 1;
	*bronzeCoins = 0;
	*silverCoins = 0;
	*goldCoins = 0;
	*inebriated = 0;
	*action = 0;
	*encounterNum = 0;
	*numOfMobs = 5;
	*chapter = 1;
	*fallDamage = -1;
}
void cooldown(int *roundsUntilSpecialAttack)
{
	if(*roundsUntilSpecialAttack > 0)
	{
		printf("========\n");
		printf("%d rounds until Special Attack\n", *roundsUntilSpecialAttack);
		*roundsUntilSpecialAttack -= 1;
	}
	else
	{
		printf("========\n");
		printf("Special Attack is ready\n");
	}
}
void specialAttack(int roundsUntilSpecialAttack, int class)
{
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

// void attackPlayer(int *specialAttackActivated, int numOfMobs, int mob1Health, int mob2Health, int mob3Health,
// 	int mob4Health, int mob5Health)
// {
// 	int action;
// 	int damageTaken;
// 	if(!*specialAttackActivated)
// 	{
// 		if(numOfMobs > 1)
// 		{
// 			printf("The Goblins attack you for %d damage each\n", damageTaken = -(rand() % 3));
// 		}
// 		else if(numOfMobs == 1)
// 		{
// 			printf("The Goblin attacks you for %d damage\n", damageTaken = -(rand() % 3));
// 		}
// 		if(damageTaken < 0)
// 		{
// 			if(mob1Health)
// 			{
// 				remainingHealth(damageTaken);
// 			}
// 			if(mob2Health)
// 			{
// 				remainingHealth(damageTaken);	
// 			}
// 			if(mob3Health)
// 			{
// 				remainingHealth(damageTaken);	
// 			}
// 			if(mob4Health)
// 			{
// 				remainingHealth(damageTaken);
// 			}
// 			if(mob5Health)
// 			{
// 				remainingHealth(damageTaken);
// 			}
// 		}
// 	}
// 	else
// 	{
// 		printf("You took 0 damage thanks to your patron\n");
// 		*specialAttackActivated = 0;
// 	}
// 	printf("You survive the Goblins' attacks\n");
// 	printf("\nWhat is your next move?\n1: Make an attack\n2: You carefully go away\n");
// 	specialAttack();
// 	scanf("%d", &action);
// 	cooldown();
// 	switch(action)
// 	{
// 		case 1:
// 			printf("========\n");
// 			if(mob1Health > 0)
// 			{
// 				attackGoblin(0, &mob1Health);
// 			}
// 			else if(mob2Health > 0)
// 			{
// 				attackGoblin(0, &mob2Health);
// 			}
// 			else if(mob3Health > 0)
// 			{
// 				attackGoblin(0, &mob3Health);
// 			}
// 			else if(mob4Health > 0)
// 			{
// 				attackGoblin(0, &mob4Health);
// 			}
// 			else if(mob5Health > 0)
// 			{
// 				attackGoblin(0, &mob5Health);
// 				if(mob5Health <= 0)
// 				{
// 					printf("You killed all the Goblins\n");
// 					chapter1Choice3Choice3Choice3();
// 					break;
// 				}
// 			}
// 			goblinsMultipleAttacks();
// 			if(mob5Health > 0)
// 			{
// 				attackPlayer();
// 			}
// 			break;
// 		case 2:
// 			printf("========\n");
// 			chapter1Choice3Choice3Choice3();
// 			break;
// 		case 4:
// 			specialAttackAction();
// 			break;
// 		}
// }

// void multipleAttacks(int chapter, int numOfAttacks, int numOfMobs, char mobType[30], int mob1Health, int mob2Health,
// 	int mob3Health, int mob4Health, int mob5Health)
// {
// 	int action;
// 	for(int i = 1; i < numOfAttacks; i++)
// 		{
// 			printf("\nWhat is your next move?\n1: You attack again\n2: You do nothing\n");
// 			scanf("%d", &action);
// 			cooldown();
// 			switch(action)
// 			{
// 				case 1:
// 					printf("========\n");
// 					if(mob1Health > 0)
// 					{
// 						attackGoblin(0, &mob1Health);
// 					}
// 					else if(mob2Health > 0)
// 					{
// 						attackGoblin(0, &mob2Health);
// 					}
// 					else if(mob3Health > 0)
// 					{
// 						attackGoblin(0, &mob3Health);
// 					}
// 					else if(gmob4Health > 0)
// 					{
// 						attackGoblin(0, &mob4Health);
// 					}
// 					else if(mob5Health > 0)
// 					{
// 						attackGoblin(0, &mob5Health);
// 						if(mob5Health <= 0)
// 						{
// 							printf("You killed all the %ss\n", mobType);
// 							if(chapter == 1)
// 							{
// 								chapter1Choice3Choice3Choice3();
// 							}
// 							i = numOfAttacks;
// 						}
// 					}
// 					break;
// 				case 2:
// 					printf("========\n");
// 					i = numOfAttacks;
// 					break;
// 			}
// 		}
// }

// void attackGoblin(int surprise, int *goblinAttacked)
// {
// 	damagePerAttack = damageRoll(numOfDice, diceForAttack, strength, basestrength);
// 	if(surprise)
// 	{
// 		damagePerAttack += 1;
// 		if(class == 6)
// 		{
// 			damagePerAttack *= 2;
// 		}
// 	}
// 	if(roundsUntilSpecialAttack == 0 && action == 4)
// 	{
// 		if(class == 1)
// 		{
// 			damagePerAttack = rand()%6 + 1 + rand()%6 + 1 + basestrength + strength;
// 			printf("You hit all Goblins for %d damage\n", damagePerAttack);
// 			if(damagePerAttack >= 3)
// 			{
// 				printf("You killed all the Goblins\n");
// 				if(chapter == 1)
// 				{
// 					goblin1Health = 0;
// 					goblin2Health = 0;
// 					goblin3Health = 0;
// 					goblin4Health = 0;
// 					goblin5Health = 0;
// 				}
// 				roundsUntilSpecialAttack = specialAttackCooldown;
// 				cooldown();
// 				chapter1Choice3Choice3Choice3();
// 				return;
// 			}
// 			else
// 			{
// 				if(chapter == 1)
// 				{
// 					goblin1Health -= damagePerAttack;
// 					goblin2Health -= damagePerAttack;
// 					goblin3Health -= damagePerAttack;
// 					goblin4Health -= damagePerAttack;
// 					goblin5Health -= damagePerAttack;
// 				}
// 				cooldown();
// 				return;
// 			}	
// 		}
// 		else if(class == 2)
// 		{
// 			damagePerAttack += rand()%6 + 1 + rand()%6 + 1;
// 			roundsUntilSpecialAttack = specialAttackCooldown;
// 			cooldown();
// 		}
// 		else if(class == 4)
// 		{
// 			damagePerAttack += health;
// 			roundsUntilSpecialAttack = specialAttackCooldown;
// 			cooldown();
// 		}
// 	}
// 	else
// 	{
// 	}
// 	printf("You hit the closest Goblin for %d damage\n", damagePerAttack);
// 	if(damagePerAttack >= 3)
// 	{
// 		*goblinAttacked = 0;
// 		printf("You kill the Goblin\n");
// 		numOfGoblins--;
// 	}
// 	else
// 	{
// 		*goblinAttacked -= damagePerAttack;
// 		printf("The Goblin has %d health left", *goblinAttacked);
// 	}
// }