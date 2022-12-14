const input = {
	fullLine: () => this.fullLine,
	hasMoreLines: () => !!this.fullLine[this.lineIndex],
	readLine: (() => {
		this.lineIndex = 0;
		// 백준 인식 코드
		// this.fullLine = require('fs').readFileSync('/dev/stdin').toString().split(/\r\n|\r|\n/gm);
		this.fullLine = require('fs').readFileSync('input.txt').toString().split(/\r\n|\r|\n/gm);

		return () => this.fullLine[this.lineIndex++];
	})(),
}

while(input.hasMoreLines()) {
	console.log(input.readLine());
}


