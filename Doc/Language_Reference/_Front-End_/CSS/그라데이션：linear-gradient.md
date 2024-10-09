# 그라데이션：linear-gradient

## 사용 예시

### 줄무늬 패턴 만들기

https://webclub.tistory.com/575

[줄무늬예시](https://codepen.io/display1180/pen/xLbQZP)

[체크무늬](https://codepen.io/ryusoo/pen/GRxNvEx)

<center>
<div style="
  width:50vw;
  aspect-ratio:1/1;
  line-height:50vw;
  font-weight: 600;
  font-size: 18px;
  text-shadow: -1px 0px white, 0px 1px white, 1px 0px white, 0px -1px white;
  ==============================;
  background:linear-gradient(#fb3 50%, #5ba 50%);
">
  linear-gradient(#fb3 50%, #5ba 50%)
</div>
</center>
<br />

#### 꼼수

- 일일히 50% 구분해서 쓰기 귀찮다면 다음의 꼼수가 있습니다.
- CSS3 규격에서는 어떤 한 색상의 정지 위치가 목록에 있는 다른 색상 정지 위치보다 작다면 다른 색상 정지 목록보다 가장 넓게 지정된 위치와 같게 지정됩니다.
- 다음의 사례에선 이미 50% fb3색상이 있는 상황에서 10%를 지정시켰기에 나머지 50% 전체를 fb3가 차지하게 됩니다.

<center>
<div style="
  width:50vw;
  aspect-ratio:1/1;
  display: flex;
  align-items: center;
  justify-content: center;
  font-weight: 600;
  font-size: 18px;
  text-shadow: -1px 0px white, 0px 1px white, 1px 0px white, 0px -1px white;
  ==============================;
  background:linear-gradient(#fb3 50%, #5ba 10%);
">
  linear-gradient(#fb3 50%, #5ba 10%);
</div>
</center>

#### 줄무늬 반복시키기

- background-size: 100% 30px; 를 지정하여 무늬를 반복시킬 수 있습니다.

<center>
<div style="
width:50vw;
  aspect-ratio:1/1;
  display: flex;
  align-items: center;
  justify-content: center;
  font-weight: 600;
  font-size: 16px;
  text-shadow: -1px 0px white, 0px 1px white, 1px 0px white, 0px -1px white;
  ==============================;
  background:linear-gradient(#fb3 50%, #5ba 0);
  background-size: 100% 30px;
">
  background:linear-gradient(#fb3 50%, #5ba 0);<br>
  background-size: 100% 30px;
</div>
</center>
