# DB

## 용어 정리

-   릴레이션 스키마: 테이블 헤더 행,  릴레이션 스킴 또는 릴레이션 내포(Relation Intension)라고도 한다.
-   어트리뷰트: 속성, 테이블 헤더, 그 수는 디그리(Degree)라고 표현
-   릴레이션 인스턴스: 전체 튜플들의 집합. 릴레이션 또는 릴레이션 외연(Relation Extension)라고도 한다.
-   튜플: 각 데이터 행, 그 수는 카디널리티라고 표현
-   도메인: 각 칸의 속성의 가짓수

## 요청 방식

크게 세 가지 방식을 사용합니다.

-   쿼리스트링
    -   예시

        `...?user=12&data=type`

-   REST
    -   Query Parameter 방식
    -   예시

        `.../user/12/email`

-   GraphQL

### 쿼리 스트링

### REST

### GraphQL

#### 형식

url 을 `/graphql` 로 고정하고 POST 요청의 Body에 Graphql 전용 쿼리 문법을 문자열로 전달합니다.

```txt
POST /graphql
Content-Type: application/json

{
"query": "query { user(id: 12) { name email } }"
}
```

#### 단점

N+1 문제: GraphQL의 독립적 리졸버 구조 때문에, 부모 데이터 1건을 가져온 뒤 연관된 자식 데이터 N건을 얻기 위해 DB 쿼리가 N번 추가 실행되는 현상.

이 문제를 막기 위해서 복잡하게 DataLoader 를 정의하고 resolver 로 한 번에 N 개 데이터 묶음을 가져온 뒤에 풀어서 사용해야 합니다.
