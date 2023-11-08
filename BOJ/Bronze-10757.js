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

const arrayNums = array[0].split(' ')
console.log((BigInt(arrayNums[0])+BigInt(arrayNums[1])).toString())
    
// 답안지 종료
  process.exit();
})