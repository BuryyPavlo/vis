#include <readlogfile.h>
#include <QFile>
#include <QString>
#include <iostream>
#include <QDateTime>
#include <QDate>
#include <errormessage.h>

READLOGFILE::READLOGFILE(QString inWayToTxtFile):QFile(inWayToTxtFile)
{
    wayToTxtFile = inWayToTxtFile;
    QFile logFile (wayToTxtFile);
    if (!logFile.open(QIODevice::ReadOnly))
    {
        ERRORMESSAGE error(1,1);
        ifOpen = false;
    } else {
        ifOpen = true;
    }
}

bool READLOGFILE::getIfOpen(){
    return ifOpen;
}

void READLOGFILE::readLog(){
    QFile logFile (wayToTxtFile);
    logFile.open(QIODevice::ReadOnly);
    logFile.seek(positionInFile);
    QString dani = logFile.readLine();
    positionInFile += dani.length();
    QStringList words;
    if ((dani=="\r\n") || (dani=="")) {
        ERRORMESSAGE error(1,2);
    } else {
        QString tempstr;
        int lengt=0;
        do {
            lengt=dani.indexOf("\t");
            if (lengt==-1){
                words.append(dani.remove(dani.count()-2,dani.count()));
                break;
            } else {
                tempstr=dani;
                words.append(tempstr.remove(lengt,tempstr.size()));
                dani.remove(0,lengt+1);
            }
        }while (lengt!=-1);
        if (words.count() == 7) {
            namePhoto = words.at(0);
            xBla = words.at(1).toDouble();
            yBla = words.at(2).toDouble();
            zBla = words.at(3).toDouble();
            yawBla = words.at(4).toDouble();
            pitchBla = words.at(5).toDouble();
            rollBla = words.at(6).toDouble();
        } else{
            ERRORMESSAGE error(1,3);

        }
    }
}

double READLOGFILE::getYawBla(){
    return yawBla;
}

double READLOGFILE::getRollBla(){
    return rollBla;
}

double READLOGFILE::getPitchBla(){
    return pitchBla;
}

double READLOGFILE::getX(){
    return xBla;
}

double READLOGFILE::getY(){
    return yBla;
}

double READLOGFILE::getZ(){
    return zBla;
}
