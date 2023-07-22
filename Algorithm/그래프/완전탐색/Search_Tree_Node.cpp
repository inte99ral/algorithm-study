#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Timer {
private:
	vector<clock_t> start;
	vector<clock_t> end;
	vector<unsigned int> time;
public:
	Timer(int index) {
		cout << "[Timer Activate]" << endl;
		this->start = vector<clock_t>(index);
		this->end = vector<clock_t>(index);
		this->time = vector<unsigned int>(index, 0);
	};
	~Timer() {
		cout << "[Timer Deactivate]" << endl;
	};
	void Start(int index) {
		time[index] = 0;
		start[index] = clock();
		return;
	}
	void End(int index) {
		end[index] = clock();
		time[index] = end[index] - start[index];
		return;
	}
	unsigned int Time(int index) {
		return time[index];
	}
	void Display(int index) {
		cout << "[TIME " << index << "] : " << time[index] << " ms" << endl;
	}

	void DisplayAll() {
		for (unsigned int i = 0; i < time.size(); i++) cout << "[TIME " << i << "] : " << time[i] << " ms" << endl;
	}
};

// 1. Self-Extension Tree (with Self Depth Count) : 자동 확장 트리
/*
class Node {
	int count;
	int depth;
	Node* pNode;
	vector<Node> vn;
public:
	Node(int depth, Node* pNode) {
		this->pNode = pNode;
		this->count = 0;
		this->depth = depth;
		if (depth < 8) {
			Node cNode = Node(depth + 1, this);
			this->vn.push_back(cNode);
			CountUp();
		}
	}
	Node(int depth) {
		this->pNode = this;
		this->count = 0;
		this->depth = depth;
		Node cNode = Node(depth + 1, this);
		this->vn.push_back(cNode);
		CountUp();
	}

	void CountUp() {
		this->count++;
		if (this->pNode != this) {
			pNode->CountUp();
		}
		return;
	}

	int NodePrint() {
		return this->count;
	}
};

int main() {
	Node node = Node(0);
	cout << node.NodePrint();
	return 0;
}
//*/

// 2. Normal Binary Search Tree (BST) : 이진 탐색 트리 
/*
template<typename T> class BinarySearchTree {
private:
	BinarySearchTree<T>* left, * right;
	T value;

	void DisplaySequence(BinarySearchTree<T>* curr) {
		if (curr != nullptr) {
			DisplaySequence(curr->left);
			cout << curr->value << ' ';
			DisplaySequence(curr->right);
		}
		return;
	}
	void SizeSequence(BinarySearchTree<T>* curr, int* count) {
		if (curr != nullptr) {
			SizeSequence(curr->left, count);
			*count += 1;
			SizeSequence(curr->right, count);
		}
		return;
	}
	void PrintSequence(BinarySearchTree<T>* curr) {
		if (curr == nullptr) return;
		if (curr->left != nullptr) cout << curr->left->value;
		else cout << "==";
		cout << " < " << curr->value << " > ";
		if (curr->right != nullptr) cout << curr->right->value;
		else cout << "==";
		cout << endl;
		PrintSequence(curr->left);
		PrintSequence(curr->right);
		return;
	}
	BinarySearchTree<T>* SearchMaxNode(BinarySearchTree<T>* curr) {
		if (curr == nullptr) return nullptr;
		while (curr->right != nullptr) curr = curr->right;
		return curr;
	}
	BinarySearchTree<T>* RemoveSequence(BinarySearchTree<T>* curr, T _value) {
		if (curr == nullptr) return curr;
		else if (curr->value > _value) curr->left = RemoveSequence(curr->left, _value);
		else if (curr->value < _value) curr->right = RemoveSequence(curr->right, _value);
		else {
			BinarySearchTree<T>* target = curr;

			if (target->right == nullptr && target->left == nullptr) {
				delete curr;
				curr = nullptr;
			}
			else if (target->right == nullptr) {
				curr = curr->left;
				delete target;
			}
			else if (target->left == nullptr) {
				curr = curr->right;
				delete target;
			}
			else {
				target = SearchMaxNode(curr->left);
				curr->value = target->value;
				curr->left = RemoveSequence(curr->left, target->value);
			}
		}
		return curr;
	}
public:
	BinarySearchTree(T value = NULL) {
		this->left = nullptr;// root
		this->right = nullptr;
		this->value = value;
	};

	void Insert(T _value) {
		BinarySearchTree<T>* node = new BinarySearchTree<T>(_value);

		if (this->left == nullptr) {
			this->left = node;
			return;
		}

		BinarySearchTree<T>* curr = this->left;
		T c_value = curr->value;

		while (c_value != _value) {
			if (_value < c_value) {
				if (curr->left != nullptr) {
					curr = curr->left;
					c_value = curr->value;
					continue;
				}
				else {
					curr->left = node;
					return;
				}
			}
			else {
				if (curr->right != nullptr) {
					curr = curr->right;
					c_value = curr->value;
					continue;
				}
				else {
					curr->right = node;
					return;
				}
			}
		}
		return;
	}
	void Display() {
		cout << "[DISPLAY] : ";
		if (this->left == nullptr) {
			cout << "EMPTY" << endl;
			return;
		}
		DisplaySequence(this->left);
		cout << endl;
		return;
	}
	void Print() {
		cout << "[PRINT]" << endl;
		PrintSequence(this->left);
	}
	bool Search(T _value) {
		BinarySearchTree<T>* curr = this->left;

		while (curr != nullptr) {
			if (curr->value == _value) {
				return true;
			}
			else if (curr->value > _value) curr = curr->left;
			else curr = curr->right;
		}
		return false;
	}
	void Remove(T _value) {
		RemoveSequence(this->left, _value);
	}
	int Size() {
		int* count = new int(0);
		SizeSequence(this->left, count);
		return *count;
	}
};
//*
int main() {
	Timer* timer = new Timer(1);
	timer->Start(0);
	cout << endl;

	BinarySearchTree<int>* BST = new BinarySearchTree<int>();
	BST->Insert(1);
	BST->Insert(3);
	BST->Insert(6);
	BST->Insert(9);
	BST->Insert(13);
	BST->Insert(22);
	BST->Insert(17);
	BST->Insert(10);
	BST->Insert(2);

	cout << "[SIZE] : " << BST->Size() << endl;
	BST->Display();
	BST->Print();

	if (BST->Search(4)) cout << "[SEARCH] : 4 값을 찾았습니다." << endl;
	else cout << "[SEARCH] : 4 값을 찾지 못했습니다." << endl;
	if (BST->Search(17)) cout << "[SEARCH] : 17 값을 찾았습니다." << endl;
	else cout << "[SEARCH] : 17 값을 찾지 못했습니다." << endl;

	BST->Remove(17);
	BST->Remove(9);
	BST->Remove(6);
	BST->Remove(3);
	BST->Remove(5);
	cout << endl;

	cout << "[SIZE] : " << BST->Size() << endl;
	BST->Display();
	BST->Print();

	cout << endl;
	timer->End(0);
	timer->Display(0);
	delete timer;
}
//*/

