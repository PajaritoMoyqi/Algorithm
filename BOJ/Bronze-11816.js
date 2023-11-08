const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
let array = line.split('');
if(array[0]==='0'){
  if(array[1]==='x'){
    array.shift();
    array.shift();
    const num = array.join('');
    console.log(parseInt(num, 16));
  }else{
    array.shift();
    const num = parseInt(array.join(''));
    console.log(parseInt(num, 8));
  }
}else{
  console.log(parseInt(line));
}
}).on('close', () => {
  process.exit();
})