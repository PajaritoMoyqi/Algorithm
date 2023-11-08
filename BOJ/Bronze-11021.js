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

  for(i=1; i<=num; i++){
    const arr = array[i].split(' ');
    const a = parseInt(arr[0]);
    const b = parseInt(arr[1]);
    console.log(`Case #${i}: ${a+b}`);
  }
  process.exit();
})