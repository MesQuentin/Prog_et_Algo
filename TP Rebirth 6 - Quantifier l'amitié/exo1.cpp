#include "tp6.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;

void Graph::buildFromAdjenciesMatrix(int **adjacencies, int nodeCount)
{
	/**
	  * Make a graph from a matrix
	  * first create all nodes, add it to the graph then connect them
	  * this->appendNewNode
	  * this->nodes[i]->appendNewEdge
	  */

    int i, k;
    for (i=0; i<nodeCount; i++) {
       this->appendNewNode(new GraphNode(i));
    }

    for (i=0; i<nodeCount; i++) {
        for (k=0; k<nodeCount; k++) {
            if (adjacencies[i][k] != 0) {
                this->nodes[i]->appendNewEdge(this->nodes[k], adjacencies[i][k]);
            }
        }
    }

}

void Graph::deepTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	/**
	  * Fill nodes array by travelling graph starting from first and using recursivity
      */

    nodes[nodesSize]=first;
    visited[first->value]=true;
    nodesSize++;

    for (Edge* JUSQU_AU_BOUT_DU_MONDE = first->edges; JUSQU_AU_BOUT_DU_MONDE!=NULL; JUSQU_AU_BOUT_DU_MONDE = JUSQU_AU_BOUT_DU_MONDE->next) {
        if (not visited[JUSQU_AU_BOUT_DU_MONDE->destination->value]) {
            deepTravel(JUSQU_AU_BOUT_DU_MONDE->destination, nodes, nodesSize, visited);
        }
    }


}

void Graph::wideTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	/**
	 * Fill nodes array by travelling graph starting from first and using queue
     * nodeQueue.push(a_node)
	 * nodeQueue.front() -> first node of the queue
	 * nodeQueue.pop() -> remove first node of the queue
	 * nodeQueue.size() -> size of the queue
	 */

	std::queue<GraphNode*> nodeQueue;
	nodeQueue.push(first);

    while (not nodeQueue.empty()) {
        GraphNode* EL_POP = nodeQueue.front();
        nodeQueue.pop();
        nodes[nodesSize]=EL_POP;
        visited[EL_POP->value]=true;
        nodesSize ++;

        for (Edge* JUSQU_AU_BOUT_DU_MONDE = first->edges; JUSQU_AU_BOUT_DU_MONDE!=NULL; JUSQU_AU_BOUT_DU_MONDE = JUSQU_AU_BOUT_DU_MONDE->next) {
            if (not visited[JUSQU_AU_BOUT_DU_MONDE->destination->value]) {
                nodeQueue.push(JUSQU_AU_BOUT_DU_MONDE->destination);
            }
        }

    }
}

bool Graph::detectCycle(GraphNode * first, bool visited[])
{
    /**
      Detect if there is cycle when starting from first
      (the first may not be in the cycle)
      Think about what's happen when you get an already visited node
    **/

    visited[first->value]=true;
    for (Edge * e=first->edges ; e!=nullptr ; e=e->next){
        if (visited[e->destination->value]){
            return true;
        }

        else{
            if (detectCycle(e->destination, visited)==true){
                return true;
            }
        }
    }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 150;
	w = new GraphWindow();
	w->show();

	return a.exec();
}
