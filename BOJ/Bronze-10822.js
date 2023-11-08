const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const a = line;
  const arr = a.split(',');
  let sum = 0;
  arr.forEach(elem => {
    sum += parseInt(elem);
  })
  console.log(sum);
}).on('close', () => {
  process.exit();
})