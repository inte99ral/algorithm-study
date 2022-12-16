const input = {
  readLine: (() => {
    this.fullLine = require("fs")
      .readFileSync("./input.txt")
      .toString()
      .split(/\r\n|\r|\n/gm);
    this.lineIndex = 0;

    return () => this.fullLine[this.lineIndex++];
  })(),
};

let output = 0;
input
  .readLine()
  .split(" ")
  .map((item) => {
    output += Number(item);
  });

console.log(output.toString());
