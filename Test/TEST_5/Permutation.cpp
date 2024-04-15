#include <array>
#include <cstdarg>
#include <deque>
#include <iostream>
#include <regex>
#include <algorithm>

using namespace std;

// # Prototype Declaration ====================
// ## 0. Default ===============================
template <typename T, size_t N>
void printArr(T (&arr)[N], int begin = 0, ...);
void printArrRecur(int* arr, deque<int> arrData);


// # Implements Definition ====================
// ## 0. Default ===============================

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int N = 5;
  const int R = 3;

  int origin[N][3] = {{1, 11, 111}, {2, 22, 222}, {3, 33, 333}, {4, 44, 444}, {5, 55, 555}};

  // ## 5. Iterative =============================
  {
    // https://www.google.co.kr/search?q=%EC%88%9C%EC%97%B4+swap+reverse+%EC%98%A4%EB%A6%84%EC%B0%A8%EC%88%9C&sca_esv=954f74c53a241618&sca_upv=1&hl=ko&sxsrf=ACQVn0-L2vr_gqJ4iiFrsXhFa4B33rAmGQ%3A1712642043933&ei=-9cUZv7SOP-Nvr0Py4etsAk&ved=0ahUKEwi-vJ_luLSFAxX_hq8BHctDC5YQ4dUDCBA&uact=5&oq=%EC%88%9C%EC%97%B4+swap+reverse+%EC%98%A4%EB%A6%84%EC%B0%A8%EC%88%9C&gs_lp=Egxnd3Mtd2l6LXNlcnAiIOyInOyXtCBzd2FwIHJldmVyc2Ug7Jik66aE7LCo7IicMggQABiJBRiiBDIIEAAYgAQYogQyCBAAGIAEGKIESJShiwFQoo6LAVi9oIsBcAR4AZABAJgBpAKgAbAJqgEFMC43LjG4AQPIAQD4AQGYAgigApcEwgIKEAAYRxjWBBiwA8ICBxAjGLACGCeYAwCIBgGQBgqSBwM0LjSgB9UU&sclient=gws-wiz-serp
    // https://velog.io/@ddongh1122/%EC%88%9C%EC%97%B4-Permutation-%EA%B5%AC%ED%98%84
    // https://zzingonglog.tistory.com/18
    // https://mjmjmj98.tistory.com/38
    // cout << "\n[CASES]:\n";
    // int count = perm5(origin, N, R);
    // cout << "[ANSWER]: " << count << '\n';
    next_permutation(origin, origin + 5);
  }


  return 0;
}

// ## 0. Default ===============================
template <typename T, size_t N>
void printArr(T (&arr)[N], int begin, ...) {
  deque<int> arrData;
  string arrType = typeid(arr).name();

  regex regExp("A[0-9]+_", regex::optimize);
  sregex_token_iterator iter(arrType.begin(), arrType.end(), regExp), end;

  va_list ap;
  va_start(ap, begin);
  int buffer = begin;

  while (iter != end) {
    string token = (string)*iter++;
    if (buffer) {
      arrData.push_back(buffer);
      buffer = va_arg(ap, int);
    }
    else {
      arrData.push_back(stoi(token.substr(1, token.size() - 2)));
    }
  }

  va_end(ap);

  printArrRecur((int*)arr, arrData);
  cout << "\b\b  " << endl;
}

void printArrRecur(int* arr, deque<int> arrData) {
  if (arrData.size() == 0) cout << "\033[0m" << *arr << ", ";
  else {
    int N = arrData.front();
    arrData.pop_front();
    int gap = 1;
    int color = 31 + (arrData.size() % 6);
    for (int i : arrData) gap *= i;
    cout << "\033[" << color << "m[";

    for (int n = 0; n < N; n++) {
      printArrRecur(arr, arrData);
      arr += gap;
    }
    cout << "\033[" << color << "m\b\b]\033[0m, ";
  }
}

// ## 5. Iterative =============================