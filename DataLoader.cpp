#include "DataLoader.h"
#include <iostream>

using namespace std;

Post DataLoader::parseJsonLine(string line) {
    string postId = "";
    int timestamp = 0;
    int score = 0;

    // Find "id"
    size_t idPos = line.find("\"id\"");
    if (idPos != string::npos) {
        size_t start = line.find("\"", idPos + 4) + 1;
        size_t end = line.find("\"", start);
        postId = line.substr(start, end - start);
    }

    // Find "created_utc"
    size_t timePos = line.find("\"created_utc\"");
    if (timePos != string::npos) {
        size_t start = line.find(":", timePos) + 1;
        size_t end = line.find_first_of(",}", start);
        string timeStr = line.substr(start, end - start);
        timestamp = stoi(timeStr);
    }

    // Find "score"
    size_t scorePos = line.find("\"score\"");
    if (scorePos != string::npos) {
        size_t start = line.find(":", scorePos) + 1;
        size_t end = line.find_first_of(",}", start);
        string scoreStr = line.substr(start, end - start);
        score = stoi(scoreStr);
    }

    return Post(postId, timestamp, score);
}

vector<Post> DataLoader::loadFromFile(string filename, int limit) {
    vector<Post> posts;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return posts;
    }

    string line;
    int count = 0;

    while (getline(file, line)) {
        if (limit > 0 && count >= limit) {
            break;
        }

        try {
            Post post = parseJsonLine(line);
            if (!post.postId.empty()) {
                posts.push_back(post);
                count++;
            }
        }
        catch (...) {
            continue;
        }

        if (count % 10000 == 0 && count > 0) {
            cout << "Loaded " << count << " posts..." << endl;
        }
    }

    file.close();
    cout << "Total posts loaded: " << count << endl;

    return posts;
}