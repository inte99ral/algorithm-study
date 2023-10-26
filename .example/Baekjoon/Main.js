const input = {
  fullLine: () => this.fullLine,
  hasMoreLines: () => !!this.fullLine[this.lineIndex],
  readLine: (() => {
    this.lineIndex = 0;
    this.fullLine = require('fs')
      // .readFileSync('dev/stdin') // -- 백준 입력 코드
      .readFileSync('input.txt') // -- 로컬 input.txt 입력 코드
      .toString()
      .split(/\r\n|\r|\n/gm);

    return () => this.fullLine[this.lineIndex++];
  })(),
};

while (input.hasMoreLines()) {
  console.log(input.readLine());
}
