#include "Core.h"

#include <cstdlib>
#include <cstring>

int Core::GetRandom(int min, int max)
{
	return min + rand() % max;
}

Core::cWord::cWord()
{
	Value = new char[10];
	Length = 0;
	IsWord = false;
	IsStartAndEnd = false;
}

Core::cWord::cWord(char* word)
{
	Value = new char[10];
	for (int i = 0; i < 10 && word[i] != '\0'; i++)
	{
		Value[i] = word[i];
	}
	UpdateWord();
}

Core::cWord::~cWord()
{
	delete[] Value;
}


void Core::cWord::UpdateWord()
{
	Length = 0;
	IsWord = true;
	IsStartAndEnd = false;
	
	for (int i = 0; Value[i] != '\0' && i < 10; i++)
	{
		Length++;
		if (int(Value[i]) < 65
				|| (int(Value[i]) > 90 && int(Value[i]) < 97)
				|| (int(Value[i]) > 122 && int(Value[i]) < 128)
				|| (int(Value[i]) > 175 && int(Value[i]) < 224)
				|| int(Value[i]) > 241)
		{
			IsWord = false;
		}

	}
	if (Value[0] == Value[Length - 1]) IsStartAndEnd = true;
	
	return;
}

void Core::cWord::set(char *new_word)
{
	for (int i = 0; i < 10 && new_word[i] != '\0'; i++)
	{
		Value[i] = new_word[i];
	}
	UpdateWord();
	return;
}

char* Core::cWord::get() const
{
	return Value;
}

void Core::cWord::get(char* get_word) const
{
	std::strcpy(get_word, Value);
	return;
}

int Core::cWord::getLenght() const
{
	return Length;
}

bool Core::cWord::isWord() const
{
	return IsWord;
}

bool Core::cWord::isStartAndEnd() const
{
	return IsStartAndEnd;
}

char* Core::cWord::getFullWord()
{
	char* out = new char[10];
	
	for (int i = 0; i < 10; i++)
	{
		if (i < Length) out[i] = Value[i];
		else out[i] = 32;
	}
	
	return out;
}

