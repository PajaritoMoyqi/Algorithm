const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {

let result = 0;

array.forEach((numStr, i)=>{
  if(i===0) return;
  else {
    let numsArr = numStr.split(' ')
    let res = Number(numsArr[0])*Number(numsArr[1])
    result += res;
  }
});

console.log(result);

  process.exit();
})