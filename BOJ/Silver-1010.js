const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
    
const factorial = num => {
  if(num == 0) return 1;
  else return num * factorial(num -1);
}

array.forEach((numStr, i)=>{
  if(i===0) return;
  else {
    let result;
    const numsArr = numStr.split(' ')
    const dif = Number(numsArr[1])-Number(numsArr[0])
    if(dif===0) result = 1
    else {
      result = Math.round(factorial(Number(numsArr[1]))/(factorial(Number(numsArr[0]))*factorial(dif)))
    }
    console.log(result);
  }
});
    
  process.exit();
})