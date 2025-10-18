# <img alt="b1" src="https://d2gd6pc034wcta.cloudfront.net/tier/5.svg" width="16" /> [BJ 11655](https://www.acmicpc.net/problem/11655)：ROT13

-   | 시간 제한 | 메모리 제한 |
    | :-------: | :---------: |
    |   1 초    |   256 MB    |

## 문제

&nbsp; ROT13은 카이사르 암호의 일종으로 영어 알파벳을 13글자씩 밀어서 만든다.

&nbsp; 예를 들어, "Baekjoon Online Judge"를 ROT13으로 암호화하면 "Onrxwbba Bayvar Whqtr"가 된다. ROT13으로 암호화한 내용을 원래 내용으로 바꾸려면 암호화한 문자열을 다시 ROT13하면 된다. 앞에서 암호화한 문자열 "Onrxwbba Bayvar Whqtr"에 다시 ROT13을 적용하면 "Baekjoon Online Judge"가 된다.

&nbsp; ROT13은 알파벳 대문자와 소문자에만 적용할 수 있다. 알파벳이 아닌 글자는 원래 글자 그대로 남아 있어야 한다. 예를 들어, "One is 1"을 ROT13으로 암호화하면 "Bar vf 1"이 된다.

&nbsp; 문자열이 주어졌을 때, "ROT13"으로 암호화한 다음 출력하는 프로그램을 작성하시오.

## 입력

&nbsp; 첫째 줄에 알파벳 대문자, 소문자, 공백, 숫자로만 이루어진 문자열 S가 주어진다. S의 길이는 100을 넘지 않는다.

## 출력

&nbsp; 첫째 줄에 S를 ROT13으로 암호화한 내용을 출력한다.

## 예제

-   <table>
    <tr>
    <th>예제 입력 1</th>
    <th>예제 출력 1</th>
    </tr>
    <tr>
    <td valign="top">

    ```txt
    Baekjoon Online Judge
    ```

    </td>
    <td valign="top">

    ```txt
    Onrxwbba Bayvar Whqtr
    ```

    </td>
    </tr>
    </table>

-   <table>
    <tr>
    <th>예제 입력 2</th>
    <th>예제 출력 2</th>
    </tr>
    <tr>
    <td valign="top">

    ```txt
    One is 1
    ```

    </td>
    <td valign="top">

    ```txt
    Bar vf 1
    ```

    </td>
    </tr>
    </table>

## 힌트

&nbsp; 힌트 예시

## 출처

-   문제를 만든 사람: baekjoon

## 알고리즘 분류

-   구현
-   문자열
