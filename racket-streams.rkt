;; my notes from Coursera - Programming Languages - Dan Grossman
#lang racket
(provide (all-defined-out))

;; Streams = infinite sequence of values
;; let a stream be a thunk, when called returns a pair '(next answer . next-thunk) 

;; sequence 1 1 1 1 1 1 ...
;; (car ((cdr (ones))))
(define ones (lambda () (cons 1 ones)))
;; (define ones-bad (lambda () (cons 1 (ones-bad))))) 
;; bad infinite loop! keeps returning the result of the thunk
;; (define ones-really-bad (cons 1 (ones-really-bad)))) ;; we will try to lookuo ones-really-bad

;; (car ((cdr (f 4)))) = 5
;; a function that takes x and returns a pair of (x, f(x+1)) ... (x, x+1, x+2, f(x+3))
(define (f x) (cons x (lambda () (f (+ 1 x)))))
                
;; sequence 1 2 3 4 5 ...
(define natural (lambda () (f 1)))
;; or better style        
(define nats
  (letrec ([f (lambda (x) (cons x (lambda () (f (+ x 1)))))])
    (lambda () (f 1))))

(define powers-of-two
  (letrec ([f (lambda (x) (cons x (lambda () (f (* x 2)))))])
    (lambda () (f 2))))

(define (stream-maker fn arg)
  (letrec ([f (lambda (x) 
                (cons x (lambda () (f (fn x arg)))))])
    (lambda () (f arg))))
(define nats2  (stream-maker + 1))
(define powers2 (stream-maker * 2))

;; code that uses streams

(define (number-until stream tester)
  (letrec ([f (lambda (stream ans) ;; helper function (tail-recursive)
                (let ([pr (stream)])
                  (if (tester (car pr))
                      ans
                      (f (cdr pr) (+ ans 1)))))]) ;; (cdr pr) is the new stream
    (f stream 1))) ;; call helper with acc = 1

(define four (number-until powers-of-two (lambda (x) (= x 16))))