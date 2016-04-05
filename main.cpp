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
#include <mythread.h>



int main(int argc, char* argv[])
{
    // получаем любую подключённую камеру
    CvCapture *capture = cvCreateCameraCapture(CV_CAP_ANY); //cvCaptureFromCAM( 0 );
    assert( capture );

    //cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 1280);//1280/640/320
    //cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 720);//720/480/240

    // узнаем ширину и высоту кадра
    double width = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
    double height = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
    printf("width=%.0f; height=%.0f;\n\n", width, height );

    IplImage* frame=0;

    printf("press Enter for save image!\npress Esc for quit!\n\n");

    //дані з текстового файлу
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

        // получаем кадр
        //QThread::msleep(100);
        log.readLog();
        frame = cvQueryFrame( capture );

        //out put to img
        COMPAS compas(height, 20);
        compas.inYaw(log.getYawBla());
        compas.draw(frame);
        compas.outText(frame,log.getX(),log.getY(),log.getZ(),log.getYawBla(), log.getPitchBla(), log.getRollBla());
        printf("Ok \n");

        // показываем
        cvShowImage("eye", frame);
        char c = cvWaitKey(33);
        if (c == 27) { // нажата ESC
            break;
        }
        else if(c == 10) { // Enter
            printf("ENTER!!!\n");
            // сохраняем кадр в файл
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
    // освобождаем ресурсы
    cvReleaseCapture( &capture );
    cvDestroyWindow("capture");
    return 0;
}
