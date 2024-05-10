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
  - 지금은 파티션 생성 없이 우툰투 설치과정에서 할당해줄 것 입니다.

    <br />

  - 윈도우 홈 화면에서 우클릭 → 디스크 관리 → 축소할 디스크에 우클릭 볼륨 축소
  - 이 과정에 오류가 발생하여 진행이 어렵다면 MiniTool Partition Wizard 같은 파티션 분할 보조 프로그램을 사용합니다.
  - 파티션의 분할은 해당 드라이브의 데이터(파일 및 기타)의 끝 부분보다 적게 할 수 없습니다. 따라서 Auslogics Disk Defrag 등의 디스크 조각 모음 프로그램등을 통하여 이동이 불가한 데이터 \$Mft::\$bitmap 파일이나 최대절전모드 Hibernate 파일, 가상메모리 pagefile.sys 파일들의 위치를 조정해주셔야 합니다.
    <br />
    <center>

    <img src="./asset/듀얼부팅：MultiBoot/0.png" style="width:80vw; aspect-ratio: 4 / 1"/>

    </center>
    <br />

- UEFI 해제

  - mbr2gpt 등을 사용하였거나 파티션 테이블이 MBR(Master Boot Record)이 아니라 GPT(GUID Partition Table) 유형일 경우 UEFI 옵션이 켜있을 확률이 높습니다.
  - UEFI (Unified Extensible Firmware Interface) 옵션은 바이오스의 플랫폼에 의존적인 제약 사항을 극복하고 하드웨어를 더 유연하게 지원하는 옵션입니다. 해당 옵션으로 다른 OS가 설치되어도 하드웨어 진단없이 곧바로 C드라이브 Windows로 부팅될 수 있습니다. 우리는 Ubuntu를 사용할 것이기 때문에 UEFI 옵션을 해제시켜 주어야 합니다.
  - UERI 메뉴 또는 BIOS에서 해제할 수 있는데, 진입 방법은 각 기기 별로 다르기 때문에 찾아보셔야 합니다.
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

## 우분투 OS 설치 및 환경설정

### 리눅스 설치

- 저는 서드파티 설치 허용 안하고 후에 별도로 설치하는 편 입니다.
- 어디에 설치하냐는 질문에 Manual installation 선택
- swap 파티션 지정 (스왑 파티션은 일반적으로는 램 크기의 1.5 ~ 2배, 대강 10~20GB 정도로 잡는다.)
- Ext4 파티션 지정 (Mount point는 '/' 로 지정합니다.)

<br/>

### snap 제거

- snap은 우분투 개발사 캐노니컬이 밀고있는 패키지 의존성 관리 체계입니다. 자유로운 배포환경에서 서로 의존성을 가진 패키지들이 너무 많아지자 얽히고 섞인 모든 프로그램들을 일일히 설치하고 업데이트하는 상황을 근절하기 위해서 설계되었습니다.

- 사실 딱히 제거해야 할 이유는 없습니다. 다만 사용 공간도 많이 차지 하고 (sudo fdisk -l 등을 써보면 패키지 의존성 격리를 위한 dev/loop 파티션이 수두룩하게 나옵니다.) , 자유로운 배포 환경에서 패키지 통합 시스템의 존재의의 자체가 부정적으로 받아들여지는 부분이 있습니다.

  ```bash
  $ sudo apt-mark hold snapd # 앞으로 apt에서 snap 자동설치를 막습니다
  $ sudo apt update
  $ sudo apt upgrade

  # 귀찮다면
  $ sudo apt autoremove --purge snapd # 빠르게 전체삭제 - 문제 생길 수 있음

  # 정석 방법
  $ snap list # snap 이 관리하는 패키지 목록
  $ snap remove --purge "패키지명" # 해당 패키지 snap 에서 완전제거

  # 영향을 덜 받는 순서대로 삭제하는 쪽이 더 안정적입니다.
  # snap-store >> gtk-common-themes >> gnome >> bare >> core22
  # core 삭제는 snapd에서 사용 중이라 실패할 수 있습니다.
  # 우분투 20.04 이전 $ sudo umount /snap/core"넘버"/"사용자 아이디"
  # 우분투 20.10 이상 $ sudo umount /var/snap

  $ sudo snap remove snapd
  $ sudo apt autoremove --purge snapd

  #다음은 패키지 삭제시 삭제 됐을 폴더이나 한번 더 확인

  rm -rf /snap
  rm -rf /var/snap
  rm -rf /var/lib/snapd
  ```

