# Compiler and Compiler Flags
CC=gcc
CFLAGS=-Wall -g -Iinclude
# Linker flags
LDFLAGS=-lreadline

# The build target executable:
TARGET=minios

# Source, Object files
SRCS=kernel/kernel.c kernel/system.c kernel/20211089/fork.c kernel/20211089/ipc.c kernel/20211089/est_pi.c kernel/20211089/round_robin.c
OBJS=$(SRCS:.c=.o) 

# Include directory
INCLUDE_DIR=include

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# To obtain object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up:
clean:
	rm -f $(OBJS) $(TARGET)
