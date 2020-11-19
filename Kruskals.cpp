#define MAXNUMVERTICES 10
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <climits>
using namespace std;

class Graph
{
private:
    int theGraph[MAXNUMVERTICES][MAXNUMVERTICES] = { INT_MAX };
    set<int> vertices;

public:
    void insertEdgeK(int from, int to, int weight);
    void insertVertexK(int x);
    int sumOfMST();

    // Feel free to add more methods to the API
};

void Graph::insertEdgeK(int to, int from, int weight)
{
    this->theGraph[to][from] = weight;
    this->theGraph[from][to] = weight;
}

void Graph::insertVertexK(int x)
{
    this->vertices.insert(x);
}

int Graph::sumOfMST()
{
    //your code here    
    return 0;
}

int mainK()
{
    Graph* myGraph = new Graph();
    int numEdges, inVert, outVert, wt;
    std::cin >> numEdges;
    for (int i = 0; i < numEdges; i++)
    {
        std::cin >> inVert;
        std::cin >> outVert;
        std::cin >> wt;
        myGraph->insertEdgeK(inVert, outVert, wt);
        myGraph->insertVertexK(inVert);
        myGraph->insertVertexK(outVert);
    }
    cout << myGraph->sumOfMST();
    return 0;
}