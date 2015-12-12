; @ File : idt.s
; @ Desc : Defines the idt_flush() function which sets up the IDT
;

[GLOBAL idt_flush]

idt_flush:
  mov eax , [esp+4]     ; Get the pointer to the idt struct
  lidt [eax]            ; Loads the IDT
  ret                   ; return
