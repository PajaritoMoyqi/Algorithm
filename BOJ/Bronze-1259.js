const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];

rl.on('line', line => {
  array.push(line);
}).on('close', () => {

array.pop();

for(let i=0;i<array.length;i++){
  const arr = array[i].split('');
  const strRev = arr.reverse().join('');
  if(strRev===array[i]){
    console.log('yes');
  }else{
    console.log('no');
  }
}

  process.exit();
})