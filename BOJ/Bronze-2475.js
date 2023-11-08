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
    
const nums = array[0].split(' ').map(v=>v*v).reduce((acc, cur)=>acc+cur)%10
console.log(nums)

// 답안지 종료
  process.exit();
})