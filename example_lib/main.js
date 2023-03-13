Module.onRuntimeInitialized = () => {
    const Sum = Module.cwrap('sum', 'number', ['number', 'number']);
    console.log(Sum(5, 5));
    console.log(Sum(0, 45));
};

// console.log("script main");

// const importObject = {
// 	module: {},
// 	env: {
// 		memory: new WebAssembly.Memory({ initial: 256 }),
// 	}
// };

// let module = {};

// console.log("loadModule()");
// WebAssembly.instantiateStreaming(fetch('example_lib.wasm'), importObject)
// .then(result => {
// 	console.log("module loaded()");
// 	const sum = result.instance.exports.sum;
// 	module.sum = result.instance.exports.sum;
// 	//module.sumWithArgs = result.instance.exports.sumWithArgs;
// 	console.log(sum(4, 5));
// 	console.log(sum(10, 10));
// })
// .catch(reason => {
// 	console.log(`Error exception when loading module:`);
// 	console.log(reason);
// });