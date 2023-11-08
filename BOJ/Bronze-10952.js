const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
  array.pop();
  const length = array.length;
  for(i=0; i<length; i++){
    let arr = array[i].split(' ')
    const a = parseInt(arr[0]);
    const b = parseInt(arr[1]);
    console.log(a+b);
  }
  process.exit();
})