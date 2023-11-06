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
    
let ans;
array.forEach(el=>{
  if(Number(el.split(' ')[0])%Number(el.split(' ')[1])===0) ans = 'multiple';
  else if(Number(el.split(' ')[1])%Number(el.split(' ')[0])===0) ans = 'factor';
  else ans = 'neither';
  if(el === '0 0') return;
  console.log(ans);
})

// 답안지 종료
  process.exit();
})