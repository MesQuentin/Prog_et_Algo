#include "tp1.h"
#include <QApplication>
#include <time.h>

int isMandelbrot(Point z, int n, Point point){


    if (n==0){
        return 0;
    }

    float paillettes_et_papillons = z.x;

    if (sqrt(z.x*z.x+z.y*z.y) < 2) {
        z.x=z.x*z.x-z.y*z.y+point.x;
        z.y= 2*z.y*paillettes_et_papillons+point.y;
        return isMandelbrot(z,n-1,point);
    }

    else {
        return n;
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}



