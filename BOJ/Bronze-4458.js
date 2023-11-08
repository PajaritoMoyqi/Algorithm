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
  if(array[i].charAt(0)===array[i].charAt(0).toUpperCase()){
    console.log(array[i]);
    continue;
  }
  const ar = array[i].replace(/[a-z]/, array[i].charAt(0).toUpperCase());
  console.log(ar);
}
process.exit();
})