const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
  const arr = array.slice();
  arr.forEach(el => parseInt(el));
  arr.sort(function(a,b){return a-b;})
  const val = arr.pop();
  console.log(parseInt(val));
  console.log(array.indexOf(val)+1);
})