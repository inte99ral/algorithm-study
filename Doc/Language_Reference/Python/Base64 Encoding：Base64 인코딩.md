# Base64 Encoding：Base64 인코딩

## Base64 인코딩

&nbsp; 파이썬을 이용하여 간단하게 Base64 인코딩이 가능합니다.

&nbsp; 다음은 가장 단순한 인코딩 예제입니다. 00.py 파일에 다음과 같이 코드를 작성하고 이미지 경로와 저장할 경로를 기입한 뒤에 "python 00.py" 명령어로 구동해주면 같은 경로에 00.txt 파일로 base64 코드가 나옵니다.

```py
import base64
import os

def convertToBase64(inputPath, outputPath):
  encodedStr = base64.b64encode(open(inputPath, 'rb').read()).decode('utf-8')
  open(outputPath, 'w').write(encodedStr)
  print(f"Base64 인코딩된 이미지가 {outputPath}에 저장되었습니다.")

# input path
inputPath = "00.ttf"

# output path
outputPath = "00.txt"

# 출력할 디렉토리가 없는 경우엔 생성
# os.makedirs(os.path.dirname(outputPath), exist_ok=True)

convertToBase64(inputPath, outputPath)
```

&nbsp; 다음과 같이 html 페이지에서 사용할 수 있습니다.

```html
<img src="data:image/png;base64, 『BASE64_CODE』" />
```

&nbsp; 다음과 같이 폰트도 base64 인코딩하여 사용할 수 있습니다.

```css
@font-face {
  font-family: 'YourFontName';
  src: url('data:font/ttf;base64,『BASE64_CODE』') format('truetype');
  font-weight: normal;
  font-style: normal;
}
```
