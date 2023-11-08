const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];

rl.on('line', line => {
  array.push(line);
}).on('close', () => {

const rank = [];
const num = parseInt(array.shift());
const array2 = array.map(el => el.split(' ').map(num => parseInt(num)));

for(let i=0; i<num; i++){
  let count = 0;
  for(let j=0; j<num ;j++){
    if(i!==j){
      if(array2[i][0]<array2[j][0]&&array2[i][1]<array2[j][1]){
        count++;
      }
    }
  }
  rank.push(count+1);
}
console.log(rank.join(' '))

  process.exit();
})