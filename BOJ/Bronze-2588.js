const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
  const num = parseInt(array[0]);
  const arr = array[1].split('');
  const num1 = parseInt(arr[0]);
  const num2 = parseInt(arr[1]);
  const num3 = parseInt(arr[2]);
  const num4 = parseInt(array[1]);

  console.log(num*num3);
  console.log(num*num2);
  console.log(num*num1);
  console.log(num*num4);
  process.exit();
})