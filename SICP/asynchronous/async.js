const { asyncify } = require("async");

async function exec(callback) {
  setTimeout(() => {
    console.log("DONE.");
    callback(1);
  }, 3000);
}

console.log("START!!");

asyncify.bind(
  exec((val) => {
    console.log("END " + val);
  })
);
