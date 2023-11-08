const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {

const set = new Set();

const numArr = array[0].split(' ');
const deudNum = parseInt(numArr[0]);
const boNum = parseInt(numArr[1]);

array.shift();
let count=0;
for(let i=0;i<deudNum;i++){
  set.add(array[i]);
}
for(let i=deudNum;i<deudNum+boNum;i++){
  if(set.has(array[i])) count++;
}

console.log(count);
    
  process.exit();
})