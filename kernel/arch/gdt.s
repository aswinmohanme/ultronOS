; @ File : gdt.s
; @ Desc : Defines the gdt_flush() function which sets up the GDT
;

[GLOBAL gdt_flush]      ; Set the gdt_flush globally so it can be called from gdt.cc

gdt_flush:              ; Define the Functions
    mov eax , [esp+4]   ; Get the First Parameter which is the GDT pointer
    lgdt[eax]           ; Load the GDT using our pointer

    mov ax, 0x10        ; 0x10 is the offset in the GDT to our data segment
    mov ds, ax          ; Load all data segment selectors
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:.flush     ; 0x08 is the offset to our code segment: Far jump!
.flush:
    ret
