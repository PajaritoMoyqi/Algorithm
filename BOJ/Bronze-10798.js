const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {

array.push(line);

}).on('close', () => {
    
const num1 = array.length;
const arr = array.slice();

array.sort(function(a,b){return a.length-b.length});
const num2 = array[num1-1].length;

let res = '';
for(let j=0;j<num2;j++){
  for(let i=0;i<num1;i++){
    if(!arr[i]) continue;
    res += arr[i].charAt(j);
  }
}

console.log(res)
    
process.exit();
})