/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#include "./Graph.h"
#include "./Empty.h"
#include "../Forest/Cell.h"

#define SIZE(x) (int) x.size()
#define PB(x) push_back(x)

template<class V, class E>
Graph<V, E>::Edge::Edge(E e, int vertex)
    : E(e), vertex(vertex) {
}

template<class V, class E>
Graph<V, E>::Graph(int n)
    : vertices(n) {
}

template<class V, class E>
void Graph<V, E>::edgeUndirected(int vertex_1, int vertex_2, E edge) {
    Edge ed(edge, vertex_2);

    ed.rev = SIZE(vertices[vertex_2]) + (vertex_1 == vertex_2);
    vertices[vertex_1].PB(ed);

    ed.vertex = vertex_1;
    ed.rev = SIZE(vertices[ed.vertex]) - 1;
    vertices[vertex_2].PB(ed);
}

template
class Graph<Cell, Empty>;
