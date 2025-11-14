# Visual Studio Code：비주얼 스튜디오 코드

## 단축키

### alt - 멀티 커서

| 단축키               | 기능                                                     |
| -------------------- | -------------------------------------------------------- |
| `alt + 클릭`         | 해당 마우스 커서 위치에 멀티 커서 형성                   |
| `alt + enter`        | `ctrl + F` 등으로 복수 선택된 영역 앞에 멀티 커서 형성   |
| `ctrl + shift + L`   | `alt + enter` 과 유사, 복수선택된 영역의 수정사항을 링크 |
| `alt + {↑,↓}`        | {위, 아래} 줄로 코드 줄 이동                             |
| `ctrl + alt + {↑,↓}` | {위, 아래} 줄에 멀티 커서 형성                           |

### ctrl - 복합 명령

| 단축키         | 기능      |
| -------------- | --------- |
| `ctrl + space` | 자동완성  |
| `ctrl + F`     | 단어 검색 |

## 쉘 명령어

-   <table>
    <tr>
    <th>분류</th>
    <th>변수명</th>
    <th>변수값</th>
    </tr>
    <tr>
    <td rowspan="8">경로 관련 변수</td>
    </tr>
    <tr>
    <td>${workspaceFolder}</td>
    <td>현재 VSCode에서 열린 작업 폴더의 경로</td>
    </tr>
    <tr>
    <td>${workspaceFolderBasename}</td>
    <td>작업 폴더의 이름 (슬래시 없이)</td>
    </tr>
    <tr>
    <td>${file}</td>
    <td>현재 열린 파일의 전체 경로</td>
    </tr>
    <tr>
    <td>${fileWorkspaceFolder}</td>
    <td>현재 열린 파일이 속한 작업 폴더</td>
    </tr>
    <tr>
    <td>${relativeFile}</td>
    <td>작업 폴더를 기준으로 한 현재 파일의 상대 경로</td>
    </tr>
    <tr>
    <td>${fileDirname}</td>
    <td>현재 파일이 있는 디렉토리 경로</td>
    </tr>
    <tr>
    <td>${fileExtname}</td>
    <td>현재 파일의 확장자</td>
    </tr>
    <tr>
    <td rowspan="3">파일명 관련 변수</td>
    </tr>
    <tr>
    <td>${fileBasename}</td>
    <td>현재 파일의 기본 이름 (확장자 포함)</td>
    </tr>
    <tr>
    <td>${fileBasenameNoExtension}</td>
    <td>현재 파일의 기본 이름 (확장자 제외)</td>
    </tr>
    <tr>
    <td rowspan="3">에디터 관련 변수</td>
    </tr>
    <tr>
    <td>${lineNumber}</td>
    <td>현재 활성 파일에서 선택된 라인 번호</td>
    </tr>
    <tr>
    <td>${selectedText}</td>
    <td>현재 활성 파일에서 선택된 텍스트</td>
    </tr>
    <tr>
    <td rowspan="4">시스템 관련 변수</td>
    </tr>
    <tr>
    <td>${userHome}</td>
    <td>사용자의 홈 폴더 경로</td>
    </tr>
    <tr>
    <td>${pathSeparator}</td>
    <td>운영 체제에 따른 경로 구분자 (macOS/Linux: '/', Windows: '')</td>
    </tr>
    <tr>
    <td>${execPath}</td>
    <td>VSCode 실행 파일의 경로</td>
    </tr>
    <tr>
    <td rowspan="3">기타 변수</td>
    </tr>
    <tr>
    <td>${env:Name}</td>
    <td>환경 변수 참조 (예: ${env:USERNAME})</td>
    </tr>
    <tr>
    <td>${config:Name}</td>
    <td>VSCode 설정 참조 (예: ${config:editor.fontSize})</td>
    </tr>
    </table>
