const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
array.push(line);
}).on('close', () => {
let count = 0;
for(let i=0; i<array.length; i++){
  const num1 = [0,2,4,6];
  const num2 = [1,3,5,7];

  if(i%2===0){
    for(let j of num1){
      if(array[i].charAt(j)==='F'){
        count++;
      }
    }
  }else{
    for(let j of num2){
      if(array[i].charAt(j)==='F'){
        count++;
      }
    }
  }
}
console.log(count);
  process.exit();
})