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
    
array.forEach((temp, idx)=>{
  if(temp==999||idx===0) return;
  console.log((parseFloat(array[idx])-parseFloat(array[idx-1])).toFixed(2))
})

// 답안지 종료
  process.exit();
})