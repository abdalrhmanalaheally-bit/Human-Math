CXX = g++
CXXFLAGS = -O3 -Wall -fPIC
LDFLAGS = -shared

# Source files
SOURCES = human_math.cpp
TEST_SOURCE = test_human_math.cpp
FULL_DEMO_SOURCE = full demo.cpp

# Output files
LIB = libhuman_math.so
TEST_EXECUTABLE = test_human_math
FULL_DEMO_EXECUTABLE = full_demo

# Default target
all: $(LIB) $(TEST_EXECUTABLE)

# Build shared library
$(LIB): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^
	@echo "✓ Shared library built: $(LIB)"

# Build test executable
$(TEST_EXECUTABLE): $(TEST_SOURCE) human_math.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "✓ Test executable built: $(TEST_EXECUTABLE)"

# Build full demo executable
$(FULL_DEMO_EXECUTABLE): "$(FULL_DEMO_SOURCE)" human_math.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "✓ Full demo executable built: $(FULL_DEMO_EXECUTABLE)"

# Run tests
test: $(TEST_EXECUTABLE)
	@echo "\n========== Running Human Math Tests ==========\n"
	./$(TEST_EXECUTABLE)
	@echo "\n========== Tests Complete ==========\n"

# Run full demo
demo: $(FULL_DEMO_EXECUTABLE)
	@echo "\n========== Running Full Demo ==========\n"
	./$(FULL_DEMO_EXECUTABLE)
	@echo "\n========== Demo Complete ==========\n"

# Clean build artifacts
clean:
	rm -f $(LIB) $(TEST_EXECUTABLE) $(FULL_DEMO_EXECUTABLE)
	@echo "✓ Cleaned build artifacts"

# Help target
help:
	@echo "Available targets:"
	@echo "  make all          - Build library and tests"
	@echo "  make test         - Build and run comprehensive tests"
	@echo "  make demo         - Build and run full demo"
	@echo "  make clean        - Remove build artifacts"
	@echo "  make help         - Show this help message"

.PHONY: all test demo clean help
