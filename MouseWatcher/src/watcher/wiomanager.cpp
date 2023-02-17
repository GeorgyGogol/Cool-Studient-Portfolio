#include "wiomanager.h"

#include <fstream>
#include <string>

#include "exceptions/wioexception.h"

WIOManager::WIOManager()
{

}

const char* WIOManager::PackData(const WPoint* p) const
{
    std::string out = "";

    out += std::to_string(p->X) + " ";
    out += std::to_string(p->Y) + " ";
    out += std::to_string(p->Button) + " ";
    out += std::to_string(p->getDelay()) + " ";

    return out.c_str();
}

void WIOManager::Save(WWatcher* watcher, const char* path) const
{
    using namespace std;

    ofstream out;
    out.open(path);

    if (!out.is_open()) throw WFileNotFound(IOE_REASON_SAVE);

    WPoint* pPoint;
    for (pPoint = watcher->First(); !watcher->isEnd(); pPoint = watcher->Next())
    {
        out<<PackData(pPoint);
        out<<"\n";
    }
}

WWatcher* WIOManager::Load(const char* path) const
{
    using namespace std;

    ifstream in;
    in.open(path);

    if (!in.is_open()) throw WFileNotFound(IOE_REASON_LOAD);

    WWatcher* out = new WWatcher();

    WPoint buffer;
    int mouseButtion;
    while (!in.eof()) {
        in>>buffer.X;
        in>>buffer.Y;
        in>>mouseButtion;
        in>>buffer.Delay;

        buffer.Button = Qt::MouseButton(mouseButtion);

        out->AddPoint(buffer);
    }

    in.close();

    return out;
}
