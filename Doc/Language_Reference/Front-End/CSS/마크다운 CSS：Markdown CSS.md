# 마크다운 CSS：Markdown CSS

## 개요

&nbsp; 마크다운 문법은 html 태그들을 지원하나 마크다운 문서를 읽는 체계에 따라 지원하는 정도가 다릅니다. vscode 미리보기에서는 html 문법을 거의 다 지원하는 반면, Github는 악용할 여지를 없애기 위하여 일반적인 Markdown 문법을 그대로 사용하지 않습니다. 웹 사이트의 보안과 일관성을 위해 Markdown을 HTML로 변환 후 추가 사후 처리 및 정리 작업을 수행합니다. 자세한 Github 마크다운 사양은 [Github Flavored Markdown Spec 문서](https://github.github.com/gfm/)에서 확인 하실 수 있습니다.

&nbsp; Github 가 HTML으로 변환하는 부분에서 많은 부분을 지원하지 않게되며, 특히 CSS와 js가 적용되지 않는 부분이 치명적입니다. 그럼에도 불구하고 애니메이션이나 커스텀 디자인을 넣는 편법이 존재합니다.

&nbsp; 이 편법의 구현에는 두 가지 포인트가 있습니다.

- 첫번째 포인트는 SVG 파일을 이미지 취급하여 `<img src="./file.svg" alt="" /> ` 처럼 마크다운 문서에서 띄울 수 있다는 점 입니다.
- 두번째 포인트는 SVG에서 `<foreignObject>` 태그를 통하여 텍스트 문서나 HTML 오브젝트를 지원한다는 부분입니다.

결과적으로 SVG 구현을 경유하여 HTML 오브젝트를 Markdown 문서에 간접적으로 구현이 가능합니다. 이 경우엔 결론적으론 그저 SVG 이미지를 띄운 것이기에 Github의 README.md 마크다운 문서에서도 구현이 됩니다.

## 예시

[예시](https://github.com/sindresorhus/css-in-readme-like-wat?tab=readme-ov-file)
Doc\Language_Reference\Front-End\CSS\asset\마크다운 CSS：Markdown CSS\0.svg

<img src="./asset/마크다운 CSS：Markdown CSS/0.svg" width="800" height="400" alt="Click to see the source">
