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

#define LOGP(...) std::cout << __VA_ARGS__ << std::endl

int main(int argc, char* argv[])
{
    //LOGP("----------1-----------");
    // получаем любую подключённую камеру
    CvCapture *capture = cvCreateCameraCapture(CV_CAP_ANY); //cvCaptureFromCAM( 0 );
    assert( capture );

    // cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 1280);//1280/640/320
    // cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 720);//720/480/240

    // узнаем ширину и высоту кадра
    int width = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
    int height = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
    printf("width=%d; height=%d;\n\n", width, height );

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
        //LOGP("----------4-----------");
        // получаем кадр
        log.readLog();
        frame = cvQueryFrame( capture );

        //out put to img

        COMPAS compas(height, 20);
        compas.inYaw(log.getYawBla());
        compas.draw(frame);
        //LOGP(__LINE__);
        compas.outText(frame,log.getX(),log.getY(),log.getZ(),log.getYawBla(), log.getPitchBla(), log.getRollBla());
        ORIENTATION ori (log.getX(),log.getY(),log.getZ(),log.getYawBla(), log.getPitchBla(), log.getRollBla(), 49, 36.75, 35);
        ori.printDani(frame, width);
        //LOGP(__LINE__);
        // показываем
        cvShowImage("eye", frame);
        char c = cvWaitKey(33);
        if (c == 27) { // нажата ESC
            break;
        }
        else if(c == 10) { // Enter
            //LOGP("----------5-----------");
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
        //LOGP("----------6-----------");
    }
    // освобождаем ресурсы
    cvReleaseCapture( &capture );
    cvDestroyWindow("capture");
    //LOGP("----------7-----------");
    return 0;
}
