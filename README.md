# MagicHash

This is a drop in C++ multiton container and AWK script that tracks requests to make MAGICHASH() within your code.

#Usage
The AWK script (MagicHashAwk.awk) is a preprocessor that replaces every instance of "MAGICHASH()"  (after #include "MagicHash.h") with a md5 hash of the filename and line number. After processing all of the files in it's input, it will output a header file (MagicHashAwk.h) that you can optionally include for using in your main function. That header file contains a single function that will initialize the multiton container with all known magic hashes in your project.

#Why?
Debugging primarily. For example, trying to find which function is failing to correctly modify a multidimensional vector in a dynamic fashion. This would be a pain if several of those functions change the size of the vector, and they all set the initial values of the new elements to 0.


#Requirements
AWK
openssl md5
cut
shell



#Testing Requirements
Above reqs
bash
cmp
