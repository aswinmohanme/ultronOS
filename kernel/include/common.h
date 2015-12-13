/*
  * @ File : common.h
  * @Desc : Includes some commonly used Interface routines
*/

#include <system.h>

// @ Define : Some Os Specific Details
#define OS_NAME "ULTRON"
#define OS_ARCH "x86"


// @ Task : Initialises the Descritor Tables
// and pads all interruts with 0
void init_desc_tables();
