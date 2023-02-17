#ifndef TESTUNIT_H
#define TESTUNIT_H


#include <QString>

namespace Testing {

typedef bool (*pTestFunc)();

class TestUnit
{
public:
    TestUnit(QString name, pTestFunc testFunc);

private:
    QString TestName;
    short int TestResult;
    pTestFunc TestFunc;

public:
    QString getName() const noexcept;
    bool isExeced() const noexcept;
    bool isPassed() const noexcept;
    bool isError() const noexcept;

    bool Exec() noexcept;

};

}

#endif // TESTUNIT_H
