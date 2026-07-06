# AI：인공지능

## 목차

-   [AI：인공지능](#ai인공지능)
   	-   [목차](#목차)
   	-   [이미지](#이미지)
      		-   [온디바이스 AI](#온디바이스-ai)
      		-   [온디바이스 UI 툴](#온디바이스-ui-툴)
   	-   [브금](#브금)
   	-   [AI Gemini CLI : 인공지능 제미니 CLI](#ai-gemini-cli--인공지능-제미니-cli)
      		-   [설치방법](#설치방법)
      		-   [사용방법](#사용방법)

## 이미지

### 온디바이스 AI

-   FLUX 시리즈 (Black Forest Labs)
    -   과거 오리지널 Stable Diffusion을 만들었던 핵심 개발진들이 독립하여 설립한 'Black Forest Labs'에서 내놓은 모델입니다. 현재 미드저니(Midjourney) 같은 최고 유료 모델과 비벼볼 수 있는 사실상 유일한 오픈소스 모델로 평가받습니다.
    -   주요 버전은 개발자 및 개인 연구용으로 공개된 고성능 모델 <u><b>FLUX.2 / FLUX.1</b></u> 와 출력 속도에 올인한 경량 버전 <u><b>FLUX (schnell)</b></u> 이 있습니다.

-   Stable Diffusion 3.5 Large
    -   Stability AI의 정통 후속작입니다.

### 온디바이스 UI 툴

로컬 AI 를 능동적으로 사용할 수 있도록 다음의 오픈소스 로컬 인터페이스 도구들이 존재합니다. 

-   ComfyUI: 노드(Node) 기반의 인터페이스입니다. 블록을 선으로 연결하듯 이미지 생성 파이프라인을 직접 설계할 수 있어서, FLUX나 SD 3.5 같은 최신 무거운 모델들을 가장 효율적으로 제어하고 메모리를 아낄 수 있어 전문가들에게 필수 툴이 되었습니다.
-   Automatic1111 (WebUI): 초창기에 많이 사용되던 인터페이스 도구입니다.
-   Forge / SwarmUI: WebUI의 직관적이고 쉬운 UI의 장점을 살리면서도, 내부 백엔드를 완전히 개조해 최신 고성능 모델들을 초보자도 쉽게 불러와 빠르게 돌릴 수 있도록 최적화된 프로그램들입니다.  

## 브금

-   [BGM AI](https://youtu.be/JmYEVPK0Ea0)

## AI Gemini CLI : 인공지능 제미니 CLI

### 설치방법

-   node.js 및 <b>npm</b> 설치

-   관리자권한 파워쉘 터미널에 다음의 명령어를 입력하여 제미니 CLI 설치

```bash
npm install -g @google/gemini-cli
```

-   관리자 권한 파워쉘에 다음의 명령어를 입력하여 외부 코드 실행 정책을 remotesigned 로 변경

```bash
set-executionPolicy remotesigned
```

### 사용방법

터미널에 gemini 를 입력하면 기동합니다.

다음의 기능을 수행할 수 있습니다.

-   MCP
-   파일 수정
-   스크립트 실행
-   웹검색
