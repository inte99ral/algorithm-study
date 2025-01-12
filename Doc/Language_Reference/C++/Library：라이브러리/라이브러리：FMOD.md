# 라이브러리：FMOD

## 개요

- Firelight Technologies Pty Ltd가 개발한 사운드 엔진.

- 언리얼, 유니티, 크라이엔진 등 많은 게임 엔진에서 내장 기능으로 탑재해 사용하는 사운드 라이브러리입니다. 물론 내장된 사운드 기능은 FMOD를 100% 지원하는 것이 아니므로 복잡한 기능을 사용하려면 결국 별도 플러그인을 이용해야 합니다.

- 출력 가능한 사운드 형식은 ALFF, ASF, ASX, DLS, FLAC, FSB, IT, M3U, MID, MOD, MP2, MP3, OGG, WAV, WMA 등등.. 사운드 확장자는 거의 다 지원합니다.

## 설치

[공식 사이트](https://www.fmod.com/)

FMOD Studio 를 다운 받아주세요.

FMOD가 설치된 경로를 확인하고 설치가 끝났다면

- Include 디렉토리, `<FMOD가 설치된 경로>\FMOD SoundSystem\FMOD Studio API Windows\api\lowlevel\inc` <b>"폴더 전체"</b>를 프로젝트 폴더로 복사합니다.

- 라이브러리, `<FMOD가 설치된 경로>\FMOD SoundSystem\FMOD Studio API Windows\api\lowlevel\lib` 폴더 안에서 <b>"fmod.dll"</b> 파일을 프로젝트 폴더로 복사합니다.

`<FMOD가 설치된 경로>\FMOD SoundSystem\FMOD Studio API Windows\api\lowlevel\examples` 에 예제 파일들이 있습니다.

FMOD는 예제와 메뉴얼이 정말 잘 준비되어 있습니다.

FMOD가 설치된 폴더에 가보시면 있으니 혹여나 디테일한 사용법이나 기능이 궁금하시다면 찾아가셔서 살펴보시기 바랍니다.

## gcc 명령어

기본 형태

`g++ <INPUT_FILE> -o <OUTPUT_FILE>`

기본 형태

`g++ -I<DIRECTORY_PATH> <INPUT_FILE> -o <OUTPUT_FILE>`

[추가 설명](https://dlemrcnd.tistory.com/73)
