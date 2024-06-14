# 서로소：Union-Find Algorithm

## 개념정리

- 서로소 집합(Disjoint Sets)이란 공통 원소가 없는 두 집합을 의미합니다.
- 서로소 집합임을 검증하는 알고리즘(Union-Find Algorithm) 은 각 집합의 중심점을 잡고 이를 기준으로 두 집합이 최종적으로 같은 중심점을 공유하는가 파악합니다. 이 과정에서 각 집합의 중추를 찾는 탐색 과정(Find)과, 중심점을 공유하는 두 집합을 해당 중심점 기준으로 정리하는 합집합 과정(Union)을 필요로 합니다.
- 중심점을 잡기 위하여

  1. 노드의 고유한 번호를 키 값으로 하는 데이터 테이블을 만듭니다.
  2. 노드 간의 간선 연결 관계를 부모-자식 관계로 취급합니다.
  3. 자식 노드를 키 값으로 가지는 데이터 객체에 부모 노드의 고유 번호를 넣어 부모를 가르키도록 합니다.
  4. 부모 노드는 자기 자신을 부모 노드로 취급하여 자기 자신의 고유한 값을 가르킵니다. (따라서 간선이 아예 없다면 모두 자기 자신을 가르키고 있습니다.)
  5. 자식 노드에 연결되는 자식의 자식 노드들 또한 모두 부모 노드의 고유한 값을 가리키도록 합니다.
  6. `Find` - 자식 노드의 값을 노드가 자기 자신을 가르킬 때까지 재귀적으로 따라가면 언젠가 가장 높은 부모 노드에 닿기 때문에 중심점을 찾을 수 있게 됩니다.
  7. `Union` - 연결되는 두 노드의 가장 높은 부모 노드, 즉 루트 노드, 이 중심점이 다르다면 둘 중 하나의 부모 노드가 다른 하나의 부모 노드의 자식으로 들어가게 합니다. 이렇게 하면 다시 하나의 중심점 밑에 모든 자식들이 속하게 됩니다.
  8. 최종적으로 부모를 공유하는 노드끼리 집합이며, 공유하지 않는 집합은 서로소 집합임을 알 수 있습니다.
  9. `Path Compression` - Find 함수는 경로 압축(Path Compression) 기법을 적용해 시간 복잡도를 개선할 수 있습니다. 경로 압축 기법은 재귀적으로 호출하면서 값을 리턴하면서 동시에 갱신하는 기법입니다. <br/><center>`f(x) { return x = f(x); }`</center>위 기법을 이용하면 Find 함수를 호출되면서 지나간 모든 노드의 부모 노드를 즉시 중심점인 루트 노드로 바로 향하게 만들 수 있습니다. 경로 압축을 사용하지 않을 경우, 부모-자식 관계를 하나씩 거슬러 올라가면서 최악의 경우 전체 노드의 수 V 만큼 전부 읽어야하며 이 경우 Find 함수의 시간 복잡도는 O(V) 입니다. 경로 압축을 사용하면 모든 노드가 곧바로 최상단 루트 노드를 가르키므로 O(1) 으로 크게 개선됩니다.
  10. 노드의 개수 V, 간선 수 E 에 대하여 시간 복잡도는 O(V + E(1 + log(2-E/V)V)) 입니다. 근사치로 V + Elog2V 값을 계산하여 연산 횟수를 대강 파악할 수 있습니다.

<br/>

## 구현방법

<br/>

<center>
<img src="..\asset\Graph\Union-Find\0.svg" title="From I" style="width:20vw; aspect-ratio: 1 / 1"/>

<br/>

다음의 그래프 조건에선 {1, 2, 4} {3, 5, 7} {6, 8, 9} 가 서로소 집합이다.

</center>

#### ● C++

