#ifndef QCWORD_H
#define QCWORD_H

#include "Core.h"
#include "QString"

class QcWord : public Core::cWord
{
public:
	QcWord();
	QcWord(QString word);
	~QcWord();
private:
	QString QValue;

	void UpdateQWord();
public:
	void set(QString new_word);
	QString getFullWord();
};

#endif // QCWORD_H
