#include <errormessage.h>
#include <QFile>
#include <QString>
#include <iostream>
#include <QDateTime>
#include <QDate>

ERRORMESSAGE::ERRORMESSAGE(){
    textError = "невідома помилка!";
}

ERRORMESSAGE::ERRORMESSAGE(int proces, int type){
    QDateTime now = QDateTime::currentDateTime();
    QString strTime;
    strTime = now.toString("dd:MM:yyyy_HH:mm:ss:zzz");
    QString strProces ;
    switch (proces){
    case 1:
        strProces = "Файл! ";
        textError = strProces + strTime + "  ";
        switch (type){
        case 1:
            textError +=  "Помилка читання файлу про положення БЛА!\n\n";
            break;
        case 2:
            textError += "Не відбувся запис у файл logGPS!\n\n";
            break;
        case 3:
            textError += "Неправильна кільксть аргументів у записі GPS!\n\n";
            break;
        default:
            textError += "Невідома помилка!\n\n";
            break;
        }
    case 2:
        strProces = "Камера! ";
        textError = strProces + strTime + "  ";
        switch (type){
        case 1:
            textError +=  "Не підключена камера!\n\n";
            break;
        default:
            textError += "Невідома помилка!\n\n";
            break;
        }

    }
}

ERRORMESSAGE::~ERRORMESSAGE(){
    std::cout << textError.toStdString();
}
