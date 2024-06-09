#include "../include/adjMatrix.hpp"


/*
 * ===========================================================================
 * =                               CONSTRUCTOR                               =
 * ===========================================================================
 */

adjMatrix::adjMatrix(int size) : graph(size){
    adjmatrix.resize(size, vector<int>(size, 0));
}

adjMatrix::adjMatrix(int size, bool isDigraph) : graph(size, isDigraph){
    adjmatrix.resize(size, vector<int>(size, 0));
}

/*
 * ===========================================================================
 * =                                  VERTEX                                 =
 * ===========================================================================
 */

    bool adjMatrix::hasVertex(int v) const {
        return v < this->V;
    }
    void adjMatrix::addVertex(int quant) {
        this->V += quant;
        adjmatrix.resize(this->V, vector<int>(this->V, 0));
    }
    bool adjMatrix::removeVertex(int v) {
        return v<V;
    }


/*
 * ===========================================================================
 * =                                   EDGE                                  =
 * ===========================================================================
 */

    bool adjMatrix::viableEdge(int from, int to) const {
        return hasVertex(from) && hasVertex(to);
    }
    bool adjMatrix::hasEdge(int from, int to) {
        return hasVertex(from) && hasVertex(to) && adjmatrix[from][to] > 0;
    }
    bool adjMatrix::addEdge(int from, int to){
        return addEdge(from, to, 1);
    }
    bool adjMatrix::addEdge(int from, int to, int weight) {
        bool success = false;
        if (viableEdge(from,to) && adjmatrix[from][to] == 0)
        {
            adjmatrix[from][to] = weight;
            if (!digraph)
            {
                adjmatrix[to][from] = weight;
            }
            
            success = true;
        }
        return success;
        
    }
    bool adjMatrix::editEdge(int from, int to, int weight) {
        bool success = false;
        if (hasEdge(from,to))
        {
            adjmatrix[from][to] = weight;
            if (!digraph)
            {
                adjmatrix[to][from] = weight;
            }
            
            success = true;
        }
        return success;
    }
    bool adjMatrix::removeEdge(int from, int to) {
        bool success = false;
        if (hasEdge(from,to))
        {
            adjmatrix[from][to] = 0;
            if (!digraph)
            {
                adjmatrix[to][from] = 0;
            }
            
            success = true;
        }
        return success;
    }
    void adjMatrix::removeAllEdgesTo(int to) {
        if (digraph)
        {
            for (int i = 0; i < V; i++)
            {
                adjmatrix[i][to] = 0;
            }
            
        }
    }
    void adjMatrix::removeAllEdgesFrom(int from) {
        if (digraph)
        {
            for (int i = 0; i < V; i++)
            {
                adjmatrix[from][i] = 0;
            }
            
        }
    }

    void adjMatrix::DFSUtil(int v, vector<bool>& visitado) {
        visitado[v] = true;
        cout << v << " ";

        for (int i = 0; i < V; ++i) {
            if (adjmatrix[v][i] && !visitado[i]) {
                DFSUtil(i, visitado);
            }
        }
    }

    void adjMatrix::DFS(int v) {
        vector<bool> visitado(V, false);
        DFSUtil(v, visitado);
    }

    void adjMatrix::BFS(int v) {
        vector<bool> visitado(V, false);
        list<int> fila;

        visitado[v] = true;
        fila.push_back(v);

        while (!fila.empty()) {
            v = fila.front();
            cout << v << " ";
            fila.pop_front();

            for (int i = 0; i < V; ++i) {
                if (adjmatrix[v][i] && !visitado[i]) {
                    visitado[i] = true;
                    fila.push_back(i);
                }
            }
        }
    }

/*
 * ===========================================================================
 * =                                   DEBUG                                 =
 * ===========================================================================
 */

    void adjMatrix::print() const {
        cout << "  ";
        for (int i = 0; i < V; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0; i < V; i++)
        {
            cout << i << " ";
            for (int j = 0; j < V; j++)
            {
                cout << adjmatrix[i][j] << " ";
            }
            cout << endl;
            
        }
        
        
    }