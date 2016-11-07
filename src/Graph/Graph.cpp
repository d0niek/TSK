
#include "./Graph.h"

#define SIZE(x) (int) x.size()
#define PB(x) push_back(x)

Graph::Graph(unsigned long n = 0) : g(n)
{
}

template<class V, class E>
void Graph::edgeD(int b, int e, E d = E())
{
    g[b].PB(Edge<E>(d, e));
}

template<class V, class E>
void Graph::edgeU(int b, int e, E d = E())
{
    g[b].PB(Edge<E>(d, e));
    g[e].PB(Edge<E>(d, b));
}

void Graph::bfs(int s)
{
    for (auto it = g.begin(); it != g.end(); it++) {
        it->setT(-1);
        it->setS(-1);
    }

    g[s].setT(0);

    int qu[SIZE(g)], b = 0, e = 0;

    qu[0] = s;

    while (b <= e) {
        s = qu[b++];

        for (auto it = g[s].begin(); it != g[s].end(); it++) {
            if (g[it->getV()].getT() == -1) {
                qu[++e] = it->getV();
                g[it->getV()].setT(g[s].getT() + 1);
                g[it->getV()].setS(s);
            }
        }
    }
}

void Graph::dfs(int e = -1)
{
    this->t = -1;

    int b = 0;

    e == -1 ? e = SIZE(this->g) - 1 : b = e;

    for (int x = 0; x < SIZE(this->g); x++) {
        this->g[x].setD(-1);
        this->g[x].setF(-1);
        this->g[x].setS(-1);
    }

    for (int x = b; x <= e; x++) {
        if (this->g[x].getS() == -1) {
            this->dfsR(x);
        }
    }
}

void Graph::dfsR(int v)
{
    g[v].setD(++this->t);

    for (auto it = g[v].begin(); it != g[v].end(); it++) {
        if (g[it->getV()].getS() == -1) {
            g[it->getV()].setS(v);

            this->dfsR(it->getV());
        }
    }

    g[v].setF(++this->t);
}

template<class V, class E>
std::vector<Vertex<V, E> > Graph::getG()
{
    return this->g;
}
