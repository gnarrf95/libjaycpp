# ==============================================================================
# Compiler

CC = gcc -Wall -Werror -std=c11
CXX = g++ -Wall -Werror -std=c++11

# ==============================================================================
# Compiler and linker flags

INC = -I inc/

CFLAGS = $(INC)

LDF_PTHREAD = -lpthread

LDFLAGS = $(LDF_PTHREAD)

# Use build flags to change compilation parameters for library.
# Flags:
# * "-D JCON_NO_DEBUG"  if jcon modules should not log debug messages
# * "-D JUTIL_NO_DEBUG" if jutil modules should not log debug messages
BUILD_FLAGS = -DJUTIL_NO_DEBUG

HEADERS_C_LIB = $(wildcard inc/jaycpp/*.h)
HEADERS_CPP_LIB = $(wildcard inc/jaycpp/*.hpp)

HEADERS_C_INT = $(wildcard inc/*.h)
HEADERS_CPP_INT = $(wildcard inc/*.hpp)

HEADERS_C = $(HEADERS_C_LIB) $(HEADERS_C_INT)
HEADERS_CPP = $(HEADERS_CPP_LIB) $(HEADERS_CPP_INT)
HEADERS = $(HEADERS_C) $(HEADERS_CPP)

# Get all subdirectories of src
# https://stackoverflow.com/questions/13897945/wildcard-to-obtain-list-of-all-directories
SRCDIRS = $(sort $(dir $(wildcard src/*/)))

SRC_C = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)*.c))
SRC_CPP = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)*.cpp))

# ==============================================================================
# Objects

OBJ_C = $(subst src, build/objects, $(SRC:.c=.o))
OBJ_CPP = $(subst src, build/objects, $(SRC_CPP:.cpp=.o))

OBJ = $(OBJ_C) $(OBJ_CPP)

OBJDIRS = $(sort $(dir $(OBJ)))

# ==============================================================================
# Targets

TARGET_LIBJAYCPP = build/lib/libjaycpp.so

# ==============================================================================
# Install variables

PREFIX ?= /usr/local

HEADERS_INSTALLED = $(subst inc/jaycpp/,$(PREFIX)/include/jaycpp/,$(HEADERS_INST))
TARGET_LIBJAYCPP_INSTALLED = $(subst build/lib,$(PREFIX)/lib,$(TARGET_LIBJAYCPP))

# ==============================================================================
# Build recipes

# ------------------------------------------------------------------------------
# Compile Tests
check: $(OBJ)
	@echo "Source Code compiled successfully."

# ------------------------------------------------------------------------------
# Build all parts of the project
.PHONY: all
all: lib

# ------------------------------------------------------------------------------
# Compile Library
.PHONY: lib
lib: $(TARGET_LIBJAYCPP)
	@echo "All libraries done."

$(TARGET_LIBJAYCPP): $(OBJ)
	$(CC) -shared -o $@ $(CFLAGS) $? $(LDFLAGS)

# ------------------------------------------------------------------------------
# Library Installation
.PHONY: install_dev
install_dev: install_lib install_inc
	@echo "Ready for development."

.PHONY: install
install: install_lib
	@echo "Installation finished."

.PHONY: install_all
install_all: install_lib install_inc
	@echo "Installation finished."

install_lib: $(TARGET_LIBJAYCPP) preinstall
	install -m 755 $(TARGET_LIBJAYCPP) $(PREFIX)/lib/
	ldconfig

install_inc: preinstall
	for header in $(HEADERS); do install -m 755 $$header $(PREFIX)/include/jaycpp/; done

preinstall:
	install -d $(PREFIX)/include/jaycpp/
	install -d $(PREFIX)/lib/

# ------------------------------------------------------------------------------
# Library Uninstall
.PHONY: uninstall
uninstall: uninstall_lib uninstall_inc
	@echo "Uninstallation finished."

uninstall_lib:
	rm -f $(TARGET_LIBJAYCPP_INSTALLED)

uninstall_inc:
	rm -rf $(PREFIX)/include/jaycpp

# ------------------------------------------------------------------------------
# Make Documentation
.PHONY: docs
docs: doc_doxygen
	@echo "Documentation done."

doc_md: 
	# Need to add usage and dev docs.

doc_doxygen: Doxyfile
	doxygen Doxyfile

# ------------------------------------------------------------------------------
# General Recipes

build/objects/%.o: src/%.c build
	$(CC) -c $< -o $@ $(CFLAGS) $(BUILD_FLAGS) -fpic

build/objects/%.o: src/%.cpp build
	$(CXX) -c $< -o $@ $(CFLAGS) $(BUILD_FLAGS) -fpic

build:
	mkdir -p build/objects
	mkdir -p build/tests
	mkdir -p build/lib
	for dir in $(OBJDIRS); do mkdir -p $$dir; done

clean:
	rm -rf docs/doxygen/ build/
	clear