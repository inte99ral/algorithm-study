# 파워쉘：PowerShell

## 개요

```ps
Write-Host 'Hello, world!'
```

- Windows PowerShell은 마이크로소프트가 개발한 CLI 셸 및 스크립트 언어를 특징으로 하는 명령어 인터프리터이다. 윈도우 XP 이상에서 사용할 수 있으며 Windows 7부터 기본적으로 설치되어 있다.

## 주석

```ps
# 한줄 주석 처리

<#
  블록 주석 처리
#>
```

## 명령 대체：Command Substitution

```ps
Echo "TEST : $(gcc -v)"
```

## 파워쉘 스크립트 파일 .ps1

파워쉘 스크립트 파일의 확장자는 .ps1 입니다.
끝의 1은 버전명 같지만 powershell 2.0 에서도 확장자는 같습니다.

- 실행되지 않을 시 [참고문헌](<https://learn.microsoft.com/ko-kr/previous-versions/dd347628(v=technet.10)?redirectedfrom=MSDN>)

## 템플릿

### txt 확장자 파일 검색

- 리눅스 예시

```bash
# vscode 쉘에선 ${fileBasenameNoExtension} 이 주소로 바뀜
"g++ -g $(find . -type f -iregex \".*.cpp\") -o ${fileDirname}\\${fileBasenameNoExtension}.exe",
```

- 파워쉘에선

```ps
# 사용자의 홈 디렉터리 = $home
# 예시 Dir $Home/Desktop
Get-Childitem -Path $home -Recurse -Force -Filter *.txt

# 괄호화
Echo (Get-ChildItem -Path C:\Users\dkdld\Desktop -Recurse -Include *.?xt).FullName

# 이름이 * 확장자 가 임의의 한글자와 xt로 끝나는 파일들 전부 출력
echo "TEST : $((Get-ChildItem -Path C:\Users\dkdld\Desktop -Recurse -Include *.?xt).FullName)"
```
