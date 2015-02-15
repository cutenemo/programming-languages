// Playground - noun: a place where people can play

import UIKit

var x = 4.3
var y = 5.2

// 0.0: An example of passing the function multiply to perform operation in operate
func multiply(opt1: Double, opt2: Double) -> Double {
    return opt1 * opt2
}

func performOperation(operation: (Double, Double) -> Double) {
    var value : Double = operation(x, y)
    println(value)
}

func operate0(operation: Character) {
    switch(operation) {
    case "*": performOperation(multiply)
    default: break
    }
}
operate0("*")

// 1.0: Simplify move multiply inside performOperation, note the location of the curly braces

func operate1(operation: Character) {
    switch(operation) {
    case "*": performOperation({ (opt1: Double, opt2: Double) -> Double in
        return opt1 * opt2 })
    default: break
    }
}

// 2.0: Simplify by removing the types, type inference will do it

func operate2(operation: Character) {
    switch(operation) {
    case "*": performOperation({ (opt1, opt2) in return opt1 * opt2 })
    default: break
    }
}

// 3.0: Simplify by removing the return keyword

func operate3(operation: Character) {
    switch(operation) {
    case "*": performOperation({ (opt1, opt2) in opt1 * opt2 })
    default: break
    }
}

// 4.0: we don't need named paramters

func operate4(operation: Character) {
    switch(operation) {
    case "*": performOperation({ $0 * $1 })
    default: break
    }
}

// 5.0: since the last argument is the closure operation in performOperation,
// we can change performOperation({ $0 * $1 }) to performOperation() { $0 * $1 }

func operate5(operation: Character) {
    switch(operation) {
    case "*": performOperation() { $0 * $1 }
    default: break
    }
}

// 6.0: change performOperation() { $0 * $1 } to performOperation { $0 * $1 } (currying!)

func operate(operation: Character) {
    switch(operation) {
    case "*": performOperation { $0 * $1 }
    default: break
    }
}
