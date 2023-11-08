const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


rl.on('line', line => {
const array = [];
for(let i=0;i<line.length;i++){
  array.push(line.substring(i,line.length));
}
array.sort()
let res = '';
for(let i=0;i<array.length;i++){
  res=res+array[i]+'\n';
}
console.log(res.trim());
}).on('close', () => {
  process.exit();
})