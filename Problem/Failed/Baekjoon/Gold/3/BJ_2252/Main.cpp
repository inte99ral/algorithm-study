#include <iostream>

using namespace std;

class Node {
 private:
  int i;
 public:
  Node();
  Node(int p);
  void printNode();
};

int main() {
  Node n1;

  Node n2(2);

  n1.printNode();

  return 0;
}

Node::Node()
  :i(0) {
  cout << "test : " << this -> i << "\n";
}

Node::Node(int p)
  :i(p) {
  cout << "test : " << this -> i << "\n";
}

void Node::printNode() {
  cout << "work\n";
}