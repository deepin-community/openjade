<!doctype style-sheet PUBLIC "-//James Clark//DTD DSSSL Style Sheet//EN">
<!-- Copyright (C) 1999 Avi Kivity -->
                 
<![cdata[                
                 
(root
    (test-expression-language)
)

(define (test-expression-language)
    (sosofo-append
        (make-test "Character Primitives" test-char)
	(make-test "Character Properties" test-char-properties)
        (make-test "String Primitives" test-string)
	(make-test "Standard examples" test-examples)
    )
)

(define (test-char)
    (sosofo-append
        (testcase 'char=?      #\a #\b)
        (testcase 'char=?      #\a #\a)
        (testcase 'char=?      #\a #\A)
        (testcase 'char<?      #\a #\b)
        (testcase 'char<?      #\a #\a)
        (testcase 'char<?      #\a #\A)
        (testcase 'char<=?     #\a #\b)
        (testcase 'char<=?     #\a #\a)
        (testcase 'char<=?     #\a #\A)
        (testcase 'char>?      #\a #\b)
        (testcase 'char>?      #\a #\a)
        (testcase 'char>?      #\a #\A)
        (testcase 'char>=?     #\a #\b)
        (testcase 'char>=?     #\a #\a)
        (testcase 'char>=?     #\a #\A)
        (testcase 'char-ci=?   #\a #\b)
        (testcase 'char-ci=?   #\a #\a)
        (testcase 'char-ci=?   #\a #\A)
        (testcase 'char-ci<?   #\a #\b)
        (testcase 'char-ci<?   #\a #\a)
        (testcase 'char-ci<?   #\a #\A)
        (testcase 'char-ci<=?  #\a #\b)
        (testcase 'char-ci<=?  #\a #\a)
        (testcase 'char-ci<=?  #\a #\A)
        (testcase 'char-ci>?   #\a #\b)
        (testcase 'char-ci>?   #\a #\a)
        (testcase 'char-ci>?   #\a #\A)
        (testcase 'char-ci>=?  #\a #\b)
        (testcase 'char-ci>=?  #\a #\a)
        (testcase 'char-ci>=?  #\a #\A)
    )
)

(add-char-properties funny: #\a #\a)
(add-char-properties funny: (char-property 'funny #\a) #\b #\c)
(add-char-properties funny: (char-property 'funny #\z) #\d)
(declare-char-property funny 'boring)
(define (test-char-properties)
    (sosofo-append
        (testcase 'char-property 'space? #\space)
        (testcase 'char-property 'space? #\space 'foo)
	(testcase 'char-property 'space? #\exclamation-mark)
	(testcase 'char-property 'space? #\exclamation-mark 'foo)
        (testcase 'char-property 'break-before-priority #\space)
	(testcase 'char-property 'break-after-priority #\space)
	(testcase 'char-property 'break-before-priority #\a)
	(testcase 'char-property 'break-after-priority #\a)
	(testcase 'char-property 'funny #\a)
	(testcase 'char-property 'funny #\b)
	(testcase 'char-property 'funny #\c)
	(testcase 'char-property 'funny #\d)
	(testcase 'char-property 'funny #\e)
	(testcase 'char-property 'funny #\z)
    ))

(define (test-string)
    (empty-sosofo)
)

(define (test-examples)
    (sosofo-append
        (testcase 'not  #t)
        (testcase 'not  3)
        (testcase 'not  (list 3))
        (testcase 'not  #f)
        (testcase 'not  '())
        (testcase 'not  (list))
        (testcase 'not  'nil)
        (testcase 'boolean?  #f)
        (testcase 'boolean?  0)
        (testcase 'boolean?  '())
        (testcase 'pair?  '(a . b))
        (testcase 'pair?  '(a b c))
        (testcase 'pair?  '())
        (testcase 'cons  'a '())
        (testcase 'cons  '(a) '(b c d))
        (testcase 'cons  "a" '(b c))
        (testcase 'cons  'a 3)
        (testcase 'cons  '(a b) 'c)
	(testcase 'car  '(a b c))
	(testcase 'car  '((a) b c d))
	(testcase 'car  '(1 . 2))
	;(testcase 'car  '()) ;==> error
        (testcase 'cdr	'((a) b c d))
	(testcase 'cdr 	'(1 . 2))
	;(testcase 'cdr  '()) ;==> error
	(testcase 'list?  '(a b c))
	(testcase 'list?  '())
	(testcase 'list?  '(a . b))
	(testcase 'list  'a (+ 3 4) 'c)
	(testcase 'list)
	(testcase 'length  '(a b c))
	(testcase 'length  '(a (b) (c d e)))
	(testcase 'length  '())
	(testcase 'append  '(x) '(y))
	(testcase 'append  '(a) '(b c d))
	(testcase 'append  '(a (b)) '((c))) 	
	(testcase 'append  '(a b) '(c . d)) 	
	(testcase 'append  '() 'a) 	
	(testcase 'reverse  '(a b c))
	(testcase 'reverse  '(a (b c) d (e (f))))
	(testcase 'list-ref  '(a b c d) 2)
	(testcase 'list-ref  '(a b c d) (inexact->exact (round 1.8)))
	(testcase 'member  'a '(a b c))
	(testcase 'member  'b '(a b c))
	(testcase 'member  'a '(b c d))
	(testcase 'assoc  'a '((a 1) (b 2) (c 3)))
	(testcase 'assoc  'b '((a 1) (b 2) (c 3)))
	(testcase 'assoc  'd '((a 1) (b 2) (c 3)))
	(testcase 'symbol?  'foo)
	(testcase 'symbol?  (car '(a b)))
	(testcase 'symbol?  "bar")
	(testcase 'symbol?  'nil)
	(testcase 'symbol?  '())
	(testcase 'symbol?  #f)
	(testcase 'symbol->string  'flying-fish)
	(testcase 'symbol->string (string->symbol "Malvina"))
	(testcase 'equal?  'mISSISSIppi 'mississippi)
	(testcase 'equal?  'bitBlt (string->symbol "bitBlt"))
	(testcase 'equal?  'JollyWog 
		(string->symbol (symbol->string 'JollyWog)))
	(testcase 'string=? "K. Harper, M.D."
		(symbol->string (string->symbol "K. Harper, M.D.")))
	(testcase 'keyword->string  Argentina:)
	(testcase 'string->keyword  "foobar")
	(testcase 'real?  3)
	(testcase 'integer?  3.0)
	(testcase 'max  3 4)
	(testcase 'max  3.9 4)
	(testcase '+  3 4)
	(testcase '+  3)
	(testcase '+) 
	(testcase '*  4)
	(testcase '*)
	(testcase '-  3 4)
	(testcase '-  3 4 5)
	(testcase '-  3)
	(testcase '/  3 4 5)
	(testcase '/  3)
        (testcase 'abs  -7)
	(testcase 'modulo  13 4)
	(testcase 'remainder  13 4)
	(testcase 'modulo  -13 4)
	(testcase 'remainder  -13 4)
	(testcase 'modulo  13 -4)
	(testcase 'remainder  13 -4)
	(testcase 'modulo  -13 -4)
	(testcase 'remainder  -13 -4)
	(testcase 'remainder  -13 -4.0)
	(testcase 'floor  -4.3)
	(testcase 'ceiling  -4.3)
	(testcase 'truncate  -4.3)
	(testcase 'round  -4.3)
	(testcase 'floor  3.5)
	(testcase 'ceiling  3.5)
	(testcase 'truncate  3.5)
	(testcase 'round  3.5)
	(testcase 'round  7)
	(testcase 'string->number  "100")
	(testcase 'string->number  "100" 16)
	(testcase 'string->number  "1e2")
	(testcase 'procedure?  car)
	(testcase 'procedure?  'car)
	(testcase 'procedure?  (lambda (x) (* x x)))
	(testcase 'procedure?  '(lambda (x) (* x x)))
	(testcase 'apply  + (list 3 4))
	(testcase 'map  cadr '((a b) (d e) (g h)))
	(testcase 'map  (lambda (n) (expt n n)) '(1 2 3 4 5))
	(testcase 'map  + '(1 2 3) '(4 5 6))
    )
)

(define symbol-proc-map
    `(
        (char=? . ,char=?) (char<? . ,char<?) (char<=? . ,char<=?) 
        (char>? . ,char>?) (char>=? . ,char>=?) (char-ci=? . ,char-ci=?)
        (char-ci<? . ,char-ci<?) (char-ci<=? . ,char-ci<=?)
        (char-ci>? . ,char-ci>?) (char-ci>=? . ,char-ci>=?)
	(char-property . ,char-property)
        (not . ,not) (boolean? . ,boolean?) (pair? . ,pair?) 
        (cons . ,cons) (car . ,car) (cdr . ,cdr) (list? . ,list?)
	(list . ,list) (length . ,length) (append . ,append)
	(reverse . ,reverse) (list-ref . ,list-ref) (member . ,member)
	(assoc . ,assoc) (symbol? . ,symbol?) 
	(symbol->string . ,symbol->string) (equal? . ,equal?)
	(string=? . ,string=?) (keyword->string . ,keyword->string)
	(string->keyword . ,string->keyword) (real? . ,real?)
	(integer? . ,integer?) (max . ,max) (+ . ,+) (* . ,*) (- . ,-)
	(/ . ,/) (abs . ,abs) (modulo . ,modulo) (remainder . ,remainder)
	(floor . ,floor) (ceiling . ,ceiling) (truncate . ,truncate)
	(round . ,round) (string->number . ,string->number)
	(procedure? . ,procedure?) (apply . ,apply) (map . ,map)
    )     
)
     
(define (symbol->proc sym) (cdr (assoc sym symbol-proc-map)))     
                  
(define (testcase proc-sym #!rest args)
    (write-line
        (string-append
            "(" 
            (symbol->string proc-sym)
            (reduce 
                args
                (lambda (args arg) (string-append args " " (obj->string arg)))
                ""
            )
            ") --> "
            (obj->string (apply (symbol->proc proc-sym) args))
        )
    )
)       

(define (reduce list combine init)
  (let loop ((result init)
             (list list))
    (if (null? list)
        result
        (loop (combine result (car list))
              (cdr list)))))

(define (obj->string obj)
    (cond
        ((char? obj) (list->string (list #\# #\\ obj)))
        ((string? obj) (string-append "\"" obj "\""))
        ((boolean? obj) (if obj "#t" "#f"))
        ((symbol? obj) (symbol->string obj))
	((keyword? obj) (string-append (keyword->string obj) ":"))
        ((number? obj) (number->string obj)) 
	((procedure? obj) "procedure")
        ((list? obj) 
	    (if (null? obj)
		"()"
            	(apply string-append 
                    (append (list "(" (obj->string (car obj)))
                        (map (lambda (x) 
				(string-append " " (obj->string x))) (cdr obj))
                    '(")")))))
	((pair? obj) (string-append "(" (obj->string (car obj))
				" . " (obj->string (cdr obj)) ")"))
        (else "unimplemented")
    )
)           
                  
(define (make-test title proc)
    (sosofo-append
        (write-line title)
        (proc)
        (write-empty-line)
    )
)    

(define (write-empty-line) (write-line ""))

(define newline "\carriage-return;\line-feed;")

(define (write-line string)
    (make formatting-instruction
        data: (string-append string newline)
    )
)

(declare-flow-object-class formatting-instruction
  "UNREGISTERED::James Clark//Flow Object Class::formatting-instruction")

(declare-default-language (language "EN" "US"))

(define language
  (external-procedure "UNREGISTERED::OpenJade//Procedure::language"))

]]>