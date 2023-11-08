const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {

const num1 = line.split(' ')[0].split('').map(el=>parseInt(el));
const num2 = line.split(' ')[1].split('').map(el=>parseInt(el));

let sum = 0;

for(let j=0;j<num2.length;j++){
  const sumArr = num1.reduce((acc,el)=> {return acc + el*num2[j]},0);
  sum+=sumArr
}
console.log(sum);

}).on('close', () => {
  process.exit();
})