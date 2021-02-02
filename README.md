# SYN_abstractVM_2019
# How to Use
./abstractVM [opt.avm]

; ---------------

; - example . avm -

; ---------------

push int32 (33)

push int32 (42)

add

push float (44.55)

mul

push double (42.42)

push int32 (42)

dump

pop

assert double (42.42)

exit

You can use commands after execution without args (more details in the pdf)
