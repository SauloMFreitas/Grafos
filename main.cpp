#include "include/graphs.hpp"

int main()
{
    graph *g = new adjList(3);
    g->addEdge(0,1);
    g->print();

    std::cout << "aaaaaaaaaaaaaaa"<<std::endl;

    return 0;
}
