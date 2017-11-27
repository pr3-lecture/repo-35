(defun rotiere(liste)
(cond
  ((null (cdr liste)) liste)
  (t (cons (first (last liste))
           (append (butlast (rest liste))
                   (list (first liste)))))
  ))


(setf x (rotiere '(1 2 3 4)))
(print x)
