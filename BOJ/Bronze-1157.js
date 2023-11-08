const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const obj = {};
  for(const item of line.toUpperCase()){
    if(!obj[item]){
      obj[item] = 0;
    }
    obj[item] += 1;
  }
  const arrKey = Object.keys(obj);
  const arrValue = Object.values(obj);
  const arrValue2 = Object.values(obj);


  const num = arrValue.sort(function(a, b){return a-b;}).pop();
  if(arrValue2.indexOf(num)===arrValue2.lastIndexOf(num)){
    console.log(arrKey[arrValue2.indexOf(num)]);
  }else{
    console.log('?');
  }
}).on('close', () => {
  process.exit();
})