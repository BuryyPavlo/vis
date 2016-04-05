#include <mythread.h>
#include <iostream>
#include <compas.h>

void MyThread ::run (int height, int percent, CvArr* img, double yaw)
{
    COMPAS compas(height, percent);
    compas.inYaw(yaw);
    compas.draw(img);
    compas.outText(img,yaw,20,10,0,0,0);
    printf("Ok \n");
}

