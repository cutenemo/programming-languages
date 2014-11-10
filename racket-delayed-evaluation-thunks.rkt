;; programming languages - UW - Dan Grossman

;; In if-statements (if e1 e2 e3) we don't evaluate both expressions e2 and e3
;; Function arguments are always evaluated first before the body
;; here we evaluate x, y and z before evaluating the body 

(define (my-if-bad x y z) (if x y z))

;; we re-write this to take advantage of the fact that functions don't
;; get evaluated until they are called, here y and z are functions and so we don't 
;; evaluted them yet until they are called

(define (my-if x y z) (if x (y) (z)))

;; so to delay evaluation we put expressions in function
;; a zero-argument function used to delay evaluation is called a thunk

;; Example
;; e ;; expression
;; (lambda () e) ;; we don't evaluate until gets called, called a thunk
;; (e) ;; the way to call a thunk