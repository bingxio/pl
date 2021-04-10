; Basic Syntax
(write-line "Hello LISP!")	; Hello LISP!
(write "Hello LISP!")		; "Hello LISP!"
(write-line " ")		; NEW LINE
(write '(* 2 3))		; (* 2 3)

; Data Type
(setq x 10)
(setq y 3.2)
(setq z nil)
(setq a 11.0e+4)
(setq b 12/4)
(setq c "OK")
(setq p 's)

(print x)	; 10
(print y)	; 3.2
(print z)	; NIL
(print a)	; 110000.0
(print b)	; 3
(print c)	; "OK"
(print p)	; S

(print (type-of x))	; INTEGER
(print (type-of y))	; SINGLE-FLOAT
(print (type-of z))	; NULL
(print (type-of a))	; SINGLE-FLOAT
(print (type-of b))	; INTEGER
(print (type-of c))	; SIMPLE-BASE-STRING
(print (type-of p))	; SYMBOL

; Macro
(defmacro setTo(num)	; Set num to 10 and print
  (setq num 10)
  (print num))
(setq x 25)
(print x)		; 25
(setTo x)

; Variable
(defvar k 20)
(format t "k = ~d" k)	; 20
(write-line "")		; NEW LINW
(format t "x = ~2d y = ~2d ~%" x x)

(let ((x 'a)
      (y 'b)
      (z 'c))
(format t "x = ~a y = ~a z = ~a ~%" x y z))

(let ((a '(a b c))
      (b '(1 2 3)))
(format t "a = ~a b = ~a" a b))

(defconstant PI 3.141592)
(defun area-circle(rad)
  (terpri)
  (format t "Radius: ~5f" rad)
  (format t "~%Area: ~10f" (* PI rad rad)))
(area-circle 43)

; Operator
(setq a 10)
(setq b 20)

(write-line "")

(format t "A + B = ~d~%" (+ a b))
(format t "A - B = ~d~%" (- a b))
(format t "A * B = ~d~%" (* a b))
(format t "B / A = ~d~%" (/ b a))
(format t "A incf 2 = ~d~%" (incf a 2))
(format t "A decf 2 = ~d~%" (decf a 4))

(format t "A = B = ~d~%" (= a b))
(format t "A /= B = ~d~%" (/= a b))
(format t "A > B = ~d~%" (> a b))
(format t "A < B = ~d~%" (< a b))
(format t "A >= B = ~d~%" (>= a b))
(format t "A <= B = ~d~%" (<= a b))
(format t "Max A B = ~d~%" (max a b))
(format t "Min A B = ~d~%" (min a b))

(format t "A and B = ~a~%" (and a b))
(format t "A or B = ~a~%" (or a b))
(format t "not A is ~a~%" (not a))

; Condition
(setq a 10)
(cond ((> a 20)
       (format t "a is less than 20"))
      (t (format t "value of a is ~d~%" a)))
(if (< a 20)
  	(format t "a is less than 20~%")
		(format t "a is greater than 20~%"))
(when (> a 5)
  (format t "a is greater than 5~%"))
(setq d 4)
(case d
  (1 (print "A"))
  (2 (print "B"))
  (3 (print "C"))
  (4 (print "D")))

(write-line "")

; Loop
(setq x 10)
(loop(write x)
  (setq x (+ x 1))
  (terpri)
  (when (> x 20)
    (return a)))
(loop for x in '(tom dick harry)
      do (format t "~s " x))
(loop for x from 10 to 20
	do (print x))
(loop for x from 1 to 50
      if (evenp x)
      do (format t "~d " x))
(write-line "")
(do ((x 0 (+ 2 x))
	(y 20 (- y 2)))
     ((= x y) (- x y))
     (format t "x = ~d y = ~d ~%" x y))
(dotimes (n 11)
  (print n) (prin1 (* n n)))
(write-line "")
(dolist (n '(1 2 3 4 5 6 7 8))
  (format t "number: ~d square: ~d ~%" n (* n n)))
