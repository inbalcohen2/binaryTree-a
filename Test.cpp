#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
using namespace std;
#include "BinaryTree.hpp"
using namespace ariel;

// check if the root is the last number that we add 
TEST_CASE ("add root-int") {
    BinaryTree<int> tree_of_ints_root;
    CHECK_NOTHROW(tree_of_ints_root.add_root(1));
    auto it=tree_of_ints_root.begin_inorder();
    
    CHECK((*it)==1);
    for (int i = 0; i < 3; i++) {
        tree_of_ints_root.add_root(i);
    }
     it=tree_of_ints_root.begin_inorder();
    CHECK((*it)==2);
// check now root-string
    }
TEST_CASE ("add root-string") {
    BinaryTree<string> tree_of_strings_root;
    CHECK_NOTHROW(tree_of_strings_root.add_root("inbal"));
    auto it=tree_of_strings_root.begin_inorder();
    CHECK((*it)=="inbal");
    CHECK_NOTHROW(tree_of_strings_root.add_root("inbal"));
    CHECK_NOTHROW(tree_of_strings_root.add_root("cohen"));
    it=tree_of_strings_root.begin_preorder();
    CHECK((*it)=="cohen");
    }
    // checkd if the add left is work 
TEST_CASE ("add left-int") {
    BinaryTree<int> tree_of_ints_left;
    CHECK_THROWS(tree_of_ints_left.add_left(1, 2));//not have yet a root
    CHECK_NOTHROW(tree_of_ints_left.add_root(1));
    int arrPostorder[]={5,4,3,2,1};
    int arrInorder[]={6,4,3,2,1};
    int arrPreorder[]={1,2,3,4,6};

    for (int i = 1; i < 5; i++) {
        CHECK_NOTHROW(tree_of_ints_left.add_left(i, i+1));////5<4<3<2<1
    }
     cout << tree_of_ints_left << endl;
     //init to num of root
     int i=0;
      for (auto it=tree_of_ints_left.begin_postorder(); it!=tree_of_ints_left.end_postorder(); ++it) {
        CHECK((*it)==arrPostorder[i++]);   
    }  
    CHECK_NOTHROW(tree_of_ints_left.add_left(4, 6));//6<4<3<2<1
    CHECK_THROWS(tree_of_ints_left.add_left(5, 7));//5 not exist_not valid
    cout << tree_of_ints_left << endl;

    i=0;
    for (auto it=tree_of_ints_left.begin_inorder(); it!=tree_of_ints_left.end_inorder(); ++it) {
        CHECK((*it)==arrInorder[i++]);   ////6<4<3<2<1
    }
    i=0;
    for (auto it=tree_of_ints_left.begin_preorder(); it!=tree_of_ints_left.end_preorder(); ++it) {
        CHECK((*it)==arrPreorder[i++]);   
    }
    }
        // check if the add right is work 

     TEST_CASE ("add right-int") {
    BinaryTree<int> tree_of_ints_right;
    CHECK_THROWS(tree_of_ints_right.add_right(2, 1));//not have a root yet
    CHECK_NOTHROW(tree_of_ints_right.add_root(1));
    int arrPostorder[]={5,4,3,2,1};
    int arrInorder[]={1,2,3,4,6};
    int arrPreorder[]={1,2,3,4,6};

    for (int i = 1; i < 5; i++) {
       CHECK_NOTHROW(tree_of_ints_right.add_right(i, i+1));////1>2>3>4>5
    }
     cout << tree_of_ints_right << endl;
     //init to num of root
     int i=0;
      for (auto it=tree_of_ints_right.begin_postorder(); it!=tree_of_ints_right.end_postorder(); ++it) {
        CHECK((*it)==arrPostorder[i++]);   
    }  
    CHECK_NOTHROW(tree_of_ints_right.add_right(4, 6));////1>2>3>4>6
    CHECK_THROWS(tree_of_ints_right.add_right(5, 7));//5 not exist_not valid
    cout << tree_of_ints_right << endl;

    i=0;
    for (auto it=tree_of_ints_right.begin_inorder(); it!=tree_of_ints_right.end_inorder(); ++it) {
        CHECK((*it)==arrInorder[i++]);   ////6<4<3<2<1
    }
    i=0;
    for (auto it=tree_of_ints_right.begin_preorder(); it!=tree_of_ints_right.end_preorder(); ++it) {
        CHECK((*it)==arrPreorder[i++]);   
    }
     }
     // check all  tree _root_left_right -int
