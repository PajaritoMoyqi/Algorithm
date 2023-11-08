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
    
array.forEach((num, idx) => {
  if(idx===0) return;

  const res = num.split(' ').map(v=>Number(v)).reduce((acc,cur)=>acc+cur);
  console.log(`Case ${idx}: ${res}`)
})

// 답안지 종료
  process.exit();
})