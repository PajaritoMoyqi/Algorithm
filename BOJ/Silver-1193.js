const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const num = parseInt(line);

  function bee(i){
    return (i+1)*i/2;
  }

  for(let i=1;;i++){
    if(num<=bee(i)){
      const dif = bee(i)-num;
      if(i%2===0){
        console.log(String(i-dif)+'/'+String(1+dif));
      }else{
        console.log(String(1+dif)+'/'+String(i-dif));
      }
      break;
    }
  }
}).on('close', () => {
  process.exit();
})