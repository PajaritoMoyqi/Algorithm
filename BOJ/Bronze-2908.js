const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const arr = line.split(' ');
  const num1 = parseInt(arr[0].split('').reverse().join(''));
  const num2 = parseInt(arr[1].split('').reverse().join(''));
  if(num1>num2){
    console.log(num1);
  }else{
    console.log(num2);
  }
}).on('close', () => {
  process.exit();
})