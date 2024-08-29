# 명령어：Command

<style>
 .example { width: 90vw; & > tbody > tr > td { border: solid 1px lightgray; }; }
 .center { text-align: center; & * { text-align: center; }; }
</style>

## Linux Command

### 목록

<center>
<table class="example">
<tr class="center">
  <th>동작</th>
  <th>명령어</th>
</tr>
<tr>
  <td>셸 특수문자</td>
  <td>

```bash
# ~：사용자의 홈 디렉터리.
cd ~ #홈 디렉터리로 이동
cd ~<username> #해당 사용자의 홈 디렉터리로 이동

# -：이전 작업 디렉터리.
cd - #이전 작업 디렉터리로 이동

# ;：연결된 명령을 왼쪽부터 차례로 실행.
date; ls; pwd # date->ls->pwd 순으로 명령 실행.

# |：왼쪽 명령의 실행 결과를 오른쪽 명령의 입력으로 전달.
ls -al / | more #ls -al /의 실행 결과를 more 입력으로 전달.

# *：임의의 문자열을 나타내는 특수문자.
ls -F t* #temp, tmp... 파일명이 t로 시작하는 파일 리스트 출력

# ?：임의의 한 문자를 나타내는 특수문자.
ls t?.txt #t1.txt, t2.txt...

# []：정해진 조건의 한 문자를 나타내는 특수문자.
ls -l t[135].txt #t1.txt, t3.txt...

# ''：문자를 감싸서 문자열로 만들고, 모든 특수문자의 기능을 없앰.
echo '$SHELL' #$SHELL 문자열이 화면에 출력.

# ""：문자를 감싸서 문자열로 만들고, $, `, \를 제외한 특수문자의 기능을 없앰.
echo "$SEHLL" #$이 명령으로 실행됨

# ``：감싸인 문자열 부분을 명령으로 해석
echo "Today is `date`" #`date` 가 명령으로 해석됨. Today is 2021. 01. 22 (금) 16:49:12 KST
```

  </td>
</tr>
<tr>
  <td>계정 및<br />권한</td>
  <td>

```bash
# 루트 계정 비밀번호 설정
sudo passwd root

# 현재 계정 확인
whoami

# switch user 계정 변경(권한 변경)
su {계정명} #현재 계정의 환경변수를 유지하고 전환
su - {계정명} #환경변수까지 root 계정으로 전환

# 전환 취소 원 계정으로 복귀
exit

