const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  let nth = parseInt(line);
  let startNum = 665;

  while(nth>0){
    startNum++;
    if(startNum.toString().includes('666')) nth--;
  }
  console.log(startNum);
}).on('close', () => {
  process.exit();
})