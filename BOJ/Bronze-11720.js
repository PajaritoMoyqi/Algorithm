const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});
let sum = 0;
const array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
  const target = array[1];
  arr = target.split('');
  arr.forEach(element => {
    sum += parseInt(element);
  });
  console.log(sum)
  process.exit();
})