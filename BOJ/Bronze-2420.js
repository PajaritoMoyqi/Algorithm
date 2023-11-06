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
    
console.log(Math.abs(Number(array[0].split(' ')[0])-Number(array[0].split(' ')[1])));

// 답안지 종료
  process.exit();
})