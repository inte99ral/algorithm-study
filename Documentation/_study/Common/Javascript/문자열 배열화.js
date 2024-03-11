// Read ====================
const input = {
  hasNextLine: () => !!this.fullLine[this.lineIndex],
  readLine: (() => {
    this.lineIndex = 0;
    this.fullLine = require('fs')
      .readFileSync('input.txt')
      .toString()
      .split(/\r\n|\n|\r/gm);
    return () => this.fullLine[this.lineIndex++];
  })(),
};

// Input ====================
let jobs;

jobs = [];
input
  .readLine()
  .slice(2, -2)
  .split('], [')
  .map((i) => {
    let inputData = [];

    i.split(', ').map((j) => {
      inputData.push(Number(j));
    });

    jobs.push(inputData);
  });

// Solution ====================
function solution(jobs) {
  var answer = 0;
  return answer;
}

// Answer ====================
console.log('[answer]: ', solution(jobs));
