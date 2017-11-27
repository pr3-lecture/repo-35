(defun my-reverseR (liste)
    (cond
        ((null liste) nil)
        ((listp (car liste))
            (append (my-reverseR (cdr liste)) (list (my-reverseR (car liste)))))
        (T
            (append (my-reverseR (cdr liste))
            (list (car liste))))))

(setf x (my-reverseR '(eins zwei (zwei (zwei drei) eins) drei vier)))
(print x)
