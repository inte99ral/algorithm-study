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

<center>
<table class="example">
  <tr class="center">
    <th>동작</th><th>명령어</th>
  </tr>
  <tr>
    <td>저장소 생성</td>
    <td>

```bash
$ git init
```

  </td>
  </tr>
    <tr>
    <td>저장소 복제</td>
    <td>

```bash
$ git clone "https://.. URL" #URL 주소
$ git clone "/로컬/저장소/경로" #로컬 디렉토리 주소
```

  </td>
  </tr>
    </tr>
    <tr>
    <td>변경 수용</td>
    <td>

```bash
$ git add "파일명" #해당 파일의 변경을 스테이지에 올립니다.
$ git add * #모든 변경을 스테이지에 올립니다.
$ git add . #.gitignore 제외, 모든 변경을 스테이지에 올립니다.

$ git commit -m "커밋 메시지" #스테이징 영역에 올라와 있던 변경사항들을 수용합니다.

$ git push origin "브랜치 이름"
```

  </td>
  </tr>
    <tr>
    <td>브랜치 생성</td>
    <td>

```bash
$ git branch #브랜치 목록
$ git branch "브랜치 이름" #브랜치 생성
$ git branch -d "브랜치 이름" #브랜치 삭제
$ git push origin "브랜치 이름" #브랜치 원본 저장소로 전송

$ git checkout -b "브랜치 이름" #해당 브랜치로 이동
```

  </td>
  </tr>
  <tr>
    <td>갱신 및 병합</td>
    <td>

```bash
$ git branch #브랜치 목록
```

  </td>
  </tr>
</table>
</center>
