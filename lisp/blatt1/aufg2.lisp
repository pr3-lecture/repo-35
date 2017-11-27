;Darstellung Binärbaum:
;(1 (2 (4) (5)) (3 (6) (7 () (8))))

;links: cadr (car (cdr tree))
;rechts: caddr (car (cdr (cdr tree)))
;Inorder
(defun inorder (tree)
  (cond ((null tree) nil)
      (t (inorder (cadr tree))
          (print (car tree))
          (inorder (caddr tree))))
  )

;(setf x (inorder '(1 (2 (4) (5)) (3 (6) (7 () (8))))))

;Preorder
(defun preorder (tree)
  (cond ((null tree) nil)
        (t (print (car tree))
           (preorder (cadr tree))
           (preorder (caddr tree)))))

;(setf y (preorder '(1 (2 (4) (5)) (3 (6) (7 () (8))))))


;Postorder
(defun postorder (tree)
  (cond ((null tree) nil)
        (t (postorder (cadr tree))
           (postorder (caddr tree))
           (print (car tree)))))

;(setf z (postorder '(1 (2 (4) (5)) (3 (6) (7 () (8))))))
