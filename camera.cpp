#include <camera.h>
#include <errormessage.h>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

Camera::Camera(){
    capture = cvCreateCameraCapture(CV_CAP_ANY);
    if (capture == 0  ) {
        ERRORMESSAGE error(2,1);
        statusCamera = false;
    } else
    matrixHeightMeters = 0.049;
    matrixWidthMeters  = 0.03675;
    foxusLenght = 0.035;

    setMatrixWidthPixel();
    setMartixHeightPixel();
    frame=0;
}

Camera::~Camera(){
    cvReleaseCapture( &capture );
    cvDestroyWindow("capture");
}

void Camera::setMatrixWidthPixel(){
    matrixWidthPixel = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
}

void Camera::setMartixHeightPixel(){
    martixHeightPixel = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
}

void Camera::setMatrixWidthPixel(int inMartixWidthPixel){
    matrixWidthPixel = inMartixWidthPixel;
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, matrixWidthPixel);
}

void Camera::setMartixHeightPixel(int inMartixHeightPixel){
    martixHeightPixel = inMartixHeightPixel;
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, martixHeightPixel);
}

double Camera::getfocusLenght(){
    return foxusLenght;
}

double Camera::getMatrixHeightMeters(){
    return matrixHeightMeters;
}

double Camera::getMatrixWidthMeters(){
    return matrixWidthMeters;
}

int Camera::getMatrixHeightPixel(){
    return matrixWidthPixel;
}

int Camera::getMatrixWidthPixel(){
    return matrixWidthPixel;
}

void Camera::setFrame(){
    frame = cvQueryFrame( capture );
}

IplImage* Camera::getFrame(){
    return frame;
}


bool Camera::getStatusCamera(){
    return statusCamera;
}
