const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {  
  array.push(line);
}).on('close', () => {
const num = array[0];
const arr = [];
for(let i=1;i<=num;i++){
  arr.push(array[i]);
}

arr.sort(function(a,b){return a-b});
for(let i=0;i<num;i++){
  console.log(arr.shift());
}
  process.exit();
})