#pragma once
#ifndef DATA_LOADER_H
#define DATA_LOADER_H

using namespace std;

#include "Post.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class DataLoader {
public:
    static vector<Post> loadFromFile(string filename, int limit = -1);
    static Post parseJsonLine(string line);
};

#endif