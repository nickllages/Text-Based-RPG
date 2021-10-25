int strengthRoll(int base_strength, int strength)
{
	return rand() % 6 + base_strength + strength;
}

int dexterityRoll(int base_dexterity, int dexterity)
{
	return rand() % 6 + base_dexterity + dexterity;
}

int constitutionRoll(int base_constitution, int constitution)
{
	return rand() % 6 + base_constitution + constitution;
}

int inteligenceRoll(int base_inteligence, int inteligence)
{
	return rand() % 6 + base_inteligence + inteligence;
}

int wisdomRoll(int base_wisdom, int wisdom)
{
	return rand() % 6 + base_wisdom + wisdom;
}

int charismaRoll(int base_charisma, int charisma)
{
	return rand() % 6 + base_charisma + charisma;
}

int damageRoll(int numOfDice, int diceForAttack, int strength, int base_strength)
{
	return numOfDice*(rand() % diceForAttack) + strength + base_strength;
}