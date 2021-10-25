/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * Nicholas Lages                                                      *
 * Fall 2021                                                           *
 * Contains functions used to create a character in the Text-Based RPG *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int characterSpecies(int createChoice, int *fallDamage, int *health, int *base_strength, int *base_dexterity,
	int *base_constitution, int *base_inteligence, int *base_wisdom, int *base_charisma)
{
	int speciesChoice;
	if(createChoice)
	{
		printf("Choose a race:\n1: Elf\n2: Human\n3: Orc\n4: Dwarf\n5: Goblin\n");
		scanf("%d", &speciesChoice);
	}
	else if(!createChoice)
	{
		speciesChoice = (rand() % 5) + 1;
	}
	switch(speciesChoice)
	{
		case 1:
			printf("You chose Elf as your species\n");
			*fallDamage += 5;
			*health += 5;
			*base_strength += 0;
			*base_dexterity += 1;
			*base_constitution += 0;
			*base_inteligence += 1;
			*base_wisdom += 3;
			*base_charisma += -1;
			break;
		case 2:
			printf("You chose Human as your species\n");
			*fallDamage += 1;
			*health += 5;
			*base_strength += 1;
			*base_dexterity += 0;
			*base_constitution += 0;
			*base_inteligence += 1;
			*base_wisdom += 0;
			*base_charisma += 2;
			break;
		case 3:
			printf("You chose Orc as your species\n");
			*fallDamage += 4;
			*health += 10;
			*base_strength += 3;
			*base_dexterity += -1;
			*base_constitution += 4;
			*base_inteligence += -1;
			*base_wisdom += -1;
			*base_charisma += 0;
			break;
		case 4:
			printf("You chose Dwarf as your species\n");
			*fallDamage += 3;
			*health += 7;
			*base_strength += 2;
			*base_dexterity += 0;
			*base_constitution += 1;
			*base_inteligence += 1;
			*base_wisdom += 1;
			*base_charisma += -1;
			break;
		case 5:
			printf("You chose Goblin as your species\n");
			*fallDamage += 0;
			*health += 3;
			*base_strength += -1;
			*base_dexterity += 4;
			*base_constitution += -2;
			*base_inteligence += 0;
			*base_wisdom += -1;
			*base_charisma += 4;
			break;
	}
	FILE *characterFile;
	characterFile = fopen("Character File.txt", "a");
	fprintf(characterFile, "\tSpecies: ");
	switch(speciesChoice)
	{
		case 1:
			fprintf(characterFile, "Elf\n");
			break;
		case 2:
			fprintf(characterFile, "Human\n");
			break;
		case 3:
			fprintf(characterFile, "Orc\n");
			break;
		case 4:
			fprintf(characterFile, "Dwarf\n");
			break;
		case 5:
			fprintf(characterFile, "Goblin\n");
			break;
	}
	fclose(characterFile);
	return speciesChoice;
}

