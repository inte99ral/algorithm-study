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

## 버전 체크：Version

```ps
$PSVersionTable
```

## 기본 형식

&nbsp; 엔터키가 입력되기 전까지 대기

```powershell
Echo "Hello, world"

Read-Host -Prompt "Press Enter to continue..."

# 또는
Write-Host "Press Enter to continue..."
Read-Host
```

&nbsp; 다음 키가 입력되기 전까지 대기

```powershell
Add-Type -TypeDefinition @"
using System;
using System.Runtime.InteropServices;
public class Keyboard {
    [DllImport("msvcrt.dll")]
    public static extern int _getch();
}
"@

Write-Host "Press any key to continue..."
[void][Keyboard]::_getch()
```

&nbsp; 'A' 키가 입력되기 전까지 대기

```powershell
Add-Type -TypeDefinition @"
using System;
using System.Runtime.InteropServices;
public class GlobalKeyListener {
    [DllImport("user32.dll")]
    public static extern short GetAsyncKeyState(int vKey);
    public static bool IsKeyPressed(int vKey) {
        return (GetAsyncKeyState(vKey) & 0x8000) != 0;
    }
}
"@

Write-Host "Press the 'A' key to continue..."

while ($true) {
    if ([GlobalKeyListener]::IsKeyPressed(65)) { # 65는 'A' 키의 가상키 코드입니다.
        break
    }
    Start-Sleep -Milliseconds 100
}
```

## 키보드 입력

```powershell
$answer = Read-Host "계속하시겠습니까? (Y/N)"
if ($answer -eq "Y" -or $answer -eq "y") {
    Write-Host "진행합니다."
} elseif ($answer -eq "N" -or $answer -eq "n") {
    Write-Host "종료합니다."
} else {
    Write-Host "잘못된 입력입니다."
}

# 영문
$answer = Read-Host "Do you want to continue? (Y/N)"
if ($answer -eq "Y" -or $answer -eq "y") {
    Write-Host "Proceeding."
} elseif ($answer -eq "N" -or $answer -eq "n") {
    Write-Host "Exiting."
} else {
    Write-Host "ERROR: Invalid input."
}
```

## 명령 대체：Command Substitution

```ps
Echo "TEST : $(gcc -v)"
```

## 배열：Array

### 배열 생성

```powershell
# 빈 배열 생성
$data = @()

# 값이 들어간 배열 생성
$data = @('Zero', 'One', 'Two', 'Three')
```

### 배열 읽기

```powershell
# 전체 요소
$data

# 첫 번째 요소
$data[0]

# 두 번째 요소
$data[1]

# 루프
foreach ($line in $lines) {
  Echo $line
}

# 배열의 길이
$data.Count
```

### 배열 수정

```powershell
$data[1] = 'ONE'
```

### 배열 삭제

```powershell
# 예: 2번째 요소(인덱스 1) 삭제
$data = $data | Where-Object { $_ -ne $data[1] }

# 'Two'만 삭제
$data = $data | Where-Object { $_ -ne 'Two' }
```

## 별칭：Alias

&nbsp; 파워쉘에서는 사용자가 직접 명령어의 별칭을 정하여 숏컷으로 활용할 수 있습니다.

<table>
<tr>
  <th>기능</th>
  <th>명령어</th>
</tr>
<tr>
  <td>별칭 설정</td>
  <td>Set-Alias 『별칭 이름』 『별칭 정의』</td>
</tr>
<tr>
  <td>별칭 전체 리스트</td>
  <td>Get-Alias</td>
</tr>
<tr>
  <td>별칭 이름으로 검색</td>
  <td>Get-Alias -Name 『검색어』</td>
</tr>
<tr>
  <td>별칭 정의으로 검색</td>
  <td>Get-Alias -Definition 『검색어』</td>
</tr>
<tr>
  <td>별칭 삭제</td>
  <td>Remove-Item Alias:『별칭 이름』</td>
</tr>
<tr>
  <td>별칭 리스트 출력</td>
  <td>Export-Alias -Path "『파일 이름』.txt"</td>
</tr>
<tr>
  <td>별칭 리스트 입력</td>
  <td>Import-Alias -Path "『파일 이름』.txt"</td>
</tr>
</table>

## 함수：Function

&nbsp; 파워쉘에서는 별칭을 지정할 뿐 아니라 명령어까지 커스텀할 수 있습니다.

예를 들어, Hi 입력시 Hello, world 가 출력되게 하고 싶다면...

```powershell
function hi { echo "hello, world" }
```

다음을 입력한 뒤에 hi 를 치면 됩니다.

인자를 넣어야 한다면

```powershell
function Add-Numbers {
    param (
        [int]$x,
        [int]$y
    )
    return $x + $y
}
```

