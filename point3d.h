#ifndef POINT3D_H
#define POINT3D_H
#include <QString>

class Point3D{

private:
    double x;
    double y;
    double z;
public:
    Point3D(double inX, double inY, double inZ);
    Point3D();
    Point3D operator = (Point3D right);
    Point3D add(Point3D point, Point3D pointAdd);
    void add(double addX,double addY, double addZ);
    ~Point3D();
    QString toText(Point3D point);
    QString toText(double arg, QString text);

};

#endif // POINT3D_H
