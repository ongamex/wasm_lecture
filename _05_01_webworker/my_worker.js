self.onmessage = function(message) {
    console.log(message.data);

    let sum = 0;
    for(let t = 0; t < 5000000000; t++) {
        sum += 1;
    }

    let i64ArrShared = new BigInt64Array(message.data);
    Atomics.store(i64ArrShared, 0, BigInt(1));
    Atomics.store(i64ArrShared, 1, BigInt(sum));

    self.postMessage(sum);
}