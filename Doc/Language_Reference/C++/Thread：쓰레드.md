# Thread：쓰레드

## 개념 설명

&nbsp; 프로그램을 실행하면 함수를 호출하고 결과를 처리하고 종료를 하게 됩니다. 이것을 프로세스라고 부릅니다.

```cpp
#include <iostream>

using namespace std;

void func1(string tag, int count) {
  for (int i = 0; i < count; i++) cout << tag << " : " << i << endl;
}

int main() {
  func1("task 1", 5);
  func1("task 2", 5);
  return 0;
}
```

&nbsp; 이렇게 코드를 짜면 func1 함수를 호출하고 순서대로 한 칸 씩 줄을 바꾸며 0~4 의 숫자가 나오고 func1 이 끝나면, 그 다음에 func1 을 다시 호출하여 다시 0~4의 숫자가 나올 것 입니다.

&nbsp; 하지만 두 함수를 병렬로 같이 동시에 작동시키려면 어떻게 해야할까요? 이때 사용되는 것이 복수 개의 프로세스를 작업할 수 있도록 만드는 멀티 쓰레드 입니다.

```cpp
#include <iostream>
#include <thread>

using namespace std;

void func2(string tag, int count) {
  for (int i = 0; i < count; i++) cout << tag << " : " << i << endl;
}

int main() {
  thread t1(func2, "task1", 5);
  thread t2(func2, "task2", 5);

  cout << "Main thread: Waiting for threads to finish" << endl;

  t1.join();
  t2.join();

  cout << "Main thread: All threads have finished" << endl;

  return 0;
}
```

&nbsp; 이렇게 각 프로세스를 진행할 쓰레드를 만들어 준 뒤에, join() 으로 시작시키면 복수 개의 쓰레드가 동시에 작동하기 때문에 처리되는 즉시 cin 스트림으로 출력을 하므로 엉망진창으로 task1task2:0task1:4 처럼 마구 섞여서 나오게 됩니다.

&nbsp; 다음의 예시처럼 쓰레드 병렬처리 중 서로의 연산이 섞이지 않도록 각 쓰레드에서 프로세스를 정돈해주셔야 합니다.

```cpp
#include <iostream>
#include <thread>

using namespace std;

void func2(string tag, int count) {
  for (int i = 0; i < count; i++) cout << tag + " : " + to_string(i) + "\n"; // <--
}

int main() {
  thread t1(func2, "task1", 5);
  thread t2(func2, "task2", 5);

  cout << "Main thread: Waiting for threads to finish" << endl;

  t1.join();
  t2.join();

  cout << "Main thread: All threads have finished" << endl;

  return 0;
}
```
