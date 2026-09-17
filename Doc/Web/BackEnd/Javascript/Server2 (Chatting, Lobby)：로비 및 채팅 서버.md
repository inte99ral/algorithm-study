# Server(Chatting, Lobby)：로비 및 채팅 서버

## sdsd

-   Server(Chatting, Lobby)：로비 및 채팅 서버
    -   TCP / WebSocket
    -   대기실, 친구 목록, 텍스트 채팅

## 개요

&nbsp; 대기실, 친구 목록, 텍스트 채팅, 알림과 공지 등, 단발성 신호가 아니라 장기적인 시그널을 보내는 서버를 구축할 때는

-   `TCP` 전송계층(Transport Layer)프로토콜
-   `WebSocket` 응용계층(Application Layer)프로토콜

을 사용합니다.

&nbsp; WebSocket(RFC 6455) 프로토콜은 OSI 7계층 중 7계층 (응용 계층) 에 속하는 프로토콜로 처음 연결을 맺을 때 Upgrade: websocket이라는 HTTP 헤더를 사용해 TCP 커넥션을 WebSocket 프로토콜로 전환(Handshake)합니다. 이후, HTTPS 프로토콜과 다르게 단발성으로 연결을 끊지 않고 유지하며 상호 통신이 가능합니다. 
