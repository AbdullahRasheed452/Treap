#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
#include <string>
#include "BST.h"
#include "Treap.h"
#include "DataLoader.h"

using namespace std;

// Global variables to track loaded posts
vector<Post> loadedPosts;
bool dataLoaded = false;

// MENU FUNCTIONS 

void displayMenu() {
    cout << endl;
    cout << "=====================================================" << endl;
    cout << "     Social Media Feed Management System             " << endl;
    cout << "=====================================================" << endl;
    cout << "  1. Add Post" << endl;
    cout << "  2. Like Post" << endl;
    cout << "  3. Delete Post" << endl;
    cout << "  4. Search Post" << endl;
    cout << "  5. Get Most Popular Post" << endl;
    cout << "  6. Get Most Recent Posts" << endl;
    cout << "  7. Display Tree Stats" << endl;
    cout << "  8. Run Assignment Test Case" << endl;
    cout << "  9. Validate Treap Structure" << endl;
    cout << "  10. Run Complex Validation Test" << endl;
    cout << "  11. Load Dataset & Run Performance Test" << endl;
    cout << "  12. Load Dataset Only (No Performance Test)" << endl;
    cout << "  0. Exit" << endl;
    cout << "=====================================================" << endl;
    if (dataLoaded) {
        cout << "  [Dataset loaded: " << loadedPosts.size() << " posts]" << endl;
        cout << "=====================================================" << endl;
    }
    cout << "  Enter your choice: ";
}

void runAssignmentTestCase(BST& bst, Treap& treap) {
    cout << endl;
    cout << "--- Running Assignment Test Case ---" << endl;

    // Clear existing data
    bst = BST();
    treap = Treap();
    dataLoaded = false;
    loadedPosts.clear();

    // Step 1: Add posts
    cout << endl << "Step 1: Adding 5 posts..." << endl;

    bst.addPost("ejualnb", 1554076800, 55);
    bst.addPost("ejualnc", 1554076800, 12);
    bst.addPost("ejualnd", 1554076800, 27);
    bst.addPost("ejualne", 1554076800, 14);
    bst.addPost("ejualnl", 1554076809, 13);

    treap.addPost("ejualnb", 1554076800, 55);
    treap.addPost("ejualnc", 1554076800, 12);
    treap.addPost("ejualnd", 1554076800, 27);
    treap.addPost("ejualne", 1554076800, 14);
    treap.addPost("ejualnl", 1554076809, 13);

    cout << "  BST Size: " << bst.getSize() << ", Height: " << bst.getHeight() << endl;
    cout << "  Treap Size: " << treap.getSize() << ", Height: " << treap.getHeight() << endl;

    Post* popular = treap.getMostPopular();
    cout << "  Treap Most Popular: " << popular->postId << " (score: " << popular->score << ")" << endl;

    // Step 2: Like post twice
    cout << endl << "Step 2: Liking 'ejualnl' twice..." << endl;

    bst.likePost("ejualnl");
    bst.likePost("ejualnl");

    treap.likePost("ejualnl");
    treap.likePost("ejualnl");

    Post* bstLiked = bst.searchPost("ejualnl");
    Post* treapLiked = treap.searchPost("ejualnl");

    cout << "  BST 'ejualnl' score: " << bstLiked->score << " (expected: 15)" << endl;
    cout << "  Treap 'ejualnl' score: " << treapLiked->score << " (expected: 15)" << endl;

    // Step 3: Delete post
    cout << endl << "Step 3: Deleting 'ejualnc'..." << endl;

    bst.deletePost("ejualnc");
    treap.deletePost("ejualnc");

    cout << "  BST Size after delete: " << bst.getSize() << " (expected: 4)" << endl;
    cout << "  Treap Size after delete: " << treap.getSize() << " (expected: 4)" << endl;

    Post* bstDeleted = bst.searchPost("ejualnc");
    Post* treapDeleted = treap.searchPost("ejualnc");

    if (bstDeleted == nullptr) {
        cout << "  BST: 'ejualnc' not found (deleted successfully)" << endl;
    }
    if (treapDeleted == nullptr) {
        cout << "  Treap: 'ejualnc' not found (deleted successfully)" << endl;
    }

    // Step 4: Get most popular
    cout << endl << "Step 4: Getting most popular post..." << endl;

    Post* bstPopular = bst.getMostPopular();
    Post* treapPopular = treap.getMostPopular();

    cout << "  BST Result: (" << bstPopular->postId << ", " << bstPopular->timestamp << ", " << bstPopular->score << ")" << endl;
    cout << "  Treap Result: (" << treapPopular->postId << ", " << treapPopular->timestamp << ", " << treapPopular->score << ")" << endl;
    cout << "  Expected: (ejualnb, 1554076800, 55)" << endl;

    // Verification
    cout << endl;
    cout << "=====================================================" << endl;
    if (treapPopular->postId == "ejualnb" && treapPopular->score == 55 && treap.getSize() == 4) {
        cout << "  ALL ASSIGNMENT TESTS PASSED!" << endl;
    }
    else {
        cout << "  SOME TESTS FAILED!" << endl;
    }
    cout << "=====================================================" << endl;
}

