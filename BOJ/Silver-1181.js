const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
array.push(line);
}).on('close', () => {
array.shift();
const sortedArray = array.sort((a, b) => a.length - b.length || a.localeCompare(b));
const uniqueArray = new Set(sortedArray);
console.log(Array.from(uniqueArray).join('\n'));
  process.exit();
})