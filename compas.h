#ifndef COMPAS_H
#define COMPAS_H
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv/cv.h"
#include <QString>
#include <iostream>

class COMPAS
{
private:
    double precent;
    int backDown = 10;
    int sizeCompass ;
    int heigthCompass;
    int widhtCompass;
    int centerCompassX;
    int centerCompassY;
    //point before
    int topX, topY;
    int bottomX, bottomY;
    int leftX, leftY;
    int rightX, rightY;
    // point after
    int topX1, topY1;
    int bottomX1, bottomY1;
    int leftX1, leftY1;
    int rightX1, rightY1;
    //povorot
    double yawRad;
    double matixYaw[2][2];
    //input
    int height;
    //out Print
    int xOut = 10;

    QString toText(double x, QString str);

public:
    COMPAS(int inHeight, int inPrecent);
    void inYaw(double inYaw);
    void rotation();
    void draw(CvArr* img);
    void outText(CvArr* img, double x, double y, double z, double yaw,double pitch, double roll);
    ~COMPAS();

};

#endif // COMPAS_H
