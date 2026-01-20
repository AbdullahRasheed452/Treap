#ifndef POST_H
#define POST_H

#include <string>

struct Post {
    std::string postId;
    int timestamp;
    int score;

    Post(std::string id = "", int time = 0, int sc = 0)
        : postId(id), timestamp(time), score(sc) {
    }
};

#endif