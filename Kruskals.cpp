#define MAXNUMVERTICES 10
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

class Graph
{
private:
    int theGraph[MAXNUMVERTICES][MAXNUMVERTICES] = { INT_MAX };
    set<int> vertices;
    //map<int, pair<int, int>> graph;
    vector<pair<int, pair<int, int>>> graph;
    int j = -1;

public:
    void insertEdge(int from, int to, int weight);
    void insertVertex(int x);
    int sumOfMST();
    vector<int> initializeSet(int n);
    int find(int x, vector<int>& parents);
    void Union(vector<int>& set, int a, int b);
    // Feel free to add more methods to the API
};

vector<int> Graph::initializeSet(int n) { // From video from Lisha review
    vector<int> set(n, 0);
    for (int i = 1; i <= n; i++)
        set[i] = i;
    return set;
}

int Graph::find(int x, vector<int>& parents) { // From video from Lisha review
    if (parents[x] == x)
        return x;
    return find(parents[x], parents);

}

void Graph::Union(vector<int>& set, int a, int b) { // From video from Lisha review
    int m1 = find(a, set); // root of the set that a is inside
    int m2 = find(b, set); // root of the set that b is belonging to
    set[m1] = m2;
}

void Graph::insertEdge(int to, int from, int weight)
{

    this->theGraph[to][from] = weight;
    this->theGraph[from][to] = weight;
    graph.push_back({ weight, {to, from} });

}

void Graph::insertVertex(int x)
{
    this->vertices.insert(x);
}

int Graph::sumOfMST()
{

    vector<int> disjoint = initializeSet(vertices.size());
    int sum = 0;
    sort(graph.begin(), graph.end());
    for (auto edge : graph) {

        int m1 = find(edge.second.first, disjoint);
        int m2 = find(edge.second.second, disjoint);

        if (m1 != m2) {
            Union(disjoint, edge.second.first, edge.second.second);

            sum += edge.first;
        }

    }


    //your code here 
    return sum;
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
    cout << myGraph->sumOfMST();
}