다음과 같이 인자를 지정해 준 뒤에 명시적으로 인자에 값을 넣거나, 위치 기반으로 값을 넣을 수 있습니다.

```powershell
Add-Numbers -x 3 -y 4

Add-Numbers 3 4
```

위치 기반으로 값을 넣는 것을 원치 않을 경우 `[CmdletBinding(PositionalBinding=$false)]` 함수 정의에 해당 특성을 넣어주면 됩니다.

```
function AddTest {
    [CmdletBinding(PositionalBinding=$false)]
    param (
        [int]$x,
        [int]$y
    )
    return $x + $y
}

```

한 번, 지정한 함수를 앞으로 영구적으로 사용하고 싶다면 파워쉘의 "$PROFILE" 파일에 함수를 작성하면 됩니다.

"$PROFILE" 은 PowerShell이 시작될 때마다 자동으로 실행되는 사용자 설정 파일이기 때문에 지정해둔 설정이 시작할 때 마다 적용됩니다.

- "$PROFILE" 사용자 설정 파일이 존재하는 지 확인

```powershell
Test-Path $PROFILE
```

- "False" 즉, 없을 경우엔 다음의 명령어로 사용자 설정 파일 생성

```powershell
New-Item -Path $PROFILE -ItemType File -Force
```

- "$PROFILE" 사용자 설정 파일 수정

```powershell
notepad $PROFILE
```

## 파워쉘 스크립트 파일 .ps1

파워쉘 스크립트 파일의 확장자는 .ps1 입니다.
끝의 1은 버전명 같지만 powershell 2.0 에서도 확장자는 같습니다.

