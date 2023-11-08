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

let ans = 0;
array.forEach((data, idx)=> {
  if(idx===0) return;

  const arr = data.split(' ')

  const students = Number(arr[0]);
  const apples = Number(arr[1]);
  const residue = apples%students;
  ans += residue;
})

console.log(ans);
    
// 답안지 종료
  process.exit();
})