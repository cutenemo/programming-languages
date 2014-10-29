(* Programming Languages, University of Washington, Dan Grossman *)
(* Type Inference *)

(* Over constrained system => error, un-constrained => polymorphic types *)
(* languages can have type inference without type variables *)
(* languages can have type variables without type variables (java) *)

(*
step 1: length T1 -> T2
step 2: xs: T1
step 3: T2: int (since [] -> 0)
step 4: x: T3, xs: T3 list
step 5: T1: T3 list (since we're calling recursively length xs)
finally: f: 'a list -> int
*)

fun length xs = 
	case xs of
		[] => 0
		| x::xs => 1 + (length xs)
