#include "Prompt.h"

Prompt::Prompt() : c('$') {

}

Prompt::Prompt(char c) : c(c) {

}

Prompt::~Prompt()
{
}

char Prompt::getPrompt() const
{
	return c;
}
