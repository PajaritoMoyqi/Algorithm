const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
const num1 = parseInt(array[0]);
String.prototype.del = function (index){
  return this.substr(0,index) + this.substr(index+1);
}

for(let i=1;i<=num1;i++){
  let arr = array[i].split(' ');
  const res = arr[1].del(parseInt(arr[0])-1);
  console.log(res);
}
  process.exit();
})