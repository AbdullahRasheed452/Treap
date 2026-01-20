//#ifndef PERFORMANCE_TEST_H
//#define PERFORMANCE_TEST_H
//
//#include "BST.h"
//#include "Treap.h"
//#include <vector>
//#include <string>
//#include <chrono>
//#include <fstream>
//#include <random>
//
//struct TestResult {
//    int dataSize;
//
//    // BST metrics
//    double bstInsertTime;
//    double bstSearchTime;
//    double bstDeleteTime;
//    int bstHeight;
//
//    // Treap metrics
//    double treapInsertTime;
//    double treapSearchTime;
//    double treapDeleteTime;
//    int treapHeight;
//    int treapRotations;
//};
//
//class PerformanceTest {
//private:
//    std::vector<Post> generateRandomPosts(int count);
//    std::string generateRandomId(int length);
//
//public:
//    TestResult runTest(int dataSize);
//    void runAllTests(std::vector<int> sizes, std::string outputFile);
//    void printResult(TestResult result);
//};
//
//#endif