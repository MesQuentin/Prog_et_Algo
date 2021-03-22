#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChild(int nodeIndex)
{
    return (2*nodeIndex+1);
}

int Heap::rightChild(int nodeIndex)
{
    return (2*(nodeIndex+1));
}

void Heap::insertHeapNode(int heapSize, int value)
{
    int i = heapSize;
    this->__get__(i)=value;

    while (i>0 && this->__get__(i)>this->__get__((i-1)/2)) {
        swap(this->__get__(i), this->__get__((i-1)/2));
        i=(i-1)/2;
    }
}

void Heap::heapify(int heapSize, int nodeIndex)
{
    int i_max = nodeIndex;
    int SUMO=i_max;

    if (SUMO<this->__get__(i_max*2+1)) {
        SUMO=i_max*2+1;
    }
    if (SUMO<this->__get__(2*(i_max+1))) {
        SUMO=2*(i_max+1);
    }

    if (SUMO != i_max) {
        swap (this->__get__(i_max), this->__get__(SUMO));
        heapify(heapSize, SUMO);
    }
}

void Heap::buildHeap(Array& numbers)
{
    int WHO_IS_THAT_POKEMON=0;

    while (WHO_IS_THAT_POKEMON<numbers.size()) {
        insertHeapNode(WHO_IS_THAT_POKEMON+1, numbers[WHO_IS_THAT_POKEMON]);
        WHO_IS_THAT_POKEMON++;
    }
}

void Heap::heapSort()
{
    int IT_IS_PIKACHU;
    int FUUUUCK=this->size();
    for (IT_IS_PIKACHU=FUUUUCK-1; IT_IS_PIKACHU>0; IT_IS_PIKACHU--) {
        swap(this->__get__(0), this->__get__(IT_IS_PIKACHU));
        heapify(IT_IS_PIKACHU, 0);
    }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
