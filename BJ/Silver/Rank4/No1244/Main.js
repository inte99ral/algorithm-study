const input = {
  hasNextLine: () => !!this.fullLine[this.lineIndex],
  readLine: (() => {
    this.lineIndex = 0;
    this.fullLine = require('fs').readFileSync('input.txt').toString().split(/\r\n|\n|\r/gm);
    return () => this.fullLine[this.lineIndex++];
  })(),
}

let switchLen;
let switchArr;
let N;
let studentData;

switchLen = Number(input.readLine());
switchArr = [0,];
input.readLine().split(' ').map((item) => {switchArr.push(Number(item))});
N = Number(input.readLine());

for(let n = 0; n < N; n++){
  studentData = [];
  input.readLine().split(' ').map((item) => {studentData.push(Number(item))})

  // 남학생
  if(studentData[0] == 1){
    for(let i = studentData[1]; i <= switchLen; i += studentData[1])
      switchArr[i] = Number(!switchArr[i]);
  }
  // 여학생
  else{
    switchArr[studentData[1]] = Number(!switchArr[studentData[1]]);
    for(let i = 1; i <= switchLen; i++){
      // 범위 이탈
      if(switchArr[studentData[1] - i] == undefined) break;
      if(switchArr[studentData[1] + i] == undefined) break;
      if(switchArr[studentData[1] - i] != switchArr[studentData[1] + i]) break;

      // 값 변경
      switchArr[studentData[1] - i] = Number(!switchArr[studentData[1] - i]);
      switchArr[studentData[1] + i] = Number(!switchArr[studentData[1] + i]);
    }
  }
}

console.log(switchArr.slice(1));