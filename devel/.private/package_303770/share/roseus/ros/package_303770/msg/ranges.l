;; Auto-generated. Do not edit!


(when (boundp 'package_303770::ranges)
  (if (not (find-package "PACKAGE_303770"))
    (make-package "PACKAGE_303770"))
  (shadow 'ranges (find-package "PACKAGE_303770")))
(unless (find-package "PACKAGE_303770::RANGES")
  (make-package "PACKAGE_303770::RANGES"))

(in-package "ROS")
;;//! \htmlinclude ranges.msg.html


(defclass package_303770::ranges
  :super ros::object
  :slots (_ranges ))

(defmethod package_303770::ranges
  (:init
   (&key
    ((:ranges __ranges) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _ranges __ranges)
   self)
  (:ranges
   (&optional __ranges)
   (if __ranges (setq _ranges __ranges)) _ranges)
  (:serialization-length
   ()
   (+
    ;; float32[] _ranges
    (* 4    (length _ranges)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[] _ranges
     (write-long (length _ranges) s)
     (dotimes (i (length _ranges))
       (sys::poke (elt _ranges i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[] _ranges
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _ranges (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _ranges i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get package_303770::ranges :md5sum-) "b59fbb52705f63cb3fada08d311c9c4d")
(setf (get package_303770::ranges :datatype-) "package_303770/ranges")
(setf (get package_303770::ranges :definition-)
      "float32[] ranges
")



(provide :package_303770/ranges "b59fbb52705f63cb3fada08d311c9c4d")


