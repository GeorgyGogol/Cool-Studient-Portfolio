#ifndef WEXCEPTION_H
#define WEXCEPTION_H


#include <exception>
#include <string>
//#include <QString>

class WException : public std::exception
{
public:
    WException(std::string message);

private:
    std::string Message;

public:
    const char* what() const noexcept override;

};

#endif // WEXCEPTION_H