void runComplexValidationTest(Treap& treap) {
    cout << endl;
    cout << "=====================================================" << endl;
    cout << "      COMPLEX VALIDATION TEST SEQUENCE               " << endl;
    cout << "=====================================================" << endl;

    // Reset treap
    treap = Treap();

    cout << endl << "Phase 1: Inserting 20 posts with varying scores..." << endl;

    // Insert posts with different scores
    treap.addPost("alpha", 1000001, 50);
    treap.addPost("beta", 1000002, 80);
    treap.addPost("gamma", 1000003, 30);
    treap.addPost("delta", 1000004, 95);
    treap.addPost("epsilon", 1000005, 15);
    treap.addPost("zeta", 1000006, 70);
    treap.addPost("eta", 1000007, 25);
    treap.addPost("theta", 1000008, 88);
    treap.addPost("iota", 1000009, 42);
    treap.addPost("kappa", 1000010, 67);
    treap.addPost("lambda", 1000011, 33);
    treap.addPost("mu", 1000012, 91);
    treap.addPost("nu", 1000013, 19);
    treap.addPost("xi", 1000014, 76);
    treap.addPost("omicron", 1000015, 54);
    treap.addPost("pi", 1000016, 100);
    treap.addPost("rho", 1000017, 11);
    treap.addPost("sigma", 1000018, 63);
    treap.addPost("tau", 1000019, 45);
    treap.addPost("upsilon", 1000020, 82);

    cout << "  Inserted 20 posts." << endl;
    cout << "  Size: " << treap.getSize() << ", Height: " << treap.getHeight() << endl;
    cout << "  Rotations so far: " << treap.getRotationCount() << endl;

    cout << endl << "  Validating after insertions..." << endl;
    bool valid1 = treap.validateStructure();
    cout << "  Structure valid: " << (valid1 ? "YES" : "NO") << endl;

    // Phase 2: Like operations
    cout << endl << "Phase 2: Performing 10 like operations..." << endl;

    treap.likePost("epsilon");
    treap.likePost("epsilon");
    treap.likePost("epsilon");
    treap.likePost("rho");
    treap.likePost("gamma");
    treap.likePost("nu");
    treap.likePost("eta");
    treap.likePost("pi");
    treap.likePost("pi");
    treap.likePost("alpha");

    cout << "  Completed 10 like operations." << endl;
    cout << "  Rotations so far: " << treap.getRotationCount() << endl;

    cout << endl << "  Validating after likes..." << endl;
    bool valid2 = treap.validateStructure();
    cout << "  Structure valid: " << (valid2 ? "YES" : "NO") << endl;

    Post* mostPopular = treap.getMostPopular();
    cout << "  Most popular: " << mostPopular->postId << " (score: " << mostPopular->score << ")" << endl;
    cout << "  Expected: pi (score: 102)" << endl;

    // Phase 3: Delete operations
    cout << endl << "Phase 3: Deleting 5 posts..." << endl;

    treap.deletePost("delta");
    treap.deletePost("rho");
    treap.deletePost("kappa");
    treap.deletePost("theta");
    treap.deletePost("lambda");

    cout << "  Deleted 5 posts." << endl;
    cout << "  Size: " << treap.getSize() << " (expected: 15)" << endl;
    cout << "  Height: " << treap.getHeight() << endl;
    cout << "  Rotations so far: " << treap.getRotationCount() << endl;

    cout << endl << "  Validating after deletions..." << endl;
    bool valid3 = treap.validateStructure();
    cout << "  Structure valid: " << (valid3 ? "YES" : "NO") << endl;

    // Phase 4: More insertions after deletions
    cout << endl << "Phase 4: Inserting 5 new posts..." << endl;

    treap.addPost("phi", 1000021, 99);
    treap.addPost("chi", 1000022, 77);
    treap.addPost("psi", 1000023, 55);
    treap.addPost("omega", 1000024, 110);
    treap.addPost("final", 1000025, 5);

    cout << "  Inserted 5 new posts." << endl;
    cout << "  Size: " << treap.getSize() << " (expected: 20)" << endl;
    cout << "  Height: " << treap.getHeight() << endl;
    cout << "  Rotations so far: " << treap.getRotationCount() << endl;

    cout << endl << "  Validating after new insertions..." << endl;
    bool valid4 = treap.validateStructure();
    cout << "  Structure valid: " << (valid4 ? "YES" : "NO") << endl;

    mostPopular = treap.getMostPopular();
    cout << "  Most popular: " << mostPopular->postId << " (score: " << mostPopular->score << ")" << endl;
    cout << "  Expected: omega (score: 110)" << endl;

    // Final Report
    cout << endl;
    cout << "=====================================================" << endl;
    cout << "           FINAL VALIDATION SUMMARY                  " << endl;
    cout << "=====================================================" << endl;
    cout << "  Phase 1 (After insertions):  " << (valid1 ? "PASSED" : "FAILED") << endl;
    cout << "  Phase 2 (After likes):       " << (valid2 ? "PASSED" : "FAILED") << endl;
    cout << "  Phase 3 (After deletions):   " << (valid3 ? "PASSED" : "FAILED") << endl;
    cout << "  Phase 4 (After more inserts):" << (valid4 ? "PASSED" : "FAILED") << endl;
    cout << "=====================================================" << endl;

    if (valid1 && valid2 && valid3 && valid4) {
        cout << "  ALL STRUCTURAL VALIDATIONS PASSED!" << endl;
        cout << "  Treap maintained both BST and Heap properties" << endl;
        cout << "  throughout all complex operations." << endl;
    }
    else {
        cout << "  SOME VALIDATIONS FAILED!" << endl;
    }
    cout << "=====================================================" << endl;

    treap.printValidationReport();
}

