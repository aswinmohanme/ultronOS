
# Make File for Bulding Ultron

# Sets up the Assembler
AS := nasm
ASFLAGS := -f elf
ASFILES := $(wildcard kernel/boot/*.s kernel/arch/*.s)
ASOBJECTS := $(ASFILES:.s=.s.o)

# Compile C++ Files
CXX := g++
CXXFLAGS := -c -nostdlib -nostdinc -fno-builtin -fno-stack-protector -ffreestanding -m32 -I./kernel/include
CXXFILES := $(wildcard *.cc kernel/*.cc kernel/core/*.cc kernel/modules/*.cc)
CXXOBJECTS := $(CXXFILES:.cc=.o)
CXXHEADERS := $(wildcard *h kernel/include/*.h)

# Manage Dependencies So that make remakes requred files when header changes
DEPENDS := $(CXXFILES:.cc=.d)

# Manage the Precompiled Headers
PRECOMP := $(CXXHEADERS:.h=.h.gch)

# Linker
LD := ld
LDFLAGS := -m elf_i386 -T link.ld

# Style Script
STYLER := bash scripts/style.sh

# Declare clean and run as Phony Targets
.PHONY: clean run style

# The Final Product will be ultron.bin in the build directory
all: ultron.bin

# Ultron.img : It is the Final Product formed by linking all the object files together
ultron.bin : $(ASOBJECTS) $(CXXOBJECTS)
		$(LD) $(LDFLAGS) -o build/$@ $^

# Run the Kernel : First Make the Kernel and then run it
run: ultron.bin
		qemu-system-i386 -kernel 'build/ultron.bin'

# Assemble the Assembly Files into object Files
# This Assembles all the Files into thier respective object files
%.s.o: %.s
		$(AS) $(ASFLAGS) $< -o $@

# Compile the C++ Files into corresponding object Files and place it in same directory
%.o: %.cc
		$(CXX) $(CXXFLAGS) -o $@ $<

# Generate the Dependency Make files so 'make' updates
# the objects when headers are modified
# The -MD and -MM Options Generates the MakeFiles
%.d: %.cc
		$(CXX) -MM -MD -I./kernel/include -o $@ $<

# Inlcude the Generated Make Files
-include $(DEPENDS)

# Style the Script uses AStlye to Format to GNU Style
style:
	$(STYLER) kernel cc
	$(STYLER) kernel h

# Clean this Mess
clean: $(ASOBJECTS) $(CXXOBJECTS) $(DEPENDS) $(PRECOMP)
		$(RM) $^
