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

const factorial = (num) => {
  if(num == 0) return 1;
  else return num * factorial(num - 1);
}

let result;
const numsArr = array[0].split(' ')
const dif = Number(numsArr[0])-Number(numsArr[1])
if(dif===0) result = 1
else {
  result = Math.round(factorial(Number(numsArr[0]))/(factorial(Number(numsArr[1]))*factorial(dif)))
}
console.log(result);
    
// 답안지 종료
  process.exit();
})