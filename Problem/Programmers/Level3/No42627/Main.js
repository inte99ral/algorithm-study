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
let total = 0;
let maxTotal = 0;
let mean = 0;
let order = [];

const solution = (jobs) => {
  console.log('[jobs]: ', jobs);
  console.log('[jobs]: ', jobs[0][1]);

  for (let i = 0; i < jobs.length; i++) {
    order.push(i);
  }

  for (let i = 0; i < order.length; i++)
    total += jobs[order[i]][1] * (order.length - i) - jobs[order[i]][0];

  mean = parseInt(total / jobs.length);

  return mean;
};

const perm = (index, length) => {
 if()
};

// Answer ====================
console.log('[answer]: ', solution(jobs));
