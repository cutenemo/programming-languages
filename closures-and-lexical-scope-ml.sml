(* Source: Coursera, Programming Languages, UW, Dan Grossman *)

(* CLOSURES *)
(* Functions are values. A function value has two parts, the code for the function 
and the environment that was current when we created the function (definition time). 
This “pair” is called a function closure or just closure. yay *)


(* LEXICAL SCOPE *)
(* Lexical Scope means that the body of a function is evaluated in the environment where 
the function is defined not where the function called (dynamic scope) *)

val x = 1
fun f y = x + y (* This closure icrements y by 1 *)
val x = 2
val y = 3
val z = f (x+y) (* f increments (x+y=5) by 1 so z = 6, thanks lexical scope *)