int characterClass(int createChoice, int *health, int *base_strength, int *base_dexterity, int *base_constitution,
	int *base_inteligence, int *base_wisdom, int *base_charisma, int *strength, int *specialAttackCooldown,
	int *specialAttackRange, int *specialAttackHealing, int *specialAttackDamage, int *damagePerAttack)
{
	int classChoice;
	if(createChoice)
	{
		printf("Choose a class:\n1: Wizard\n2: Ranger\n3: Cleric\n4: Warrior\n5: Paladin\n6: Rogue\n");
		scanf("%d", &classChoice);
	}
	else if(!createChoice)
	{
		classChoice = ((rand() % 6)) + 1;
	}
	switch(classChoice)
	{
		case 1:
			printf("You chose Wizard as your class\n");
			*health += 0;
			*base_strength += 1;
			*base_dexterity += 0;
			*base_constitution += 1;
			*base_inteligence += 2;
			*base_wisdom += 2;
			*base_charisma += -1;
			*specialAttackCooldown = 5;
			*specialAttackRange = 8;
			*specialAttackDamage  = rand() % 6 + 1 + rand() % 6 +1 + *base_strength + *strength;
			break;
		case 2:
			printf("You chose Ranger as your class\n");
			*health += 0;
			*base_strength += 1;
			*base_dexterity += 2;
			*base_constitution += -1;
			*base_inteligence += 2;
			*base_wisdom += 1;
			*base_charisma += 0;
			*specialAttackCooldown = 3;
			*specialAttackRange = 8;
			*specialAttackDamage = rand() % 6 + 1 + rand() % 6 +1;
			break;
		case 3:
			printf("You chose Cleric as your class\n");
			*health += 1;
			*base_strength += 1;
			*base_dexterity += 0;
			*base_constitution += 2;
			*base_inteligence += 0;
			*base_wisdom += 2;
			*base_charisma += -1;
			*specialAttackCooldown = 5;
			*specialAttackRange = 2;
			*specialAttackHealing = 5;
			break;
		case 4:
			printf("You chose Warrior as your class\n");
			*health += 2;
			*base_strength += 2;
			*base_dexterity += 0;
			*base_constitution += 1;
			*base_inteligence += 0;
			*base_wisdom += 0;
			*base_charisma += 2;
			*specialAttackCooldown = 5;
			*specialAttackDamage = *health;
			break;
		case 5:
			printf("You chose Paladin as your class\n");
			*health += 4;
			*base_strength += 3;
			*base_dexterity += -2;
			*base_constitution += 3;
			*base_inteligence += 0;
			*base_wisdom += 1;
			*base_charisma += 0;
			*specialAttackCooldown = 7;
			break;
		case 6:
			printf("You chose Rogue as your class\n");
			*health += -1;
			*base_strength += 1;
			*base_dexterity += 4;
			*base_constitution += -2;
			*base_inteligence += 1;
			*base_wisdom += 2;
			*base_charisma += -1;
			*specialAttackCooldown = 0;
			*specialAttackDamage = 2*(*damagePerAttack);
			break;
	}
	FILE *characterFile;
	characterFile = fopen("Character File.txt", "a");
	fprintf(characterFile, "\tClass: ");
	switch(classChoice)
	{
		case 1:
			fprintf(characterFile, "Wizard\n");
			break;
		case 2:
			fprintf(characterFile, "*Ranger\n");
			break;
		case 3:
			fprintf(characterFile, "Cleric\n");
			break;
		case 4:
			fprintf(characterFile, "Warrior\n");
			break;
		case 5:
			fprintf(characterFile, "Paladin\n");
			break;
		case 6:
			fprintf(characterFile, "Rogue\n");
			break;
	}
	fprintf(characterFile, "\tBase Stats:\n");
	fprintf(characterFile, "\t  Strength: %d\n", *base_strength);
	fprintf(characterFile, "\t  Dexterity: %d\n", *base_dexterity);
	fprintf(characterFile, "\t  Constitution: %d\n", *base_constitution);
	fprintf(characterFile, "\t  Inteligence: %d\n", *base_inteligence);
	fprintf(characterFile, "\t  Wisdom: %d\n", *base_wisdom);
	fprintf(characterFile, "\t  Charisma: %d\n", *base_charisma);
	fclose(characterFile);
	return classChoice;
}

void characterRolledStats(int *strength, int *dexterity, int *constitution, int *inteligence, int *wisdom, int *charisma)
{
	*strength = (rand() % 6) + 1;
	*dexterity = (rand() % 6) + 1;
	*constitution = (rand() % 6) + 1;
	*inteligence = (rand() % 6) + 1;
	*wisdom = (rand() % 6) + 1;
	*charisma = (rand() % 6) + 1;
	FILE *characterFile;
	characterFile = fopen("Character File.txt", "a");
	fprintf(characterFile, "\tRolled Stats:\n");
	fprintf(characterFile, "\t  Strength: %d\n", *strength);
	fprintf(characterFile, "\t  Dexterity: %d\n", *dexterity);
	fprintf(characterFile, "\t  Constitution: %d\n", *constitution);
	fprintf(characterFile, "\t  Inteligence: %d\n", *inteligence);
	fprintf(characterFile, "\t  Wisdom: %d\n", *wisdom);
	fprintf(characterFile, "\t  Charisma: %d\n", *charisma);
	fclose(characterFile);
}

