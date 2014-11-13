; Coursera - UW - Dan Grossman
; notes

; static checking happens after parsing and before runtime
; it is part of the language definition 
; The most common way to define a language’s static checking is via a type system

; example
; preventing 3 / 0 can happen at
; 0) in the editor
; 1) compile time (Racket)
; 2) link time (let it pass when checking individual files, disallow it later if may gets called in main)
; 3) run time (ML)
; 4) later! return Inf

#lang racket
(define x (/ 3 0)) ;  /: division by zero
