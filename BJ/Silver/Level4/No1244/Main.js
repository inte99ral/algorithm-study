const input = {
    hasNextLine: () => !!this.fullLine[this.lineIndex],
    readLine: (() => {
        this.lineIndex = 0;
        this.fullLine = require('fs').readFileSync('input.txt').toString().split(/\r\n|\n|\r/gm);
        return () => this.fullLine[this.lineIndex];
    })(),
}

const switchLen = input.readLine();
const switchArr = [];