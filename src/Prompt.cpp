#include "Prompt.h"

Prompt::Prompt(char c) : sign(c)
{
}

Prompt::~Prompt()
{
}

void Prompt::setSign(char c)
{
	sign = c;
}

char Prompt::getSign()
{
	return sign;
}
