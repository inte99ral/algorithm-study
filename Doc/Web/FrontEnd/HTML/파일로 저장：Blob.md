# 텍스트 파일에 저장하기：Basic Form

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <title>텍스트 파일 저장</title>
  </head>
  <body>
    <input type="text" id="chat" placeholder="저장할 내용을 입력해주세요." />
    <input type="text" id="file_name" placeholder="생성할 파일 이름을 입력해주세요." />

    <button onclick="Download()">다운로드</button>

    <script>
      function Download() {
        let chatting = document.querySelector('#chat');
        let file_name = document.querySelector('#file_name');

        const blob = new Blob([chatting.value], { type: 'text/plain' });
        const url = window.URL.createObjectURL(blob);

        const a = document.createElement('a');
        a.style.display = 'none';
        a.href = url;
        a.download = file_name.value;
        document.body.appendChild(a);

        a.click();

        setTimeout(() => {
          document.body.removeChild(a);
          window.URL.revokeObjectURL(url);
        }, 100);
      }
    </script>
  </body>
</html>
```
