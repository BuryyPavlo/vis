#ifndef TEXTFILE_H
#define TEXTFILE_H
#include <QString>

class TEXTFILE
{
private:
    QString wayToTxtFile;
    int positionInFile = 0;
    bool ifOpen = false;
    int getTextPosition();
    int setTextPosition(int lenght);

    int namePhoto;
    double xBla;
    double yBla;
    double zBla;
    double yawBla;
    double pitchBla;
    double rollBla;

public:
    TEXTFILE(QString inWayToTxtFile);
    bool getIfOpen();
    readFile()

};

#endif // TEXTFILE_H
