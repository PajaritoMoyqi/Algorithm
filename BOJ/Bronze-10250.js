const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const array = [];
rl.on('line', line => {
  array.push(line);
}).on('close', () => {

const num = parseInt(array[0]);
for(let i=1;i<num+1;i++){
  const arr = array[i].split(' ');
  const height = parseInt(arr[0]);
  const hostNum = parseInt(arr[2]);
  let roomNumStr = String(Math.ceil(hostNum/height));
  if(roomNumStr.length===1){
    roomNumStr = "0" + roomNumStr
  }
  let roomFloor = '';
  if(hostNum%height===0){
    roomFloor = String(height);
  }else{
    roomFloor = String(hostNum%height)
  }
  console.log(parseInt(roomFloor+roomNumStr));
}
  process.exit();
})