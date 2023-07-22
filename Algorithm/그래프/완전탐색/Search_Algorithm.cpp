#include <iostream>
#include <vector>

using namespace std;

template<typename T> class Node {
private:
	T value;
	bool check;
	vector<Node<T>*> vn;

	void DisplaySequence(Node<T>* n, int depth) {
		if (n == nullptr || n->check == true) return;
		n->check = true;

		for (int i = 0; i < depth; i++) cout << "      ";
		if (depth != 0) cout << (char)3 << "  "; else cout << "-  ";
		cout << n->value << endl;

		for (int i = 0; i < n->vn.size(); i++) DisplaySequence(n->vn[i], depth + 1);
		return;
	}
	void ResetSequence(Node<T>* n) {
		if (n == nullptr) return;
		if (!n->check) return;

		n->check = false;
		for (int i = n->vn.size() - 1; i >= 0; i--) ResetSequence(n->vn[i]);
		return;
	}
	Node<T>* DepthFirstSearchSequence(Node<T>* curr, T _value) {
		if (curr == nullptr) return nullptr;
		if (curr->check == false) return nullptr;
		if (curr->value == _value) return curr;

		for (int i = 0; i < curr->vn.size(); i++) {
			Node<T>* target = DisplaySequence(vn[i]);
			if (target != nullptr) return target;
		}
		return nullptr;
	}
	Node<T>* BreathFirstSearchSequence() {
		return this;
	}
public:
	Node(T _value) {
		this->value = _value;
		this->check = false;
		this->vn = vector<Node<T>*>(0);
	}
	T Value() {
		return this->value;
	}
	Node<T>* Insert(T _value) {
		Node<T>* newNode = new Node<T>(_value);
		newNode->vn.push_back(this);
		this->vn.push_back(newNode);
		return this;
	}
	Node<T>* Insert(Node<T>* n) {
		n->vn.push_back(this);
		this->vn.push_back(n);
		return this;
	}
	void Display() {
		cout << "[DISPLAY] :" << endl;
		DisplaySequence(this, 0);
		ResetSequence(this);
		cout << endl;
		return;
	}
	Node<T>* DFS(T _value) {
		return DepthFirstSearchSequence(this, _value);
	}
};

int main(){

	Node<int> *n1 = new Node<int>(1);
	Node<int>* n2 = new Node<int>(2);
	n1->Insert(3)->Insert(5)->Insert(7)->Insert(9);
	n2->Insert(n1)->Insert(4)->Insert(6)->Insert(8)->Insert(10);
	n2->Display();
	n1->Display();
	//n1->Insert(30)->Insert(n2)->Insert(40)->Insert(7)->Insert(10)->Display();
	return 0;
}