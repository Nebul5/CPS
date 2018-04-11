g++ --std=c++14 -o tests.out ../test-main.o test-circle.cpp test-rotated.cpp\
      test-polygon.cpp test-rectangle.cpp test-scaled.cpp test-vertical.cpp\
      test-horizontal.cpp test-spacer.cpp catch.hpp \
    ../source/circle.cpp ../source/shape.cpp \
    ../source/polygon.cpp ../source/rectangle.cpp \
    ../source/scaled.cpp ../source/vertical.cpp\
    ../source/rotated.cpp ../source/horizontal.cpp ../source/spacer.cpp -Wextra\
