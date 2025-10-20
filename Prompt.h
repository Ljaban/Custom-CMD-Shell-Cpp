#pragma once
#ifndef PROMPT_H
#define PROMPT_H

class Prompt {
public:
	Prompt();
	Prompt(char c);
	~Prompt();

	char getPrompt() const;

private:
	char c;
};
#endif
