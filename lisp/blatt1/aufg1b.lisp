(defun neues-vorletztes (x liste)
  (append (reverse (cdr (reverse liste)))
	(list x) (list (car (reverse liste)))))

(setf x (neues-vorletztes "hallo" '(1 2 3 4)))
(print x)
