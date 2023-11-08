const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
  const a = parseInt(array[0]);
  const b = parseInt(array[1]);
  console.log(a+b);
  process.exit();
})