const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
array.push(line);
}).on('close', () => {
  const arr1 = array[0];
  const arr2 = array[1];
  if(arr1.length<arr2.length){
    console.log('no');
  }else if(arr1.length>=arr2.length){
    console.log('go');
  }
  process.exit();
})