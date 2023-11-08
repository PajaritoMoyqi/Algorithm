const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
// 답안지 시작
    
const today = new Date();
const year = today.getUTCFullYear();
console.log(year);
const month = today.getUTCMonth()+1;
console.log(month);
const date = today.getUTCDate();
console.log(date);

// 답안지 종료
  process.exit();
})