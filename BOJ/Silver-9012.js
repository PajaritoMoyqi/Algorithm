const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
  array.push(line)
}).on('close', () => {

const num = parseInt(array[0]);
for(let i=1;i<=num;i++){
  let aa = array[i];
  while(/\(\)/g.test(aa)){
    aa = aa.replace(/\(\)/g, '');
  }
  if(aa.length===0) console.log('YES');
  else console.log('NO');
}

  process.exit();
})