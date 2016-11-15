/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef FORESTGENERATOR_H
#define FORESTGENERATOR_H

#include "../Util/Vector2f.h"
#include "../Graph/Graph.h"
#include "../Graph/Empty.h"
#include "./Cell.h"

class ForestGenerator {
    private:
        int cellsPerRow;
        int cellsPerColumn;

    public:
        ForestGenerator(int cellsPerRow, int cellsPerColumn);

        std::vector<Cell> Generate(float width, float height);
};

#endif //FORESTGENERATOR_H
