#include "qcword.h"

QcWord::QcWord()
{
	QValue.clear();
	Length = 0;
	IsWord = false;
	IsStartAndEnd = false;
}

QcWord::QcWord(QString word)
{
	QValue.clear();
	QValue.push_back(word);
	UpdateQWord();
}

QcWord::~QcWord()
{
	QValue.~QString();
}

void QcWord::UpdateQWord()
{
	Length = QValue.length();
	//IsWord = true;

	if (QValue.front() == QValue.back()) IsStartAndEnd = true;
	else IsStartAndEnd = false;

	return;
}

void QcWord::set(QString new_word)
{
	QValue.clear();
	QValue.push_back(new_word);
	UpdateQWord();
	return;
}

QString QcWord::getFullWord()
{
	QString out;
	out.push_back(QValue);
	for (int i = out.length(); i < 10; i++)
	{
		out.push_back(" ");
	}
	return out;
}

