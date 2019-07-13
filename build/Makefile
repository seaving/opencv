# Makefile Written by ticktick

# Show how to cross-compile c/c++ code for android platform

.PHONY: clean
#-------------------------------------------------------
CUR_DIR = ../source
COMMON_DIR = $(CUR_DIR)/common
APPLICATION_DIR = $(CUR_DIR)/application
#-------------------------------------------------------
TARGET = bin/opencv
#-------------------------------------------------------
#-------------------------------------------------------
#-------------------------------------------------------
#-------------------------------------------------------
CC = gcc
CXX = g++
AR = ar
LD = ld
STRIP = strip
WALL = -Wall
CFLAGS = -g -O2
CXXFLAGS = -g -O2
#-------------------------------------------------------
#-------------------------------------------------------
INCLUDE = -I$(COMMON_DIR)/src \
			-I$(COMMON_DIR)/inc \
			-I$(APPLICATION_DIR)/src \
			-I$(APPLICATION_DIR)/inc \
			-I/usr/local/include \
			-I/usr/local/event2 \
			-I/usr/local/include/json-c \
			-I/usr/local/include/openssl \
			-I/usr/local/include/opencv \
			-I/usr/local/include/opencv2
#-------------------------------------------------------
STATIC_LIB = /usr/local/lib/libevent.a \
				/usr/local/lib/libevent_openssl.a \
				/usr/local/lib/libjson-c.a \
				/usr/local/lib/libssl.a \
				/usr/local/lib/libcrypto.a \
#-------------------------------------------------------
SHARE_LIB_PATH = 
SHARE_LIB = -ldl -lz -lpthread \
	-lopencv_calib3d -lopencv_core -lopencv_features2d \
	-lopencv_flann -lopencv_highgui -lopencv_imgcodecs \
	-lopencv_imgproc -lopencv_ml -lopencv_objdetect \
	-lopencv_photo -lopencv_shape -lopencv_stitching \
	-lopencv_superres -lopencv_ts -lopencv_videoio \
	-lopencv_video -lopencv_videostab -lopencv_viz
#-------------------------------------------------------
OBJ_DIR = obj
#-------------------------------------------------------
#获取当前目录下所有的.c文件
SOURCE_C = $(wildcard $(COMMON_DIR)/src/*.c) \
		$(wildcard $(APPLICATION_DIR)/src/*.c)

SOURCE_CXX = $(wildcard $(COMMON_DIR)/src/*.cpp) \
		$(wildcard $(APPLICATION_DIR)/src/*.cpp)
#-------------------------------------------------------
#得到相应的.o文件,所有的.c文件替换为.o文件
OBJ_C = $(patsubst %.c,$(OBJ_DIR)/%.c.o,$(notdir $(SOURCE_C)))

OBJ_CXX = $(patsubst %.cpp,$(OBJ_DIR)/%.cpp.o,$(notdir $(SOURCE_CXX)))
#-------------------------------------------------------
$(OBJ_DIR)/%.c.o:$(COMMON_DIR)/src/%.c
	@echo "CC $<"
	@$(CC) -ggdb $(WALL) $(CFLAGS) $(INCLUDE) $< -c -o $@

$(OBJ_DIR)/%.c.o:$(APPLICATION_DIR)/src/%.c
	@echo "CC $<"
	@$(CC) -ggdb $(WALL) $(CFLAGS) $(INCLUDE) $< -c -o $@

$(OBJ_DIR)/%.cpp.o:$(COMMON_DIR)/src/%.cpp
	@echo "CC $<"
	@$(CXX) -ggdb $(WALL) $(CXXFLAGS) $(INCLUDE) $< -c -o $@

$(OBJ_DIR)/%.cpp.o:$(APPLICATION_DIR)/src/%.cpp
	@echo "CC $<"
	@$(CXX) -ggdb $(WALL) $(CXXFLAGS) $(INCLUDE) $< -c -o $@
#-------------------------------------------------------
#生成目标的依赖
$(TARGET): $(OBJ_C) $(OBJ_CXX)
	@echo "--------------create $(TARGET)---------"
	@$(CXX) $(WALL) $(CXXFLAGS) $(SHARE_LIB_PATH) -o $@ $^ $(STATIC_LIB) $(SHARE_LIB)
	$(STRIP) $(TARGET)
	ls -alh $(TARGET)
#-------------------------------------------------------
clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(TARGET)
#-------------------------------------------------------