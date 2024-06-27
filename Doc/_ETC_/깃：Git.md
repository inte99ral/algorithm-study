# 깃：Git

<style>
 .example { width: 90vw; & > tbody > tr > td { border: solid 1px lightgray; }; }
 .center { text-align: center; & * { text-align: center; }; }
</style>

<br />

## 공식 문서

- https://git-scm.com/docs

- [참고 링크](https://velog.io/@delilah/GitHub-Git-%EB%AA%85%EB%A0%B9%EC%96%B4-%EB%AA%A8%EC%9D%8C)

<br />

## 목록

git config --list

<center>
<table class="example">
  <tr class="center">
    <th>동작</th>
    <th>명령어</th>
  </tr>
    <tr>
    <td>GIT 설정</td>
    <td>

```bash
git config --list #전체 설정 확인, :상태에서 q를 누르면 git bash에서 나가진다.
git config user.name #사용자 이름 확인
git config user.email #사용자 이메일 확인

git config --global user.name "사용자 이름" #사용자 이름 설정
git config --global user.email "사용자 이메일" #사용자 이메일 설정
```

  </td>
  </tr>
  <tr>
    <td>저장소 생성</td>
    <td>

```bash
git init
```

  </td>
  </tr>
    <tr>
    <td>저장소 복제 &<br />변경사항 수용</td>
    <td>

```bash
git clone "https://.. URL" #URL 주소
git clone "/로컬/저장소/경로" #로컬 디렉토리 주소

git pull #저장소의 변경사항을 모두 수용합니다.
git pull origin "대상브랜치" #저장소 해당 브랜치의 변경사항을 모두 수용합니다.

git fetch #변경사항을 가져오되 병합은 하지 않습니다.
git merge "대상 브랜치 이름" #대상 브랜치의 변경사항을 현재 브랜치에 병합합니다.
```

  </td>
  </tr>
    </tr>
    <tr>
    <td>변경사항 적용</td>
    <td>

```bash
git status #git이 관리하고있는 파일들의 상태를 보여줍니다.

git add "파일명" #해당 파일의 변경을 스테이지에 올립니다.
git add * #모든 변경을 스테이지에 올립니다.
git add . #.gitignore 제외, 모든 변경을 스테이지에 올립니다.

git commit -m "(따옴표 포함)커밋 메시지" #스테이징 영역에 올라와 있던 변경사항들을 브랜치에 적용합니다.

git push origin "브랜치 이름" #브랜치를 원본 저장소로 전송합니다.

git reset #add 전부 취소
git reset HEAD "파일명" #해당 파일 add 취소
git reset HEAD^ #가장 최신 커밋 1개 삭제
git reset HEAD^ #가장 최신 커밋 1개 삭제
git reset HEAD^^^^^ #가장 최신 커밋 5개 삭제
```

  </td>
  </tr>
    <tr>
    <td>브랜치 생성</td>
    <td>

```bash
git branch #브랜치 목록과 현 브랜치를 보여줍니다.
git branch -v #브랜치목록과 마지막 커밋 상세정보까지 보여줍니다.
git branch -r #Origin 원본 저장소 브랜치목록을 보여줍니다.
git branch -a #모든 브랜치목록을 보여줍니다.

git branch "브랜치 이름" #브랜치를 생성합니다.
git branch -d "브랜치 이름" #브랜치를 삭제합니다.
git push origin "브랜치 이름" #브랜치를 원본 저장소로 전송합니다.

git checkout "브랜치 이름" #해당 브랜치로 이동
git checkout -b "브랜치 이름" #해당 브랜치를 생성과 동시에 이동
```

  </td>
  </tr>
  <tr>
    <td>갱신 및 병합</td>
    <td>

```bash
git branch #브랜치 목록

git merge [브랜치명]
```

  </td>
  </tr>
</table>
</center>

<br />

## 컨벤션

- [참고링크](https://velog.io/@shin6403/Git-git-%EC%BB%A4%EB%B0%8B-%EC%BB%A8%EB%B2%A4%EC%85%98-%EC%84%A4%EC%A0%95%ED%95%98%EA%B8%B0)
