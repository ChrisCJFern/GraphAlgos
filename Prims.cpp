#pragma once
#define MAXNUMVERTICES 100
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <climits>
using namespace std;


class Graph
{
private:
    int theGraph[MAXNUMVERTICES][MAXNUMVERTICES] = { 0 };
    set<int> vertices;

public:
    void insertEdge(int from, int to, int weight);
    void insertVertex(int x);
    void primMST();
    // Feel free to add more methods to the API
};

void Graph::insertEdge(int from, int to, int weight)
{
    this->theGraph[to][from] = weight;
    this->theGraph[from][to] = weight;
}

void Graph::insertVertex(int x)
{
    this->vertices.insert(x);
}

void Graph::primMST()
{
    set<int> inSpanningTree;
    // find minimum edge
    int minEdge = INT_MAX;
    int minFrom = -1;
    int minTo = -1;
    for (auto from : vertices) {
        for (auto to : vertices) {
            if (theGraph[from][to] != 0 && theGraph[from][to] < minEdge) {
                minEdge = theGraph[from][to];
                minFrom = from;
                minTo = to;
            }
        }
    }
    vertices.erase(minFrom);
    vertices.erase(minTo);
    inSpanningTree.insert(minFrom);

    cout << minFrom << "|" << minTo << "|" << minEdge << endl;
    //your code here        
}

int main()
{
    Graph* myGraph = new Graph();
    int numEdges, inVert, outVert, wt;
    std::cin >> numEdges;
    for (int i = 0; i < numEdges; i++)
    {
        std::cin >> inVert;
        std::cin >> outVert;
        std::cin >> wt;
        myGraph->insertEdge(inVert, outVert, wt);
        myGraph->insertVertex(inVert);
        myGraph->insertVertex(outVert);
    }
    //myGraph->primMST();
}