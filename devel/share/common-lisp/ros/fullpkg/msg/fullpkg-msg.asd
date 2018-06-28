
(cl:in-package :asdf)

(defsystem "fullpkg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "mesg" :depends-on ("_package_mesg"))
    (:file "_package_mesg" :depends-on ("_package"))
  ))