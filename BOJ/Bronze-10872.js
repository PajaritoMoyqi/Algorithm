const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const a = parseInt(line);
  function factorial(num){
    if(num<2){
      return 1;
    }else{
      return factorial(num-1)*num;
    }
  }
  console.log(factorial(a));
}).on('close', () => {
  process.exit();
})