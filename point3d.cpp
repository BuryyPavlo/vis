#include <point3d.h>
#include <QString>

Point3D::Point3D(){
    x = 0;
    y = 0;
    z = 0;

}

Point3D::Point3D(double inX, double inY, double inZ){
    x = inX;
    y = inY;
    z = inZ;
}


Point3D Point3D::operator = (Point3D right){
    x = right.x;
    y = right.y;
    z = right.z;
    return *this;

}

Point3D Point3D::add(Point3D point, Point3D pointAdd){
    Point3D resultPoint(point.x+pointAdd.x,point.y+pointAdd.y, point.z+pointAdd.z );
    return resultPoint;
}

void Point3D::add(double addX, double addY, double addZ){
    x += addX;
    y += addY;
    z += addZ;
}

Point3D::~Point3D(){

}

QString Point3D::toText(double arg, QString name){
    QString  text =  QString::number(arg,'f');
    return  (name + text);
}

QString Point3D::toText(Point3D point){
    QString X = toText(point.x, "X = ");
    QString Y = toText(point.y, "Y = ");
    return X = X + Y;
}
