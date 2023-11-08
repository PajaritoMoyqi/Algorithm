const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
  const res = parseInt(array[0])*parseInt(array[1])*parseInt(array[2]);

  const obj = {};
  for(const item of String(res)){
    if(!obj[item]){
      obj[item] = 0;
    }
    obj[item] += 1;
  }

  function print(obj){
    for(let i=0;i<10;i++){
      if(!obj[i]){
        console.log(0);
      }else{
        console.log(obj[i]);
      }
    }
  }
  print(obj);
  process.exit();
})