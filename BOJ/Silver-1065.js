const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const num = parseInt(line);
  let total = 99;
  const array = String(num).split('');
  let count = 0;
  if(num<100){
    console.log(num);
  }else{
    for(let i = num; i>99; i--){
      if(i===1000) continue;
      const arr = String(i).split('');
      if(arr[0]-arr[1]===arr[1]-arr[2]){
        count++;
      }
    }
    console.log(total+count);
  }
}).on('close', () => {
  process.exit();
})