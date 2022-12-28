#pragma once

#define LAB_NUM "8"
#define LAB_TEXT "Создание приложений для обработки строк"
#define VAR "3/28"
#define VAR_TEXT "3. В заданной строке, состоящей из слов, разделенных одним или более пробелами, определите количество слов, начинающихся и заканчивающихся на одну и ту же букву.\n28. Строка состоит из слов длиной менее 10 символов, разделенных запятыми. Преобразуйте строку, заменив запятые группами пробелов так, чтобы каждое слово начиналось с позиции 10*(k - 1) + 1, где k – номер \"слова\"."
#define FIO "Гоголев Георгий Михайлович"
#define GROUP "БИК-2051"

namespace Core {

int GetRandom(int min = -15000, int max = 15000);

class cWord{
public:
	cWord();
	cWord(char* word);
	~cWord();

private: char* Value;
protected:
	int Length;
	bool IsWord;
	bool IsStartAndEnd;
	
	void UpdateWord();
public:
	void set(char *new_word);
	char* get() const;
	void get(char* get_word) const;
	int getLenght() const;
	bool isWord() const;
	bool isStartAndEnd() const;
	char* getFullWord();
};

}

