# Semantic Versioning：유의적 버전 명세

- [참고 링크](https://velog.io/@i33w/semver)

Semantic Versioning 은 소프트웨어 서비스 간에 의존성 문제를 조정하기 위하여 GitHub의 공동 설립자인 Tom Preston-Werner가 제안한 방식입니다.

Semantic Versioning은 버전 번호를 어떻게 정하고 올려야 하는지를 명시하는 규칙입니다.

한 개발 패키지의 버전을 `.` 으로 구분하여 세 부분으로 나눠 표기합니다.

<div align="center">
`『MAJOR_NUMBER』.『MINOR_NUMBER』.『PATCH_NUMBER』`
</div>

- 전 버전과 호환되지 않게 API가 바뀌면 주(主) major 버전을 한 단계 올립니다.
- 전 버전과 호환되면서 새로운 기능이 추가되었다면 부(部) minor 버전을 한 단계 올립니다.
- 전 버전과 호환되면서 문제점만 개선한 것이라면 수(修) patch 버전을 한 단계 올립니다.

네 부분으로 구분했을 경우에는 맨 끝에 빌드번호를 붙인 경우 입니다.

<div align="center">
`『MAJOR_NUMBER』.『MINOR_NUMBER』.『PATCH_NUMBER』.『BUILD_NUMBER』`
</div>

- 빌드 번호는 배포나 수정사항의 순번 등 추가 정보를 제공합니다.
