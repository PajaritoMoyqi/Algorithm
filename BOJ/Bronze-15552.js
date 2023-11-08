const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let res = '';
rl.on('line', line => {
  const arr = line.split(' ');
  if(arr.length === 2){
    const a = parseInt(arr[0]);
    const b = parseInt(arr[1]);
    res += a+b + '\n';
  }
}).on('close', () => {
  console.log(res);
  process.exit();
})