//LOAD DATASET FUNCTION

bool loadDataset(BST& bst, Treap& treap, bool runPerfTest) {
    cout << endl;
    cout << "========================================================" << endl;
    if (runPerfTest) {
        cout << "       Load Dataset & Run Performance Test             " << endl;
    }
    else {
        cout << "              Load Dataset into Trees                   " << endl;
    }
    cout << "========================================================" << endl;
    cout << endl;

    // Get user input for dataset size
    int datasetSize;
    string dataFile;
    int insertChoice;

    cout << "Enter dataset size (e.g., 10000, 100000): ";
    cin >> datasetSize;

    cout << "Enter data file name (e.g., reddit_sample.json): ";
    cin >> dataFile;

    cout << endl;
    cout << "Insert into which data structure?" << endl;
    cout << "  1. BST only" << endl;
    cout << "  2. Treap only" << endl;
    cout << "  3. Both (BST and Treap)" << endl;
    cout << "  Choice: ";
    cin >> insertChoice;

    cout << endl;
    cout << "Configuration:" << endl;
    cout << "  Dataset file: " << dataFile << endl;
    cout << "  Target size: " << datasetSize << " posts" << endl;
    cout << "  Insert into: ";
    if (insertChoice == 1) cout << "BST only" << endl;
    else if (insertChoice == 2) cout << "Treap only" << endl;
    else cout << "Both (BST and Treap)" << endl;
    cout << endl;

    // Clear existing data
    bst = BST();
    treap = Treap();
    loadedPosts.clear();
    dataLoaded = false;

    // Load data
    cout << "Loading data from file..." << endl;
    auto loadStart = chrono::high_resolution_clock::now();
    loadedPosts = DataLoader::loadFromFile(dataFile, datasetSize);
    auto loadEnd = chrono::high_resolution_clock::now();
    double loadTime = chrono::duration<double, milli>(loadEnd - loadStart).count();

    cout << "Loaded " << loadedPosts.size() << " posts in " << fixed << setprecision(2) << loadTime << " ms" << endl;
    cout << endl;

    if (loadedPosts.size() == 0) {
        cout << "Error: No posts loaded! Check file path." << endl;
        return false;
    }

    // Variables for timing
    double bstInsertTime = 0, treapInsertTime = 0;
    double bstSearchTime = 0, treapSearchTime = 0;
    double bstDeleteTime = 0, treapDeleteTime = 0;
    double bstGetPopularTime = 0, treapGetPopularTime = 0;
    double bstGetRecentTime = 0, treapGetRecentTime = 0;

    // INSERT INTO BST (if selected)
    if (insertChoice == 1 || insertChoice == 3) {
        cout << "--- INSERTING INTO BST ---" << endl;
        auto start = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < loadedPosts.size(); i++) {
            bst.addPost(loadedPosts[i].postId, loadedPosts[i].timestamp, loadedPosts[i].score);
            if ((i + 1) % (loadedPosts.size() / 10) == 0) {
                cout << "  BST: " << (i + 1) << " / " << loadedPosts.size()
                    << " (" << ((i + 1) * 100 / loadedPosts.size()) << "%)" << endl;
            }
        }
        auto end = chrono::high_resolution_clock::now();
        bstInsertTime = chrono::duration<double, milli>(end - start).count();
        cout << "  BST Insert Done! Time: " << bstInsertTime << " ms" << endl << endl;
    }
    else {
        cout << "--- SKIPPING BST (not selected) ---" << endl << endl;
    }

    // INSERT INTO TREAP (if selected)
    if (insertChoice == 2 || insertChoice == 3) {
        cout << "--- INSERTING INTO TREAP ---" << endl;
        auto start = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < loadedPosts.size(); i++) {
            treap.addPost(loadedPosts[i].postId, loadedPosts[i].timestamp, loadedPosts[i].score);
            if ((i + 1) % (loadedPosts.size() / 10) == 0) {
                cout << "  Treap: " << (i + 1) << " / " << loadedPosts.size()
                    << " (" << ((i + 1) * 100 / loadedPosts.size()) << "%)" << endl;
            }
        }
        auto end = chrono::high_resolution_clock::now();
        treapInsertTime = chrono::duration<double, milli>(end - start).count();
        cout << "  Treap Insert Done! Time: " << treapInsertTime << " ms" << endl << endl;
    }
    else {
        cout << "--- SKIPPING TREAP (not selected) ---" << endl << endl;
    }

    dataLoaded = true;

    cout << "========================================================" << endl;
    cout << "  Dataset loaded successfully!" << endl;
    if (insertChoice == 1 || insertChoice == 3) {
        cout << "  BST Size: " << bst.getSize() << ", Height: " << bst.getHeight() << endl;
    }
    if (insertChoice == 2 || insertChoice == 3) {
        cout << "  Treap Size: " << treap.getSize() << ", Height: " << treap.getHeight() << endl;
    }
    cout << "========================================================" << endl;
    cout << endl;
    cout << "You can now perform operations (search, delete, like, etc.)" << endl;
    cout << "on the loaded posts using the menu options 1-6." << endl;

    // Run performance tests if requested
    if (runPerfTest) {
        cout << endl;
        cout << "========================================================" << endl;
        cout << "              Running Performance Tests                  " << endl;
        cout << "========================================================" << endl;

        // SEARCH TEST
        int searchCount = min(1000, (int)loadedPosts.size());
        cout << endl << "--- SEARCH TEST (" << searchCount << " lookups) ---" << endl;

        if (insertChoice == 1 || insertChoice == 3) {
            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < searchCount; i++) {
                bst.searchPost(loadedPosts[i].postId);
            }
            auto end = chrono::high_resolution_clock::now();
            bstSearchTime = chrono::duration<double, milli>(end - start).count();
            cout << "  BST Search: " << bstSearchTime << " ms" << endl;
        }

        if (insertChoice == 2 || insertChoice == 3) {
            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < searchCount; i++) {
                treap.searchPost(loadedPosts[i].postId);
            }
            auto end = chrono::high_resolution_clock::now();
            treapSearchTime = chrono::duration<double, milli>(end - start).count();
            cout << "  Treap Search: " << treapSearchTime << " ms" << endl;
        }

        // DELETE TEST
        int deleteCount = min(100, (int)loadedPosts.size());
        cout << endl << "--- DELETE TEST (" << deleteCount << " deletions) ---" << endl;

        int startIdx = loadedPosts.size() - deleteCount;

        if (insertChoice == 1 || insertChoice == 3) {
            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < deleteCount; i++) {
                bst.deletePost(loadedPosts[startIdx + i].postId);
            }
            auto end = chrono::high_resolution_clock::now();
            bstDeleteTime = chrono::duration<double, milli>(end - start).count();
            cout << "  BST Delete: " << bstDeleteTime << " ms" << endl;
        }

        if (insertChoice == 2 || insertChoice == 3) {
            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < deleteCount; i++) {
                treap.deletePost(loadedPosts[startIdx + i].postId);
            }
            auto end = chrono::high_resolution_clock::now();
            treapDeleteTime = chrono::duration<double, milli>(end - start).count();
            cout << "  Treap Delete: " << treapDeleteTime << " ms" << endl;
        }

        // GET MOST POPULAR TEST
        int popularCount = 100;
        cout << endl << "--- GET MOST POPULAR TEST (" << popularCount << " calls) ---" << endl;

        Post* bstPopular = nullptr;
        Post* treapPopular = nullptr;

        if (insertChoice == 1 || insertChoice == 3) {
            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < popularCount; i++) {
                bstPopular = bst.getMostPopular();
            }
            auto end = chrono::high_resolution_clock::now();
            bstGetPopularTime = chrono::duration<double, milli>(end - start).count();
            cout << "  BST getMostPopular: " << bstGetPopularTime << " ms" << endl;
        }

        if (insertChoice == 2 || insertChoice == 3) {
            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < popularCount; i++) {
                treapPopular = treap.getMostPopular();
            }
            auto end = chrono::high_resolution_clock::now();
            treapGetPopularTime = chrono::duration<double, milli>(end - start).count();
            cout << "  Treap getMostPopular: " << treapGetPopularTime << " ms" << endl;
        }

        // GET MOST RECENT TEST
        int recentK = 10;
        int recentCount = 100;
        cout << endl << "--- GET MOST RECENT TEST (k=" << recentK << ", " << recentCount << " calls) ---" << endl;

        if (insertChoice == 1 || insertChoice == 3) {
            auto start = chrono::high_resolution_clock::now();
            vector<Post> bstRecent;
            for (int i = 0; i < recentCount; i++) {
                bstRecent = bst.getMostRecent(recentK);
            }
            auto end = chrono::high_resolution_clock::now();
            bstGetRecentTime = chrono::duration<double, milli>(end - start).count();
            cout << "  BST getMostRecent: " << bstGetRecentTime << " ms" << endl;
        }

        if (insertChoice == 2 || insertChoice == 3) {
            auto start = chrono::high_resolution_clock::now();
            vector<Post> treapRecent;
            for (int i = 0; i < recentCount; i++) {
                treapRecent = treap.getMostRecent(recentK);
            }
            auto end = chrono::high_resolution_clock::now();
            treapGetRecentTime = chrono::duration<double, milli>(end - start).count();
            cout << "  Treap getMostRecent: " << treapGetRecentTime << " ms" << endl;
        }

        // Get final metrics
        int bstHeight = bst.getHeight();
        int treapHeight = treap.getHeight();
        int bstBalanceFactor = bst.getBalanceFactor();
        int treapBalanceFactor = treap.getBalanceFactor();
        int treapRotations = treap.getRotationCount();
        int bstSize = bst.getSize();
        int treapSize = treap.getSize();

        // RESULTS TABLE
        cout << endl;
        cout << fixed << setprecision(2);
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "|              PERFORMANCE RESULTS                          |" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "| Metric                |      BST      |      Treap       |" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "| Data Size (initial)   | " << setw(12) << loadedPosts.size()
            << " | " << setw(16) << loadedPosts.size() << " |" << endl;
        cout << "| Data Size (final)     | " << setw(12) << bstSize
            << " | " << setw(16) << treapSize << " |" << endl;
        cout << "| Insert Time (ms)      | " << setw(12) << bstInsertTime
            << " | " << setw(16) << treapInsertTime << " |" << endl;
        cout << "| Search Time (ms)      | " << setw(12) << bstSearchTime
            << " | " << setw(16) << treapSearchTime << " |" << endl;
        cout << "| Delete Time (ms)      | " << setw(12) << bstDeleteTime
            << " | " << setw(16) << treapDeleteTime << " |" << endl;
        cout << "| getMostPopular (ms)   | " << setw(12) << bstGetPopularTime
            << " | " << setw(16) << treapGetPopularTime << " |" << endl;
        cout << "| getMostRecent (ms)    | " << setw(12) << bstGetRecentTime
            << " | " << setw(16) << treapGetRecentTime << " |" << endl;
        cout << "| Tree Height           | " << setw(12) << bstHeight
            << " | " << setw(16) << treapHeight << " |" << endl;
        cout << "| Balance Factor        | " << setw(12) << bstBalanceFactor
            << " | " << setw(16) << treapBalanceFactor << " |" << endl;
        cout << "| Rotations             | " << setw(12) << "N/A"
            << " | " << setw(16) << treapRotations << " |" << endl;
        cout << "+-----------------------------------------------------------+" << endl;

        // Average times (only if both selected)
        if (insertChoice == 3) {
            cout << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "|              AVERAGE TIME PER OPERATION                   |" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "| Metric                |      BST      |      Treap       |" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "| Insert (avg)          | " << setw(12) << (bstInsertTime / loadedPosts.size())
                << " | " << setw(16) << (treapInsertTime / loadedPosts.size()) << " |" << endl;
            cout << "| Search (avg)          | " << setw(12) << (bstSearchTime / searchCount)
                << " | " << setw(16) << (treapSearchTime / searchCount) << " |" << endl;
            cout << "| Delete (avg)          | " << setw(12) << (bstDeleteTime / deleteCount)
                << " | " << setw(16) << (treapDeleteTime / deleteCount) << " |" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
        }

        // Most Popular
        cout << endl;
        cout << "Most Popular Post:" << endl;
        if (bstPopular != nullptr) {
            cout << "  BST:   " << bstPopular->postId << " (score: " << bstPopular->score << ")" << endl;
        }
        if (treapPopular != nullptr) {
            cout << "  Treap: " << treapPopular->postId << " (score: " << treapPopular->score << ")" << endl;
        }

        // Key Observations
        cout << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "|                   KEY OBSERVATIONS                        |" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        if (insertChoice == 3) {
            cout << "| 1. Treap height (" << treapHeight << ") vs BST height (" << bstHeight << ")" << endl;
            cout << "| 2. Treap balance factor (" << treapBalanceFactor << ") vs BST (" << bstBalanceFactor << ")" << endl;
        }
        if (insertChoice == 2 || insertChoice == 3) {
            cout << "| 3. Treap getMostPopular is O(1) - just returns root" << endl;
        }
        if (insertChoice == 1 || insertChoice == 3) {
            cout << "| 4. BST getMostPopular is O(n) - must traverse all nodes" << endl;
        }
        if (insertChoice == 2 || insertChoice == 3) {
            cout << "| 5. Treap uses " << treapRotations << " rotations to stay balanced" << endl;
        }
        cout << "+-----------------------------------------------------------+" << endl;

        // SAVE TO CSV
        ofstream csv("reddit_performance_results.csv");
        csv << "Metric,BST,Treap" << endl;
        csv << "Data Size," << loadedPosts.size() << "," << loadedPosts.size() << endl;
        csv << "Insert Time (ms)," << bstInsertTime << "," << treapInsertTime << endl;
        csv << "Search Time (ms)," << bstSearchTime << "," << treapSearchTime << endl;
        csv << "Delete Time (ms)," << bstDeleteTime << "," << treapDeleteTime << endl;
        csv << "getMostPopular (ms)," << bstGetPopularTime << "," << treapGetPopularTime << endl;
        csv << "getMostRecent (ms)," << bstGetRecentTime << "," << treapGetRecentTime << endl;
        csv << "Tree Height," << bstHeight << "," << treapHeight << endl;
        csv << "Balance Factor," << bstBalanceFactor << "," << treapBalanceFactor << endl;
        csv << "Rotations,0," << treapRotations << endl;
        csv.close();

        cout << endl;
        cout << "Results saved to: reddit_performance_results.csv" << endl;
        cout << "Run 'python visualize.py' to generate graphs." << endl;
    }

    cout << endl;
    cout << "========================================================" << endl;
    int totalPosts = max(bst.getSize(), treap.getSize());
    cout << "  " << totalPosts << " posts are now available for operations!" << endl;
    cout << "  Use menu options 1-6 to interact with the data." << endl;
    cout << "========================================================" << endl;

    return true;
}

