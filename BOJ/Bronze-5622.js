const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const array = line.split('');
  let timeNeeded = 0;
  for(let i=0; i<array.length; i++){
    if((array[i] !== "S" && array[i] !=="V" && array[i] !=="Y" && array[i] !=="Z")){
      timeNeeded += Math.floor((array[i].charCodeAt(0)-65)/3) + 3;
    }else if(array[i] === "S"){
      timeNeeded += 8;
    }else if(array[i] === "V"){
      timeNeeded += 9;
    }else if((array[i] === "Y" || array[i] ==="Z")){
      timeNeeded += 10;
    }
  }
  console.log(timeNeeded);
}).on('close', () => {
  process.exit();
})