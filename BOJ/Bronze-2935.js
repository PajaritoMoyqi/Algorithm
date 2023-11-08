const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});
const array = [];
rl.on('line', line => {
array.push(line);
}).on('close', () => {
const n = parseInt(array[0].length)-1;
const m = parseInt(array[2].length)-1;
let res = '1';
if(array[1]==='*'){
  for(i=0;i<n+m;i++){
    res += '0';
  }
}else if(array[1]==='+'){
  if(n===m){
    res = '2';
    for(i=0;i<n;i++){
      res += '0';
    }
  }else if(n>m){
    for(i=0;i<n;i++){
      if(i===n-m-1){
        res += '1'
      }else{
        res += '0';
      }
    }
  }else if(m>n){
    for(i=0;i<m;i++){
      if(i===m-n-1){
        res += '1'
      }else{
        res += '0';
      }
    }
  }
}
console.log(res);
  process.exit();
})