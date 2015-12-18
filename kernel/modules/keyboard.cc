//
// keyboard.c -- Defines the functions related to the keyboard driver.
//          Written for JamesM's kernel development tutorials.
//

#include <system.h>

//Define your keyboard layouts here:

keymap_t us =
{
  //normal keys
  {
    /* first row - indices 0 to 14 */
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',

    /* second row - indices 15 to 28 */
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', //Enter key

    /* 29 = Control, 30 - 41: third row */
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',

    /* fourth row, indices 42 to 54, zeroes are shift-keys*/
    0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,

    '*',

    /* Special keys */

    0, //ALT - 56
    ' ', // Space - 57
    0, //Caps lock - 58
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // F1 to F10 - 59 to 68
    0, //Num lock - 69
    0, //Scroll lock - 70
    0, //Home - 71
    0, //Up arrow - 72
    0, //Page up - 73
    '-',
    0, //Left arrow - 75
    0,
    0, //Right arrow -77
    '+',
    0, //End - 79
    0, //Dowm arrow - 80
    0, //Page down - 81
    0, //Insert - 82
    0, //Delete - 83
    0, 0, 0,
    0, //F11 - 87
    0, //F12 - 88
    0, //All others undefined
  },
  //caps
  {
    /* first row - indices 0 to 14 */
    0, 27, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '\b',

    /* second row - indices 15 to 28 */
    '\t', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n', //Enter key

    /* 29 = Control, 30 - 41: third row */
    0, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"', '~',

    /* fourth row, indices 42 to 54, zeroes are shift-keys*/
    0, '|', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0,

    '*',

    /* Special keys */

    0, //ALT - 56
    ' ', // Space - 57
    0, //Caps lock - 58
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // F1 to F10 - 59 to 68
    0, //Num lock - 69
    0, //Scroll lock - 70
    0, //Home - 71
    0, //Up arrow - 72
    0, //Page up - 73
    '-',
    0, //Left arrow - 75
    0,
    0, //Right arrow -77
    '+',
    0, //End - 79
    0, //Dowm arrow - 80
    0, //Page down - 81
    0, //Insert - 82
    0, //Delete - 83
    0, 0, 0,
    0, //F11 - 87
    0, //F12 - 88
    0, //All others undefined
  },

  // control_map
  {
    29, // Ctrl
    56, // Alt
    0,  // AltGr
    42, // left Shift
    54, // right Shift
    58, // Caps lock
    70, // Scroll lock
    69  // Num lock
  },

  //Set the initial status of all control keys to "not active"
  0
};

keymap_t gb =
{
  // normal keys
  {
    /* first row - indices 0 to 14 */
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',

    /* second row - indices 15 to 28 */
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', // Enter key

    /* 29 = Control, 30 - 41: third row */
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '#',

    /* fourth row, indices 42 to 54, zeroes are shift-keys*/
    0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,

    '*',

    /* Special keys */

    0, // ALT - 56
    ' ', //  Space - 57
    0, // Caps lock - 58
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //  F1 to F10 - 59 to 68
    0, // Num lock - 69
    0, // Scroll lock - 70
    0, // Home - 71
    0, // Up arrow - 72
    0, // Page up - 73
    '-',
    0, // Left arrow - 75
    0,
    0, // Right arrow -77
    '+',
    0, // End - 79
    0, // Dowm arrow - 80
    0, // Page down - 81
    0, // Insert - 82
    0, // Delete - 83
    0, 0, 0,
    0, // F11 - 87
    0, // F12 - 88
    0, // All others undefined
  },

  // caps
  {
    /* first row - indices 0 to 14 */
    0, 27, '!', '@', '£', '$', '%', '^', '&', '*', '(', ')', '_', '+', '\b',

    /* second row - indices 15 to 28 */
    '\t', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n', // Enter key

    /* 29 = Control, 30 - 41: third row */
    0, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"', '~',

    /* fourth row, indices 42 to 54, zeroes are shift-keys*/
    0, '|', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0,

    '*',

    /* Special keys */

    0, // ALT - 56
    ' ', //  Space - 57
    0, // Caps lock - 58
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //  F1 to F10 - 59 to 68
    0, // Num lock - 69
    0, // Scroll lock - 70
    0, // Home - 71
    0, // Up arrow - 72
    0, // Page up - 73
    '-',
    0, // Left arrow - 75
    0,
    0, // Right arrow -77
    '+',
    0, // End - 79
    0, // Dowm arrow - 80
    0, // Page down - 81
    0, // Insert - 82
    0, // Delete - 83
    0, 0, 0,
    0, // F11 - 87
    0, // F12 - 88
    0, // All others undefined
  },

  // control_map
  {
    29, // Ctrl
    56, // Alt
    0,  // AltGr
    42, // left Shift
    54, // right Shift
    58, // Caps lock
    70, // Scroll lock
    69  // Num lock
  },

  //Set the initial status of all control keys to "not active"
  0
};


keymap_t *current_layout;

// Indices into the circular buffer for the keyboard data.
u32int keyboard_buffer_start, keyboard_buffer_end;
// Circular buffer giving content captured from keyboard.
char keyboard_buffer[256];

void init_keyboard_driver()
{
  register_interrupt_handler(IRQ1, &keyboard_handler);
  switch_layout(&gb);

  keyboard_buffer_start = 0;
  keyboard_buffer_end = 0;
}

char keyboard_getchar()
{
  if (keyboard_buffer_start != keyboard_buffer_end)
    {
      char c = keyboard_buffer[keyboard_buffer_start++];
      // Wrap to the start of the buffer if we went off the end.
      keyboard_buffer_start &= 255;
      return c;
    }
  else return '\0';
}

void switch_layout(keymap_t *layout)
{
  current_layout = layout;
}

void keyboard_handler(registers_t regs)
{

  u8int scancode = io::inb(0x60);

  // Has the key been released? Check bit no. 7
  if(scancode & RELEASED_MASK)
    {
      // We only need to check the first five ones,
      // because they're the only ones doing anything
      // on release
      u32int i;
      for(i = 0; i < 5; i++)
        {
          if(current_layout->control_map[i] == (scancode & ~RELEASED_MASK))
            {
              // releasing the key always disables its function
              current_layout->controls &= ~(1 << i);
              return;
            }
        }
    }
  else
    {
      // check if pressed key was a control key and
      // invert its bit in the status map
      u32int i;
      for(i = 0; i < 8; i++)
        {
          if(current_layout->control_map[i] == scancode)
            {
              //if bit is set, delete it
              if(current_layout->controls & 1 << i)
                current_layout->controls &= ~(1 << i);
              // if not, set it
              else
                current_layout->controls |= 1 << i;
              return;
            }
        }

      // if it was a non-control key, just print it upper or lowercase version
      // depending on the status of the control keys
      u8int *scancodes = current_layout->scancodes;
      if ((current_layout->controls & (LSHIFT | RSHIFT | CAPSLOCK))
          && !(current_layout->controls & CONTROL))
        scancodes = current_layout->shift_scancodes;

      // Avoid buffer overruns if possible.
      if (keyboard_buffer_end != keyboard_buffer_start-1)
        {
          keyboard_buffer[keyboard_buffer_end++] = scancodes[scancode];
          keyboard_buffer_end &= 255;
        }
    }
}
