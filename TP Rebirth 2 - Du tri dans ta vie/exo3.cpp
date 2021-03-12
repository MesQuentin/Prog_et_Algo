#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;


void bubbleSort(Array& toSort){
    int KO;
    int CANTAL_INDEPENDENT;
    for (CANTAL_INDEPENDENT=0; CANTAL_INDEPENDENT<toSort.size()-1; CANTAL_INDEPENDENT++) {
        for (KO=0; KO<toSort.size()-1 ; KO++){
            if (toSort[KO]>toSort[KO+1]) {
                toSort.swap(KO, KO+1);
            }
        }
    }
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 100;
	w = new TestMainWindow(bubbleSort);
	w->show();

	return a.exec();
}
