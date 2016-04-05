#ifndef READLOGFILE_H
#define READLOGFILE_H
#include <QString>
#include <QFile>
#include <compas.h>


class READLOGFILE: public QFile
{
private:
    QString wayToTxtFile;
    int positionInFile = 0;
    bool ifOpen = false;
    int getTextPosition();
    int setTextPosition(int lenght);

    // readinf date
    QString namePhoto  = 0;
    double xBla    = 0;
    double yBla    = 0;
    double zBla    = 0;
    double yawBla  = 0;
    double pitchBla= 0;
    double rollBla = 0;
    void printError(int numErro);
    void printError();

public:
    READLOGFILE(QString inWayToTxtFile);
    bool getIfOpen();
    void readLog();
    double getX();
    double getY();
    double getZ();
    double getYawBla();
    double getPitchBla();
    double getRollBla();
};

#endif // READLOGFILE_H
