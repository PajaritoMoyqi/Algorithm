const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const arr = line.split(' ');
  const startMoney = parseInt(arr[0]);
  const getMoney = parseInt(arr[2]) - parseInt(arr[1]);
  let profit = startMoney;

  if(getMoney<=0){
    console.log(-1);
  }else{
    console.log(Math.floor(startMoney/getMoney)+1);
  }
}).on('close', () => {
  process.exit();
})