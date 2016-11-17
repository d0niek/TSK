/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#include "./Graph.h"
#include "./Empty.h"
#include "../Forest/Cell.h"

#define SIZE(x) (int) x.size()
#define PB(x) push_back(x)

template<class V, class E>
Graph<V, E>::Edge::Edge(E e, int v)
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

template<class V, class E>
void Graph<V, E>::bfs(int source) {
    resetVerticesForBfs(source);

    int queue[SIZE(vertices)];
    int b = 0;
    int e = 0;

    queue[0] = source;

    while (b <= e) {
        source = queue[b++];

        for (auto it = vertices[source].begin(); it != vertices[source].end(); it++) {
            if (vertices[it->vertex].t == -1) {
                queue[++e] = it->vertex;
                vertices[it->vertex].t = vertices[source].t + 1;
                vertices[it->vertex].s = source;
            }
        }
    }
}

template<class V, class E>
void Graph<V, E>::resetVerticesForBfs(int source) {
    for (auto it = vertices.begin(); it != vertices.end(); it++) {
        it->t = -1;
        it->s = -1;
    }

    vertices[source].t = 0;
}

template
class Graph<Cell, Empty>;
