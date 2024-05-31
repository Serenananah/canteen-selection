CXX = clang++
CXXFLAGS = -std=c++17 -I/usr/local/mysql-connector-c++-8.4.0/include/jdbc -I./include -I./utils
LDFLAGS = -L/usr/local/mysql-connector-c++-8.4.0/lib64 -lmysqlcppconn

SRCS = $(wildcard src/*.cpp utils/*.cpp)
OBJ = $(SRC:.cpp=.o)

canteen_selection: $(OBJS)
    $(CXX) -o $@ $^ $(LDFLAGS)

.cpp.o:
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f *.o canteen_selection
