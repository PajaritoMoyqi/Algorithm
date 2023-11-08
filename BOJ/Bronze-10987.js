const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
let array = line.split('');
let count = 0;

for(let i=0;i<array.length;i++){
  if(array[i]==='a'||array[i]==='u'||array[i]==='i'||array[i]==='o'||array[i]==='e'){
    count++;
  }
}
console.log(count);
}).on('close', () => {
  process.exit();
})