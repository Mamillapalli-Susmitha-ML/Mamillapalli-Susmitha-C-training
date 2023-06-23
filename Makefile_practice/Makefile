all:hello
hello:main.o function1.o function2.o
	g++ main.cpp function1.cpp function2.cpp -o result
function1.o:function1.cpp 
	g++ -c function1.cpp
function2.o:function2.cpp	
	g++ -c function2.cpp
main.o:main.cpp	
	g++ -c main.cpp
clean:
	rm -f *.o result

//This looks like a bash script, study little bit more on Makefile targets and flags

# hello:
# 	echo "Hello world"
# 	touch myfile1.txt
# 	cat>>myfile1.txt
# 	cat myfile1.txt

# some_file:other_file
# 	echo "This is some_file depends on other_file"
# 	touch some_file.txt
# other_file:
# 	echo "This is other_file do nothing"

# some_file:
# 	touch some_file.txt
# clean:
# 	rm some_file.txt

# files:=file1.txt file2.txt
# some_file:${files}
# 	echo "this is a variable with values" ${files}
# 	touch some_file1.txt
# file1.txt:
# 	touch file1.txt
# file2.txt:
# 	touch file2.txt
# clean:
# 	rm -f file1.txt file2.txt some_file1.txt


# all:file1 file2 file3
# file1:
# 	touch file1.txt
# file2:
# 	touch file2.txt
# file3:
# 	touch file3.txt
# clean:
# 	rm -f file1.txt file2.txt file3.txt

# files:=file1 file2
# all:file1 file2
# file1:
# 	echo "File1 creation"
# 	touch $@
# file2:
# 	echo "File2 creation"
# 	touch $@
# file1 file2:
# 	echo "File creation"
# 	touch $@
# clean:
# 	rm -f ${files}

# files=$(wildcard *.txt)
# print:
# 	echo "searched files" $(files)
# clean:
# 	rm -f ${files}



# all:file1.txt file2.txt file3.txt
# file1.txt file2.txt file3.txt:myfile1 myfile2
# 	echo "Targets are " $@
# 	echo "Dependencies are "$^
# myfile1:
# 	echo "This is myfile1"
# myfile2:
# 	echo "This is myfile2"


# objects = foo.o bar.o all.o
# all: bar.o foo.o all.o
# foo.o: foo.c
# bar.o: bar.c
# all.o: all.c
# all.c:
# 	echo "int main() { return 0; }" > all.c
# %.c:
# 	touch $@

# objects = foo.o bar.o all.o
# all: $(objects)

# # These files compile via implicit rules
# # Syntax - targets ...: target-pattern: prereq-patterns ...
# # In the case of the first target, foo.o, the target-pattern matches foo.o and sets the "stem" to be "foo".
# # It then replaces the '%' in prereq-patterns with that stem
# $(objects): %.o: %.c

# all.c:
# 	echo "int main() { return 0; }" > all.c

# %.c:
# 	touch $@

# clean:
# 	rm -f *.c *.o all


# all:on.o tw.o
# on.o:on.c
# tw.o:tw.c
# on.c:
# 	echo "int main() { return 0; }" > on.c
# tw.c:
# 	echo "int main() { return 0; }" > tw.c
# %.c:
# 	touch $@


# objects=foo.o bar.o all.o
# all:$(objects)
# $(objects):%.o:%.c
# all.c:
# 	echo "int main() {return 0;}" >all.c
# %.c:
# 	touch $@


# obj_files = foo.result bar.o lose.o
# src_files = foo.raw bar.c lose.c

# all: $(obj_files)
# # Note: PHONY is important here. Without it, implicit rules will try to build the executable "all", since the prereqs are ".o" files.
# .PHONY: all 

# # Ex 1: .o files depend on .c files. Though we don't actually make the .o file.
# $(filter %.o,$(obj_files)): %.o: %.c
# 	echo "target: $@ prereq: $<"

# # Ex 2: .result files depend on .raw files. Though we don't actually make the .result file.
# $(filter %.result,$(obj_files)): %.result: %.raw
# 	echo "target: $@ prereq: $<" 

# %.c %.raw:
# 	touch $@

# clean:
# 	rm -f $(src_files)




# all:hello
# hello::
# 	echo "welcome first time"
# hello:: 
# 	echo "welcome second time"
# hello::
# 	echo "welcome third time"


# all:hello
# hello:
# 	@echo "This line won't gets printed"
# 	echo "This line get printed"



# make_var = I am a make variable
# now:
# 	# Same as running "sh_var='I am a shell variable'; echo $sh_var" in the shell
# 	sh_var='I am a shell variable'; echo $$sh_var

# 	# Same as running "echo I am a make variable" in the shell
# 	echo $(make_var)

# make_var="make variable"
# first:
# 	loc_var="local variable";echo $${loc_var}
# 	@echo ${make_var}


# x="hello"
# y=${x}
# x="world"
# z:="welcome"
# w:=${x}
# x="hey folks"
# print:
# 	@echo "x=${x} y=${y} z=${z} w=${w}"
