(define-library (picrin control list)
  (import (scheme base)
          (picrin control))

  (define-syntax for
    (syntax-rules ()
      ((_ expr ...)
       (reset expr ...))))

  (define (in m)
    (shift k (apply append (map k m))))

  (define (yield x)
    (list x))

  (define (null . x)
    '())

  (export for in yield null))
