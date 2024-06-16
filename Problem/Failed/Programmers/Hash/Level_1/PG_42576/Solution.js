// -- Reader Object ==================
const reader = {
  hasNextLine: () => !!this.fullLine[this.lineIndex],
  readLine: (() => {
    this.lineIndex = 0;
    this.fullLine = require('fs')
      .readFileSync('question/input.txt')
      .toString()
      .split(/\r\n|\n|\r/gm);
    return () => this.fullLine[this.lineIndex++];
  })(),
};

// -- Local Input ====================
let input = [];

let iter = reader.readLine().matchAll(/[0-9]+/g);

for (let curr = iter.next(); !curr.done; curr = iter.next()) {
  input.push([curr.value[0], iter.next().value[0]]);
}

console.log('[answer]: ', solution(input));

// -- Solution =======================
/**
 * node Solution.js
 */
function solution(datas) {
  let answer = 0;

  datas.forEach((e) => {
    console.log(`[${e[0]}, ${e[1]}]`);
  });

  return answer;
}
