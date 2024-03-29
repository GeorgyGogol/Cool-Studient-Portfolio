#include "cfileserver.h"

#include <fstream>
#include <string>
#include <cstring>

#include "cfieldsettings.h"

namespace automat {
    
cFileServer::cFileServer()
{

}

int cFileServer::defineFileVersion(char* fileVer)
{
    int out = -1;

    if(strcmp(fileVer, "fVer2") == 0) out = 2;

    return out;
}

cField* cFileServer::fVer2(const char* path)
{
    using namespace std;

    cField* out;
    ifstream file(path);

    if (!file.is_open()) throw "Load map error! File is not found";

    string sBuf;
    file>>sBuf;

    FieldSettings fs;
    file>>fs.FieldName;
    file>>fs.CloseTopBottom>>fs.CloseLeftRight;
    file>>fs.Height>>fs.Width;
    out = new cField(fs);

    bool dataBuf;
    for (unsigned int y = 0; y < fs.Height; ++y) {
        for (unsigned int x = 0; x < fs.Width; ++x) {
            file>>dataBuf;
            out->setCell(x, y, dataBuf);
        }
    }

    file.close();

    return out;
}

void cFileServer::SaveTo(cField* field, const char* path)
{
    using namespace std;

    ofstream file;

    file.open(path);
    if (!file.is_open()) throw "Save map error! File is not found";

    file<<"fVer2"<<endl;
    file<<field->getFieldName()<<endl;
    file<<field->GetCloseTopBottom()<<" "<<field->GetCloseLeftRight()<<endl;
    file<<field->getHeight()<<" "<<field->getWidth()<<endl;

    for (int y = 0; y < field->getHeight(); ++y) {
        for (int x = 0; x < field->getWidth(); ++x) {
            file<<field->getCell(x, y)->getStatus()<<" ";
        }
        file<<endl;
    }
    file<<endl;

    file<<"Additional Field information:"<<endl;
    file<<"Cells: "<<field->getWidth() * field->getHeight()<<endl;
    file<<"Size: "<<field->getSize()<<" Bytes"<<endl;
    file<<"Age: "<<field->getAge()<<endl;

    file.close();
}

cField* cFileServer::LoadFrom(const char* path)
{
    std::ifstream file(path);

    if (!file.is_open()) throw "Load map error! File is not found";

    char* sBuf = new char;
    file>>sBuf;
    file.close();

    switch (defineFileVersion(sBuf))
    {
    case 2:
        return fVer2(path);

    default:
        throw "Load map error! File version is not found";
    }
}

}

