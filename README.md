
# Ultron OS
---------------------
Ultron OS is an x86 Operating System written in C++. It is able to boot Initialise the GDT and and IDT and do a couple of   things that Operating Systems are supposed to do.
Author : @aswinmohanme

------------------------
- [Ultron OS](#)
	- [Description](#)
	- [Installation](#)
		- [Requirements](#)
		- [Getting the Source](#)
		- [Compiling](#)
		- [Testing](#)

------------------------
## Description
Ultron is designed with OOP in mind and has not failed to live up to the promise at all possible places.

---------------------------------------
## Installation
### Requirements
For Compiling the Operating System image it is required that these dependencies must be met.
> * Any ***nix** like system
> * The GNU **GCC** compiler Toolchain
> * Netwide Assembler **NASM**
> * GNU **Make**
> * GNU general linker **ld**
> * Astlye Formatter

For Testing the Operating System it is recommended to use
> **Qemu** the Emulator of our Choice  

-------------------------------
### Getting the Source
The most recent Source Code is hosted on *https://github.com/aswinmohanme/Ultron-OS*

> **How to get the most Recent Version **


```bash
# Get the Updated Source from github
git clone https://github.com/aswinmohanme/Ultron-OS
```

### Compiling
```
# Change the Directory into the Current One
cd Ultron-OS
# Run Make at the root of the project
make
```

### Testing
Make sure you have installed **qemu** on your system. From the project root run
```
# This Command Runs the OS on an Emulated Machine
make run
```

Thanks !! Enjoy
