
#include "./Edge.h"

template<class E>
Edge::Edge(E e, int v) : E(e)
{
    this->v = v;
}

int Edge::getV()
{
    return this->v;
}
