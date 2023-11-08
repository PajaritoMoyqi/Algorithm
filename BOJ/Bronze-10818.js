const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
  const num = parseInt(array[0]);
  const arr = array[1].split(' ').map(el => parseInt(el));
  arr.sort(function(a,b){
    return a-b;
  })
  console.log(arr[0] + ' ' + arr[arr.length-1]);
  process.exit();
})