```cpp
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

// # Prototype Declaration ====================
void makeSet(int x);
int findSet(int x);
void unionSet(int x, int y);

// # Global Variable & Constant================
const string input =
  "9 8\n"
  "1 2\n"
  "1 4\n"
  "2 4\n"
  "3 5\n"
  "5 7\n"
  "6 8\n"
  "6 9\n"
  "8 9\n";

int *nodes;

// # Implements Definition ====================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int V;
  int E;

  // * INPUT
  {
    stringbuf inputbuf(input);
    streambuf *backup = cin.rdbuf(&inputbuf);

    cin >> V >> E;

    nodes = new int[V + 1]();

    for (int v = 1; v <= V; v++) {
      makeSet(v);
    }

    for (int e = 0; e < E; e++) {
      int x, y;
      cin >> x >> y;

      unionSet(x, y);
    }

    cin.clear();
    cin.rdbuf(backup);
  }

  // * OUTPUT_1
  {
    cout << "[NODE NUM] : ";
    for (int v = 1; v <= V; v++) {
      cout << v << ", ";
    }
    cout << "\b\b \n";

    cout << "[ROOT NUM] : ";
    for (int v = 1; v <= V; v++) {
      cout << nodes[v] << ", ";
    }
    cout << "\b\b \n\n";
  }

  // * OUTPUT_2
  {
    map<int, vector<int>> sets;

    for (int v = 1; v <= V; v++) {
      sets[nodes[v]].push_back(v);
    }

    for (pair<int, vector<int>> set : sets) {
      cout << "[ROOT NUM " << set.first << "] : {";
      for (int i : set.second) {
        cout << i << ", ";
      }
      cout << "\b\b}\n";
    }
    cout << "\b\b \n";

  }

  delete[] nodes;
  return 0;
}

void makeSet(int x) {
  nodes[x] = x;
}

int findSet(int x) {
  if (nodes[x] == x) return x;
  return nodes[x] = findSet(nodes[x]); // Path Compression
}

void unionSet(int x, int y) {
  nodes[findSet(y)] = findSet(x);
}
```

<br/>

#### ● Java

```java
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
  // # Global Variable & Constant================
  private static String input =
    "9 8\n" +
    "1 2\n" +
    "1 4\n" +
    "2 4\n" +
    "3 5\n" +
    "5 7\n" +
    "6 8\n" +
    "6 9\n" +
    "8 9\n";

  private static int[] nodes;

  // # Implements Definition ====================
  public static void main(String[] args) throws Exception {
    Main mainInstance = new Main();
    int V;
    int E;

    // * INPUT
    {
      Scanner sc = new Scanner(input);

      V = sc.nextInt();
      E = sc.nextInt();

      nodes = new int[V + 1];

      for (int v = 1; v <= V; v++) {
        mainInstance.makeSet(v);
      }

      for (int e = 0; e < E; e++) {
        mainInstance.unionSet(sc.nextInt(), sc.nextInt());
      }

      sc.close();
    }

    // * OUTPUT_1
    {
      System.out.print("| NODE NUM |");
      for (int v = 1; v <= V; v++) {
        System.out.printf("%3d |", v);
      }
      System.out.print("\n|----------");
      for (int v = 1; v <= V; v++) {
        System.out.print("+----");
      }
      System.out.print("|\n| ROOT NUM |");
      for (int v = 1; v <= V; v++) {
        System.out.printf("%3d |", nodes[v]);
      }
    }

    System.out.println('\n');

    // * OUTPUT_2
    {
      HashMap<Integer,ArrayList<Integer>> sets = new HashMap<>();

      for (int v = 1; v <= V; v++) {
        if(!sets.containsKey(nodes[v])) sets.put(nodes[v], new ArrayList<>());
        sets.get(nodes[v]).add(v);
      }

      for (int i : sets.keySet()) {
        System.out.printf("[ROOT NUM %d] : {", i);
        for(int j : sets.get(i)) {
          System.out.printf("%d, ", j);
        }
        System.out.print("\b\b}\n");
      }
    }
  }

  void makeSet(int x) {
    nodes[x] = x;
  }

  int findSet(int x) {
    if(x == nodes[x]) return x;
    return nodes[x] = findSet(nodes[x]); // Path Compression
  }

  void unionSet(int x, int y) {
    nodes[findSet(y)] = findSet(x);
  }
}
```
