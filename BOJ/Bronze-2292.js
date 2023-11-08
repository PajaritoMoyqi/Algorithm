const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const num = parseInt(line);

  function bee(i){
    return 1+6*i*(i-1)/2
  }

  for(let i=1;;i++){
    if(num<=bee(i)){
      console.log(i);
      break;
    }
  }
}).on('close', () => {
  process.exit();
})