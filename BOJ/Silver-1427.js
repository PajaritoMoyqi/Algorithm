const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
const array = line.split('');
array.sort(function(a,b){return b-a});
console.log(array.join(''));
}).on('close', () => {
  process.exit();
})