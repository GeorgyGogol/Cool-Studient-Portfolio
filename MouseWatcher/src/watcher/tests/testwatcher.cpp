#include "testwatcher.h"

namespace Testing {

//#pragma push
//#pragma

#include "unittests.cpp"

TestWatcher::TestWatcher()
{   
    //Tests.push_back(new TestUnit("Points List", Test_Points));
    //Tests.push_back(new TestUnit("is End", Test_isEnd));
    //Tests.push_back(new TestUnit("is Begin", Test_isBegin));
    //Tests.push_back(new TestUnit("Add as pointer", Test_AddPointPointer));
}

QString TestWatcher::RunTests()
{
    QString out = "TestWatcher tests\n";
    bool allRight = true;

    bool testResult;



    for (QVector<TestUnit>::iterator it = Tests.begin(); it != Tests.end(); ++it ) {
        out += "Test: " + (*it).getName() + " ";

        testResult = (*it).Exec();
        allRight *= testResult;

        out += testResult ? "Passed" : "Failed";
        out += "\n";
    }

    out += allRight ? "All Test passed, ok!" :
                      "There are failed tests :(";

    return out;
}

}
