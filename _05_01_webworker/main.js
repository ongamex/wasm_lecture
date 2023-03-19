const worker = new Worker("my_worker.js");
		
document.getElementById("changeBgColor").addEventListener("click", changeBgColor);
document.getElementById("computeOnPage").addEventListener("click", computeSumInPage);
document.getElementById("computeInWorker").addEventListener("click", computeSumInWorker);

worker.onmessage = function(message) {
    document.getElementById("log").innerHTML += "Serial sum is: " + message.data + "</br>";
    console.log("Serial sum is: " + message.data);
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
    worker.postMessage("Some data that is copied!");
}


function changeBgColor(event) {
    if(document.body.style.background == "white") {
        document.body.style.background = "BlanchedAlmond";
    } else {
        document.body.style.background = "white";
    }
}