<br/>

### Grub 설치 및 조정

- GRUB(GRand Unified Bootloader) 는 멀티부트로더 입니다.
- 디폴트 값을 변경하고 싶다면 Ctrl + Alt + T 터미널 열고 vi /etc/default/grub 또는 해당 위치에 직접 가서 텍스트 에디터로 수정
- 화면 크기
  ```bash
  #grub 파일 잘 보면 #로 주석 처리된 해당 항목이 있을 겁니다.
  #입력할 값은 우분투, 윈도우를 고르는 GRUB 부팅 화면에서 c 입력
  #grub-efi 명령창으로 넘어가고 여기서 videoinfo 입력
  #grub이 지원하는 해상도가 뜹니다.
  #텍스트 크기는 고정이므로 해상도 값을 낮출수록 텍스트 크기가 커집니다.
  GRUB_GFXMODE=1280x1024
  ```
- 부팅 선택 메뉴의 대기 시간 조정

  ```bash
  GRUB_TIMEOUT=10
  ```

- 노트북에서 fn키 화면밝기 조절이 안될 때 (인텔 그래픽 설정 먼저 다룰것)

  ```bash
  GRUB_CMDLINE_LINUX_DEFAULT="quiet splash" #BEFORE
  GRUB_CMDLINE_LINUX_DEFAULT="quiet splash acpi_backlight=vendor"
  ```

- 설정이 끝나면 터미널에서 업데이트

  ```bash
  $ sudo update-grub
  $ sudo reboot
  ```

<br/>

### Nvidia 그래픽 드라이버

