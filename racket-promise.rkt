#lang racket

;; returns a mutable pair (false/thunk)
(define (my-delay th)
  (mcons #f th))

;; call my-force on the return pair (false/thunk) which is called a promise
(define (my-force p)
  (if (mcar p) ;; if the car of the promise is true
      (mcdr p) ;; return the cdr of the promise
      (begin (set-mcar! p #t) ;; set the car of the promise to true (evaluated)
             (set-mcdr! p ((mcdr p))) ;; the cdr holds the result now of the thunk!
             (mcdr p )))) ;; and then we return the result


