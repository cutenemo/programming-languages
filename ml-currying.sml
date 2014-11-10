(* Source: Coursera: Programming Languages, Dan Grossman, University of Washington *)

(* Currying is named after a logician named Haskell Curry who studied related ideas *)

(* Curried functions take arguments sequentially, returning a function after each 
argument until the function body is fully evaluated. *)

(* the old way. ML functions take exactly one argument encoded as an n-tuple *)
fun sorted_tuple(x, y, z) = z >= y andalso y >= x
val x1 = sorted_tuple (1, 2, 3)

(* the curry way. one argument at a time: return a function after each arguemnt *)
fun sorted_curry1 x = fn y => fn z => z >= y andalso y >= x
val sorted_curry2 = fn x => fn y => fn z => z >= y andalso y >= x
val x2 = sorted_curry1 1 2 3
val x3 = sorted_curry2 1 2 3

(* If we call sorted_curry 4 we will get a closure that has x in its environment. 
If we then call this closure with 5, we will get a closure that has x and y in 
its environment. If we then call this closure with 6, we will get true 
because 6 is greater than 5 and 5 is greater than 4.*)

(* syntactic sugar for currying, the nicer way of doing currying *)
fun sorted_curry_sugar x y z = z >= y andalso y >= x
val x4 = sorted_curry_sugar 1 2 3