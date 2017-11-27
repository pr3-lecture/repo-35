(defun my-lengthR (liste)
    (cond ((null liste) 0)
        ((listp (car liste))
            (+ (my-lengthR (car liste)) (my-lengthR (cdr liste))))
        (T (+ 1 (my-lengthR (cdr liste))))))

        (setf y (my-lengthR '(1 (2 3) (4 5) 6)))
        (print y)
