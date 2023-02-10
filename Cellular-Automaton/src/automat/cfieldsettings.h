#ifndef CFIELDSETTINGS_H
#define CFIELDSETTINGS_H


#include <string>

namespace automat {

struct FieldSettings
{
    FieldSettings();

    unsigned int Width, Height;
    bool CloseTopBottom, CloseLeftRight;
    std::string FieldName;
};

}

#endif // CFIELDSETTINGS_H
