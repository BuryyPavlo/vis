#ifndef ORIENTATION_H
#define ORIENTATION_H

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv/cv.h"
#include "QString"

class ORIENTATION{

private:
    double xBla    ;
    double yBla    ;
    double zBla    ;
    double yawBla  ;
    double pitchBla;
    double rollBla ;
    double cameraHeight;
    double cameraWidht;
    double cameraFocus;

    double matrixYaw[3][3];
    double matrixRoll[3][3];
    double matrixPitch[3][3];

    //function
    double toRadian(double angle );
    double mmToMeters(double mm);
    double smToMeters(double sm);

    double mulMatrix[3][3];
    double mulMatrix1[3][3];

    void multiplicateMatrix(double a[3][3], double b[3][3]);
    void multiplicateMatrix1(double a[3][3], double b[3][3]);

    void findAnglPoint();
    void rotartion();

    struct point{
        double x = 0;
        double y = 0;
        double z = 0;
    };

    point P1;
    point P2;
    point P3;
    point P4;
    point O1;

    point  multiplicatePoint(point A);
    QString toText(point A);
    point add(point A, point B);

public:
    ORIENTATION(double x, double y, double z, double yaw, double pitch, double roll, double height, double widht, double focus);
    ~ORIENTATION();
    void printDani(CvArr* img, int width);
};

#endif // ORIENTATION_H
