아래와 같이 vector 매개변수로 두어 함수를 호출한 경우 함수 안에서 값을 바꾸더라도 해당 함수가 반환된 이후인 main 함수에서는 영향이 없습니다.

```cpp
#include<bits/stdc++.h>
using namespace std;

void func(vector<int> vect) {
  vect.push_back(30);
}

int main() {
  vector<int> v;
  v.push_back(10);
  v.push_back(20);

  func(v);

  for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';

  return 0;
}
```

<br />
때문에, 호출한 함수안에서 vector 값을 변경하고 싶은 경우에는 vector를 값에 의한 호출(call by value)이 아닌, 아래와 같이 참조에 의한 호출(call by reference)을 이용하여야합니다.
<br />

```cpp
#include<bits/stdc++.h>
using namespace std;

void func(vector<int> &vect) {
  vect.push_back(30);
}

int main() {
  vector<int> v;
  v.push_back(10);
  v.push_back(20);

  func(v);

  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";

  return 0;
}
```
