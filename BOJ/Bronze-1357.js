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
    
const numbers = array[0].split(' ');
const num1 = numbers[0];
const num2 = numbers[1];

const reverseNum = str => {
  if(typeof str === 'number') str = String(str);
  return Number(str.split('').reverse().join(''));
}

console.log(reverseNum(reverseNum(num1)+reverseNum(num2)));

// 답안지 종료
  process.exit();
})