#include <readlogfile.h>
#include <QFile>
#include <QString>
#include <iostream>
#include <QDateTime>
#include <QDate>

READLOGFILE::READLOGFILE(QString inWayToTxtFile):QFile(inWayToTxtFile)
{
    wayToTxtFile = inWayToTxtFile;
    QFile logFile (wayToTxtFile);
    if (!logFile.open(QIODevice::ReadOnly))
    {
        printError(1);
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
        printError(2);
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
            printError(3);
        }
    }
}

//start of class error

void READLOGFILE::printError(int numErro){
    QString erroText;
    switch (numErro) {
    case 1:
        erroText =  "Помилка читання файлу про положення БЛА!\n\n";
        break;
    case 2:{
        QDateTime now = QDateTime::currentDateTime();
        QString strTime;
        strTime = now.toString("dd:MM:yyyy_HH:mm:ss:zzz");
        erroText = "Не відбувся запис у файл logGPS!\n\n"+strTime;}
        break;
    case 3:
        erroText = "Неправильна кільксть аргументів у записі GPS!\n\n";
        break;
    default:
        erroText = "Невідома помилка!\n\n";
        break;
    }
    std::cout << erroText.toStdString();
}

void READLOGFILE::printError(){
    std::cout << "Невідома помилка!\n\n";
}
//end of class error

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
