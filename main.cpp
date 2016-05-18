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
#include <math.h>
#include <QTimer>

#include <compas.h>
#include <readlogfile.h>
#include <errormessage.h>
#include <orientation.h>

int main()
{
    CvCapture *capture = cvCreateCameraCapture(CV_CAP_ANY);
    if (capture == 0  ) {
        ERRORMESSAGE error(2,1);
        return 0;
    }

    // cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 1280);//1280/640/320
    // cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 720);//720/480/240

    int width = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
    int height = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
    printf("width=%d; height=%d;\n\n", width, height );

    IplImage* frame=0;
    printf("press Enter for save image!\npress Esc for quit!\n\n");

    QString fileTxtName = "//home//buryi//blaphoto//data.txt";
    READLOGFILE log(fileTxtName);
    if (log.getIfOpen() == false) {
        return 0;
    }

    QDateTime now = QDateTime::currentDateTime();
    QString strTime;
    strTime = now.toString("dd:MM:yyyy_HH:mm:ss:zzz");
    std:: cout << strTime.toStdString()<< "\n";
    while(true){
        log.readLog();
        frame = cvQueryFrame( capture );

        COMPAS compas(height, 20);
        compas.inYaw(log.getYawBla());
        compas.draw(frame);
        compas.outText(frame,log.getX(),log.getY(),log.getZ(),log.getYawBla(), log.getPitchBla(), log.getRollBla());
        ORIENTATION ori (log.getX(),log.getY(),log.getZ(),log.getYawBla(), log.getPitchBla(), log.getRollBla(), 49, 36.75, 35);
        ori.printDani(frame, width);
        cvShowImage("eye", frame);
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
            cvSaveImage(filename, frame);
        }
    }
    cvReleaseCapture( &capture );
    cvDestroyWindow("capture");
    return 0;
}
