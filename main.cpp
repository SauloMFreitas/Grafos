#include "include/graphs.hpp"

int main()
{
    // funções de lista de adjacendia
    cout << "------------------------------------------------------------------------" << endl;
    cout << "------------------------- Lista de adjacência --------------------------" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "lista inicializada - grafo não direcionado inicializado" << endl;
    graph *g = new adjList(3);
    g->print();
    cout << "adiciona 2 vertices ao grafo" << endl;
    g->addVertex(2);
    g->print();
    cout << "adiciona uma aresta {0,1} de peso 1(peso não selecionado)" << endl;
    g->addEdge(0,1);
    g->print();
    cout << "adiciona uma aresta {0,2} de peso 5(escolhido pelo usuário)" << endl;
    g->addEdge(0,2, 5);
    g->print();
    cout << "edita o peso de uma aresta já adicionada, aresta {0,1} (peso atual 1) para peso 5" << endl;
    g->editEdge(0,1,5);
    g->print();
    cout << "remove uma aresta já adicionada" << endl;
    g->removeEdge(0,1);
    g->print();
    cout << "busca em largura" << endl;
    g->BFS(0);
    cout << endl << "busca em profundidade" << endl;
    g->DFS(0);

    // funções de matriz de adjacência
    cout << "------------------------------------------------------------------------" << endl;
    cout << "------------------------- matriz de adjacência -------------------------" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "lista inicializada - grafo não direcionado inicializado" << endl;
    g = new adjMatrix(3);
    g->print();
    cout << "adiciona 2 vertices ao grafo" << endl;
    g->addVertex(2);
    g->print();
    cout << "adiciona uma aresta {0,1} de peso 1(peso não selecionado)" << endl;
    g->addEdge(0,1);
    g->print();
    cout << "adiciona uma aresta {0,2} de peso 5(escolhido pelo usuário)" << endl;
    g->addEdge(0,2, 5);
    g->print();
    cout << "edita o peso de uma aresta já adicionada, aresta {0,1} (peso atual 1) para peso 5" << endl;
    g->editEdge(0,1,5);
    g->print();
    cout << "remove uma aresta já adicionada" << endl;
    g->removeEdge(0,1);
    g->print();
    cout << "busca em largura" << endl;
    g->BFS(0);
    cout << endl << "busca em profundidade" << endl;
    g->DFS(0);

    return 0;
}
