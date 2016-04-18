#include <compas.h>
#include <math.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv/cv.h"
#include <sstream>
#include <iostream>
#include <QByteArray>

COMPAS::COMPAS(int inHeight, int inPercent){
    height = inHeight;
    precent = ((double)inPercent/100);
    sizeCompass = (precent * height);
    heigthCompass = (int)(0.5 * sizeCompass);
    widhtCompass = (int)(heigthCompass * 0.25);
    centerCompassY = height - heigthCompass -backDown;
    centerCompassX = heigthCompass + backDown;
    topY    = - heigthCompass;
    topX    = 0;
    bottomY = heigthCompass;
    bottomX = 0;
    leftY   = 0;
    leftX   = - widhtCompass;
    rightY  = 0;
    rightX  = widhtCompass;
}

void COMPAS::inYaw(double inYaw){
    yawRad = inYaw*M_PI/180;
    matixYaw[0][0] = cos(yawRad);
    matixYaw[0][1] = sin(yawRad);
    matixYaw[1][0] = - matixYaw[0][1];
    matixYaw[1][1] = matixYaw[0][0];
    rotation();
}

void COMPAS::rotation(){
    topX1    = (int)(topX*matixYaw[0][0]+matixYaw[0][1]*topY);
    topY1    = (int)(topX*matixYaw[1][0]+matixYaw[1][1]*topY);
    bottomX1 = (int)(bottomX*matixYaw[0][0]+matixYaw[0][1]*bottomY);
    bottomY1 = (int)(bottomX*matixYaw[1][0]+matixYaw[1][1]*bottomY);
    rightX1  = (int)(rightX*matixYaw[0][0]+matixYaw[0][1]*rightY);
    rightY1  = (int)(rightX*matixYaw[1][0]+matixYaw[1][1]*rightY);
    leftX1   = (int)(leftX*matixYaw[0][0]+matixYaw[0][1]*leftY);
    leftY1   = (int)(leftX*matixYaw[1][0]+matixYaw[1][1]*leftY);
    topX1    += centerCompassX;
    rightX1  += centerCompassX;
    bottomX1 += centerCompassX;
    leftX1   += centerCompassX;
    topY1    += centerCompassY;
    rightY1  += centerCompassY;
    bottomY1 += centerCompassY;
    leftY1   += centerCompassY;
}
void COMPAS::draw(CvArr* img){
    cvLine(img,cvPoint(topX1, topY1), cvPoint(rightX1, rightY1),CV_RGB(0,0,250),2,8);
    cvLine(img,cvPoint(rightX1, rightY1), cvPoint(bottomX1, bottomY1),CV_RGB(250,0,0),2,8);
    cvLine(img,cvPoint(bottomX1, bottomY1), cvPoint(leftX1, leftY1),CV_RGB(250,0,0),2,8);
    cvLine(img,cvPoint(leftX1, leftY1), cvPoint(topX1, topY1),CV_RGB(0,0,250),2,8);
}

void COMPAS::outText(CvArr* img, double x, double y, double z, double yaw,double pitch, double roll){
    CvFont font;
    cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 0.4, 0.4, 0, 1, 9);
    cvPutText(img, toText(x, "X = ").toLatin1().data() , cvPoint(xOut,10), &font,CV_RGB(0,0,250));\
    cvPutText(img, toText(y, "Y = ").toLatin1().data()  , cvPoint(xOut,20), &font,CV_RGB(0,0,250));
    cvPutText(img, toText(z, "Z = ").toLatin1().data()  , cvPoint(xOut,30), &font,CV_RGB(0,0,250));
    cvPutText(img, toText(yaw, "Yaw = ").toLatin1().data()  , cvPoint(xOut,45), &font,CV_RGB(0,0,250));
    cvPutText(img, toText(pitch, "Pitch = ").toLatin1().data()  , cvPoint(xOut,55), &font,CV_RGB(0,0,250));
    cvPutText(img, toText(roll, "Roll = ").toLatin1().data()  , cvPoint(xOut,65), &font,CV_RGB(0,0,250));
}

QString COMPAS::toText(double x, QString str){
    QString text =  QString::number(x,'f');
    str = str + text;
    return str;
}

COMPAS::~COMPAS(){

}
