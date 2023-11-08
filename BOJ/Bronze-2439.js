const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  let a = parseInt(line);
  const newOne = new Array(a);
  newOne.fill(' ');
  for(i=a;i>0;i--){
    newOne.shift();
    newOne.push("*");
    let str = newOne.join('');
    console.log(str);
  }
}).on('close', () => {
  process.exit();
})