#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;


void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax)
{
    int start=0;
    int end=array.size();
    int mid;

    indexMin = indexMax = -1;

    //Recherche de indexMin
    while (start<end) {
        mid = (start+end)/2;

        if (toSearch>array[mid]) {
            start = mid+1;
        }

        else if (toSearch < array[mid]) {
            end = mid;
        }

        else {
            indexMin = mid;
            end = mid;
        }
    }

    start =0;
    end=array.size();

    //Recherche de indexMax
    while (start<end) {
        mid = (start+end)/2;

        if (toSearch>array[mid]) {
            start = mid+1;
        }

        else if (toSearch < array[mid]) {
            end = mid;
        }

        else {
            indexMax = mid;
            start = mid+1;
        }
    }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchAllWindow(binarySearchAll);
	w->show();

	return a.exec();
}
