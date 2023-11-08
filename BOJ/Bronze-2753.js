const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const a = parseInt(line);
  if(a%4 != 0){
    console.log(0);
  }else{
    if(a%400 == 0){
      console.log(1);
    }else if(a%100 == 0){
      console.log(0);
    }else{
      console.log(1);
    }
  }
}).on('close', () => {
  process.exit();
})