// YOUR SOLUTION GOES HERE -- YOU DON'T NEED TO ERASE THE REST  
// -----------------------------------------------------------  
// MAKE SURE THAT YOUR SUBMISSION COMPILES, OTHERWISE YOU WILL  
// GET ZERO POINTS TODAY AND THAT WILL BE A PITY!  
// ------------------------(snip)-----------------------------  
#include <queue>  
#include <iostream>  
#include <vector>  
  
using namespace std;  
  
class Tree {  
public:  
  Tree() : root(nullptr) {}  
  ~Tree() { delete root; }  
  
  void insert(int v);  
  vector<int> lsum();  
  
private:  
  struct node {  
    node(int d, node *l, node *r) : data(d), left(l), right(r) {}  
    ~node() { delete left; delete right; }  
  
    int data;  
    node *left, *right;  
  };  
  
  static node *insert(node *t, int v);  
  
  node *root;  
  
  int maxdepth(node * root);  
  vector<int> hel(vector<int> &sums, node *root, int level);  
  
};  
  
int Tree::maxdepth(node * root){  
    if (root == NULL)  
        return 0;  
    else {  
        int ldepth = maxdepth(root->left);  
        int rdepth = maxdepth(root->right);  
        if (ldepth > rdepth)  
          return(ldepth + 1);  
        else   
          return(rdepth + 1);  
    }  
}  
  
vector<int> Tree::hel(vector<int> &sums, node *root, int level){  
  if (root!=nullptr){  
    sums[level] += root->data;  
    hel(sums, root->left, level+1);  
    hel(sums, root->right, level+1);  
  }  
  return sums;  
}  
  
vector<int> Tree::lsum() {  
   vector<int> result(maxdepth(root) ,0);  
  hel(result, root, 0);  
    
  return result;  
}  
  
// YOU DON'T NEED TO CHANGE THE REST. IF YOU DO, YOU'D BETTER  
// KNOW WHAT YOU'RE DOING...  
  
void Tree::insert(int v) { root = insert(root, v); }  
  
Tree::node *Tree::insert(node *t, int v) {  
  if (t == nullptr)  
    return new node(v, nullptr, nullptr);  
  if (v < t->data)  
    t->left = insert(t->left, v);  
  else  
    t->right = insert(t->right, v);  
  return t;  
}  
  
// ------------------------(snip)-----------------------------  
// YOUR SOLUTION ENDS HERE -- YOU DON'T NEED TO ERASE THE REST  
  
#ifndef CONTEST  
  
int main() {  
  Tree t;  
  int values[] = {42, 17, 57, 12, 34, 89, 16, 38, 5};  
  for (int v : values) t.insert(v);  
  cout << "t =     42" << endl;  
  cout << "       /  \\" << endl;  
  cout << "     17    57" << endl;  
  cout << "    /  \\    \\" << endl;  
  cout << "  12    34   89" << endl;  
  cout << " /  \\    \\" << endl;  
  cout << "5    16   38" << endl;  
  cout << endl;  
  vector<int> sums = t.lsum();  
  for (int i = 0; i < sums.size(); ++i)  
    cout << "Level " << i << " has sum " << sums[i] << endl;  
}  
  
#endif