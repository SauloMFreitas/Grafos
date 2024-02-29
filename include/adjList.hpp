#ifndef GRAPH_LIST_HPP
#define GRAPH_LIST_HPP

#include "graph.hpp"
class adjList : public graph
{
private:
    vector<list<pair<int, int>>> adjlist;
public:
    // constructor
    adjList(int size);
    adjList(int size, int isDigraph);

    // Vertex
    bool hasVertex(int v) const override;
    void addVertex(int quant) override;
    bool removeVertex(int v) override;

    // Edge
    bool viableEdge(int from, int to) const override;
    bool hasEdge(int from, int to) override;
    bool addEdge(int from, int to) override;
    bool addEdge(int from, int to, int weight) override;
    bool editEdge(int from, int to, int weight) override;
    bool removeEdge(int from, int to) override;
    void removeAllEdgesTo(int to) override;
    void removeAllEdgesFrom(int from) override;

    // Debug
    void print() const override;
};
#endif // GRAPH_LIST_HPP