# 명령어 줄 가장 앞에 표기되는 지표입니다.
"$" #유저 계정(사용자 권한)에서 명령을 받습니다.
"#" #루트 계정(관리자 권한)에서 명령을 받습니다.
"%" #C 쉘 명령프롬프트
```

  </td>
</tr>
<tr>
  <td>압축</td>
  <td>

```bash
#zip 파일 압축
$ sudo apt-get install zip #zip 패키지를 필요로 합니다.
$ zip {압축 파일명}.zip ./* #모든 파일(./*)을 {압축파일명}.zip 으로 압축합니다.

#zip 파일 압축 풀기
$ sudo apt-get install unzip #unzip 패키지를 필요로 합니다.

$ unzip {압축 파일명}.zip #zip 압축 풀기
$ unzip {압축 파일명}.zip -d /home/{디렉토리} #특정 디렉토리에 압축풀기
```

  </td>
  </tr>
  <tr>
    <td>패키지 다운로드</td>
    <td>

```bash
# apt : Advanced Packaging Tool
# ★ : 관리자 권한 필요
# apt-get 은 더 low 한 단계의 명령입니다.

apt update #★패키지를 다운로드 할 수 있는 저장소를 업데이트한다.

apt list --upgradable #업그레이드가 가능한 패키지 목록을 출력한다.

apt upgrade #★전체 패키지를 업그레이드한다.

apt install 패키지 이름 #★특정 패키지를 설치한다
apt install --only-upgrade 패키지 이름 #★특정 패키지만 업그레이드한다.

apt list *패키지이름* #이름이 포함된 패키지 모두 검색
apt list --installed #설치된 패키지 목록을 출력한다.
apt search 검색어 #패키지를 검색한다.
apt show 패키지 이름 #특정 패키지에 대한 정보를 확인한다.

apt remove 패키지 이름 #★특정 패키지를 삭제합니다.
apt purge 패키지 이름 #★특정 패키지와 관계된 모든 의존성을 숙청합니다.

# PPA는 Third Party Software에 대한 패키지를 위해서 런치패드에서 제공하는 개인용 소프트웨어 패키지 저장소를 말합니다.
add-apt-repository ppa:{개인용 패키지 저장소 (예시 : createsc/3beol)}
```

  </td>
  </tr>
</table>
</center>

### 목록

<center>
<table class="example">
  <tr class="center">
    <th>명령어</th><th>유래</th><th>동작</th><th>예시</th>
  </tr>
  <tr>
    <td>$</td>
    <td>-</td>
    <td>명령 처리 준비 상황 표기
    </td>
    <td>

```bash
$ #means you are a normal user.
# #means you are the system administrator
% #In the C shell, the prompt ends with percentage sign
```

  </td>
  </tr>
  <tr>
    <td>sudo</td>
    <td>Super User DO<br />or<br />Substitute User DO</td>
    <td>관리자 권한으로 실행</td>
    <td>

```bash
sudo "명령어"
```

  </td>
  </tr>
  <tr>
    <td>cd</td>
    <td>Change Directory</td>
    <td>디렉토리 이동</td>
    <td>

```bash
#현재 위치한 디렉토리를 표시합니다.
pwd

#해당 디렉토리로 이동.
cd "디렉토리명"

#최상위 디렉토리로 이동.
cd /

#한 단계 상위 디렉토리로 이동.
cd ..

#현 사용자 홈 디렉토리로 이동.
cd ~

#계정명의 홈 디렉토리로 이동.
cd ~ "계정명"

#바로 이전 경로의 디렉토리로 이동.
cd -
```

  </td>
  </tr>
  <tr>
    <td>vi</td>
    <td>VI text editor</td>
    <td>파일 텍스트 수정</td>
    <td>

```bash
i #커서 앞부터 입력
a #커서 뒤부터 입력
왼쪽으로 이동 - h
아래로 이동 - j
위로 이동 - k
오른쪽으로 이동 - l
한 글자 삭제 - x
한 단어 삭제 - dw
한 줄 삭제 - ddn
번째 줄 삭제 - ndd
현재 커서 위치부터 끝까지 : D
검색 - /(내용)
현재줄 복사하기 - yyn
번째 줄 복사하기 - nyy
붙여넣기 - p
undo(실행취소) - u
변경 사항을 저장하지 않고 종료 - :q!
저장 - :w
저장 후 종료 - :wq
저장 후 종료 - :ZZ
```

  </td>
  </tr>
</table>
</center>

- apt : [참고 링크](https://uyt8989.tistory.com/75)
- ls : 현재 디렉토리에 있는 파일 및 폴더를 출력

- cp <파일1> <파일2>: 파일1과 동일한 파일2를 만든다.

- mkdir <디렉토리이름>: <디렉토리이름>의 폴더를 만든다.

- rmdir <디렉토리이름>: <디렉토리이름>의 폴더를 삭제한다.

- pwd: 현재 경로 출력

- touch <파일명>: <파일명> 파일 생성

### vi

## Shell Script

### 목록

- 출력

### 출력

[참고링크](https://directori.tistory.com/133)

- 기본 출력
  - echo
  - print

```bash
echo "Echo Test" # 자동 개행
printf "printf Test" # 자동 개행X
printf "%s %s" print test # 뒤에 오는 문자열들이 전달되는 인자라고 생각하면 됩니다.
```

<br/>

- $ - arguments 전달인자 값으로 전환
  - $# : 스크립트에 전달되는 인자들의 수(C언어에서 args)
  - $0 : 실행하는 스크립트의 파일명으로 실행했을 때 경로를 포함한다면 경로를 포함해서 나옵니다.
  - $1, $2 … : 스크립트로 전달된 인자들(C언어에서 argv[0], argv[1]…)

```bash
#!/bin/bash

echo "Echo Test"
printf "printf Test\n"
printf "Name of script : %s\n" $0
printf "%d arguments %s %s\n" $# $1 $2
```

<br/>

- ${parameter} - parameter substitution 매개변수 값으로 전환

```bash
#!/bin/bash

test="abc"
num=100

echo "${test}"
echo "${num}"
```

<br/>

- $(command) - command substitution 명령어 값으로 전환

```bash
echo "Echo Test" # 자동 개행
printf "printf Test" # 자동 개행X
printf "%s %s" print test # 뒤에 오는 문자열들이 전달되는 인자라고 생각하면 됩니다.
```

<br/>

## [터미널에 컬러로 출력해보자](https://bigbigpark.github.io/cpp_useful/color-print/)

|         | foreground | background |
| ------- | ---------- | ---------- |
| black   | 30         | 40         |
| red     | 31         | 41         |
| green   | 32         | 42         |
| yellow  | 33         | 43         |
| blue    | 34         | 44         |
| magenta | 35         | 45         |
| cyan    | 36         | 46         |
| white   | 37         | 47         |
| Default | 38         | 39         |
| Off     | 0          | 0          |

```cpp
// \033[#;#;#m 형태로 적용 \033[0m 으로 해제
#include <iostream>

int main(int argc, char** argv)
{
  std::cout << "\033[1;30m" << "black " << "\033[0m" << std::endl;
  std::cout << "\033[1;31m" << "red " << "\033[0m" << std::endl;
  std::cout << "\033[1;32m" << "green " << "\033[0m" << std::endl;
  std::cout << "\033[1;33m" << "yellow " << "\033[0m" << std::endl;
  std::cout << "\033[1;34m" << "blue " << "\033[0m" << std::endl;
  std::cout << "\033[1;35m" << "magenta " << "\033[0m" << std::endl;
  std::cout << "\033[1;36m" << "cyan " << "\033[0m" << std::endl;
  std::cout << "\033[1;37m" << "white " << "\033[0m" << std::endl;

  return 0;
}
```

# MSYS2

[참고링크](https://wikidocs.net/219732)
