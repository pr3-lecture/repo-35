(defun my-reverse (liste)
    (cond
        ((null liste)'())
        (T
            (append (my-reverse (cdr liste))
            (list (car liste))))))

(setf x (my-reverse '(eins zwei (zwei (zwei drei) eins) drei vier)))
(print x)
