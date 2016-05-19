#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv/cv.h"
#include <QDateTime>
#include <QDate>
#include <QString>
#include <QFile>

#include <QTimer>

#include <compas.h>

#include <errormessage.h>
#include <orientation.h>

#include <camera.h>
#include <readlogfile.h>
#include <proces.h>

#include <point3d.h>

int main()
{
    Camera camera;

    printf("press Enter for save image!\npress Esc for quit!\n\n");

    QString fileTxtName = "//home//buryi//blaphoto//data.txt";
    READLOGFILE log(fileTxtName);
    while(true)

    {
        log.readLog();
        IplImage *frame = camera.getFrame();
        COMPAS compas(camera.getMatrixHeightPixel(), 20);
        compas.inYaw(log.getYawBla());
        compas.draw(frame);
        compas.outText(frame,log.getX(),log.getY(),log.getZ(),log.getYawBla(), log.getPitchBla(), log.getRollBla());
        Point3D mainPoint(log.getX(),log.getY(),log.getZ());
        ORIENTATION ori (mainPoint,log.getYawBla(), log.getPitchBla(), log.getRollBla(), 49, 36.75, 35);
        //ori.printDani(frame, camera.getMatrixWidthPixel());

        cvShowImage("Falcon eye", frame);
        char c = cvWaitKey(33);
        if (c == 27) { // нажата ESC
            break;
        }
        else if(c == 10) { // Enter;
            printf("ENTER!!!\n");
            QDateTime now = QDateTime::currentDateTime();
            QString strTime;
            strTime = now.toString("dd:MM:yyyy_HH:mm:ss:zzz");
            strTime = "//home//buryi//blaphoto//"+strTime+".jpg";
            QByteArray ba = strTime.toLatin1();
            char *filename = ba.data();
            printf("capture... %s\n",filename);
            cvSaveImage(filename, camera.getFrame());
        }
    }
    return 0;
}
