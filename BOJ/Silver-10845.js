const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});
const array = [];
rl.on('line', line => {
array.push(line);
}).on('close', () => {

const num = parseInt(array.shift());

const stack = [];
let res = ''
for(let i=0;i<num;i++){
  if(array[i]==='pop'){
    if(stack.length===0) res = res+'-1'+'\n';
    else res = res+stack.shift()+'\n';
  }else if(array[i]==='size'){
    if(stack.length===0) res = res+'0'+'\n';
    else res = res+stack.length+'\n';
  }else if(array[i]==='empty'){
    if(stack.length===0) res = res+'1'+'\n';
    else res = res+'0'+'\n';
  }else if(array[i]==='back'){
    if(stack.length===0) res = res+'-1'+'\n';
    else res = res+stack[stack.length-1]+'\n';
  }else if(array[i]==='front'){
    if(stack.length===0) res = res+'-1'+'\n';
    else res = res+stack[0]+'\n'
  }else{
    stack.push(parseInt(array[i].substring(5)));
  }
}

console.log(res.trim());
    
  process.exit();
})