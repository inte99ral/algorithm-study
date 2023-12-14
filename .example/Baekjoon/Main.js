/**
 * node Main.js
 */

// -- Reader Object ==================
const reader = {
  fullLine: () => this.fullLine,
  hasMoreLines: () => !!this.fullLine[this.lineIndex],
  readLine: (() => {
    this.lineIndex = 0;
    this.fullLine = require('fs')
      // .readFileSync('dev/stdin') // -- 백준 입력 코드
      .readFileSync('question/input.txt') // -- 로컬 input.txt 입력 코드
      .toString()
      .split(/\r\n|\r|\n/gm);

    return () => this.fullLine[this.lineIndex++];
  })(),
};

// -- String line
// while (reader.hasMoreLines()) console.log(reader.readLine());

// -- Int Array
let input = [];
let iter = reader.readLine().matchAll(/[0-9]+/g);
for (let curr = iter.next(); !curr.done; curr = iter.next()) input.push(curr.value[0]);

input.forEach((e) => console.log(e));
