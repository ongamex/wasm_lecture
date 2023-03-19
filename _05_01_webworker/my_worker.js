self.onmessage = function(message) {
    console.log(message.data);

    let sum = 0;
    for(let t = 0; t < 5000000000; t++) {
        sum += 1;
    }

    self.postMessage(sum);
}