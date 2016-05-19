#include <orientation.h>
#include <math.h>
#include <point3d.h>

ORIENTATION::ORIENTATION(Point3D inMainPoint, double yaw, double pitch, double roll, double height, double weight,double focus)
{
    Point3D mainpoint = inMainPoint;
    yawBla = toRadian(yaw);
    pitchBla = toRadian(pitch);
    rollBla = toRadian(roll);
    cameraHeight = mmToMeters(height);
    cameraWidht  = mmToMeters(weight);
    cameraFocus  = mmToMeters(focus);

}

ORIENTATION::~ORIENTATION(){
    //what do ???
}

double ORIENTATION::toRadian(double angle){
    return angle*M_PI/180;
}

double ORIENTATION::smToMeters(double sm){
    return sm/100;
}

double ORIENTATION::mmToMeters(double mm){
    return smToMeters(mm/10);
}

