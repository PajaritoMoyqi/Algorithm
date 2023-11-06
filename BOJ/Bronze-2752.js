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
    
const nums = array[0].split(' ').map(num => Number(num)).sort((a,b)=>a-b).join(' ')
console.log(nums)

// 답안지 종료
  process.exit();
})