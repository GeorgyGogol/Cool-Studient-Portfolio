#include "cfileserver.h"

#include <fstream>

namespace automat {
cFileServer::cFileServer()
{

}

void cFileServer::SaveTo(cField* field, const char* path)
{
    using namespace std;

    ofstream file;

    file.open(path);
    if (!file.is_open()) throw "Save map error! File is not found";

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
    using namespace std;

    cField* out;
    ifstream file(path);

    if (!file.is_open()) throw "Load map error! File is not found";

    unsigned int W, H;
    file>>H>>W;
    out = new cField(H, W);

    bool buf;
    for (unsigned int y = 0; y < H; ++y) {
        for (unsigned int x = 0; x < W; ++x) {
            file>>buf;
             out->setCell(x, y, buf);
        }
    }

    file.close();

    return out;
}

}

