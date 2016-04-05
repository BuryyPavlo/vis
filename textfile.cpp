#include <textfile.h>
#include <QFile>
#include <QString>

TEXTFILE::TEXTFILE(QString inWayToTxtFile){
    wayToTxtFile =inWayToTxtFile;
    QFile txtFile(wayToTxtFile);
    if (!txtFile.open(QIODevice::ReadOnly))
    {
        printf("Помилка читання файлу про положення БЛА!\n\n");
        ifOpen = false;
    } else {
        ifOpen = true;
    }
}

bool TEXTFILE::getIfOpen(){
    return ifOpen;
}

