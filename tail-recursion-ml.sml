(* Source: Coursera: Programming Languages, Dan Grossman, University of Washington *)

fun sum1 xs =
    case xs of
        [] => 0
      | i::xs => i + sum1 xs
(* in the first case, we are calling sum1 recursively but note that 
   when we come back, we need to add i before finally returning. (extra work)
   So for sum1, there will be one call-stack element “stack frame”
   for each recursive call to sum1, i.e., the stack will be as big as the list. 
   and it's all because 
   *)    
      
fun sum2 xs =
    let fun f (xs, acc) =
        case xs of
            [] => acc
            | i::xs => f(xs, i + acc)
    in
        f(xs, 0)
    end
(* tail recursion is accomplished by making sure the recursive call is the last
   thing we will do before we return (a tail call) When a call is a tail call, 
   the caller’s stack-frame is popped before the call the callee’s stack-frame 
   just replaces the caller’s. This makes sense: the caller was just going to 
   return the callee’s result anyway. Therefore, calls to sum2 never use more 
   than 1 stack frame.
*)   