void characterBaseWeapon(int createChoice, int characterSpecies, int characterClass, int *base_weapon, int *currWeapon, int *range,
	int *numOfAttacks, int *numOfDice, int *diceForAttack)
{
	int weaponChoice;
	if(createChoice)
	{
		printf("Choose a weapon:\n1: Long Sword\n2: Dagger\n3: Staff\n4: Club\n5: Warhammer\n6: Bow\n");
		scanf("%d", &weaponChoice);
	}
	else if(!createChoice)
	{
		weaponChoice = ((rand() % 6)) + 1;
	}
	switch(weaponChoice)
	{
		case 1: //Long Sword
			printf("You chose the Long Sword\n");
			*base_weapon = weaponChoice;
			*currWeapon = *base_weapon;
			*range = 3;
			*numOfAttacks = 1;
			*numOfDice = 2;
			*diceForAttack = 6;
			if(characterClass == 4){
				*numOfDice += 1;
			}
			break;
		case 2: // Dagger
			printf("You chose the Dagger\n");
			*base_weapon = weaponChoice;
			*currWeapon = *base_weapon;
			*range = 1;
			*numOfAttacks = 3;
			*numOfDice = 3;
			*diceForAttack = 4;
			if(characterClass == 6)
			{
				*numOfDice += 1;
			}
			if(characterClass == 2)
			{
				*range += 5;
			}
			if(characterSpecies == 5)
			{
				*numOfAttacks += 1;
			}
			break;
		case 3: // Staff
			printf("You chose the Staff\n");
			*base_weapon = weaponChoice;
			*currWeapon = *base_weapon;
			*range = 4;
			*numOfAttacks = 1;
			*numOfDice = 2;
			*diceForAttack = 6;
			if(characterClass == 1)
			{
				*numOfDice += 1;
			}
			if(characterClass == 3)
			{
				*range += 2;
			}
			break;
		case 4: // Club
			printf("You chose the Club\n");
			*base_weapon = weaponChoice;
			*currWeapon = *base_weapon;
			*range = 2;
			*numOfAttacks = 2;
			*numOfDice = 1;
			*diceForAttack = 12;
			if(characterSpecies == 3)
			{
				*numOfDice += 1;
			}
			break;
		case 5: // Warhammer
			printf("You chose the Warhammer\n");
			*base_weapon = weaponChoice;
			*currWeapon = *base_weapon;
			*range = 2;
			*numOfAttacks = 1;
			*numOfDice = 2;
			*diceForAttack = 10;
			if(characterClass == 5)
			{
				*numOfDice += 1;
			}
			if(characterSpecies == 4)
			{
				*numOfDice += 1;
			}
			if(characterSpecies == 5)
			{
				*range -= 1;
			}
			break;
		case 6: // Bow
			printf("You chose the Bow\n");
			*base_weapon = weaponChoice;
			*currWeapon = *base_weapon;
			*range = 8;
			*numOfAttacks = 2;
			*numOfDice = 1;
			*diceForAttack = 8;
			if(characterSpecies == 1)
			{
				*numOfAttacks += 1;
			}
			break;
	}
	FILE *characterFile;
	characterFile = fopen("Character File.txt", "a");
	fprintf(characterFile, "\tWeapon(s):\n");
	switch(*currWeapon)
	{
		case 1:
			fprintf(characterFile, "\t  Long Sword\n");
			break;
		case 2:
			fprintf(characterFile, "\t  Dagger\n");
			break;
		case 3:
			fprintf(characterFile, "\t  Staff\n");
			break;
		case 4:
			fprintf(characterFile, "\t  Club\n");
			break;
		case 5:
			fprintf(characterFile, "\t  Warhammer\n");
			break;
		case 6:
			fprintf(characterFile, "\t  Bow\n");
			break;
	}
	fprintf(characterFile, "\t    Damage: %dd%d\n", *numOfDice, *diceForAttack);
	fprintf(characterFile, "\t    Range: %d\n", *range);
	fprintf(characterFile, "\t    Attacks per turn: %d\n", *numOfAttacks);
	fclose(characterFile);
}

void characterName(void)
{	
	char firstName[30];
	char familyName[30];
	FILE *characterFile;
	characterFile = fopen("Character File.txt", "a");
	fprintf(characterFile, "Character File:\n");
	printf("Choose a Name:");
	scanf("%s", firstName);
	fprintf(characterFile, "\tName: %s ", firstName);
	printf("Choose a Family Name:");
	scanf("%s", familyName);
	fprintf(characterFile, "%s\n", familyName);
	fclose(characterFile);
}