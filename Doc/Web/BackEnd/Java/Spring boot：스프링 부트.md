# Spring boot：스프링 부트

- 스프링부트는 Java 기반으로 웹

vscode 의 spring tool 를 설치해서 사용하거나, eclipse IDE 에서 spring tool 을 결합한 spring tool suite (STS) 를 쓰는 방법도 있습니다.

## Java 설치

스프링부트는 Java 언어 기반이기 때문에 컴퓨터 OS 에서 Java 를 이해하고 처리할 수 있어야합니다.

- Julu 8.0.1

## 스프링 부트 확장 설치

VSCode 의 Extension 탭 (ctrl + shift + x)에서 다음의 확장을 검색하고 설치합니다.

- Spring Boot Extension Pack
- Java Extension Pack

## 프로젝트 생성

1. `ctrl + shift + P` 단축키로 명령 팔레트를 열어주세요.
2. 팔레트에서 Spring Initializr: Create a Maven Project 를 선택합니다.

---

## 추가내용

- 톰캣 스레드 풀 설정
  - server.tomcat.threads.max를 조정하여 동시 요청 처리 능력을 최적화합니다
  - 게임 서버의 경우 동시 접속자 수에 맞춰 적절히 설정하는 것이 중요합니다
- WebSocket을 사용한 실시간 양방향 통신
- RESTful API를 통한 게임 생성 및 연결
- STOMP 프로토콜을 활용한 메시지 라우팅
- SockJS를 이용한 폴백 메커니즘 구현
