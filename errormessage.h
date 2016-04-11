#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H
#include <QString>

class ERRORMESSAGE{
private:
    QString textError;
    void printError();
public:
    ERRORMESSAGE();
    ERRORMESSAGE(int proces, int type);
    ~ERRORMESSAGE();
};

#endif // ERRORMESSAGE_H