- 실행되지 않을 시 [참고문헌](<https://learn.microsoft.com/ko-kr/previous-versions/dd347628(v=technet.10)?redirectedfrom=MSDN>)

## .exe 패키징

&nbsp; 윈도우즈 OS 에는 여러 파일들을 설치구동파일 exe 속에 패키징하는 IExpress 라는 도구가 있습니다.

&nbsp; 이를 이용하여 ps1 파워쉘 구동 파일을 .exe 속에 포장할 수 있습니다.

- 파워쉘에서 IExpress 툴을 호출합니다.

  ```powershell
  iexpress.exe
  ```

- "Create new Self Extraction Directive file" 항목을 선택하고 다음으로 넘어갑니다.
- "Extract files and run an installation command" 항목을 선택하고 다음으로 넘어갑니다.
- 패키지 제목을 입력 후 다음으로 넘어갑니다.
  - 설치창이나 오류 시에 창의 제목으로 뜨는 이름입니다.
- 프롬프트 설정에서 "No prompt" 선택 후 다음으로 넘어갑니다.
- 굳이 표기할 라이센스가 없다면 "Do not display a license" 선택 후 다음으로 넘어갑니다.
- `Add` 버튼을 눌러 test.ps1 파일을 추가합니다. 다음으로 넘어갑니다.
- 설치 후 작업에 대한 창이 뜹니다. 여기서 Install Program 입력 상자에 설치가 끝나면 파워쉘을 키고 test.ps1 을 구동시키는 명령어를 직접 작성합니다.

  - ```powershell
    powershell.exe -ExecutionPolicy Bypass -File test.ps1
    ```

  - Post Install Command 항목은 설치 직후 커맨드나 프로그램 구동 이후에 추가로 실행할 작업입니다. 보통 쓸 일이 없습니다.

- 창표시 옵션은 Default 로 고르고 다음으로 넘어갑니다.
- 완료 메시지는 No message 로 고르고 다음으로 넘어갑니다.
- `C:/test.exe` 같은 느낌으로 패키지 저장 위치와 파일명을 지정합니다.
- 재부팅이 필요없을때는 No restart 를 선택합니다. 다음으로 넘어갑니다.
- SED 파일을 남겨놓아 재수정할 필요성이 없다면 남기지 않는 쪽을 선택해주세요. 다음으로 넘어갑니다.
- 패키지가 생성됩니다.

## .exe 컴파일

&nbsp; 윈도우즈 OS 에는 IExpress 같이 .exe 으로 파일들을 감싸는 패키징 도구가 있지만, IExpress는 단순히 여러 파일을 하나의 셀프-추출 실행파일 EXE로 묶고, 내부적으로 PowerShell을 호출해 ps1을 실행합니다. 실제로 exe 실행파일로 컴파일이 된 것이 아닙니다.

&nbsp; ps1 파일을 exe 실행파일로 변환하기 위해서는 별도의 모듈을 설치해야 합니다. PS2EXE는 PowerShell 스크립트를 .NET 기반의 진짜 실행 파일(EXE)로 "컴파일"합니다. 이 EXE는 ps1 파일을 별도로 추출하지 않아도 바로 실행됩니다.

&nbsp; 또한, PS2EXE는 아이콘 지정, 관리자 권한 실행, 콘솔 숨김(-noConsole), 32/64비트 지정, 버전 정보 삽입 등 다양한 빌드 옵션을 제공합니다.

&nbsp; 파워쉘에서 nuget 패키지 매니저를 통하여 다음의 명령어로 PS2EXE 모듈을 설치할 수 있습니다.

```powershell
Install-Module ps2exe
```

&nbsp; 파워쉘에서 다음의 명령어로 PS2EXE 버전 및 기능 확인이 가능합니다.

```powershell
# 버전 확인 명령어
Invoke-ps2exe -?
```

### 파일 생성하기

&nbsp; 파워쉘에서 변환 명령어를 실행합니다.

```powershell
# 기본 명령어
Invoke-PS2EXE .\원본.ps1 .생성경로\생성할파일.exe

# 단축 명령어
ps2exe .\원본.ps1 .생성경로\생성할파일.exe

# .exe 구동 시에 콘솔창이 뜨지 않는 옵션
Invoke-PS2EXE .\원본.ps1 .생성경로\생성할파일.exe -noConsole
```

### 아이콘 만들기

&nbsp; 원하는 아이콘을 .ico 파일 형식으로 변환해서 준비했다면, 다음의 명령어로 .exe 의 아이콘으로 만들 수 있습니다.

```powershell
# 아이콘 지정
Invoke-ps2exe .\test.ps1 .\test.exe -icon .\myicon.ico
```

&nbsp; 더 복합적인 설정은 .rc 설정파일을 같이 컴파일하거나 `Resource Hacker` 를 이용해주세요.

## 템플릿

### 타임 스탬프 프로필에 찍기

```powershell
Set-Content -Path $PROFILE -Value ((Get-Content $PROFILE), @(
  'Echo "Current Time"'
  'Echo " * $(Get-Date -Format "yyyy-MM-dd HH:mm:ss")"'
  'Echo "Activation Time"'
  ('Echo " * ' + (Get-Date -Format "yyyy-MM-dd HH:mm:ss") + '"')
  'Echo ""'
))

Write-Host "Press Enter to continue..."
Read-Host
```

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

### 관리자 계정인지 확인

```powershell
# 현재 프로세스가 관리자 권한인지 확인
$isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)

if ($isAdmin) {
    Write-Output "현재 PowerShell은 관리자 권한으로 실행 중입니다."
} else {
    Write-Output "현재 PowerShell은 일반 권한으로 실행 중입니다."
}
```

### 환경변수 특정 값 유무 확인

```powershell
function Test-DotNetPath {
    $dotnetPath = "C:\Program Files\dotnet\"
    $envPath = [System.Environment]::GetEnvironmentVariable("Path", "Machine") + ";" +
               [System.Environment]::GetEnvironmentVariable("Path", "User")
    if ($envPath -split ';' | Where-Object { $_.TrimEnd('\') -ieq $dotnetPath.TrimEnd('\') }) {
        return 1
    } else {
        return 0
    }
}
```

### 파워쉘 창 새로고침

```powershell
Start-Process powershell #일반 실행
#Start-Process powershell -Verb RunAs #관리자 권한 실행
Exit #닫기
```

### 프로필을 수정

```powershell
function test02 {
  $content = Get-Content $PROFILE
  $content = @('Echo "Hi"') + $content[1..($content.Count - 1)]
  Set-Content -Path $PROFILE -Value $content
  # 파워창 새로고침 필요
}
```

### 파일에서 특정 키워드 줄 확인

- 키워드가 나오는 모든 줄을 배열로 저장

```powershell
$lines = Select-String -Path "a.ps1" -Pattern "\$data=0" | ForEach-Object { $_.LineNumber }
```

- 키워드가 나오는 첫번째 줄만 저장

```powershell
$firstLine = (Select-String -Path "a.ps1" -Pattern "\$data=0" | Select-Object -First 1).LineNumber
```

### MSYS2 쉘 호출

```powershell
function msys {
  [CmdletBinding(PositionalBinding=$false)]
  param (
    [switch]$unset,
    [string]$set,
    [switch]$get,
    [switch]$path,
    [switch]$admin,
    [switch]$h,
    [switch]$restart
  )

  # msys -h ====================================================================

  if ($h) {
    Echo "msys - MSYS Environment Setting Tool"
    Echo ""
    Echo "Usage: msys [no-option-mode] | (-get | -set <value> | -unset) [-path] [-admin] | -h | -restart"
    Echo ""
    Echo "Options:"
    Echo "  msys                    : Open MSYS shell."
    Echo "  msys -get -path         : Show MSYS path data."
    Echo "  msys -set <value> -path : Modify MSYS path data."
    Echo "  msys -unset -path       : Clear MSYS path data."
    Echo "  msys -get               : Show MSYS env variable."
    Echo "  msys -set <value>       : Modify MSYS env variable."
    Echo "  msys -unset             : Clear MSYS env variable."
    Echo "  msys -h                 : Show help information."
    Echo "  msys -restart           : Restart Powershell."
    Echo "       -admin             : as admin."
    Echo ""
    Echo "Caution:"
    Echo "  * This tool requires MSYS2. please install MSYS2 first"
    Echo "  * This tool requires msysPath(like C:\...\msys64\). please use -get -path, -set -path option first"
    Echo "  * The file `"msys2_shell.cmd`" must exist in the msysPath."
    Echo "  * Please set no more than one env variable."
    return
  }

  # msys -restart ==============================================================

  if ($restart) {
    if ($admin) { Start-Process powershell -Verb RunAs }
    else { Start-Process powershell }
    Exit
  }

  if ($path) {

    # msys -unset -path ==========================================================

    if ($unset) {
      $pathlines = Select-String -Path $PROFILE -Pattern "msysPath = `"" | ForEach-Object { $_.LineNumber }
      $lines = Get-Content $PROFILE
      $newLines = $lines | Where-Object { ($lines.IndexOf($_) + 1) -notin $pathlines }
      Set-Content $PROFILE $newLines

      msys -restart
    }

    # msys -set -path ============================================================

    if ($set) {
      if (!(Test-Path -Path ($set + "msys2_shell.cmd"))) {
        Echo "ERROR: `"$set`" Invalid path."
        return
      }

      $pathlines = Select-String -Path $PROFILE -Pattern "msysPath = `"" | ForEach-Object { $_.LineNumber }
      $lines = Get-Content $PROFILE
      $newLines = $lines | Where-Object { ($lines.IndexOf($_) + 1) -notin $pathlines }
      Set-Content $PROFILE ("`$msysPath = `"$set`"", $newLines)

      msys -restart
    }

    # msys -get -path ============================================================

    if ($get) {
      if ($msysPath) { Write-Host "- : `$msysPath = `"$msysPath`"" -ForegroundColor Green }
      else { Write-Host "- : `$msysPath => UNSET" -ForegroundColor Red }

      $pathlines = Select-String -Path $PROFILE -Pattern "msysPath = `"" | ForEach-Object { $_.LineNumber }
      $lines = Get-Content $PROFILE
      foreach ($pathline in $pathlines) { Echo ("" + $pathline + " : " + $lines[$pathline - 1]) }
      return
    }
  }

  # msys msysPath existence check ==============================================

  if (!$msysPath) {
    Echo "ERROR: msys requires msysPath(like C:\...\msys64\). please use -get -path, -set -path option first"
    return
  }

  # msys msysPath integrity check ==============================================

  if (!(Test-Path -Path ($msysPath + "msys2_shell.cmd"))) {
    Echo "ERROR: `"$msysPath`" Invalid path."
    return
  }

  # msys admin check ===========================================================

  if ($admin -and (!([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator))) {
    Echo "ERROR: -admin option requires that you run as an administrator."
    return
  }

  # msys -unset ================================================================

  if ($unset) {
    if ($admin) { [System.Environment]::SetEnvironmentVariable("Path", ([System.Environment]::GetEnvironmentVariable("Path", "Machine") -replace ($msysPath.Replace("\","\\") + "[^;]*;"), ""), "Machine") }
    else { [System.Environment]::SetEnvironmentVariable("Path", ([System.Environment]::GetEnvironmentVariable("Path", "User") -replace ($msysPath.Replace("\","\\") + "[^;]*;"), ""), "User") }
    return
  }

  # msys -set ==================================================================

  if ($set) {
    if ($admin) {
      $machPath = [System.Environment]::GetEnvironmentVariable("Path", "Machine")
      switch ($set) {
        UCRT64 { [System.Environment]::SetEnvironmentVariable("Path", ($machPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "ucrt64\bin;", "Machine") }
        MINGW64 { [System.Environment]::SetEnvironmentVariable("Path", ($machPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "mingw64\bin;", "Machine") }
        CLANG64 { [System.Environment]::SetEnvironmentVariable("Path", ($machPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "clang64\bin;", "Machine") }
        MSYS2 { [System.Environment]::SetEnvironmentVariable("Path", ($machPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "usr\bin;", "Machine") }
        default { Echo "ERROR: `"$set`" Invalid argument." }
      }
    }
    else {
      $userPath = [System.Environment]::GetEnvironmentVariable("Path", "User")
      switch ($set) {
        UCRT64 { [System.Environment]::SetEnvironmentVariable("Path", ($userPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "ucrt64\bin;", "User") }
        MINGW64 { [System.Environment]::SetEnvironmentVariable("Path", ($userPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "mingw64\bin;", "User") }
        CLANG64 { [System.Environment]::SetEnvironmentVariable("Path", ($userPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "clang64\bin;", "User") }
        MSYS2 { [System.Environment]::SetEnvironmentVariable("Path", ($userPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "usr\bin;", "User") }
        default { Echo "ERROR: `"$set`" Invalid argument." }
      }
    }
    return;
  }

  # msys -get ==================================================================

  if ($get) {
    $userNum = -1
    $machNum = -1
    $userPath = [System.Environment]::GetEnvironmentVariable("Path", "User")
    $machPath = [System.Environment]::GetEnvironmentVariable("Path", "Machine")

    if ($userPath -like ("*" + $msysPath + "ucrt64\bin*")) { $userNum *= -1; }
    if ($userPath -like ("*" + $msysPath + "mingw64\bin*")) { $userNum *= -2; }
    if ($userPath -like ("*" + $msysPath + "clang64\bin*")) { $userNum *= -3; }
    if ($userPath -like ("*" + $msysPath + "usr\bin*")) { $userNum *= -4; }

    if ($machPath -like ("*" + $msysPath + "ucrt64\bin*")) { $machNum *= -1; }
    if ($machPath -like ("*" + $msysPath + "mingw64\bin*")) { $machNum *= -2; }
    if ($machPath -like ("*" + $msysPath + "clang64\bin*")) { $machNum *= -3; }
    if ($machPath -like ("*" + $msysPath + "usr\bin*")) { $machNum *= -4; }

    Write-Host " * UCRT64  " -ForegroundColor Green -NoNewline
    if ($userNum -eq 1) { Write-Host " <== USER" -NoNewline } else { Write-Host "         " -NoNewline }
    if ($machNum -eq 1) { Write-Host " <== MACHINE" } else { Write-Host "            " }

    Write-Host " * MINGW64 " -ForegroundColor Green -NoNewline
    if ($userNum -eq 2) { Write-Host " <== USER" -NoNewline } else { Write-Host "         " -NoNewline }
    if ($machNum -eq 2) { Write-Host " <== MACHINE" } else { Write-Host "            " }

    Write-Host " * CLANG64 " -ForegroundColor Green -NoNewline
    if ($userNum -eq 3) { Write-Host " <== USER" -NoNewline } else { Write-Host "         " -NoNewline }
    if ($machNum -eq 3) { Write-Host " <== MACHINE" } else { Write-Host "            " }

    Write-Host " * MSYS2   " -ForegroundColor Green -NoNewline
    if ($userNum -eq 4) { Write-Host " <== USER" -NoNewline } else { Write-Host "         " -NoNewline }
    if ($machNum -eq 4) { Write-Host " <== MACHINE" } else { Write-Host "            " }

    Write-Host " * UNSET   " -ForegroundColor Red -NoNewline
    if ($userNum -eq -1) { Write-Host " <== USER" -NoNewline } else { Write-Host "         " -NoNewline }
    if ($machNum -eq -1) { Write-Host " <== MACHINE" } else { Write-Host "            " }

    Write-Host " * CONFLICT" -ForegroundColor Red -NoNewline
    if (($userNum -le -2) -or ($userNum -ge 5)) { Write-Host " <== USER" -NoNewline } else { Write-Host "         " -NoNewline }
    if (($machNum -le -2) -or ($machNum -ge 5)) { Write-Host " <== MACHINE" } else { Write-Host "            " }

    return;
  }

  # msys =======================================================================

  if ($admin) {
    $machNum = -1
    $machPath = [System.Environment]::GetEnvironmentVariable("Path", "Machine")
    if ($machPath -like ("*" + $msysPath + "ucrt64\bin*")) { $machNum *= -1; }
    if ($machPath -like ("*" + $msysPath + "mingw64\bin*")) { $machNum *= -2; }
    if ($machPath -like ("*" + $msysPath + "clang64\bin*")) { $machNum *= -3; }
    if ($machPath -like ("*" + $msysPath + "usr\bin*")) { $machNum *= -4; }

    switch ($machNum) {
      -1 { Echo "ERROR: Path missing" }
      1 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -ucrt64 }
      2 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -mingw64 }
      3 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -clang64 }
      4 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -msys }
      default { Echo "ERROR: Path conflict" }
    }
  }
  else {
    $userNum = -1
    $userPath = [System.Environment]::GetEnvironmentVariable("Path", "User")
    if ($userPath -like ("*" + $msysPath + "ucrt64\bin*")) { $userNum *= -1; }
    if ($userPath -like ("*" + $msysPath + "mingw64\bin*")) { $userNum *= -2; }
    if ($userPath -like ("*" + $msysPath + "clang64\bin*")) { $userNum *= -3; }
    if ($userPath -like ("*" + $msysPath + "usr\bin*")) { $userNum *= -4; }

    switch ($userNum) {
      -1 { Echo "ERROR: Path missing" }
      1 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -ucrt64 }
      2 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -mingw64 }
      3 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -clang64 }
      4 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -msys }
      default { Echo "ERROR: Path conflict" }
    }
  }
}
```

### MSYS2 쉘 호출 함수 설치

```powershell
function InstallMsys {
  $answer = Read-Host "This will modify the `$PROFILE file. Continue? (Y/N)"
  if ($answer -eq "Y" -or $answer -eq "y") {
    Write-Host "Proceeding..."
  }
  elseif ($answer -eq "N" -or $answer -eq "n") {
    Write-Host "Exiting."
    return
  }
  else {
    Write-Host "ERROR: Invalid input."
    return
  }

  $answer = Read-Host "Do you want to completely overwrite the `$PROFILE file, or select 'N' to prepend the content to it? (Y/N)"
  if ($answer -eq "Y" -or $answer -eq "y" -or $answer -eq "N" -or $answer -eq "n") {
    if ($answer -eq "Y" -or $answer -eq "y") {
      Write-Host "Proceeding overwrite..."
      Set-Content -Path $PROFILE -Value "" -NoNewline
    }
    else {
      Write-Host "Proceeding prepend..."
    }

    Set-Content -Path $PROFILE -Value ((Get-Content $PROFILE), @(
      'function msys {'
      '  [CmdletBinding(PositionalBinding=$false)]'
      '  param ('
      '    [switch]$unset,'
      '    [string]$set,'
      '    [switch]$get,'
      '    [switch]$path,'
      '    [switch]$admin,'
      '    [switch]$h,'
      '    [switch]$restart'
      '  )'
      ''
      '  # msys -h ===================================================================='
      ''
      '  if ($h) {'
      '    Echo "msys - MSYS Environment Setting Tool"'
      '    Echo ""'
      '    Echo "Usage: msys [no-option-mode] | (-get | -set <value> | -unset) [-path] [-admin] | -h | -restart"'
      '    Echo ""'
      '    Echo "Options:"'
      '    Echo "  msys                    : Open MSYS shell."'
      '    Echo "  msys -get -path         : Show MSYS path data."'
      '    Echo "  msys -set <value> -path : Modify MSYS path data."'
      '    Echo "  msys -unset -path       : Clear MSYS path data."'
      '    Echo "  msys -get               : Show MSYS env variable."'
      '    Echo "  msys -set <value>       : Modify MSYS env variable."'
      '    Echo "  msys -unset             : Clear MSYS env variable."'
      '    Echo "  msys -h                 : Show help information."'
      '    Echo "  msys -restart           : Restart Powershell."'
      '    Echo "       -admin             : as admin."'
      '    Echo ""'
      '    Echo "Caution:"'
      '    Echo "  * This tool requires MSYS2. please install MSYS2 first"'
      '    Echo "  * This tool requires msysPath(like C:\...\msys64\). please use -get -path, -set -path option first"'
      '    Echo "  * The file `"msys2_shell.cmd`" must exist in the msysPath."'
      '    Echo "  * Please set no more than one env variable."'
      '    return'
      '  }'
      ''
      '  # msys -restart =============================================================='
      ''
      '  if ($restart) {'
      '    if ($admin) { Start-Process powershell -Verb RunAs }'
      '    else { Start-Process powershell }'
      '    Exit'
      '  }'
      ''
      '  if ($path) {'
      ''
      '    # msys -unset -path =========================================================='
      ''
      '    if ($unset) {'
      '      $pathlines = Select-String -Path $PROFILE -Pattern "msysPath = `"" | ForEach-Object { $_.LineNumber }'
      '      $lines = Get-Content $PROFILE'
      '      $newLines = $lines | Where-Object { ($lines.IndexOf($_) + 1) -notin $pathlines }'
      '      Set-Content $PROFILE $newLines'
      ''
      '      msys -restart'
      '    }'
      ''
      '    # msys -set -path ============================================================'
      ''
      '    if ($set) {'
      '      if (!(Test-Path -Path ($set + "msys2_shell.cmd"))) {'
      '        Echo "ERROR: `"$set`" Invalid path."'
      '        return'
      '      }'
      ''
      '      $pathlines = Select-String -Path $PROFILE -Pattern "msysPath = `"" | ForEach-Object { $_.LineNumber }'
      '      $lines = Get-Content $PROFILE'
      '      $newLines = $lines | Where-Object { ($lines.IndexOf($_) + 1) -notin $pathlines }'
      '      Set-Content $PROFILE ("`$msysPath = `"$set`"", $newLines)'
      ''
      '      msys -restart'
      '    }'
      ''
      '    # msys -get -path ============================================================'
      ''
      '    if ($get) {'
      '      if ($msysPath) { Write-Host "- : `$msysPath = `"$msysPath`"" -ForegroundColor Green }'
      '      else { Write-Host "- : `$msysPath => UNSET" -ForegroundColor Red }'
      ''
      '      $pathlines = Select-String -Path $PROFILE -Pattern "msysPath = `"" | ForEach-Object { $_.LineNumber }'
      '      $lines = Get-Content $PROFILE'
      '      foreach ($pathline in $pathlines) { Echo ("" + $pathline + " : " + $lines[$pathline - 1]) }'
      '      return'
      '    }'
      '  }'
      ''
      '  # msys msysPath existence check =============================================='
      ''
      '  if (!$msysPath) {'
      '    Echo "ERROR: msys requires msysPath(like C:\...\msys64\). please use -get -path, -set -path option first"'
      '    return'
      '  }'
      ''
      '  # msys msysPath integrity check =============================================='
      ''
      '  if (!(Test-Path -Path ($msysPath + "msys2_shell.cmd"))) {'
      '    Echo "ERROR: `"$msysPath`" Invalid path."'
      '    return'
      '  }'
      ''
      '  # msys admin check ==========================================================='
      ''
      '  if ($admin -and (!([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator))) {'
      '    Echo "ERROR: -admin option requires that you run as an administrator."'
      '    return'
      '  }'
      ''
      '  # msys -unset ================================================================'
      ''
      '  if ($unset) {'
      '    if ($admin) { [System.Environment]::SetEnvironmentVariable("Path", ([System.Environment]::GetEnvironmentVariable("Path", "Machine") -replace ($msysPath.Replace("\","\\") + "[^;]*;"), ""), "Machine") }'
      '    else { [System.Environment]::SetEnvironmentVariable("Path", ([System.Environment]::GetEnvironmentVariable("Path", "User") -replace ($msysPath.Replace("\","\\") + "[^;]*;"), ""), "User") }'
      '    return'
      '  }'
      ''
      '  # msys -set =================================================================='
      ''
      '  if ($set) {'
      '    if ($admin) {'
      '      $machPath = [System.Environment]::GetEnvironmentVariable("Path", "Machine")'
      '      switch ($set) {'
      '        UCRT64 { [System.Environment]::SetEnvironmentVariable("Path", ($machPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "ucrt64\bin;", "Machine") }'
      '        MINGW64 { [System.Environment]::SetEnvironmentVariable("Path", ($machPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "mingw64\bin;", "Machine") }'
      '        CLANG64 { [System.Environment]::SetEnvironmentVariable("Path", ($machPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "clang64\bin;", "Machine") }'
      '        MSYS2 { [System.Environment]::SetEnvironmentVariable("Path", ($machPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "usr\bin;", "Machine") }'
      '        default { Echo "ERROR: `"$set`" Invalid argument." }'
      '      }'
      '    }'
      '    else {'
      '      $userPath = [System.Environment]::GetEnvironmentVariable("Path", "User")'
      '      switch ($set) {'
      '        UCRT64 { [System.Environment]::SetEnvironmentVariable("Path", ($userPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "ucrt64\bin;", "User") }'
      '        MINGW64 { [System.Environment]::SetEnvironmentVariable("Path", ($userPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "mingw64\bin;", "User") }'
      '        CLANG64 { [System.Environment]::SetEnvironmentVariable("Path", ($userPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "clang64\bin;", "User") }'
      '        MSYS2 { [System.Environment]::SetEnvironmentVariable("Path", ($userPath -replace ($msysPath.Replace("\","\\") + "[^;]*;"), "") + $msysPath + "usr\bin;", "User") }'
      '        default { Echo "ERROR: `"$set`" Invalid argument." }'
      '      }'
      '    }'
      '    return;'
      '  }'
      ''
      '  # msys -get =================================================================='
      ''
      '  if ($get) {'
      '    $userNum = -1'
      '    $machNum = -1'
      '    $userPath = [System.Environment]::GetEnvironmentVariable("Path", "User")'
      '    $machPath = [System.Environment]::GetEnvironmentVariable("Path", "Machine")'
      ''
      '    if ($userPath -like ("*" + $msysPath + "ucrt64\bin*")) { $userNum *= -1; }'
      '    if ($userPath -like ("*" + $msysPath + "mingw64\bin*")) { $userNum *= -2; }'
      '    if ($userPath -like ("*" + $msysPath + "clang64\bin*")) { $userNum *= -3; }'
      '    if ($userPath -like ("*" + $msysPath + "usr\bin*")) { $userNum *= -4; }'
      ''
      '    if ($machPath -like ("*" + $msysPath + "ucrt64\bin*")) { $machNum *= -1; }'
      '    if ($machPath -like ("*" + $msysPath + "mingw64\bin*")) { $machNum *= -2; }'
      '    if ($machPath -like ("*" + $msysPath + "clang64\bin*")) { $machNum *= -3; }'
      '    if ($machPath -like ("*" + $msysPath + "usr\bin*")) { $machNum *= -4; }'
      ''
      '    Write-Host " * UCRT64  " -ForegroundColor Green -NoNewline'
      '    if ($userNum -eq 1) { Write-Host " <== USER" -NoNewline } else { Write-Host "         " -NoNewline }'
      '    if ($machNum -eq 1) { Write-Host " <== MACHINE" } else { Write-Host "            " }'
      ''
      '    Write-Host " * MINGW64 " -ForegroundColor Green -NoNewline'
      '    if ($userNum -eq 2) { Write-Host " <== USER" -NoNewline } else { Write-Host "         " -NoNewline }'
      '    if ($machNum -eq 2) { Write-Host " <== MACHINE" } else { Write-Host "            " }'
      ''
      '    Write-Host " * CLANG64 " -ForegroundColor Green -NoNewline'
      '    if ($userNum -eq 3) { Write-Host " <== USER" -NoNewline } else { Write-Host "         " -NoNewline }'
      '    if ($machNum -eq 3) { Write-Host " <== MACHINE" } else { Write-Host "            " }'
      ''
      '    Write-Host " * MSYS2   " -ForegroundColor Green -NoNewline'
      '    if ($userNum -eq 4) { Write-Host " <== USER" -NoNewline } else { Write-Host "         " -NoNewline }'
      '    if ($machNum -eq 4) { Write-Host " <== MACHINE" } else { Write-Host "            " }'
      ''
      '    Write-Host " * UNSET   " -ForegroundColor Red -NoNewline'
      '    if ($userNum -eq -1) { Write-Host " <== USER" -NoNewline } else { Write-Host "         " -NoNewline }'
      '    if ($machNum -eq -1) { Write-Host " <== MACHINE" } else { Write-Host "            " }'
      ''
      '    Write-Host " * CONFLICT" -ForegroundColor Red -NoNewline'
      '    if (($userNum -le -2) -or ($userNum -ge 5)) { Write-Host " <== USER" -NoNewline } else { Write-Host "         " -NoNewline }'
      '    if (($machNum -le -2) -or ($machNum -ge 5)) { Write-Host " <== MACHINE" } else { Write-Host "            " }'
      ''
      '    return;'
      '  }'
      ''
      '  # msys ======================================================================='
      ''
      '  if ($admin) {'
      '    $machNum = -1'
      '    $machPath = [System.Environment]::GetEnvironmentVariable("Path", "Machine")'
      '    if ($machPath -like ("*" + $msysPath + "ucrt64\bin*")) { $machNum *= -1; }'
      '    if ($machPath -like ("*" + $msysPath + "mingw64\bin*")) { $machNum *= -2; }'
      '    if ($machPath -like ("*" + $msysPath + "clang64\bin*")) { $machNum *= -3; }'
      '    if ($machPath -like ("*" + $msysPath + "usr\bin*")) { $machNum *= -4; }'
      ''
      '    switch ($machNum) {'
      '      -1 { Echo "ERROR: Path missing" }'
      '      1 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -ucrt64 }'
      '      2 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -mingw64 }'
      '      3 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -clang64 }'
      '      4 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -msys }'
      '      default { Echo "ERROR: Path conflict" }'
      '    }'
      '  }'
      '  else {'
      '    $userNum = -1'
      '    $userPath = [System.Environment]::GetEnvironmentVariable("Path", "User")'
      '    if ($userPath -like ("*" + $msysPath + "ucrt64\bin*")) { $userNum *= -1; }'
      '    if ($userPath -like ("*" + $msysPath + "mingw64\bin*")) { $userNum *= -2; }'
      '    if ($userPath -like ("*" + $msysPath + "clang64\bin*")) { $userNum *= -3; }'
      '    if ($userPath -like ("*" + $msysPath + "usr\bin*")) { $userNum *= -4; }'
      ''
      '    switch ($userNum) {'
      '      -1 { Echo "ERROR: Path missing" }'
      '      1 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -ucrt64 }'
      '      2 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -mingw64 }'
      '      3 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -clang64 }'
      '      4 { &($msysPath + "msys2_shell.cmd") -defterm -here -no-start -msys }'
      '      default { Echo "ERROR: Path conflict" }'
      '    }'
      '  }'
      '}'
    ))
  }
  else {
    Write-Host "ERROR: Invalid input."
    return
  }
}

InstallMsys

Write-Host "The task is finished. Press Enter to close the window..."
Read-Host
```
