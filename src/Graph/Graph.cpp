
#include "./Graph.h"

#define SIZE(x) (int) x.size()
#define PB(x) push_back(x)

template<class V, class E>
Graph<V, E>::Graph(unsigned int n)
    : vertices(n) {
}

template<class V, class E>
void Graph<V, E>::edgeDirected(unsigned int from, unsigned int to, E edge) {
    vertices[from].PB(Ed(edge, to));
}

template<class V, class E>
void Graph<V, E>::edgeUndirected(unsigned int vertex_1, unsigned int vertex_2, E edge) {
    Ed ed(edge, vertex_2);

    ed.rev = SIZE(vertices[vertex_2]) + (vertex_1 == vertex_2);
    vertices[vertex_1].PB(ed);

    ed.rev = SIZE(vertices[ed.v = vertex_1]) - 1;
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

        for (auto it =vertices[source].begin(); it != vertices[source].end(); it++) {
            if (vertices[it->getVertex()].getT() == -1) {
                queue[++e] = it->getVertex();
                vertices[it->getVertex()].setT(vertices[source].getT() + 1);
                vertices[it->getVertex()].setS(source);
            }
        }
    }
}

template<class V, class E>
void Graph<V, E>::resetVerticesForBfs(int source) {
    for (auto it =vertices.begin(); it != vertices.end(); it++) {
        it->setT(-1);
        it->setS(-1);
    }

    vertices[source].setT(0);
}

template<class V, class E>
std::vector<typename Graph<V, E>::Ve> Graph<V, E>::getVertices() {
    return vertices;
}

template<class V, class E>
Graph<V, E>::Ed::Ed(E e, int v)
    : E(e), vertex(vertex) {
}

template<class V, class E>
int Graph<V, E>::Ed::getVertex() {
    return this->vertex;
}
