#ifndef TESTWATCHER_H
#define TESTWATCHER_H


#include <QVector>
#include <QString>
#include "testunit.h"

namespace Testing {

class TestWatcher
{
public:
    TestWatcher();

private:
    QVector<TestUnit> Tests;

public:
    QString RunTests();

};

}

#endif // TESTWATCHER_H
