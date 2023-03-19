const worker = new Worker("my_worker.js");
let sab = new SharedArrayBuffer(BigInt64Array.BYTES_PER_ELEMENT * 2);

document.getElementById("changeBgColor").addEventListener("click", changeBgColor);
document.getElementById("computeOnPage").addEventListener("click", computeSumInPage);
document.getElementById("computeInWorker").addEventListener("click", computeSumInWorker);

worker.onmessage = function(message) {
    document.getElementById("log").innerHTML += "Web-Worker sum is: " + message.data + "</br>";
    console.log("Serial sum is: " + message.data);

    let i64ArrShared = new BigInt64Array(sab);

    document.getElementById("log").innerHTML += "sab[0] = " + i64ArrShared[0] + "</br>";
    document.getElementById("log").innerHTML += "sab[1] = " + i64ArrShared[1] + "</br>";
}

function computeSumInPage(event) {
    let sum = 0;
    for(let t = 0; t < 5000000000; t++) {
        sum += 1;
    }
    
    document.getElementById("log").innerHTML += "Serial sum is: " + sum + "</br>";
    console.log("Serial sum is: " + sum);
}

function computeSumInWorker(event) {
    sab[0] = 0;
    worker.postMessage(sab);


}

function changeBgColor(event) {
    if(document.body.style.background == "white") {
        document.body.style.background = "BlanchedAlmond";
    } else {
        document.body.style.background = "white";
    }
}
