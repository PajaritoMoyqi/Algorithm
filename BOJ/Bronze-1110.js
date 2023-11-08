const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  let num = line;
  if(num.length<2) num = "0"+num;
  let count = 0;
  let newNumber = num;
  let result = '';
  for(let i=1;;i++){
    const array = newNumber.split('');
    const lastNum = array[1];
    result = String(parseInt(array[0])+parseInt(array[1])).split('').pop()
    newNumber = lastNum+result;
    if(newNumber===num){
      console.log(i);
      break;
    }
  }  
}).on('close', () => {
  process.exit();
})