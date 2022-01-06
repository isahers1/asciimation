# The target "our-movie.o" has two dependencies: "our-move.cpp" and "asciimation.hpp"
# Make will confirm that the dependenies are up to date and then it will run
# the command on the following line to generate our-movie.o.
OPENCV_LIBS=-lopencv_imgcodecs -lopencv_core -lopencv_imgproc -lopencv_video -lopencv_videoio
FLAGS = -g -std=c++17 -pedantic -Wall -Wextra

all: our-movie

our-movie.o: our-movie.cpp asciimation.hpp sprite.hpp
	clang++ -c $(FLAGS) $<

# The target "sprite.o" has two dependencies "sprite.cpp" and
# "sprite.hpp". Make will make sure that the command runs if either of these
# files have changed since the last time Make had to make sprite.o
sprite.o: sprite.cpp sprite.hpp
	clang++ -c $(FLAGS) $<

# The target "asciimation.o" has three dependencies "asciimation.cpp", "sprite.hpp", and
# "asciimation.hpp". Make will make sure that the command runs if either of these
# files have changed since the last time Make had to make sprite.o
asciimation.o: asciimation.cpp asciimation.hpp sprite.hpp
	clang++ -c $(FLAGS) $<

# The target "our-movie" has two dependencies "our-movie.o" and"asciimation.o"
# Make will make sure these two dependencies are up to date and
# then it will run the commend on the following line, to compile an executable
# and give it the name "our-movie"
our-movie: our-movie.o asciimation.o sprite.o
	clang++ -o $@ $(FLAGS) $^ $(OPENCV_LIBS)

# This is a "dummy" target.  When we tell Make to make clean, it has no
# dependencies and it will just run the command below, which removes all object
# files and the executable (if they exist).
clean:
	rm -rf *.o our-movie
