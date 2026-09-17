# Server(Realtime)：실시간 통신 서버

## 개요

&nbsp; 실시간 통신하는 캐릭터 이동, 사격, 동기화, 물리 판정등을 계산하는 서버는 정보를 주고 받을 때,

-   `UDP` 전송계층(Transport Layer)프로토콜
-   `WebRTC` 기술 표준(Framework)

을 사용합니다.

&nbsp; 기술 표준인 WebRTC 방식은 P2P(Peer-to-Peer)로 영상, 음성, 데이터를 실시간 교환할 수 있도록 여러 프로토콜과 API가 결합되어 있습니다. 음성 및 영상의 암호화 스트리밍 응용계층 프로토콜인 `SRTP`, 데이터 채널 파일 전송 응용계층 프로토콜 `SCTP`, NAT/방화벽을 뚫고 P2P 연결을 맺기 위한 P2P 전송계층 프로토콜 `ICE` / `STUN` / `TURN` 등이 복합적으로 사용된 집약체입니다.

&nbsp; 복잡한 개념없이도 누구나 쉽게 실시간 데이터 송수신을 할 수 있도록 만들어진 프레임워크라고 볼 수 있습니다.

## WebSocket 과의 비교

&nbsp; 채팅이나 로비등 실시간으로 계속 데이터를 주고 받는 것이 아니라 변화에 대한 신호만 주고 받을 때는 WebSocket 기술을 사용하는 편입니다. 하지만 실시간 게임 렌더링이나 보이스 채팅 등 서버와 초당 수십번의 소통을 해야만 하는 경우엔 적용하기 힘듭니다. 이때 WebRTC 기술을 적용할 수 있습니다. 

&nbsp; WebSocket은 TCP 기반이고, WebRTC는 UDP 기반입니다. 두 기술은 웹 브라우저 환경에서 실시간 통신을 구현하기 위해 만들어졌지만, 사용하는 아래 레이어 프로토콜과 목적이 다릅니다.

-   <table>
    <tr class=r0>
    <th> 구분 </th>
    <th> WebSocket </th>
    <th> WebRTC </th>
    </tr>

    <tr class=r1>
    <td> 기반 프로토콜 </td>
    <td> TCP </td>
    <td> UDP (ICE, DTLS, SRTP/SCTP) </td>
    </tr>

    <tr class=r2>
    <td> 통신 방식 </td>
    <td> Client-Server (중앙 서버 필수) </td>
    <td> P2P (Peer-to-Peer) 또는 Client-Server </td>
    </tr>

    <tr class=r3>
    <td> 연결 속도/지연 </td>
    <td> 상대적으로 높음 (TCP 오버헤드) </td>
    <td> 초저지연 (Sub-second) </td>
    </tr>

    <tr class=r4>
    <td> 데이터 손실 </td>
    <td> 재전송으로 보장함 (Lossless) </td>
    <td> 일부 허용 (Unreliable / Partial-reliable) </td>
    </tr>

    <tr class=r5>
    <td> 주요 용도 </td>
    <td> 채팅, 알림, 로비 상태, 웹 소켓 통신 </td>
    <td> 음성/영상 통화(Zoom/Discord), 실시간 인게임 데이터 </td>
    </tr>
    </table>
