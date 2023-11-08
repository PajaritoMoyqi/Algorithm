const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {
  let total = 0
  const num = parseInt(array[0]);
  const scores = array[1].split(' ').map(el => parseInt(el)).sort(function(a, b){
    return a-b;
  })
  scores.forEach(el => {
    total += el;
  })
  const avg = total/num;
  console.log(avg*100/scores.pop());
  process.exit();
})