TEST_CASE ("full binart tree- int") {
    BinaryTree<int> tree_of_ints_full;
    CHECK_THROWS(tree_of_ints_full.add_right(1, 2));///not have root 
    CHECK_THROWS(tree_of_ints_full.add_left(1, 3));
    tree_of_ints_full.add_root(1);
    int arrPostorder[]={5,6,5,4,3,4,3,2,1};
    int arrInorder[]={5,3,6,4,5,1,4,2,3};
    int arrPreorder[]={1,3,5,4,6,5,2,4,3};

    for (int i = 1; i < 5; i++) {
        tree_of_ints_full.add_right(i, i+1);////1>2>3>4>5
        tree_of_ints_full.add_left(i, i+2);////1>2>3>4>5
  
    }
    cout << tree_of_ints_full << endl;//1 3 5 4 6 5 2 4 3
     cout << tree_of_ints_full << endl;
     //init to num of root
     int i=0;
      for (auto it=tree_of_ints_full.begin_postorder(); it!=tree_of_ints_full.end_postorder(); ++it) {
        CHECK((*it)==arrPostorder[i++]);   
    }  

    i=0;
    for (auto it=tree_of_ints_full.begin_inorder(); it!=tree_of_ints_full.end_inorder(); ++it) {
        CHECK((*it)==arrInorder[i++]);   ////6<4<3<2<1
    }
    i=0;
    for (auto it=tree_of_ints_full.begin_preorder(); it!=tree_of_ints_full.end_preorder(); ++it) {
        CHECK((*it)==arrPreorder[i++]);   
    }
     }
     // check all  tree _root_left_right -string

TEST_CASE(" Binary tree (root_left_right )-string"){

    BinaryTree<string> bTree_full_String;
    CHECK_THROWS(bTree_full_String.add_left("i","a"));//not have a root yet
    CHECK_THROWS(bTree_full_String.add_right("a", "l"));
    CHECK_NOTHROW(bTree_full_String.add_root("s"));//s
    CHECK_NOTHROW(bTree_full_String.add_root("i"));//i
    CHECK_NOTHROW(bTree_full_String.add_left("i","n"));
    CHECK_NOTHROW(bTree_full_String.add_right("n", "a"));
    CHECK_NOTHROW(bTree_full_String.add_right("a", "l"));
    CHECK_NOTHROW(bTree_full_String.add_left("n", "b"));
    CHECK_NOTHROW(bTree_full_String.add_right("i","c"));
    CHECK_NOTHROW(bTree_full_String.add_left("c","o"));
    CHECK_NOTHROW(bTree_full_String.add_right("c","e"));
    CHECK_NOTHROW(bTree_full_String.add_left("e", "h"));
    CHECK_NOTHROW(bTree_full_String.add_right("e","n"));

    string Inorder[]={"b","n","a","l","i","c","o","h","e","n"};
    // i n b a l c o h e n
    string Preorder[]={"i","n","b","a","l","c","o","e","h","n"};
    string Postorder[]={"b","l","a","n","c","h","n","e","o","i"};
    int i=0;
    for (auto it=bTree_full_String.begin_inorder(); it!=bTree_full_String.end_inorder(); ++it) {
        CHECK((*it)==Inorder[i++]);
    }
     i=0;    
    for (auto it=bTree_full_String.begin_preorder(); it!=bTree_full_String.end_preorder(); ++it) {
        CHECK((*it)==Preorder[i++]);  
    }
    i=0;
    for (auto it=bTree_full_String.begin_postorder(); it!=bTree_full_String.end_postorder(); ++it) {
        CHECK((*it)==Postorder[i++]);    
    }
} 