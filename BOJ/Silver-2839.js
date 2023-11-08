const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
const num = parseInt(line);

if(num>9){
  let times = Math.floor(num/5);
  for(let k=1;k<=3;k++){
    const dif = num-5*times
    if(dif%3===0){
      console.log(dif/3+times);
      break;
    }else{
      times--;
    }
  }
}else if(num === 1 || num === 2 || num === 4 || num === 7){
  console.log(-1);
}else if(num === 3 || num === 5){
  console.log(1);
}else if(num === 6 || num === 8){
  console.log(2);
}else if(num === 9){
  console.log(3);
}
}).on('close', () => {
  process.exit();
})