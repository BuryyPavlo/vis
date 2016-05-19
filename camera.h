#ifndef CAMERA_H
#define CAMERA_H
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

class Camera{
private:
    double matrixHeightMeters;
    double matrixWidthMeters;
    int matrixWidthPixel;
    int martixHeightPixel;
    double foxusLenght;
    bool statusCamera;
    IplImage *frame;

    CvCapture *capture;

public:
    Camera();
    ~Camera();
    int getMatrixWidthPixel();
    int getMatrixHeightPixel();
    void setMatrixWidthPixel();
    void setMartixHeightPixel();
    void setMatrixWidthPixel(int inMatrixWidthPixel);
    void setMartixHeightPixel(int inMartixHeightPixel);
    double getMatrixHeightMeters();
    double getMatrixWidthMeters();
    double getfocusLenght();
    IplImage* getFrame();
    void setFrame();
    bool getStatusCamera();

};

#endif // CAMERA_H
