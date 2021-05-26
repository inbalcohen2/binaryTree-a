
#include <iostream>
#include <unordered_map>
#include <utility>      // std::pair, std::make_pair

using namespace std;
namespace ariel {

template <typename T>
class BinaryTree {
private:
// unordered_map<T, pair<T,T> > tree;
T node;

class iterator
{
public:
T it;

//constructor
iterator(T v) : it(v){
}

// operators
bool operator!=(iterator const &other) const
{
        return it != other.it;
}
bool operator==(BinaryTree::iterator const &other) const
{
        return it == other.it;

}
T operator*() const
{
        return it;
}
iterator &operator++()
{

        // ++it;
        return *this;
}
iterator *operator->() const
     {
        iterator *target;
        return target;
       }
int size(){
return 1;
}
};


public:
BinaryTree() {
}
BinaryTree<T>& add_root(T x){
        return *this;
}
BinaryTree<T>& add_left(T exsist,T swap){
        return *this;
}
BinaryTree<T>& add_right(T exsist,T swap){
        return *this;
}
iterator begin(){
    return iterator(node);
}
iterator   end(){
    return iterator(node);
  }
iterator   begin_preorder(){
    return iterator(node);
}
iterator  end_preorder(){
    return iterator(node);
}
iterator   begin_inorder(){
    return iterator(node);
}
iterator   end_inorder(){
    return iterator(node);
}
iterator   begin_postorder(){
    return iterator(node);
}
iterator end_postorder(){

    return iterator(node);
}
friend ostream& operator<<(ostream& os,BinaryTree<T>& tree){
        return os;
}
};




}
