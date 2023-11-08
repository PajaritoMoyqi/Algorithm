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
for(let i=1;i<=num;i++){
  const arr = array[i].split(',')
  console.log(parseInt(arr[1])+parseInt(arr[0]));
}
  process.exit();
})