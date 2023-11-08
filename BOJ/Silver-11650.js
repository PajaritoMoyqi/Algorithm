const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

input.shift();
const array = input.map(raw =>
  raw.split(' ').map(num => parseInt(num))
);

let results = '';
array.sort((a, b) => {
  if (a[0] !== b[0]) {
    return a[0] - b[0];
  }
  return a[1] - b[1];
}).forEach(pos => {
  results += `${pos[0]} ${pos[1]}\n`;
});

console.log(results);