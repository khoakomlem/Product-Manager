#ifndef GLOBAL
#define GLOBAL
#include "Util/Util.hpp"
#include "Model/Model.hpp"

struct Global {
    Util::Manager<Model::Bill*> bills;
    Util::Manager<Model::Employee*> employees;
    Util::Manager<Model::Item*> items;
    int framerate = 20;
    bool requestClearDevice = false;
};

#endif