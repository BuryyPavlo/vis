#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv/cv.h"

class MyThread : public QThread
{
  Q_OBJECT
public:
    void run (int height, int percent,CvArr* img, double yaw);
};

#endif // MYTHREAD_H
