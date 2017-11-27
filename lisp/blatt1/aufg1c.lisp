(defun my-length (liste)
    (cond
      ((null liste) 0)
      (t (+ 1 (my-length (cdr liste))))
      )
  )
(setf y (my-length '(1 2 3 4 5 6)))
(print y)
