
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include "php_ext.h"
#include "myapp.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"

zend_class_entry *myapp_normalizechars_ce;
zend_class_entry *myapp_quantum_ce;

ZEND_DECLARE_MODULE_GLOBALS(myapp)

PHP_MINIT_FUNCTION(myapp){

	ZEPHIR_INIT(Myapp_NormalizeChars);
	ZEPHIR_INIT(Myapp_Quantum);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(myapp){

	assert(ZEPHIR_GLOBAL(function_cache) == NULL);
	//assert(ZEPHIR_GLOBAL(orm).parser_cache == NULL);
	//assert(ZEPHIR_GLOBAL(orm).ast_cache == NULL);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_zephir_globals *zephir_globals TSRMLS_DC) {

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache options */
	zephir_globals->function_cache = NULL;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;

}

static PHP_RINIT_FUNCTION(myapp){

	php_zephir_init_globals(ZEPHIR_VGLOBAL TSRMLS_CC);
	//myapp_init_interned_strings(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(myapp){

	if (ZEPHIR_GLOBAL(start_memory) != NULL) {
		zephir_clean_restore_stack(TSRMLS_C);
	}

	if (ZEPHIR_GLOBAL(function_cache) != NULL) {
		zend_hash_destroy(ZEPHIR_GLOBAL(function_cache));
		FREE_HASHTABLE(ZEPHIR_GLOBAL(function_cache));
		ZEPHIR_GLOBAL(function_cache) = NULL;
	}

	return SUCCESS;
}

static PHP_MINFO_FUNCTION(myapp)
{
	php_info_print_table_start();
	php_info_print_table_header(2, PHP_MYAPP_NAME, "enabled");
	php_info_print_table_row(2, "Version", PHP_MYAPP_VERSION);
	php_info_print_table_end();
}

static PHP_GINIT_FUNCTION(myapp)
{
	zephir_memory_entry *start;

	php_zephir_init_globals(myapp_globals TSRMLS_CC);

	/* Start Memory Frame */
	start = (zephir_memory_entry *) pecalloc(1, sizeof(zephir_memory_entry), 1);
	start->addresses       = pecalloc(16, sizeof(zval*), 1);
	start->capacity        = 16;
	start->hash_addresses  = pecalloc(4, sizeof(zval*), 1);
	start->hash_capacity   = 4;

	myapp_globals->start_memory = start;

	/* Global Constants */
	ALLOC_PERMANENT_ZVAL(myapp_globals->global_false);
	INIT_PZVAL(myapp_globals->global_false);
	ZVAL_FALSE(myapp_globals->global_false);
	Z_ADDREF_P(myapp_globals->global_false);

	ALLOC_PERMANENT_ZVAL(myapp_globals->global_true);
	INIT_PZVAL(myapp_globals->global_true);
	ZVAL_TRUE(myapp_globals->global_true);
	Z_ADDREF_P(myapp_globals->global_true);

	ALLOC_PERMANENT_ZVAL(myapp_globals->global_null);
	INIT_PZVAL(myapp_globals->global_null);
	ZVAL_NULL(myapp_globals->global_null);
	Z_ADDREF_P(myapp_globals->global_null);

}

static PHP_GSHUTDOWN_FUNCTION(myapp)
{
	assert(myapp_globals->start_memory != NULL);

	pefree(myapp_globals->start_memory->hash_addresses, 1);
	pefree(myapp_globals->start_memory->addresses, 1);
	pefree(myapp_globals->start_memory, 1);
	myapp_globals->start_memory = NULL;
}

zend_module_entry myapp_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_MYAPP_EXTNAME,
	NULL,
	PHP_MINIT(myapp),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(myapp),
#else
	NULL,
#endif
	PHP_RINIT(myapp),
	PHP_RSHUTDOWN(myapp),
	PHP_MINFO(myapp),
	PHP_MYAPP_VERSION,
	ZEND_MODULE_GLOBALS(myapp),
	PHP_GINIT(myapp),
	PHP_GSHUTDOWN(myapp),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_MYAPP
ZEND_GET_MODULE(myapp)
#endif
