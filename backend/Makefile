CXX = clang++
CXXFLAGS = -std=c++17 -I/usr/local/mysql-connector-c++-8.4.0/include/jdbc
LDFLAGS = -L/usr/local/mysql-connector-c++-8.4.0/lib64 -lmysqlcppconn

SRCS = main.cpp Canteen.cpp DataLoader.cpp Stall.cpp Dish.cpp User.cpp Order.cpp DBOperations.cpp
OBJS = $(SRCS:.cpp=.o)

canteen_selection: $(OBJS)
    $(CXX) -o $@ $^ $(LDFLAGS)

.cpp.o:
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f *.o canteen_selection
