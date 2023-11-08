const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


rl.on('line', line => {
const arr = line.split('-');
let res = '';
for(let i=0;i<arr.length;i++){
  res += arr[i].charAt(0);
}

console.log(res);
}).on('close', () => {
  process.exit();
})    