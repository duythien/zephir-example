
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_MYAPP_H
#define PHP_MYAPP_H 1

#define ZEPHIR_RELEASE 1

#include "kernel/globals.h"

#define PHP_MYAPP_NAME        "myapp"
#define PHP_MYAPP_VERSION     "0.0.1"
#define PHP_MYAPP_EXTNAME     "myapp"
#define PHP_MYAPP_AUTHOR      ""
#define PHP_MYAPP_ZEPVERSION  "0.4.1a"
#define PHP_MYAPP_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(myapp)

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

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

#define zephir_globals_def myapp_globals
#define zend_zephir_globals_def zend_myapp_globals

extern zend_module_entry myapp_module_entry;
#define phpext_myapp_ptr &myapp_module_entry

#endif
