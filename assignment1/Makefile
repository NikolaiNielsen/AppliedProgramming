# the compiler to use
CC = clang++

# compiler flags:
# -g    adds debugging information to the executable file
# -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall
  
#files to link:
LFLAGS = 2_6.cpp 3_3.cpp 5_4.cpp 5_3.cpp 5_6.cpp 5_10.cpp
  
# the name to use for both the target source file, and the output file:
TARGET = main
   
all: $(TARGET)
     
$(TARGET): $(TARGET).cpp 2_6.cpp 2_6.h 3_3.cpp 3_3.h 5_4.cpp 5_4.h 5_3.cpp 5_3.h 5_6.cpp 5_6.h 5_10.cpp 5_10.h
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(LFLAGS)
