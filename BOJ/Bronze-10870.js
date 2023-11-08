const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


rl.on('line', line => {
function piv(n){
  if(n===0){
    return 0;
  }else if(n===1){
    return 1;
  }else{
    return piv(n-1)+piv(n-2);
  }
}

console.log(piv(parseInt(line)));
}).on('close', () => {
  process.exit();
})    