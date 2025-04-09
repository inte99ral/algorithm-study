# OOP：객체지향 (Object-Oriented Programming)

## 객체지향의 특징

추상화, 상속, 다형성, 캡슐화

### 1. Polymorphism：다형성

#### 오버로딩

##### 연산자 오버로딩

#### 오버라이딩

#### cpp 다형성 구현

- 포인터를 이용한 구현

&nbsp; 문자열스트림인 stringstream 과 파일스트림인 ifstream 은 모두 입력스트림 istream 의 자식 객체이기 때문에 (std::istream\*) 으로 할당할 수 있습니다.

&nbsp; 다음 밑의 예시는 INPUT_DATA 가 주소 값일 경우에는 파일을, 주소 값이 아니었을 경우 그 값을 그대로 문자열로 cin 출력스트림에 집어넣는 예시입니다.

```cpp
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const string INPUT_DATA =
  "1234\n"
  "asdf\n"
;

int main() {
  std::istream* IO_S = (std::filesystem::exists(INPUT_DATA))
    ? (std::istream*) new std::ifstream(INPUT_DATA)
    : (std::istream*) new std::stringstream(INPUT_DATA);
  std::streambuf* IO_BACKUP = std::cin.rdbuf(IO_S->rdbuf());

  for (std::string str; std::cin >> str;) {
    std::cout << str << "\n";
  }

  std::cin.rdbuf(IO_BACKUP);
  delete IO_S;
}
```

- 스마트 포인터를 이용한 구현

&nbsp; 객체지향의 다형성을 포인터를 직접 이용하여 구현하게 될 경우, 객체의 수명 관리와 메모리 관리를 직접해야하기 때문에 C 언어의 고질병이 발생합니다. 메모리가 누수되며, 코드 성능이 떨어지고 로직이 복잡해집니다.

&nbsp; c++ 의 스마트 포인터는 C++11(make 같은 부가적인 기능은 14) 이후 버전에서 memory 라이브러리를 참조하여 사용할 수 있습니다. 포인터 전용 컨테이너를 이용하여 안정적으로 객체지향을 구현하도록 돕습니다.

&nbsp; 기본적으로 다음의 구조로 구현이 가능합니다.

```cpp
// * make 컨테이너를 이용해서 구현하기
unique_ptr<『PARENT_CLASS』> parentClass = make_unique<『CHILD_CLASS』>();

// * 직접 생성자로 구현하기
unique_ptr<『CLASS』> parentClass(new 『CHILD_CLASS』());
```

&nbsp; **논리적으로 틀린 예시**이지만 좋은 설명의 예시이므로, 스마트 포인터를 이용하여 포인터 구현 때와 마찬가지로 출력스트림에 집어넣는 예시를 만들어보겠습니다. 할당된 메모리들을 관리할 필요가 없어졌으므로 포인터 변수값을 가지고 있지 않아도 됩니다.

```cpp
#include <memory>
#include <filesystem>

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const string INPUT_DATA =
  "1234\n"
  "asdf\n"
;

int main() {
  unique_ptr<streambuf> IO_BACKUP = unique_ptr<streambuf>(cin.rdbuf((filesystem::exists(INPUT_DATA))
    ? ((unique_ptr<istream>) make_unique<ifstream>(INPUT_DATA)) -> rdbuf()
    : ((unique_ptr<istream>) make_unique<stringstream>(INPUT_DATA)) -> rdbuf())
  );

  for (string str; cin >> str;) {
    cout << str << "\n";
  }

  // 원상복귀
  cin.rdbuf(IO_BACKUP.get());

  for (string str; cin >> str;) {
    cout << str << "\n";
  }

  return 0;
}
```

&nbsp; 위 경우 포인터로 직섭 연결할때와 똑같아 보이지만 실상은 그렇지 않습니다.

&nbsp; 문자열일때는 정상작동하는 것 **처럼** 보이겠지만 파일 경로를 의미할 때면 아예 동작조차 하지 않습니다. 그 이유는 스마트 포인터는 make_unique, make_shared 처럼 적용하고 난 뒤에 표현식이 끝나면 즉시 소멸되기 때문입니다.

&nbsp; 그나마 stringstream의 경우 소멸되고 나서도 내부 버퍼가 메모리에 있어 문제가 없지만, ifstream은 파일 핸들을 사용하기 때문에 객체가 소멸하면 파일이 닫힙니다.

&nbsp; 스마트 포인터는 **대부분의** 상황에서 더 나은 표현과 성능을 지니지만, 가끔 이렇게 할당된 메모리의 수명을 직접 관리해야 하는 경우가 있다는 것을 잊지 마세요.
