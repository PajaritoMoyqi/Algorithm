const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input;
rl.on('line', line => {
  input = line;
  rl.close();
}).on('close', () => {
  // code start
  console.log( Number( input ) * 10 / 11  );

  // code exit
  process.exit();
})