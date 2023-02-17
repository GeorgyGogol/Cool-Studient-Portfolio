#include "testunit.h"

namespace Testing {

TestUnit::TestUnit(QString name, pTestFunc testFunc) :
    TestName(name), TestResult(-1), TestFunc(testFunc)
{
}

QString TestUnit::getName() const noexcept
{
    return TestName;
}

bool TestUnit::isExeced() const noexcept
{
    return TestResult != -1;
}

bool TestUnit::isPassed() const noexcept
{
    return TestResult == 1;
}

bool TestUnit::isError() const noexcept
{
    return TestResult == 0;
}

bool TestUnit::Exec() noexcept
{
    bool result;

    try {
        result = TestFunc();
    } catch (...) {
        result = false;
    }

    TestResult = result ? 1 : 0;
    return result;
}

}

