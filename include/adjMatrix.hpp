#ifndef GRAPH_MATRIX_HPP
#define GRAPH_MATRIX_HPP

#include "graph.hpp"
class adjMatrix : public graph
{
private:
    vector<vector<int>> adjmatrix;

    void DFSUtil(int v, vector<bool>& visitado);
public:
    // constructor
    adjMatrix(int size);
    adjMatrix(int size, bool isDigraph);

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

    //search algorithm
    void BFS(int v) override;
    void DFS(int v) override;
    // Debug
    void print() const override;
};
#endif // GRAPH_MATRIX_HPP