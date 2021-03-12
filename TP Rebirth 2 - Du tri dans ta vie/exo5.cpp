#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
    if(origin.size()==1){
        return;
    }

    // initialisation
    Array& LE_TROIS = w->newArray(origin.size()/2);
    Array& A_LA_SUITE = w->newArray(origin.size()-LE_TROIS.size());

    // split
    for(int i=0; i<origin.size(); i++){
        if(i<LE_TROIS.size()){
            LE_TROIS[i]=origin[i];
        }else {
            A_LA_SUITE[i-LE_TROIS.size()]=origin[i];
        }
    }

    // recursiv splitAndMerge of lowerArray and greaterArray
    splitAndMerge(LE_TROIS);
    splitAndMerge(LE_TROIS);

    // merge
    merge(LE_TROIS, A_LA_SUITE, origin);
}

void merge(Array& LE_TROIS, Array& A_LA_SUITE, Array& result)
{
    int indexF=0, indexS=0, compteur=0;
    while(compteur<LE_TROIS.size()+A_LA_SUITE.size()){
        if(indexF==LE_TROIS.size()){
            result[compteur]=A_LA_SUITE[indexS];
            indexS++;
            compteur++;
        }else if(indexS==A_LA_SUITE.size()){
            result[compteur]=LE_TROIS[indexF];
            indexF++;
            compteur++;
        }else if(LE_TROIS[indexF]<A_LA_SUITE[indexS]){
            result[compteur]=LE_TROIS[indexF];
            indexF++;
            compteur++;
        }else{
            result[compteur]=A_LA_SUITE[indexS];
            indexS++;
            compteur++;
        }
    }
}



void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
