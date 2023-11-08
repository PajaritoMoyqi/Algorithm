const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const arr = line.split(' ');
  const hour = parseInt(arr[0]);
  const min = parseInt(arr[1]);
  if(min>=45){
    console.log(`${hour} ${min-45}`);
  }else{
    if(hour!==0){
      console.log(`${hour-1} ${min+15}`);
    }else{
      console.log(`23 ${min+15}`);
    }
  }
}).on('close', () => {
  process.exit();
})