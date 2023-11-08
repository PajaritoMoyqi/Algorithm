const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
const numArr = array[0].split(' ');
const deudNum = parseInt(numArr[0]);
const boNum = parseInt(numArr[1]);

array.shift();
array.sort();

let res = '';
let count = 0;
for(let i=0;i<deudNum+boNum;i++){
  if(array[i]===array[i+1]){
    count++;
    res = res + array[i] + '\n';
  }
}

console.log(count + '\n' + res.trim());
  process.exit();
})