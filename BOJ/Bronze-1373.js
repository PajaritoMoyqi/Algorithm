const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim();

let res = "";
while (input.length >= 3) {
  res = parseInt(input.slice(input.length-3), 2).toString(8) + res;
  input = input.slice(0, input.length-3);
}
console.log((input ? parseInt(input, 2).toString(8) : "") + res);