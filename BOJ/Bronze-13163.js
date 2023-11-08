const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {

array.push(line);

}).on('close', () => {
const num1 = parseInt(array[0]);

for(let i=1;i<=num1;i++){
  let arr = array[i].split(' ');
  arr[0] = 'god';
  console.log(arr.join(''));
}
process.exit();
})