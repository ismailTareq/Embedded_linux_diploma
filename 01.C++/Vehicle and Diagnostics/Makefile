CC = g++
CFLAGS = -std=c++17 -Wall 
C_SRCS =  $(wildcard *.cpp)
C_OBJS =  $(C_SRCS:.cpp=.o)
PROJECT_NAME = vehicle_system_and_diagnostics

all: $(PROJECT_NAME).exe
	@echo "Build complete."
%.o: %.cpp
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@
$(PROJECT_NAME).exe: $(C_OBJS)
	$(CC) $(CFLAGS) -Wl,-Map,output.map $(C_OBJS) -o $@

clean:
	rm -f $(C_OBJS) $(PROJECT_NAME).exe *.d output.map
	@echo "Clean complete."
