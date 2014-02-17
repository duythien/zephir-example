

#ifndef PHP_MYAPP_H
#define PHP_MYAPP_H 1

#include "kernel/globals.h"

#define PHP_MYAPP_NAME    "myapp"
#define PHP_MYAPP_VERSION "0.0.1"
#define PHP_MYAPP_EXTNAME "myapp"



ZEND_BEGIN_MODULE_GLOBALS(myapp)

	/* Memory */
	zephir_memory_entry *start_memory;
	zephir_memory_entry *active_memory;

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/* Function cache */
	HashTable *function_cache;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(myapp)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(myapp)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(myapp_globals_id, zend_myapp_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (myapp_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_myapp_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(myapp_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(myapp_globals)
#endif

#define zephir_globals myapp_globals
#define zend_zephir_globals zend_myapp_globals

extern zend_module_entry myapp_module_entry;
#define phpext_myapp_ptr &myapp_module_entry

#endif
