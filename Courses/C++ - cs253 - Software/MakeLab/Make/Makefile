# This is a Makefile.  Its purpose is to create the program “small”.
#
# The rules, below, indicate what depends on what, and how to build
# things when they get out-of-date.  It is VERY important to know that
# what looks like eight leading spaces is really a leading tab
# character.  Leading spaces won’t work--it MUST be a tab character.
#
# For the following questions, do the command if there is one,
# and then answer the question.  If you need another line for you
# answer, continue it on the next line, indented.
#
# As an example, I’ve already answered (1), which has nothing to do
# with anything else in this lab.
#
# Question 1 is worth 0.09 points; questions 2–14 are worth 0.07
# points each.
#
#  1) Command:  date +%A
#     Question: Describe the output of that command.
#     Answer:   It’s today’s day of the week.
#
#  2) Command:  make
#     Question: Describe what happens.  Don’t just write the commands;
#     		describe what each command does.
#     Answer:     
#   
#   MakeFile compiled main.cc and foo.cc, creating main.o and foo.o, using foo.h. 
#   This created the executable program "small"
# 
#  3) Command:  ./small
#     Question: What is the output?  Reproduce the output exactly.
#     Answer: 
#  
#Hi from main at main.cc:15
#Hi from foo at foo.cc:14
#
#  4) Command:  make
#     Question: Why did nothing much happen?
#     Answer:   
#
#     no changes were made to small, so there was nothing to compile. If I changed small, main.cc, or  
#
#  5) Command:  rm small; make
#     Question: What got remade, and why?
#     Answer:   
#
#    Only small was remade. it was the only file that was altered. The call to 'make' caused a recursive 
#    use of main.cc and foo.cc, to create a new 'small' program.
#
#  6) Command:  rm foo.o; make 
#     Question: What got remade, and why?
#     Answer:  
#
#     foo.cc and small were both remade. The compiler doesnt know if something changed inside of foo.cc
#     so the recursive call automatically remakes small as a result. Since main.cc doesnt rely on foo.cc
#     it was not remade.
#
#  7) Command:  make clean 
#     Question: What did that do?
#     Answer:   
#
#    make clean called the clean function that removed small and any .o files it found.
#
#  8) Command:  make 
#     Question: What got remade, and why?
#     Answer:   
#
#    Literally the same ones from the first call to make. Both .o files and the 'small' program were remade
##
#  9) Question: Why does main.o depend on foo.h?
#		I know that it’s because the Makefile says so.
#		Why was that dependency put into the Makefile?
#     Answer:  
#
#    Because it calls the foo() function. 
#
#
# 10) Command:  Create a new function bar() in bar.cc & bar.h,
# 		similar to foo.cc.  Change main.cc to call the new
# 		bar() function, make sure to #include the proper .h
# 		files everywhere, and type “make”.  Don’t alter Makefile.
#     Question: Why did it fail?
#     Answer:   
#
#    Because we did not define the reference to bar() in our Makefile.
#
# 11) Command:  Fix the Makefile; verify with “make” until it compiles.
#     Question: Describe your changes.  Don’t just show the changed
#     		lines--describe the purpose of each change.
#     Answer:   
#
#     I updated the creation of small to include the bar object, I updated the main class to
#     include the bar.h file that I created and call the bar() method. I also created a bar.cc file 
#     that prints a statement similar to the foo.cc file. 
# 
#
# 12) Command:  Uncomment the CXXFLAGS= line, and type “make”.
#     Question: Why didn't anything happen?
#     Answer:   
#
#    The make command didnt nead to update anything in the foo, bar, or main files. 
#
# 13) Command:  Force a rebuild with: make clean; make 
#     Question: What’s new about the commands executed?
#     Answer:   
#
#    Now the compilation process takes into account the various flags we have given it. Thankfully, 
#    still compiles correctly, and makes all of the *.o files and the small program.
#
# 14) Command: 	make clean; ls -l clean
#     Question: The target is “clean”, but no file “clean” got created.
#     		Why not?
#     Answer:   
#
#    The clean command we gave calls the -rm Bash command, which uses the "-f" tag to check of the small
#    file is present, and removes it if true. It also removes all (indicated by the *).o files.
#
#
# For extra fame & glory (but no extra points):
#
# 15) Command:  Consult the make manual at
# 		https://www.gnu.org/software/make/manual/make.html
#		and improve this Makefile by using $@ in the rule
#		that creates “small” itself.

# The CXX variable contains the name of the C++ compiler.  You can’t
# have plus signs in a Make variable, so X is a rotated plus sign.
CXX=g++

CXXFLAGS=-std=c++17 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -Wctor-dtor-privacy -Wold-style-cast -D_GLIBCXX_DEBUG -fno-diagnostics-show-option


small: main.o foo.o bar.o
	$(CXX) $(CXXFLAGS) main.o bar.o foo.o -o small

main.o: main.cc foo.h bar.h
	$(CXX) $(CXXFLAGS) -c main.cc

foo.o: foo.cc foo.h
	$(CXX) $(CXXFLAGS) -c foo.cc
 
bar.o: bar.cc bar.h
	$(CXX) $(CXXFLAGS) -c bar.cc 
 
clean:
	-rm -f small *.o
