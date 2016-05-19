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
    IplImage *frame;
    CvCapture *capture;

public:
    Camera();
    ~Camera();
    int getMatrixWidthPixel();
    int getMartixHeightPixel();
    void setMatrixWidthPixel();
    void setMartixHeightPixel();
    void setMatrixWidthPixel(int inMatrixWidthPixel);
    void setMartixHeightPixel(int inMartixHeightPixel);
    double getMatrixHeightMeters();
    double getMatrixWidthMeters();
    IplImage* getFrame();

};

#endif // CAMERA_H
