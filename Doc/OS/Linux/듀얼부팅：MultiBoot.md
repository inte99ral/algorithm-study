# 듀얼부팅：MultiBoot

[참고 링크](https://snowdeer.github.io/mac-os/2020/10/27/how-to-install-ubuntu-20p04-on-surface-pro-7/)

[참고 동영상](https://www.youtube.com/watch?v=mXyN1aJYefc)

## 목차

## 순서

### 기본 디바이스 세팅

- SSD의 BitLocker 해제

  - Windows 11 pro의 기능인 비트 로커(Bit Locker) 는 도난이나 해킹으로부터 보호하여 사용자 데이터 복구를 불가능하게 만드는 Windows에서 제공하는 디스크 암호화 기능입니다. OS가 접근해야하는 드라이브가 암호화가 되어있다면 드라이브가 잠겨 부팅이 안될 수 있습니다.
  - 탐색기에서 C 드라이브를 선택한다음 마우스 오른 클릭, ‘BitLocker 관리’를 선택합니다. 그 다음 ‘BitLocker 끄기’를 선택하면 됩니다. ‘BitLocker 켜기’ 가 목록에 뜨는 경우 애초에 BitLock가 걸려있지 않은 상황입니다.
  - 윈도우 11 Home 에선 bitlocker 기능은 지원하지 않으나 옵션 > 개인 정보 및 보안 > 장치 암호화 항목에서 장치 암호화를 해제할 수 있습니다.

- 파티션 분할

  - 별도의 드라이브 없이 한 드라이브에서 리눅스 운영체제를 설치하려고 한다면, 리눅스 OS가 사용할 공간을 분할하여 줍니다.
  - 이 화면에서도 BitLocker가 정상적으로 적용/해제되었는지 여부를 확인할 수도 있습니다.
  - [파티션 생성 없이 우툰투 설치과정에서 할당해야합니다.](https://velog.io/@whattsup_kim/Linux-%EC%9C%88%EB%8F%84%EC%9A%B0-%EB%A6%AC%EB%88%85%EC%8A%A4%EC%9A%B0%EB%B6%84%ED%88%AC-%EB%93%80%EC%96%BC%EB%B6%80%ED%8C%85-%EC%84%B8%ED%8C%85%ED%95%98%EA%B8%B0)

    <br />

  - 윈도우 홈 화면에서 우클릭 → 디스크 관리 → 축소할 디스크에 우클릭 볼륨 축소
  - 이 과정에 오류가 발생하여 진행이 어렵다면 MiniTool Partition Wizard 같은 파티션 분할 보조 프로그램을 사용합니다.
  - 파티션의 분할은 해당 드라이브의 데이터(파일 및 기타)의 끝 부분보다 적게 할 수 없습니다. 따라서 Auslogics Disk Defrag 등의 디스크 조각 모음 프로그램등을 통하여 이동이 불가한 데이터 \$Mft::\$bitmap 파일이나 최대절전모드 Hibernate 파일, 가상메모리 pagefile.sys 파일들의 위치를 조정해주셔야 합니다.

- UEFI 해제

  - mbr2gpt 등을 사용하였거나 파티션 테이블이 MBR(Master Boot Record)이 아니라 GPT(GUID Partition Table) 유형일 경우 UEFI 옵션이 켜있을 확률이 높습니다.
  - UEFI (Unified Extensible Firmware Interface) 옵션은 바이오스의 플랫폼에 의존적인 제약 사항을 극복하고 하드웨어를 더 유연하게 지원하는 옵션입니다. 해당 옵션으로 다른 OS가 설치되어도 하드웨어 진단없이 곧바로 C드라이브 Windows로 부팅될 수 있습니다. 우리는 Ubuntu를 사용할 것이기 때문에 UEFI 옵션을 해제시켜 주어야 합니다.
  - BIOS에서 해제할 수 있는데, BIOS 진입 방법은 각 기기 별로 다르기 때문에 찾아보셔야 합니다.
    - 레노버 아이디어 패드의 경우 부팅용 버튼 구멍에 핀을 꽂아 넣으셔야합니다.
    - 서피스의 경우 들어가는 방법은 전원이 꺼진 상태에서 전원 + Volume Up 키를 오래동안 누르고 있으면 됩니다.
    - [참고링크](https://www.linux.org/threads/ubuntu-22-04-on-surface-pro-7.43071/)

- BIOS 세팅
  - UBUNTU F5 ,F6를 통해서 순서를 바꿀 수 있다.

### 부팅 USB 준비

- USB 준비
  - 완전히 포맷되어 OS 부팅용 USB로 바꿀 최소 4GB 이상의 USB를 준비해야합니다.
- 리눅스 ISO 파일 다운로드
  - 부팅 가능한 리눅스 ISO 파일을 우분투 홈페이지에서 다운로드 받습니다.
- Rufus 설치
  - ISO 파일로 부팅 가능한 USB를 만들어주는 오픈소스 프로그램 Rufus를 설치하여야 합니다
  - Rufus를 사용하여 USB를 부팅 USB 로 바꾸어 줍시다.

## 우분투 OS 설치

- 리눅스 설치
  - 서드파티 프로그램 설치 허가
  - swap 파티션 지정 (스왑 파티션은 일반적으로는 램 크기의 1.5 ~ 2배, 대강 10~20GB 정도로 잡는다.)
  - Windows 나란히 설치 선택
- Grub 설치 및 조정

  - sudo update-grub
  - Ctrl + Alt + T 터미널 열고 vi /etc/default/grub 또는 텍스트 에디터로 수정
  - 부팅 선택 메뉴의 대기 시간 부여

    ```bash
    GRUB_DEFAULT=0
    GRUB_TIMEOUT_STYLE=menu
    GRUB_TIMEOUT=10
    GRUB_DISTRIBUTOR=`lsb_release -i -s 2> /dev/null || echo Debian`
    GRUB_CMDLINE_LINUX_DEFAULT="quiet splash"
    GRUB_CMDLINE_LINUX=""
    ```

  - 노트북에서 fn키 화면밝기 조절이 안될 때 (인텔 그래픽 설정 먼저 다룰것)

    ```bash
    GRUB_CMDLINE_LINUX_DEFAULT="quiet splash"
    GRUB_CMDLINE_LINUX_DEFAULT="quiet splash acpi_backlight=vendor acpi_osi=Linux"
    ```

  - 설정이 끝나면 터미널에서 업데이트
    ```bash
    $ sudo update-grub
    $ sudo reboot
    ```

- 언어팩 설치

  - [참고 링크](https://staraube.tistory.com/105)

- 크롬 설치

## 제거 루틴

- 특정 프로그램 제거
  - [참고 링크](https://velog.io/@coral2cola/Ubuntu-%ED%8C%A8%ED%82%A4%EC%A7%80-%EC%82%AD%EC%A0%9C%ED%95%98%EA%B8%B0)
  - apt list --installed `or`
- 우분투 + GRUB 부팅 제거
  - 윈도우 OS 로 컴퓨터 키고 작업표시줄 윈도우 버튼 우클릭 <br/>`-⇀` 디스크 관리 <br/>`-⇀` 우분투가 깔려있는 파티션 포맷
  - 쉬프트 + 다시시작 으로 윈도우 OS 안전모드에 진입
  - 파란 안전모드 화면에서 문제해결(Troubleshoot) 클릭 <br/>`-⇀` Advanced option <br/>`-⇀` Command Prompt 클릭 <br/>`-⇀` 관리자 계정(본인 계정) 선택
  - X:\Sources> 라고 뜨는 윈도우의 가상드라이브 X로 된 명령 프롬프트 창이 열립니다. bootrec 을 이용하여 부팅 환경을 윈도우에 기준으로 복구 해줍시다.
    - X:\Sources>bootrec /fixmbr
    - X:\Sources>bootrec /fixboot
    - X:\Sources>bootrec /scanos <br/>`-⇀` OS 스캔 명령이라 조금 기다리셔야 합니다.
    - X:\Sources>bootrec /rebuildbcd <br/>`-⇀` 부트레코드를 복구하는 명령이기에 스캔한 뒤 그 정도를 물어봅니다. <br/>`-⇀` Add installation to boot list? Yes(Y)/No(N)/All(A): <br/>`-⇀` A 를 입력해줍니다.
    - X:\Sources>exit
  - 끝났습니다. 처음의 파란 안전모드 화면에서 Continue 를 선택하여 윈도우OS 부팅을 확인해줍시다.
  - 디스크 MBR or GPT 상태나 디스크 조각 상태, 배드섹터 확인 등 복구 과정에서 윈도우 OS 환경에 혹시라도 문제가 생기지 않았는 지 돌아봐 소중한 윈도우를 챙겨줍시다.

# 정리필요

<br />
<center>

<img src="./asset/듀얼부팅：MultiBoot/0.png" style="width:80vw; aspect-ratio: 4 / 1"/>

</center>
<br />

설치 가능한 드라이버 확인 $ ubuntu-drivers devices

드라이버 설치 $sudo apt-get install nvidia-390

그래픽카드 확인 $ cat /proc/driver/nvidia/version

[키보드 세팅](https://staraube.tistory.com/105)

[멀티제스처](https://steady-hello.tistory.com/122)
