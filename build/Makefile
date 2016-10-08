# Simple Makefile for Project Euler compilation and it's test cases.
# October 8th, 2016

SRC_PATH := ../problems/src
OBJ_PATH := objs

SRC_FILES := $(wildcard $(SRC_PATH)/*.cpp)
OBJ_FILES := $(addprefix $(OBJ_PATH)/,$(notdir $(SRC_FILES:.cpp=.o)))

PROBLEMS_INC := -I ~/git_hub/ProjectEuler/problems/inc

TEST_SRC = ../test/test.cpp

UTILITY_INTEGER_INC := -I ~/git_hub/Utility/integer/inc
UTILITY_MATHS_INC := -I ~/git_hub/Utility/maths/inc

GXX = g++
CCFLAGS = -g -c -Wall -O3

LD := -lutility
LD_PATH := -L ~/git_hub/Utility/lib/

TARGET = euler

euler : $(OBJ_FILES) test
	$(GXX) $(LD_PATH) $(LD) -o $(TARGET) $(OBJ_PATH)/*.o

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.cpp
	$(GXX) $(CCFLAGS) $(PROBLEMS_INC) $(UTILITY_INTEGER_INC) $(UTILITY_MATHS_INC) $< -o $@

test: $(TEST_SRC)
	$(GXX) $(CCFLAGS) $(PROBLEMS_INC) -o objs/test.o $(TEST_SRC)

clean:
	rm -rf $(OBJ_PATH)/* $(TARGET)
