#include "../include/adjList.hpp"


/*
 * ===========================================================================
 * =                               CONSTRUCTOR                               =
 * ===========================================================================
 */

    adjList::adjList(int size) : graph(size){
        adjlist.resize(size, list<pair<int,int>>());
    }
    adjList::adjList(int size, int isDigraph) : graph(size, isDigraph){
        adjlist.resize(size, list<pair<int,int>>());
    }

/*
 * ===========================================================================
 * =                                  VERTEX                                 =
 * ===========================================================================
 */

    bool adjList::hasVertex(int v) const {
        return v < V;
    }
    void adjList::addVertex(int quant) {
        this->V += quant;
        adjlist.resize(V, list<pair<int,int>>());

    }
    bool adjList::removeVertex(int v) {
        bool success = false;
        
        
        return success;
        
    }

/*
 * ===========================================================================
 * =                                   EDGE                                  =
 * ===========================================================================
 */

    bool adjList::viableEdge(int from, int to) const {
        bool success = false;
        if(hasVertex(from) && hasVertex(to)){
            success = true;
            for(const auto& par : adjlist[from])
                if(par.first == to) 
                    success = false;
        }
        return success;
    }
    bool adjList::hasEdge(int from, int to) {
        bool success = false;
        if (hasVertex(from) && hasVertex(to))
            for(const auto& par : adjlist[from]) 
                if(par.first == to) success = true;

        return success;
    }
    bool adjList::addEdge(int from, int to) {
        bool success = false;
        if (viableEdge(from, to))
        {
            adjlist[from].push_back({to, 1});
            if (!digraph)
            {  
                adjlist[to].push_back({from, 1});
            }
            success = true;
            
        }

        return success;
    }
    bool adjList::addEdge(int from, int to, int weight) {
        bool success = false;
        if (viableEdge(from, to))
        {
            adjlist[from].push_back({to, weight});
            if (!digraph)
            {  
                adjlist[to].push_back({from, weight});
            }
            success = true;
            
        }

        return success;
    }
    bool adjList::editEdge(int from, int to, int weight) {
        if (!hasEdge(from, to)) {
            return false;
        }

        // Atualizar apenas o peso da aresta no sentido 'from' -> 'to'
        bool success = false;
        for (auto &edge : adjlist[from]) {
            if (edge.first == to) {
                edge.second = weight;
                success = true;
                break;
            }
        }

        // Para grafos não direcionados, atualize também a aresta no sentido inverso 'to' -> 'from'
        if (!digraph && success) {
            for (auto &edge : adjlist[to]) {
                if (edge.first == from) {
                    edge.second = weight;
                    break;
                }
            }
        }
        return success;
    }
    bool adjList::removeEdge(int from, int to) {
        bool success = false;
        if (hasEdge(from, to))
        {
            success = true;
            // Removendo a aresta de from para to
            adjlist[from].remove_if([to](const pair<int, int>& par) { return par.first == to; });

            // Se o grafo for não direcionado, remove também a aresta de to para from
            if (!digraph) {
                adjlist[to].remove_if([from](const pair<int, int>& par) { return par.first == from; });
            }
        }
        return success;
    }
    void adjList::removeAllEdgesFrom(int from) {
        adjlist[from].clear();
        if (!digraph)
        {
            removeAllEdgesTo(from);
        }
        
    }
    void adjList::removeAllEdgesTo(int to) {
        for (auto& lista : adjlist) {
            lista.remove_if([to](const pair<int, int>& par) { return par.first == to; });
        }
        if (!digraph)
        {
            removeAllEdgesFrom(to);
        }
    }


    void adjList::DFSUtil(int v, vector<bool>& visitado) {
        // Marca o vértice atual como visitado e imprime
        visitado[v] = true;
        cout << v << " ";

        // Recorre a todos os vértices adjacentes a este vértice
        for (const auto& par : adjlist[v]) {
            int adj = par.first;
            if (!visitado[adj]) {
                DFSUtil(adj, visitado);
            }
        }
    }

    void adjList::DFS(int v) {
        // Marca todos os vértices como não visitados
        vector<bool> visitado(V, false);

        // Chama a função recursiva de utilidade DFS para imprimir a DFS a partir de v
        DFSUtil(v, visitado);
    }

    void adjList::BFS(int v) {
        // Marca todos os vértices como não visitados
        vector<bool> visitado(V, false);

        // Cria uma fila para BFS
        list<int> fila;

        // Marca o vértice atual como visitado e enfileira
        visitado[v] = true;
        fila.push_back(v);

        while (!fila.empty()) {
            // Desenfileira um vértice da fila e imprime
            v = fila.front();
            cout << v << " ";
            fila.pop_front();

            // Obtém todos os vértices adjacentes do vértice desenfileirado v
            for (const auto& par : adjlist[v]) {
                int adj = par.first;
                if (!visitado[adj]) {
                    visitado[adj] = true;
                    fila.push_back(adj);
                }
            }
        }
    }



/*
 * ===========================================================================
 * =                                   DEBUG                                 =
 * ===========================================================================
 */

    void adjList::print() const {
        for(int i = 0; i < adjlist.size(); i++) {
            cout << i << " -> ";
            for(const auto& par : adjlist[i]) {
                cout << "(" << par.first << ", " << par.second << ") ";
            }
            cout << "\n";
        }
    }
