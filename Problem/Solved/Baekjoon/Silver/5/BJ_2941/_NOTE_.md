# BJ 2941：크로아티아 알파벳：오답노트

## 오답

## <LANGUAGE_TYPE_1>：xxxx-xx-xx：<ANNOTATION_COMMENT>

## 정답

## Java：2023-12-20

```java
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main {
  public static void main(String[] args) throws IOException, NumberFormatException {
    System.setIn(new FileInputStream("input.txt"));
    BufferedReader br;
    int answer;
    String line;

    br = new BufferedReader(new InputStreamReader(System.in));
    {
      line = br.readLine();
    }
    br.close();

    answer = line.length();
    for(int i = 1; i < line.length(); i++) {
      switch(line.charAt(i)) {
        case '=':
          if(line.charAt(i - 1) == 'z'){
            answer--;
            if(i > 1 && line.charAt(i - 2) == 'd') {
              answer--;
            }
          }
          else if(line.charAt(i - 1) == 'c') {
            answer--;
          }
          else if(line.charAt(i - 1) == 's') {
            answer--;
          }
          break;

        case '-':
          if(line.charAt(i - 1) == 'c') {
            answer--;
          }
          else if(line.charAt(i - 1) == 'd') {
            answer--;
          }
          break;

        case 'j':
          if(line.charAt(i - 1) == 'l') {
            answer--;
          }
          else if(line.charAt(i - 1) == 'n') {
            answer--;
          }
          break;
      }
    }

    System.out.println(answer);
    return;
  }
}
```

## C++：2023-12-20

```cpp
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("Problem\\Solved\\Baekjoon\\Silver\\5\\BJ_2941\\question\\input.txt", "rt", stdin);

  char input[103];
  int index = 0;
  int answer = 0;

  cin.getline(input, 103);

  while (input[index] != '\0') {
    switch (input[index]) {
      case 'c':
        if(input[index + 1] == '=' || input[index + 1] == '-') index++;
        break;
      case 'd':
        if(input[index + 1] == 'z' && input[index + 2] == '=') index += 2;
        else if(input[index + 1] == '-') index++;
        break;
      case 'l':
        if(input[index + 1] == 'j') index++;
        break;
      case 'n':
        if(input[index + 1] == 'j') index++;
        break;
      case 's':
        if(input[index + 1] == '=') index++;
        break;
      case 'z':
        if(input[index + 1] == '=') index++;
        break;
    }
    index++;
    answer++;
  }

  cout << answer;

  return 0;
}
```

## C++：2024-11-22

- 특수 기호 j, -, = 를 기준으로 파악하기

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int answer;
  int N;
  string input;

  freopen("Problem\\Solved\\Baekjoon\\Silver\\5\\BJ_2941\\_INPUT_.txt", "rt", stdin);

  cin >> input;
  answer = N = input.size();

  for (int n = 1; n < N; n++) {
    switch (input[n]) {
     case 'j':
      if (input[n - 1] == 'l' || input[n - 1] == 'n') answer--;
      break;
     case '-':
      if (input[n - 1] == 'c' || input[n - 1] == 'd') answer--;
      break;
     case '=':
      if (input[n - 1] == 'c' || input[n - 1] == 's' || input[n - 1] == 'z') answer--;
      if (n > 1 && input[n - 2] == 'd' && input[n - 1] == 'z') answer--;
      break;
    }
  }

  cout << answer;
  return 0;
}
```
