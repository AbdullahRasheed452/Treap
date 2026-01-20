//#include "PerformanceTest.h"
//#include <iostream>
//#include <iomanip>
//
//using namespace std;
//
//// Generate a random post ID
//string PerformanceTest::generateRandomId(int length) {
//    static const char chars[] = "abcdefghijklmnopqrstuvwxyz0123456789";
//    static mt19937 rng(random_device{}());
//    static uniform_int_distribution<> dist(0, sizeof(chars) - 2);
//
//    string id;
//    for (int i = 0; i < length; i++) {
//        id += chars[dist(rng)];
//    }
//    return id;
//}
//
//// Generate random posts for testing
//vector<Post> PerformanceTest::generateRandomPosts(int count) {
//    vector<Post> posts;
//    mt19937 rng(random_device{}());
//    uniform_int_distribution<> scoreDist(1, 10000);
//    uniform_int_distribution<> timeDist(1500000000, 1600000000);
//
//    for (int i = 0; i < count; i++) {
//        string id = generateRandomId(8);
//        int timestamp = timeDist(rng);
//        int score = scoreDist(rng);
//        posts.push_back(Post(id, timestamp, score));
//    }
//
//    return posts;
//}
//
//// Run a single test with given data size
//TestResult PerformanceTest::runTest(int dataSize) {
//    TestResult result;
//    result.dataSize = dataSize;
//
//    // Generate test data
//    vector<Post> posts = generateRandomPosts(dataSize);
//
//    BST bst;
//    Treap treap;
//
//    // INSERT TEST
//
//    // BST Insert
//    auto start = chrono::high_resolution_clock::now();
//    for (const Post& post : posts) {
//        bst.addPost(post.postId, post.timestamp, post.score);
//    }
//    auto end = chrono::high_resolution_clock::now();
//    result.bstInsertTime = chrono::duration<double, milli>(end - start).count();
//
//    // Treap Insert
//    start = chrono::high_resolution_clock::now();
//    for (const Post& post : posts) {
//        treap.addPost(post.postId, post.timestamp, post.score);
//    }
//    end = chrono::high_resolution_clock::now();
//    result.treapInsertTime = chrono::duration<double, milli>(end - start).count();
//
//    // HEIGHT
//    result.bstHeight = bst.getHeight();
//    result.treapHeight = treap.getHeight();
//    result.treapRotations = treap.getRotationCount();
//
//    // SEARCH TEST
//    int searchCount = min(1000, dataSize);
//
//    // BST Search
//    start = chrono::high_resolution_clock::now();
//    for (int i = 0; i < searchCount; i++) {
//        bst.searchPost(posts[i].postId);
//    }
//    end = chrono::high_resolution_clock::now();
//    result.bstSearchTime = chrono::duration<double, milli>(end - start).count();
//
//    // Treap Search
//    start = chrono::high_resolution_clock::now();
//    for (int i = 0; i < searchCount; i++) {
//        treap.searchPost(posts[i].postId);
//    }
//    end = chrono::high_resolution_clock::now();
//    result.treapSearchTime = chrono::duration<double, milli>(end - start).count();
//
//    // DELETE TEST
//    int deleteCount = min(100, dataSize);
//
//    // BST Delete
//    start = chrono::high_resolution_clock::now();
//    for (int i = 0; i < deleteCount; i++) {
//        bst.deletePost(posts[i].postId);
//    }
//    end = chrono::high_resolution_clock::now();
//    result.bstDeleteTime = chrono::duration<double, milli>(end - start).count();
//
//    // Treap Delete
//    start = chrono::high_resolution_clock::now();
//    for (int i = 0; i < deleteCount; i++) {
//        treap.deletePost(posts[i].postId);
//    }
//    end = chrono::high_resolution_clock::now();
//    result.treapDeleteTime = chrono::duration<double, milli>(end - start).count();
//
//    return result;
//}
//
//// Print a single result
//void PerformanceTest::printResult(TestResult r) {
//    cout << fixed << setprecision(2);
//    cout << "+-------------------------------------------------------+" << endl;
//    cout << "|         Data Size: " << setw(10) << r.dataSize << "                      |" << endl;
//    cout << "+-------------------------------------------------------+" << endl;
//    cout << "| Metric          |    BST      |   Treap     | Winner  |" << endl;
//    cout << "+-------------------------------------------------------+" << endl;
//
//    cout << "| Insert (ms)     | " << setw(10) << r.bstInsertTime
//        << " | " << setw(10) << r.treapInsertTime
//        << "  | " << (r.bstInsertTime < r.treapInsertTime ? "BST    " : "Treap  ") << " |" << endl;
//
//    cout << "| Search (ms)     | " << setw(10) << r.bstSearchTime
//        << " | " << setw(10) << r.treapSearchTime
//        << "  | " << (r.bstSearchTime < r.treapSearchTime ? "BST    " : "Treap  ") << " |" << endl;
//
//    cout << "| Delete (ms)     | " << setw(10) << r.bstDeleteTime
//        << " | " << setw(10) << r.treapDeleteTime
//        << "  | " << (r.bstDeleteTime < r.treapDeleteTime ? "BST    " : "Treap  ") << " |" << endl;
//
//    cout << "| Height          | " << setw(10) << r.bstHeight
//        << " | " << setw(10) << r.treapHeight
//        << "  | " << (r.bstHeight < r.treapHeight ? "BST    " : "Treap  ") << " |" << endl;
//
//    cout << "| Rotations       | " << setw(10) << "N/A"
//        << " | " << setw(10) << r.treapRotations
//        << "  |    -    |" << endl;
//
//    cout << "+-------------------------------------------------------+" << endl;
//    cout << endl;
//}
//
//// Run tests for multiple sizes and save to CSV
//void PerformanceTest::runAllTests(vector<int> sizes, string outputFile) {
//    ofstream file(outputFile);
//
//    // CSV Header
//    file << "DataSize,BST_Insert_ms,Treap_Insert_ms,BST_Search_ms,Treap_Search_ms,"
//        << "BST_Delete_ms,Treap_Delete_ms,BST_Height,Treap_Height,Treap_Rotations" << endl;
//
//    cout << "Running performance tests..." << endl << endl;
//
//    for (int size : sizes) {
//        cout << "Testing with " << size << " posts..." << endl;
//
//        TestResult r = runTest(size);
//        printResult(r);
//
//        // Write to CSV
//        file << r.dataSize << ","
//            << r.bstInsertTime << "," << r.treapInsertTime << ","
//            << r.bstSearchTime << "," << r.treapSearchTime << ","
//            << r.bstDeleteTime << "," << r.treapDeleteTime << ","
//            << r.bstHeight << "," << r.treapHeight << ","
//            << r.treapRotations << endl;
//    }
//
//    file.close();
//    cout << "Results saved to: " << outputFile << endl;
//}