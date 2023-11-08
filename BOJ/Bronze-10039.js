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
    
console.log(array.map(el=>(Number(el)>40) ? Number(el)/5 : 8).reduce((acc, cur)=> acc + cur));

// 답안지 종료
  process.exit();
})