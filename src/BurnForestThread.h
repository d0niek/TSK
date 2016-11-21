/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef BURNFORESTTHREAD_H
#define BURNFORESTTHREAD_H

#include <wx/thread.h>

#include "./Forest/Cell.h"
#include "./Graph/Graph.h"
#include "./Graph/Empty.h"

class BurnForestThread : public wxThread
{
    private:
        Graph<Cell, Empty> forest;
        int source;

    public:
        BurnForestThread(Graph<Cell, Empty> &forest, int source);

        virtual ExitCode Entry();
};

#endif //BURNFORESTTHREAD_H
