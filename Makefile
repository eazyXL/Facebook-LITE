#
#
# Specifiy the target
all:	build

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
build:	FBLUser.o FBLUserLL.o FBLPost.o FBLPostLL.o FBLCommentLL.o FBLComment.o main.o
	g++  main.o FBLUser.o FBLUserLL.o FBLPost.o FBLPostLL.o FBLCommentLL.o FBLComment.o -o main

# Specify how the object files should be created from source files
FBLUser.o:  FBLUser.cpp FBLUser.h
		g++ -c FBLUser.cpp

FBLUserLL.o: FBLUserLL.cpp FBLUserLL.h
		g++ -c FBLUserLL.cpp

FBLPost.o: FBLPost.cpp FBLPost.h
		g++ -c FBLPost.cpp

FBLPostLL.o: FBLPostLL.cpp FBLPostLL.h
		g++ -c FBLPostLL.cpp

FBLCommentLL.o: FBLCommentLL.cpp FBLCommentLL.h
		g++ -c FBLCommentLL.cpp

main.o: main.cpp
	g++ -c main.cpp

FBLComment.o: FBLComment.cpp FBLComment.h
		g++ -c FBLComment.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o main
	rm -f *.o FBLUser.o
	rm -f *.o FBLUserLL.o
	rm -f *.o FBLPost.o
	rm -f *.o FBLPostLL.o
	rm -f *.o FBLComment.o
	rm -f *.o FBLCommenLL.o

