# Node.js：런타임 환경

&nbsp; Node.js는 JavaScript 코드를 브라우저 밖에서 실행할 수 있게 해주는 런타임 환경입니다.

&nbsp; Node.js 개발 환경을 구축할 때에는 비공식 Node.js 버전 관리자 `NVM`(Node Version Manager)과 JavaScript 패키지매니저인 `npm`(node pkgmakeinst) 을 사용하여 개발 환경 관리를 할 수 있습니다.

&nbsp; 리눅스의 apt 이나 윈도우의 pacman 같은 패키지관리자에 익숙하신 분은 다음의 명령어표를 보시면 이해하기 쉬우실 겁니다.

-   버전 확인 `nvm -v` `node -v`
-   npm 남아 있는 캐시 삭제 `npm cache clean --force`
-   nvm 설치 후 최신 node 설치 nvm install lts
-   npm 최신 버전 업데이트 npm install -g npm@latest
-   사용 중인 node 버전 바꾸기 `nvm use <version>`
-   nvm 기본 node 버전 지정 `nvm alias default <version>`
-   nvm 기본 node 버전 확인 `nvm alias default`

<details open>
<summary>명령어 표</summary>
<br />
<table>
<tr>
  <th><center>⟍</center></th>
  <th>apt</th>
  <th>npm</th>
  <th>pacman</th>
</tr>
<tr>
  <td>이름 유래</td>
  <td>advanced package tool</td>
  <td>node pkgmakeinst</td>
  <td>package manager</td>
</tr>
<tr>
  <th colspan="4"><center>- 패키지 설치 및 제거 -</center></th>
</tr>
<tr>
  <td>패키지 설치</td>
  <td>sudo apt install 『패키지 이름』</td>
  <td>npm install 『패키지 이름』</td>
  <td>pacman -S 『패키지 이름』</td>
</tr>
<tr>
  <td>패키지 제거</td>
  <td>sudo apt remove 『패키지 이름』</td>
  <td>npm uninstall 『패키지 이름』</td>
  <td>pacman -R 『패키지 이름』</td>
</tr>
<tr>
  <td>패키지 설정/의존성까지 완전소거</td>
  <td>sudo apt purge 『패키지 이름』</td>
  <td>(uninstall 시 완전소거)</td>
  <td>pacman -Rns 『패키지 이름』</td>
</tr>
<tr>
  <td>필요 없는 패키지(고아 패키지) 제거</td>
  <td>sudo apt autoremove</td>
  <td>npm prune</td>
  <td>pacman -Rns $(pacman -Qdtq)</td>
</tr>
<tr>
  <td>패키지 캐시 삭제</td>
  <td>sudo apt clean</td>
  <td>npm cache clean --force</td>
  <td>pacman -Scc</td>
</tr>
<tr>
  <th colspan="4"><center>- 패키지 DB -</center></th>
</tr>
<tr>
  <td>패키지 DB 검색</td>
  <td>apt search 『검색어』</td>
  <td>npm search 『검색어』</td>
  <td>pacman -Ss 『검색어』</td>
</tr>
<tr>
  <td>패키지 DB 상세정보</td>
  <td>apt show 『패키지 이름』</td>
  <td>npm info 『패키지 이름』</td>
  <td>pacman -Si 『패키지 이름』</td>
</tr>
<tr>
  <td>패키지 DB 업데이트</td>
  <td>sudo apt update</td>
  <td>(항상 최신 DB)</td>
  <td>pacman -Sy</td>
</tr>
<tr>
  <th colspan="4"><center>- 설치된 패키지 관리 -</center></th>
</tr>
<tr>
  <td>설치된 패키지 목록</td>
  <td>apt list --installed</td>
  <td>npm list --global	</td>
  <td>pacman -Q</td>
</tr>
<tr>
  <td>설치된 패키지 검색</td>
  <td>apt list --installed 『검색어』</td>
  <td>npm ls 『검색어』</td>
  <td>pacman -Qs 『검색어』</td>
</tr>
<tr>
  <td>업그레이드 가능한 패키지 목록</td>
  <td>apt list --upgradable</td>
  <td>npm outdated</td>
  <td>pacman -Qu</td>
</tr>
<tr>
  <td>설치된 모든 패키지 업그레이드</td>
  <td>sudo apt upgrade</td>
  <td>npm update</td>
  <td>pacman -Su</td>
</tr>
<tr>
  <td>설치된 특정 패키지 업그레이드</td>
  <td>sudo apt install 『패키지 이름』</td>
  <td>npm update 『패키지 이름』</td>
  <td>pacman -S 『패키지 이름』</td>
</tr>
</table>
</details>
