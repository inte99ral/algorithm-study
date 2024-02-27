/**
 * 값에 의한 호출(Call by value) 와 참조에 의한 호출(Call by reference)
 * 또는 깊은 복사(Deep Copy)와 얕은 복사(Shallow Copy)
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * 참조에 의한 호출, 또는 얕은 복사
 * 새로운 메모리 공간에 값을 완전히 복사하여 다룬다.
 * 원본 데이터에 엑세스 할 수 없기 때문에 변경에 안전하다.
 * 통체로 복사되는 만큼 생성될 때마다 연산 비용과 저장 메모리를 감안해야 함.
 */
void callByRefVec(vector<int>* v) {
  for (int i = 0; i < (*v).size(); i++) {
    cout << (*v)[i] << ' ';
    (*v)[i] = 0;
  }
  cout << endl;
}

/**
 * 값에 의한 호출, 또는 깊은 복사
 * 새로운 메모리 공간에 값을 완전히 복사하여 다룬다.
 * 원본 데이터에 엑세스 할 수 없기 때문에 변경에 안전하다.
 * 통체로 복사되는 만큼 생성될 때마다 연산 비용과 저장 메모리를 감안해야 함.
 */
void callByValVec(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
    v[i] = 0;  // 값을 바꾸어도 원본 v 는 바뀌지 않는다
  }
  cout << endl;
}

struct ArrayWrapper {
  int arr[3][3];
  ArrayWrapper(int a[3][3]) {
    // arr = a;  // 배열을 포인터로 나타낼 수 있는 이유는 C와 C++의 암시적인 변환(Decay) 정책에 의해 가능한 일이다. [참고링크](https://kangworld.tistory.com/50)
  }
};
void callByValArr(ArrayWrapper aw) {
  // cout << "SIZE : " << size(v) << " - TYPE : " << typeid(v).name();
  cout << " - TYPE : " << typeid(aw.arr).name();
  // for (int i = 0; i < v.size(); i++) {
  //   cout << v[i] << ' ';
  //   v[i] = 0;  // 값을 바꾸어도 원본 v 는 바뀌지 않는다
  // }
  cout << endl;
}

int main() {
  vector<int> v = {1, 2, 3};
  int arr[3][3] = {{11, 12, 13}, {24, 25, 26}, {37, 38, 39}};

  // callByValVec(v);
  // callByValVec(v);

  // callByRefVec(&v);
  // callByRefVec(&v);

  cout << "SIZE : " << sizeof(arr) / sizeof(arr[0]) << endl;
  cout << "TYPE : " << typeid(arr).name() << endl;

  callByValArr(arr);

  return 0;
}