// 3. Adelson-Velskii and Landis tree (AVL tree) : 균형 트리
/*
template<typename T> class AdelsonVelskiiAndLandisTree {
private:
	// Hide Variable & Sequence
	AdelsonVelskiiAndLandisTree<T>* left, * right;
	T value;

	int Max(AdelsonVelskiiAndLandisTree<T>* curr) {
		if (curr == nullptr) return NULL;
		while (curr->right != nullptr) curr = curr->right;
		return curr->value;
	}
	int Depth(AdelsonVelskiiAndLandisTree<T>* curr) {
		int d = 0;
		if (curr != nullptr) {
			int left = Depth(curr->left);
			int right = Depth(curr->right);
			d = max(left, right) + 1;
		}
		return d;
	}
	int Factor(AdelsonVelskiiAndLandisTree<T>* curr) {
		int left = Depth(curr->left);
		int right = Depth(curr->right);
		return left - right;
	}
	AdelsonVelskiiAndLandisTree<T>* RightRotate(AdelsonVelskiiAndLandisTree<T>* d0) {
		AdelsonVelskiiAndLandisTree<T>* d1 = d0->left;

		// Position Change d0 <-> d1 
		d0->left = d1->right;
		d1->right = d0;
		return d1;
	}
	AdelsonVelskiiAndLandisTree<T>* LeftRotate(AdelsonVelskiiAndLandisTree<T>* d0) {
		AdelsonVelskiiAndLandisTree<T>* d1 = d0->right;

		// Position Change d0 <-> d1 
		d0->right = d1->left;
		d1->left = d0;
		return d1;
	}
	AdelsonVelskiiAndLandisTree<T>* Balance(AdelsonVelskiiAndLandisTree<T>* curr) {
		if (curr == nullptr) return nullptr;

		int factor = Factor(curr);
		if (factor > 1) {
			if (Factor(curr->left) >= 0) {
				// LL
				return RightRotate(curr);
			}
			else {
				// LR
				curr->left = LeftRotate(curr->left);
				return RightRotate(curr);
			}
		}
		else if (factor < -1) {
			if (Factor(curr->right) <= 0) {
				// RR
				return LeftRotate(curr);
			}
			else {
				// RL
				curr->right = RightRotate(curr->right);
				return LeftRotate(curr);
			}
		}
		return curr;
	}

	AdelsonVelskiiAndLandisTree<T>* InsertSequence(AdelsonVelskiiAndLandisTree<T>* curr, T _value) {
		if (curr == nullptr) return new AdelsonVelskiiAndLandisTree<T>(_value);
		else if (_value < curr->value) curr->left = InsertSequence(curr->left, _value);
		else if (_value > curr->value) curr->right = InsertSequence(curr->right, _value);
		else return curr;
		return Balance(curr);
	}
	AdelsonVelskiiAndLandisTree<T>* RemoveSequence(AdelsonVelskiiAndLandisTree<T>* curr, T _value) {
		if (curr == nullptr) return nullptr;
		else if (_value < curr->value) curr->left = RemoveSequence(curr->left, _value);
		else if (_value > curr->value) curr->right = RemoveSequence(curr->right, _value);
		else {
			AdelsonVelskiiAndLandisTree<T>* temp = curr;
			if ((curr->left == nullptr) && (curr->right == nullptr)) {
				delete curr;
				curr = nullptr;
			}
			else if (curr->right == nullptr) {
				curr = curr->left;
				delete temp;
			}
			else if (curr->left == nullptr) {
				curr = curr->right;
				delete temp;
			}
			else {
				curr->value = Max(curr->left);
				curr->left = RemoveSequence(curr->left, curr->value);
			}
		}
		return Balance(curr);
	}
	AdelsonVelskiiAndLandisTree<T>* FindSequence(AdelsonVelskiiAndLandisTree<T>* curr, T _value) {
		if (curr == nullptr) return nullptr;
		else if (_value < curr->value) return FindSequence(curr->left, _value);
		else if (_value > curr->value) return FindSequence(curr->right, _value);
		else return curr;
	}
	void ClearSequence(AdelsonVelskiiAndLandisTree<T>* curr) {
		if (curr == nullptr) return;
		ClearSequence(curr->left);
		ClearSequence(curr->right);
		delete curr;
		return;
	}
	void InOrderSequence(AdelsonVelskiiAndLandisTree<T>* curr) {
		if (curr != nullptr) {
			InOrderSequence(curr->left);
			cout << curr->value << ' ';
			InOrderSequence(curr->right);
		}
		return;
	}
	void DisplaySequence(AdelsonVelskiiAndLandisTree<T>* curr, int depth, int state) {
		if (curr != nullptr) {
			DisplaySequence(curr->right, depth + 1, 2);

			cout << endl;
			for (int i = 0; i < depth; i++) cout << "      ";

			switch (state)
			{
			case 0:
				cout << "- " << curr->value;
				break;
			case 1:// L
				cout << (char)3 << " " << curr->value;
				break;
			case 2:// R
				cout << (char)1 << " " << curr->value;
				break;
			default:
				break;
			}

			DisplaySequence(curr->left, depth + 1, 1);
		}
	}
	void SizeSequence(AdelsonVelskiiAndLandisTree<T>* curr, int* count) {
		if (curr != nullptr) {
			SizeSequence(curr->left, count);
			*count += 1;
			SizeSequence(curr->right, count);
		}
		return;
	}
public:
	AdelsonVelskiiAndLandisTree(T _value = NULL) {
		this->left = nullptr; // root
		this->right = nullptr;
		this->value = _value;
	};
	AdelsonVelskiiAndLandisTree<T>* Insert(T _value) {
		this->left = InsertSequence(this->left, _value);
		return this;
	}
	AdelsonVelskiiAndLandisTree<T>* Remove(T _value) {
		this->left = RemoveSequence(this->left, _value);
		return this;
	}
	AdelsonVelskiiAndLandisTree<T>* Find(T _value) {
		return FindSequence(this->left, _value);
	}
	void Display() {
		cout << "[DISPLAY] :";
		DisplaySequence(this->left, 0, 0);
		cout << endl << endl;
		return;
	}
	void InOrder() {
		cout << "[INORDER] : ";
		InOrderSequence(this->left);
		cout << endl;
		return;
	}
	int Size() {
		int* count = new int(0);
		SizeSequence(this->left, count);
		return *count;
	}
	void Clear() {
		ClearSequence(this->left);
		this->left = nullptr;
	}
	T Value() {
		if (this == nullptr) return NULL;
		return this->value;
	}
};

int main() {
	int findNum = 28;
	AdelsonVelskiiAndLandisTree<int>* AVL = new AdelsonVelskiiAndLandisTree<int>();
	Timer* timer = new Timer(1);
	timer->Start(0);
	cout << endl;

	cout << "[INSERT]  : 10, 20, 30, '20', 40, 50, 25, 27, 60, 28" << endl;
	AVL->Insert(10)->Insert(20)->Insert(30)->Insert(20)->Insert(40)->Insert(50)->Insert(25)->Insert(27)->Insert(60)->Insert(28);
	AVL->Display();
	AVL->InOrder();
	cout << "[SIZE]    : " << AVL->Size() << endl;
	if (AVL->Find(findNum) != nullptr) cout << "[FIND]    : Complete. There is " << findNum << endl; else cout << "[FIND]    : Failed. There isn't " << findNum << endl;
	cout << endl;

	cout << "[REMOVE]  : 30, 28, '100'" << endl;
	AVL->Remove(20)->Remove(30)->Remove(28)->Remove(100);
	AVL->Display();
	AVL->InOrder();
	cout << "[SIZE]    : " << AVL->Size() << endl;
	AVL->InOrder();
	if (AVL->Find(findNum) != nullptr) cout << "[FIND]    : Complete. There is " << findNum << endl; else cout << "[FIND]    : Failed. There isn't " << findNum << endl;

	AVL->Clear();

	cout << endl;
	timer->End(0);
	timer->Display(0);
	delete timer;
}
//*/