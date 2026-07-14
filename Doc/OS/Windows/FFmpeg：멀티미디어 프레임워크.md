# FFmpeg：멀티미디어 프레임워크

## 영상파일 프레임 분해

```bash
ffmpeg -i input.mp4 output_%06d.png
```

%06d는 6자리 숫자로 저장한다는 의미입니다.

-   %04d → 0001
-   %05d → 00001
-   %06d → 000001

따라서 output_000001.png ... output_000300.png 처럼 넘버링되어 각 프레임이 출력됩니다.

가변프레임 영상의 경우 다음의 명령어로 출력할 수 있습니다.

```bash
# 구버전
ffmpeg -i input.mp4 -vsync 0 frame_%06d.png

# 최신버전
ffmpeg -i input.mp4 -fps_mode passthrough frame_%06d.png
```

이 옵션은 입력 영상의 프레임을 그대로 추출하여 중복 생성이나 프레임 누락을 방지하는 데 도움이 됩니다.

## 깨진 파일 분석
