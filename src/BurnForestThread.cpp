/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#include "BurnForestThread.h"

BurnForestThread::BurnForestThread(Graph<Cell, Empty> &forest, int source)
    : wxThread(), forest(forest), source(source) {
}

wxThread::ExitCode BurnForestThread::Entry() {
    forest.bfs(source);

    return NULL;
}
