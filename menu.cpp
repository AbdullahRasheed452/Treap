//#include <iostream>
//#include <string>
//#include "BST.h"
//#include "Treap.h"
//
//using namespace std;
//
//void displayMenu() {
//    cout << endl;
//    cout << "=====================================================" << endl;
//    cout << "     Social Media Feed Management System             " << endl;
//    cout << "=====================================================" << endl;
//    cout << "  1. Add Post" << endl;
//    cout << "  2. Like Post" << endl;
//    cout << "  3. Delete Post" << endl;
//    cout << "  4. Search Post" << endl;
//    cout << "  5. Get Most Popular Post" << endl;
//    cout << "  6. Get Most Recent Posts" << endl;
//    cout << "  7. Display Tree Stats" << endl;
//    cout << "  8. Run Assignment Test Case" << endl;
//    cout << "  9. Validate Treap Structure" << endl;
//    cout << "  10. Run Complex Validation Test" << endl;
//    cout << "  0. Exit" << endl;
//    cout << "=====================================================" << endl;
//    cout << "  Enter your choice: ";
//}
//
//void runAssignmentTestCase(BST& bst, Treap& treap) {
//    cout << endl;
//    cout << "--- Running Assignment Test Case ---" << endl;
//
//    // Clear existing data
//    bst = BST();
//    treap = Treap();
//
//    // Step 1: Add posts
//    cout << endl << "Step 1: Adding 5 posts..." << endl;
//
//    bst.addPost("ejualnb", 1554076800, 55);
//    bst.addPost("ejualnc", 1554076800, 12);
//    bst.addPost("ejualnd", 1554076800, 27);
//    bst.addPost("ejualne", 1554076800, 14);
//    bst.addPost("ejualnl", 1554076809, 13);
//
//    treap.addPost("ejualnb", 1554076800, 55);
//    treap.addPost("ejualnc", 1554076800, 12);
//    treap.addPost("ejualnd", 1554076800, 27);
//    treap.addPost("ejualne", 1554076800, 14);
//    treap.addPost("ejualnl", 1554076809, 13);
//
//    cout << "  BST Size: " << bst.getSize() << ", Height: " << bst.getHeight() << endl;
//    cout << "  Treap Size: " << treap.getSize() << ", Height: " << treap.getHeight() << endl;
//
//    Post* popular = treap.getMostPopular();
//    cout << "  Treap Most Popular: " << popular->postId << " (score: " << popular->score << ")" << endl;
//
//    // Step 2: Like post twice
//    cout << endl << "Step 2: Liking 'ejualnl' twice..." << endl;
//
//    bst.likePost("ejualnl");
//    bst.likePost("ejualnl");
//
//    treap.likePost("ejualnl");
//    treap.likePost("ejualnl");
//
//    Post* bstLiked = bst.searchPost("ejualnl");
//    Post* treapLiked = treap.searchPost("ejualnl");
//
//    cout << "  BST 'ejualnl' score: " << bstLiked->score << " (expected: 15)" << endl;
//    cout << "  Treap 'ejualnl' score: " << treapLiked->score << " (expected: 15)" << endl;
//
//    // Step 3: Delete post
//    cout << endl << "Step 3: Deleting 'ejualnc'..." << endl;
//
//    bst.deletePost("ejualnc");
//    treap.deletePost("ejualnc");
//
//    cout << "  BST Size after delete: " << bst.getSize() << " (expected: 4)" << endl;
//    cout << "  Treap Size after delete: " << treap.getSize() << " (expected: 4)" << endl;
//
//    Post* bstDeleted = bst.searchPost("ejualnc");
//    Post* treapDeleted = treap.searchPost("ejualnc");
//
//    if (bstDeleted == nullptr) {
//        cout << "  BST: 'ejualnc' not found (deleted successfully)" << endl;
//    }
//    if (treapDeleted == nullptr) {
//        cout << "  Treap: 'ejualnc' not found (deleted successfully)" << endl;
//    }
//
//    // Step 4: Get most popular
//    cout << endl << "Step 4: Getting most popular post..." << endl;
//
//    Post* bstPopular = bst.getMostPopular();
//    Post* treapPopular = treap.getMostPopular();
//
//    cout << "  BST Result: (" << bstPopular->postId << ", " << bstPopular->timestamp << ", " << bstPopular->score << ")" << endl;
//    cout << "  Treap Result: (" << treapPopular->postId << ", " << treapPopular->timestamp << ", " << treapPopular->score << ")" << endl;
//    cout << "  Expected: (ejualnb, 1554076800, 55)" << endl;
//
//    // Verification
//    cout << endl;
//    cout << "=====================================================" << endl;
//    if (treapPopular->postId == "ejualnb" && treapPopular->score == 55 && treap.getSize() == 4) {
//        cout << "  ALL ASSIGNMENT TESTS PASSED!" << endl;
//    }
//    else {
//        cout << "  SOME TESTS FAILED!" << endl;
//    }
//    cout << "=====================================================" << endl;
//}
//
//void runComplexValidationTest(Treap& treap) {
//    cout << endl;
//    cout << "=====================================================" << endl;
//    cout << "      COMPLEX VALIDATION TEST SEQUENCE               " << endl;
//    cout << "=====================================================" << endl;
//
//    // Reset treap
//    treap = Treap();
//
//    cout << endl << "Phase 1: Inserting 20 posts with varying scores..." << endl;
//
//    // Insert posts with different scores
//    treap.addPost("alpha", 1000001, 50);
//    treap.addPost("beta", 1000002, 80);
//    treap.addPost("gamma", 1000003, 30);
//    treap.addPost("delta", 1000004, 95);
//    treap.addPost("epsilon", 1000005, 15);
//    treap.addPost("zeta", 1000006, 70);
//    treap.addPost("eta", 1000007, 25);
//    treap.addPost("theta", 1000008, 88);
//    treap.addPost("iota", 1000009, 42);
//    treap.addPost("kappa", 1000010, 67);
//    treap.addPost("lambda", 1000011, 33);
//    treap.addPost("mu", 1000012, 91);
//    treap.addPost("nu", 1000013, 19);
//    treap.addPost("xi", 1000014, 76);
//    treap.addPost("omicron", 1000015, 54);
//    treap.addPost("pi", 1000016, 100);
//    treap.addPost("rho", 1000017, 11);
//    treap.addPost("sigma", 1000018, 63);
//    treap.addPost("tau", 1000019, 45);
//    treap.addPost("upsilon", 1000020, 82);
//
//    cout << "  Inserted 20 posts." << endl;
//    cout << "  Size: " << treap.getSize() << ", Height: " << treap.getHeight() << endl;
//    cout << "  Rotations so far: " << treap.getRotationCount() << endl;
//
//    cout << endl << "  Validating after insertions..." << endl;
//    bool valid1 = treap.validateStructure();
//    cout << "  Structure valid: " << (valid1 ? "YES" : "NO") << endl;
//
//    // Phase 2: Like operations
//    cout << endl << "Phase 2: Performing 10 like operations..." << endl;
//
//    treap.likePost("epsilon");  // 15 -> 16
//    treap.likePost("epsilon");  // 16 -> 17
//    treap.likePost("epsilon");  // 17 -> 18
//    treap.likePost("rho");      // 11 -> 12
//    treap.likePost("gamma");    // 30 -> 31
//    treap.likePost("nu");       // 19 -> 20
//    treap.likePost("eta");      // 25 -> 26
//    treap.likePost("pi");       // 100 -> 101 (should stay at root)
//    treap.likePost("pi");       // 101 -> 102
//    treap.likePost("alpha");    // 50 -> 51
//
//    cout << "  Completed 10 like operations." << endl;
//    cout << "  Rotations so far: " << treap.getRotationCount() << endl;
//
//    cout << endl << "  Validating after likes..." << endl;
//    bool valid2 = treap.validateStructure();
//    cout << "  Structure valid: " << (valid2 ? "YES" : "NO") << endl;
//
//    Post* mostPopular = treap.getMostPopular();
//    cout << "  Most popular: " << mostPopular->postId << " (score: " << mostPopular->score << ")" << endl;
//    cout << "  Expected: pi (score: 102)" << endl;
//
//    // Phase 3: Delete operations
//    cout << endl << "Phase 3: Deleting 5 posts..." << endl;
//
//    treap.deletePost("delta");    // Delete high priority node
//    treap.deletePost("rho");      // Delete low priority node
//    treap.deletePost("kappa");    // Delete middle node
//    treap.deletePost("theta");    // Delete another high priority
//    treap.deletePost("lambda");   // Delete another node
//
//    cout << "  Deleted 5 posts." << endl;
//    cout << "  Size: " << treap.getSize() << " (expected: 15)" << endl;
//    cout << "  Height: " << treap.getHeight() << endl;
//    cout << "  Rotations so far: " << treap.getRotationCount() << endl;
//
//    cout << endl << "  Validating after deletions..." << endl;
//    bool valid3 = treap.validateStructure();
//    cout << "  Structure valid: " << (valid3 ? "YES" : "NO") << endl;
//
//    // Phase 4: More insertions after deletions
//    cout << endl << "Phase 4: Inserting 5 new posts..." << endl;
//
//    treap.addPost("phi", 1000021, 99);
//    treap.addPost("chi", 1000022, 77);
//    treap.addPost("psi", 1000023, 55);
//    treap.addPost("omega", 1000024, 110);  // New highest!
//    treap.addPost("final", 1000025, 5);
//
//    cout << "  Inserted 5 new posts." << endl;
//    cout << "  Size: " << treap.getSize() << " (expected: 20)" << endl;
//    cout << "  Height: " << treap.getHeight() << endl;
//    cout << "  Rotations so far: " << treap.getRotationCount() << endl;
//
//    cout << endl << "  Validating after new insertions..." << endl;
//    bool valid4 = treap.validateStructure();
//    cout << "  Structure valid: " << (valid4 ? "YES" : "NO") << endl;
//
//    mostPopular = treap.getMostPopular();
//    cout << "  Most popular: " << mostPopular->postId << " (score: " << mostPopular->score << ")" << endl;
//    cout << "  Expected: omega (score: 110)" << endl;
//
//    // Final Report
//    cout << endl;
//    cout << "=====================================================" << endl;
//    cout << "           FINAL VALIDATION SUMMARY                  " << endl;
//    cout << "=====================================================" << endl;
//    cout << "  Phase 1 (After insertions):  " << (valid1 ? "PASSED" : "FAILED") << endl;
//    cout << "  Phase 2 (After likes):       " << (valid2 ? "PASSED" : "FAILED") << endl;
//    cout << "  Phase 3 (After deletions):   " << (valid3 ? "PASSED" : "FAILED") << endl;
//    cout << "  Phase 4 (After more inserts):" << (valid4 ? "PASSED" : "FAILED") << endl;
//    cout << "=====================================================" << endl;
//
//    if (valid1 && valid2 && valid3 && valid4) {
//        cout << "  ALL STRUCTURAL VALIDATIONS PASSED!" << endl;
//        cout << "  Treap maintained both BST and Heap properties" << endl;
//        cout << "  throughout all complex operations." << endl;
//    }
//    else {
//        cout << "  SOME VALIDATIONS FAILED!" << endl;
//    }
//    cout << "=====================================================" << endl;
//
//    
//    treap.printValidationReport();
//}
//
//int main() {
//    BST bst;
//    Treap treap;
//
//    int choice;
//    string postId;
//    int timestamp, score, k;
//
//    while (true) {
//        displayMenu();
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            
//            cout << endl << "--- Add Post ---" << endl;
//            cout << "  Enter Post ID: ";
//            cin >> postId;
//            cout << "  Enter Timestamp: ";
//            cin >> timestamp;
//            cout << "  Enter Score: ";
//            cin >> score;
//
//            bst.addPost(postId, timestamp, score);
//            treap.addPost(postId, timestamp, score);
//
//            cout << endl << "  Post added successfully!" << endl;
//            cout << "  BST Size: " << bst.getSize() << ", Treap Size: " << treap.getSize() << endl;
//            break;
//        }
//
//        case 2: {
//            
//            cout << endl << "--- Like Post ---" << endl;
//            cout << "  Enter Post ID to like: ";
//            cin >> postId;
//
//            Post* bstPost = bst.searchPost(postId);
//            Post* treapPost = treap.searchPost(postId);
//
//            if (bstPost == nullptr || treapPost == nullptr) {
//                cout << "  Post not found!" << endl;
//            }
//            else {
//                int oldScore = bstPost->score;
//                bst.likePost(postId);
//                treap.likePost(postId);
//
//                cout << "  Post liked! Score: " << oldScore << " -> " << (oldScore + 1) << endl;
//            }
//            break;
//        }
//
//        case 3: {
//           
//            cout << endl << "--- Delete Post ---" << endl;
//            cout << "  Enter Post ID to delete: ";
//            cin >> postId;
//
//            Post* bstPost = bst.searchPost(postId);
//
//            if (bstPost == nullptr) {
//                cout << "  Post not found!" << endl;
//            }
//            else {
//                bst.deletePost(postId);
//                treap.deletePost(postId);
//
//                cout << "  Post deleted successfully!" << endl;
//                cout << "  BST Size: " << bst.getSize() << ", Treap Size: " << treap.getSize() << endl;
//            }
//            break;
//        }
//
//        case 4: {
//            
//            cout << endl << "--- Search Post ---" << endl;
//            cout << "  Enter Post ID to search: ";
//            cin >> postId;
//
//            Post* bstPost = bst.searchPost(postId);
//            Post* treapPost = treap.searchPost(postId);
//
//            if (bstPost == nullptr) {
//                cout << "  Post not found in BST!" << endl;
//            }
//            else {
//                cout << "  BST Found: (" << bstPost->postId << ", " << bstPost->timestamp << ", " << bstPost->score << ")" << endl;
//            }
//
//            if (treapPost == nullptr) {
//                cout << "  Post not found in Treap!" << endl;
//            }
//            else {
//                cout << "  Treap Found: (" << treapPost->postId << ", " << treapPost->timestamp << ", " << treapPost->score << ")" << endl;
//            }
//            break;
//        }
//
//        case 5: {
//            
//            cout << endl << "--- Most Popular Post ---" << endl;
//
//            Post* bstPopular = bst.getMostPopular();
//            Post* treapPopular = treap.getMostPopular();
//
//            if (bstPopular == nullptr) {
//                cout << "  BST: No posts!" << endl;
//            }
//            else {
//                cout << "  BST: (" << bstPopular->postId << ", " << bstPopular->timestamp << ", score: " << bstPopular->score << ")" << endl;
//            }
//
//            if (treapPopular == nullptr) {
//                cout << "  Treap: No posts!" << endl;
//            }
//            else {
//                cout << "  Treap: (" << treapPopular->postId << ", " << treapPopular->timestamp << ", score: " << treapPopular->score << ")" << endl;
//            }
//            break;
//        }
//
//        case 6: {
//           
//            cout << endl << "--- Most Recent Posts ---" << endl;
//            cout << "  Enter k (number of recent posts): ";
//            cin >> k;
//
//            vector<Post> bstRecent = bst.getMostRecent(k);
//            vector<Post> treapRecent = treap.getMostRecent(k);
//
//            cout << endl << "  BST Most Recent (" << bstRecent.size() << " posts):" << endl;
//            for (int i = 0; i < bstRecent.size(); i++) {
//                cout << "    " << (i + 1) << ". " << bstRecent[i].postId << " (timestamp: " << bstRecent[i].timestamp << ", score: " << bstRecent[i].score << ")" << endl;
//            }
//
//            cout << endl << "  Treap Most Recent (" << treapRecent.size() << " posts):" << endl;
//            for (int i = 0; i < treapRecent.size(); i++) {
//                cout << "    " << (i + 1) << ". " << treapRecent[i].postId << " (timestamp: " << treapRecent[i].timestamp << ", score: " << treapRecent[i].score << ")" << endl;
//            }
//            break;
//        }
//
//        case 7: {
//            
//            cout << endl << "--- Tree Statistics ---" << endl;
//            cout << "+---------------------------+----------+----------+" << endl;
//            cout << "| Metric                    |   BST    |  Treap   |" << endl;
//            cout << "+---------------------------+----------+----------+" << endl;
//            cout << "| Size                      | " << bst.getSize() << "        | " << treap.getSize() << "        |" << endl;
//            cout << "| Height                    | " << bst.getHeight() << "        | " << treap.getHeight() << "        |" << endl;
//            cout << "| Balance Factor            | " << bst.getBalanceFactor() << "        | " << treap.getBalanceFactor() << "        |" << endl;
//            cout << "| Rotations                 | N/A      | " << treap.getRotationCount() << "        |" << endl;
//            cout << "+---------------------------+----------+----------+" << endl;
//            break;
//        }
//
//        case 8: {
//            
//            runAssignmentTestCase(bst, treap);
//            break;
//        }
//
//        case 9: {
//            
//            treap.printValidationReport();
//            break;
//        }
//
//        case 10: {
//            
//            runComplexValidationTest(treap);
//            break;
//        }
//
//        case 0: {
//            
//            cout << endl << "Thank you for using the Social Media Feed Management System!" << endl;
//            cout << "Goodbye!" << endl << endl;
//            return 0;
//        }
//
//        default: {
//            cout << endl << "  Invalid choice! Please enter 0-10." << endl;
//            break;
//        }
//        }
//    }
//
//    return 0;
//}