//MAIN FUNCTION

int main() {
    BST bst;
    Treap treap;

    int choice;
    string postId;
    int timestamp, score, k;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            // Add Post
            cout << endl << "--- Add Post ---" << endl;
            cout << "  Enter Post ID: ";
            cin >> postId;
            cout << "  Enter Timestamp: ";
            cin >> timestamp;
            cout << "  Enter Score: ";
            cin >> score;

            int insertChoice;
            cout << "  Insert into (1=BST, 2=Treap, 3=Both): ";
            cin >> insertChoice;

            if (insertChoice == 1 || insertChoice == 3) {
                bst.addPost(postId, timestamp, score);
                cout << "  Added to BST. Size: " << bst.getSize() << endl;
            }
            if (insertChoice == 2 || insertChoice == 3) {
                treap.addPost(postId, timestamp, score);
                cout << "  Added to Treap. Size: " << treap.getSize() << endl;
            }

            cout << endl << "  Post added successfully!" << endl;
            break;
        }

        case 2: {
            // Like Post
            cout << endl << "--- Like Post ---" << endl;
            cout << "  Enter Post ID to like: ";
            cin >> postId;

            int likeChoice;
            cout << "  Like in (1=BST, 2=Treap, 3=Both): ";
            cin >> likeChoice;

            if (likeChoice == 1 || likeChoice == 3) {
                Post* bstPost = bst.searchPost(postId);
                if (bstPost == nullptr) {
                    cout << "  Post not found in BST!" << endl;
                }
                else {
                    int oldScore = bstPost->score;
                    bst.likePost(postId);
                    cout << "  BST: Score " << oldScore << " -> " << (oldScore + 1) << endl;
                }
            }

            if (likeChoice == 2 || likeChoice == 3) {
                Post* treapPost = treap.searchPost(postId);
                if (treapPost == nullptr) {
                    cout << "  Post not found in Treap!" << endl;
                }
                else {
                    int oldScore = treapPost->score;
                    treap.likePost(postId);
                    cout << "  Treap: Score " << oldScore << " -> " << (oldScore + 1) << endl;
                }
            }
            break;
        }

        case 3: {
            // Delete Post
            cout << endl << "--- Delete Post ---" << endl;
            cout << "  Enter Post ID to delete: ";
            cin >> postId;

            int deleteChoice;
            cout << "  Delete from (1=BST, 2=Treap, 3=Both): ";
            cin >> deleteChoice;

            if (deleteChoice == 1 || deleteChoice == 3) {
                Post* bstPost = bst.searchPost(postId);
                if (bstPost == nullptr) {
                    cout << "  Post not found in BST!" << endl;
                }
                else {
                    bst.deletePost(postId);
                    cout << "  Deleted from BST. Size: " << bst.getSize() << endl;
                }
            }

            if (deleteChoice == 2 || deleteChoice == 3) {
                Post* treapPost = treap.searchPost(postId);
                if (treapPost == nullptr) {
                    cout << "  Post not found in Treap!" << endl;
                }
                else {
                    treap.deletePost(postId);
                    cout << "  Deleted from Treap. Size: " << treap.getSize() << endl;
                }
            }
            break;
        }

        case 4: {
            // Search Post
            cout << endl << "--- Search Post ---" << endl;
            cout << "  Enter Post ID to search: ";
            cin >> postId;

            Post* bstPost = bst.searchPost(postId);
            Post* treapPost = treap.searchPost(postId);

            if (bstPost == nullptr) {
                cout << "  Post not found in BST!" << endl;
            }
            else {
                cout << "  BST Found: (" << bstPost->postId << ", " << bstPost->timestamp << ", " << bstPost->score << ")" << endl;
            }

            if (treapPost == nullptr) {
                cout << "  Post not found in Treap!" << endl;
            }
            else {
                cout << "  Treap Found: (" << treapPost->postId << ", " << treapPost->timestamp << ", " << treapPost->score << ")" << endl;
            }
            break;
        }

        case 5: {
            // Get Most Popular
            cout << endl << "--- Most Popular Post ---" << endl;

            Post* bstPopular = bst.getMostPopular();
            Post* treapPopular = treap.getMostPopular();

            if (bstPopular == nullptr) {
                cout << "  BST: No posts!" << endl;
            }
            else {
                cout << "  BST: (" << bstPopular->postId << ", " << bstPopular->timestamp << ", score: " << bstPopular->score << ")" << endl;
            }

            if (treapPopular == nullptr) {
                cout << "  Treap: No posts!" << endl;
            }
            else {
                cout << "  Treap: (" << treapPopular->postId << ", " << treapPopular->timestamp << ", score: " << treapPopular->score << ")" << endl;
            }
            break;
        }

        case 6: {
            // Get Most Recent
            cout << endl << "--- Most Recent Posts ---" << endl;
            cout << "  Enter k (number of recent posts): ";
            cin >> k;

            vector<Post> bstRecent = bst.getMostRecent(k);
            vector<Post> treapRecent = treap.getMostRecent(k);

            cout << endl << "  BST Most Recent (" << bstRecent.size() << " posts):" << endl;
            for (size_t i = 0; i < bstRecent.size(); i++) {
                cout << "    " << (i + 1) << ". " << bstRecent[i].postId << " (timestamp: " << bstRecent[i].timestamp << ", score: " << bstRecent[i].score << ")" << endl;
            }

            cout << endl << "  Treap Most Recent (" << treapRecent.size() << " posts):" << endl;
            for (size_t i = 0; i < treapRecent.size(); i++) {
                cout << "    " << (i + 1) << ". " << treapRecent[i].postId << " (timestamp: " << treapRecent[i].timestamp << ", score: " << treapRecent[i].score << ")" << endl;
            }
            break;
        }

        case 7: {
            // Display Tree Stats
            cout << endl << "--- Tree Statistics ---" << endl;
            cout << "+---------------------------+------------+------------+" << endl;
            cout << "| Metric                    |    BST     |   Treap    |" << endl;
            cout << "+---------------------------+------------+------------+" << endl;
            cout << "| Size                      | " << setw(10) << bst.getSize() << " | " << setw(10) << treap.getSize() << " |" << endl;
            cout << "| Height                    | " << setw(10) << bst.getHeight() << " | " << setw(10) << treap.getHeight() << " |" << endl;
            cout << "| Balance Factor            | " << setw(10) << bst.getBalanceFactor() << " | " << setw(10) << treap.getBalanceFactor() << " |" << endl;
            cout << "| Rotations                 | " << setw(10) << "N/A" << " | " << setw(10) << treap.getRotationCount() << " |" << endl;
            cout << "+---------------------------+------------+------------+" << endl;
            break;
        }

        case 8: {
            // Run Assignment Test Case
            runAssignmentTestCase(bst, treap);
            break;
        }

        case 9: {
            // Validate Treap Structure
            if (treap.getSize() == 0) {
                cout << endl << "  Treap is empty! Add posts or load dataset first." << endl;
            }
            else {
                treap.printValidationReport();
            }
            break;
        }

        case 10: {
            // Run Complex Validation Test
            runComplexValidationTest(treap);
            break;
        }

        case 11: {
            // Load Dataset & Run Performance Test
            loadDataset(bst, treap, true);
            break;
        }

        case 12: {
            // Load Dataset Only (No Performance Test)
            loadDataset(bst, treap, false);
            break;
        }

        case 0: {
            // Exit
            cout << endl << "Thank you for using the Social Media Feed Management System!" << endl;
            cout << "Goodbye!" << endl << endl;
            return 0;
        }

        default: {
            cout << endl << "  Invalid choice! Please enter 0-12." << endl;
            break;
        }
        }
    }

    return 0;
}