[추가사항](https://omnil.tistory.com/154)

```bash
#인텔 그래픽은 소프트웨어 업데이터(Software and Updates) 앱이 자동관리합니다.
#그래픽카드에 엔비디아 gforce가 있는지 확인
$ sudo lshw -c display

#엔비디아 그래픽카드 드라이버 확인.
$ cat /proc/driver/nvidia/version #없으면 No such file or directory

#설치가능한 NVIDIA 그래픽 카드 드라이버 확인
$ sudo ubuntu-drivers devices

#선택 1. 드라이버 목록 중에서 "nvidia-driver-525" 수동설치
$ sudo apt install nvidia-driver-525

#선택 2. 권장 드라이버 자동설치
$ sudo ubuntu-drivers autoinstall

#드라이버는 재부팅 후에 적용됩니다
$ sudo reboot
```

<br/>

### 키보드 & 언어팩 설정

- 우분투 상단바 우측을 클릭하면 톱니바퀴 모양의 설정 버튼이 있습니다.
- 설정 <br/>`-⇀` 시스템 <br/>`-⇀` 지역 및 언어(Region & Language) <br/>`-⇀` 설치된 언어 관리(Manage Installed languages)
- \[ Install / Remove Language... \] 클릭하여 한국어와 영어를 선택하고 apply를 눌러주세요.
- \[Apply System-Wide \] 를 클릭하여 전역적으로 설정을 맞춰주세요.
- 해당 창의 Regional Formats 탭으로 넘어가서 시간표기 포맷도 한국어로 바꿔줄 수 있습니다.
- 변경된 언어 설정은 Restart 다시시작 후에 적용됩니다.
- 다시시작하면 폴더명을 한글 이름에 맞춰 바꿀 것인지 물어보는데 영어로 유지하는 편이 좋습니다. 한글명 폴더에서는 문제가 생기는 경우가 있어요.
- 설정 `-⇀` 키보드 항목에서 \[입력 소스 추가\] 버튼을 클릭해주세요.
- 한국어 `-⇀` 한국어(Hangul) 을 추가해준 다음 다른 키보드를 전부 삭제해주세요.
- 한국어(Hangul) 키보드 칸 우측의 ⁝ 버튼을 클릭하시면 기본 설정 창을 킬 수 있습니다.
- 한영전환키 항목에 추가를 누르시고 현 키보드의 한영키를 눌러주세요. 보통은 Alt_R(오른쪽 알트키) 입니다. 추가하고 싶은 한영키 동작 버튼이 있으시면 추가하셔도 됩니다.

<br/>

### Microsoft Edge 설치

- 난 곧 죽어도 엣지를 쓰겠다
- 파이어폭스 삭제

  ```bash
  $ sudo apt purge firefox
  ```

- 엣지 설치

  ```bash
  $ sudo apt update #설치 가능한 패키지 리스트를 최신화

  $ sudo apt install software-properties-common apt-transport-https wget #HTTP/FTP 통신 파일 다운로드 소프트웨어 wget 설치

  $ wget -q https://packages.microsoft.com/keys/microsoft.asc -O- | sudo apt-key add - #wget을 이용해서 마이크로소프트의 GPG 키를 다운로드합니다. GPG 키는 비공개키 알고리즘의 형태이며 설치 프로그램의 무결성을 판단하기 위해서 필요합니다.

  $ sudo add-apt-repository "deb [arch=amd64] https://packages.microsoft.com/repos/edge stable main" #엣지 브라우저 레포지토리 활성화

  $ sudo apt install microsoft-edge-dev #엣지 패키지 다운로드

  $ microsoft-edge #엣지 실행 명령어

  #새 버전이 릴리즈 됬을 경우

  $ sudo apt update #업데이트 리스트 최신화

  $ sudo apt upgrade #Edge 패키지를 업데이트
  ```

### GIT 설치

- git 설치

  ```bash
  sudo apt install git #git 설치
  git --version #git 버전 확인

  #깃에 push했을때 올라갈 정보
  git config --global user.name [이름]
  git config --global user.mail [메일 주소]
  ```

- Github Desktop

  - [공식 문서](https://gist.github.com/berkorbay/6feda478a00b0432d13f1fc0a50467f1)
  - 설치 커맨드

    ```bash
    $ sudo wget https://github.com/shiftkey/desktop/releases/download/release-3.3.3-linux1/GitHubDesktop-linux-amd64-3.3.3-linux1.deb

    $ sudo apt install ./GitHubDesktop-linux-amd64-3.3.3-linux1.deb -y
    ```

### Visual Studio Code 설치

- VS code 설치

  - 난 곧 죽어도 vscode로 코딩을 하겠다
  - 엣지 설치와 크게 다르지 않습니다.

        ```bash
        $ sudo apt update #설치 가능한 패키지 리스트를 최신화

        $ sudo apt install software-properties-common apt-transport-https wget #HTTP/FTP 통신 파일 다운로드 소프트웨어 wget 설치

        $ wget -q https://packages.microsoft.com/keys/microsoft.asc -O- | sudo apt-key add - #wget을 이용해서 마이크로소프트의 GPG 키를 다운로드합니다. GPG 키는 비공개키 알고리즘의 형태이며 설치 프로그램의 무결성을 판단하기 위해서 필요합니다.

        $ sudo add-apt-repository "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main" #vscode 레포지토리 활성화

        $ sudo apt install code #vscode 패키지 다운로드

        $ code #vscode 실행 명령어

        $ sudo code --user-data-dir="열 폴더 따옴표 포함" #관리자 권한으로 실행

        #새 버전이 릴리즈 됬을 경우

        $ sudo apt update #업데이트 리스트 최신화

        $ sudo apt upgrade #Edge 패키지를 업데이트
        ```

### Surface Pro 7 커널

- 서피스는 마이크로소프트의 태블릿이다보니 리눅스-서피스라는 커널로 업데이트해야 보안처리된 하드웨어 컨트롤이 가능합니다.
- [참고링크](https://snowdeer.github.io/mac-os/2020/10/27/how-to-install-ubuntu-20p04-on-surface-pro-7/)
- [linux-surface의 깃허브 주소](https://github.com/linux-surface/linux-surface/wiki/Installation-and-Setup)

<br/>

### 우분투 테마 꾸미기

- 사전 준비

  - 예시용 테마
    - [WhiteSur-gtk-theme](https://github.com/vinceliuice/WhiteSur-gtk-theme)
    - [영상 자료](https://www.youtube.com/watch?v=hQDhTIX4k7s&t=491s)

- 다운로드

  ```bash
  #gnome
  $ sudo apt install gnome-shell-extension-manager
  $ sudo apt install gnome-tweaks

  #예시용 테마
  $ cd "theme 폴더 위치 경로"
  $ ./install.sh -m -t all -l -N stable --normal --round #./install.sh -h 로 옵션 검색가능
  ```

- 확장 관리자(extension manager) 앱을 켜서 확장 검색 탭에서 User Themes 를 검색 후 설치
- 설치된 확장 탭에서 User Themes 가 켜있는지 확인
- 기능 개선(tweaks)

## OS 관리 및 제거

### 배드섹터 검사

- [참고 링크](https://sharkmino.tistory.com/1543)
- OS가 설치된 디스크를 검사하려면 USB 부팅을 통해서 접근해야 합니다.
- $ sudo fdisk -l `# 디스크 목록 확인`
- $

### 특정 프로그램 제거

- [참고 링크](https://velog.io/@coral2cola/Ubuntu-%ED%8C%A8%ED%82%A4%EC%A7%80-%EC%82%AD%EC%A0%9C%ED%95%98%EA%B8%B0)
- Ubuntu에서 패키지 설치 및 제거는 dpkg(Debian Package)와 apt(Advanced Package Tool)를 이용한다.
- apt 쪽이 dpkg 의
- $ apt --installed list #또는 dpkg -l #다운로드 된 패키지 전체 검색
- $ apt --installed list `*제거하고자 하는 패키지이름*` #또는 dpgk list --installed | grep
- $ apt purge `*제거하고자 하는 패키지이름*` #remove 명령어는 환경설정 정보를 남긴다
- sudo apt clean
- sudo apt autoremove

### 우분투 제거

- [참고 링크](https://askubuntu.com/questions/429610/uninstall-grub-and-use-windows-bootloader)
- 윈도우 OS
- 윈도우 OS 로 컴퓨터 키고 작업표시줄 윈도우 버튼 우클릭 <br/>`-⇀` 디스크 관리 <br/>`-⇀` 우분투가 깔려있는 파티션 포맷
- 쉬프트 + 다시시작 으로 윈도우 OS 안전모드에 진입 [참고링크](https://askubuntu.com/questions/429610/uninstall-grub-and-use-windows-bootloader)
  - GRUB 화면으로 넘어간다면 다음의 해결책이 있습니다.
    1. 윈도우 부팅 USB로 진입하고 `[Shift] + [F10]` 또는 설치화면에서 시스템 복구로 안전모드 진입
    2. BIOS 에 진입해서 부팅 순서를 F5, F6 버튼으로 조정하여 윈도우를 최우선으로 맞춰주고 쉬프트 + 다시시작으로 안전모드 진입
- 파란 안전모드 화면에서 문제해결(Troubleshoot) 클릭 <br/>`-⇀` 고급 옵션(Advanced option) <br/>`-⇀` 명령 프롬프트(Command Prompt) 클릭

  - 방법 ① : 직접 UEFI에서 Ubuntu 부팅 옵션 제거하기

    ```bash
    #EFI 시스템 파티션을 임의의 S 드라이브에 마운트 합니다. 드라이브 이름으로 사용되지 않은 알파벳이면 아무거나 상관없습니다. 여기선 S를 예시로 사용합니다.
    mountvol S: /S

    # S: 에 할당된 EFI 파티션과 폴더에 접근합니다. cd S:\EFI 와 동일한 동작입니다.
    S:
    cd .\EFI\

    # 부트로더에 우분투 폴더가 있는 지 확인합니다.
    dir

    #둘 중에서 상황에 따라 택 1로 우분투 폴더를 지웁니다
    #1. cmd 기준 명령어
    rmdir /s /q Ubuntu #옵션 s : 안에 전부 삭제, 옵션 q : 묻지마
    #2. 파워쉘 기준 명령어 (.net 기반이라 윈도우 부팅 USB에선 구동 X)
    Remove-Item -Recurse Ubuntu
    ```

  - 방법 ② : Windows 의 부팅옵션 복구 기능으로 Ubuntu 부팅 옵션 제거

    ```bash
    bootrec /fixmbr
    bootrec /fixboot
    bootrec /scanos #OS 스캔 명령이라 조금 기다리셔야 합니다.
    bootrec /rebuildbcd #부트레코드를 복구하는 명령이기에 복구 정도를 물어봅니다. Add installation to boot list? Yes(Y)/No(N)/All(A) 질문이 뜬다면 A 를 입력해주면 됩니다.
    exit
    ```

- 끝났습니다. 처음의 파란 안전모드 화면에서 Continue 를 선택하여 윈도우OS 부팅을 확인해줍시다.
- 디스크 MBR or GPT 상태나 디스크 조각 상태, 배드섹터 확인 등 복구 과정에서 윈도우 OS 환경에 혹시라도 문제가 생기지 않았는 지 돌아봐 소중한 윈도우를 챙겨줍시다.

# 정리필요

[멀티제스처](https://steady-hello.tistory.com/122)
