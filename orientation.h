#ifndef ORIENTATION_H
#define ORIENTATION_H

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv/cv.h"
#include "QString"
#include <point3d.h>

class ORIENTATION{

private:
    Point3D mainPoint();
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
    double toRadian(double angle);
    double mmToMeters(double mm);
    double smToMeters(double sm);

public:
    ORIENTATION(Point3D inMainPoint, double yaw, double pitch, double roll, double height, double widht, double focus);
    ~ORIENTATION();
    void printDani(CvArr* img, int width);
};

#endif // ORIENTATION_H
