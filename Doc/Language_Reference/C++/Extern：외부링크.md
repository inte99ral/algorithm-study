# Extern：외부링크

## Extern > 개념 설명

&nbsp; C++의 extern 키워드는 외부로 정의된 변수나 함수에 접근하기 위해 사용하는 선언 방식입니다. 이를 JavaScript의 import와 export에 비유하면, extern은 받는 쪽에서 선언하는 방식으로 **JavaScript의 import**와 유사합니다.

&nbsp; C++에서 extern 키워드는 **외부 링크(external linkage)**를 지정하여 변수가나 함수가 다른 소스 파일에 정의되어 있음을 나타내는 데 사용됩니다. 이를 통해 여러 소스 파일 간에 전역 변수나 함수를 공유할 수 있습니다.

&nbsp; extern 키워드를 통하여 지금 정의된 변수 및 함수는 현재 파일이 아닌 다른 파일에 정의되어 있다는 것을 컴파일러에게 전할 수 있습니다.

```cpp
// # source.cpp
int number = 100; // 변수 정의
```

```cpp
// # main.cpp
#include <iostream>
extern int number; // 외부 변수 선언

int main() {
    std::cout << number << std::endl; // 출력: 100
    return 0;
}
```

&nbsp; extern 선언은 헤더 파일에 작성하고, 실제 정의는 소스 파일에 두는 것이 일반적입니다.

## Extern "C"

&nbsp; C++의 extern "C" 키워드는 보내는 쪽에서 **JavaScript의 export**와 같은 역할을 합니다. C++에서 작성된 함수나 변수를 C 코드가 사용할 수 있도록 외부로 노출시키기 위해 사용됩니다. 이를 통해 C++의 이름 맹글링(name mangling)을 방지하고 C 스타일의 함수 호출 규칙을 적용합니다.

&nbsp; 자세히 설명하자면 키워드 내부 C++ 코드가 C 와의 호환성을 유지할 것을 강제하는 키워드입니다. `extern "C" { int main() {...} }` 구조로 작성되며 C 언어 규칙을 따라서 컴파일하게 됩니다. 이런 코드는 C 라이브러리 또는 C 프로그램과 통합할 때 유용하게 사용됩니다. 코드를 강제로 단순하게 작성해야 되며, 함수 이름이 명확하고 고유해지므로 다른 언어에서도 호출 시 문제를 유발할 일이 적습니다.

&nbsp; 다만 extern "C"로 선언된 함수는 C 스타일로 컴파일되므로, C++의 오버로딩(overloading)이나 템플릿 같은 고급 기능을 사용할 수 없습니다. 순수한 C++ 프로그램에서는 필요하지 않은 제약이 걸립니다.
