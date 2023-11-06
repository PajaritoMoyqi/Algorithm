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

console.log(':fan::fan::fan:');
console.log(`:fan::${array[0]}::fan:`);
console.log(':fan::fan::fan:');


// 답안지 종료
  process.exit();
})