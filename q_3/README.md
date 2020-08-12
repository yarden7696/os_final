# How to run set_policy.c ?

First, go to folder q_3 , after that- the following commands must be run in the following order :

first terminal- 
* make set_policy
* sudo ./set_policy <policy_number> <priority_number>  (After this command we will get the process number).

- You can see in the pdf file how i check this program (by using chrt -p <process_number> in the second terminal). 

_____________________________________________________________________________________________________

Note: you can use the command `make clean` to removes all the object files that had been created in the meantime.