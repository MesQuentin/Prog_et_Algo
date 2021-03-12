#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w = nullptr;

void selectionSort(Array& toSort){
    int min;
    int index;
    for (int i=0;i<toSort.size();i++) {
        min=toSort.get(i);
        index=i;
        for (int j=i;j<toSort.size();j++) {
            if (toSort.get(j)<min){
                min=toSort.get(j);
                index=j;
            }
        }
    toSort.swap(i,index);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(selectionSort); // window which display the behavior of the sort algorithm
    w->show();

    return a.exec();
}
