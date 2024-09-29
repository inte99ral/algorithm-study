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

const getPerm = (arr, len) => {
  const output = [];
  if (len === 1) return arr.map((el) => [el]);
  // n개중에서 1개 선택할 때(nP1), 바로 모든 배열의 원소 return. 1개선택이므로 순서가 의미없음.

  arr.forEach((fixed, index, origin) => {
    const rest = [...origin.slice(0, index), ...origin.slice(index + 1)];

    const perm = getPerm(rest, len - 1);

    const attached = perm.map((el) => [fixed, ...el]);

    output.push(...attached);
  });

  return output; // 결과 담긴 results return
};

// Answer ====================
console.log('[answer]: ', solution(jobs));
console.log('[answer]: ', getPerm(jobs, 3));
