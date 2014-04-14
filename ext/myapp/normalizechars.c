
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * X
 */
ZEPHIR_INIT_CLASS(Myapp_NormalizeChars) {

	ZEPHIR_REGISTER_CLASS(Myapp, NormalizeChars, myapp, normalizechars, myapp_normalizechars_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Myapp_NormalizeChars, testCast1) {


	RETURN_LONG((int) 5.0);

}

PHP_METHOD(Myapp_NormalizeChars, testCast2) {


	RETURN_LONG(1);

}

PHP_METHOD(Myapp_NormalizeChars, trans) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *s, *replace;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &s);



	ZEPHIR_INIT_VAR(replace);
	array_init_size(replace, 173);
	add_assoc_stringl_ex(replace, SS("ế"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("ề"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("ể"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("ễ"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("ệ"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("Ế"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("Ề"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("Ể"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("Ễ"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("Ệ"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("é"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("è"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("ẻ"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("ẽ"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("ẹ"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("ê"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("É"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("È"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("Ẻ"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("Ẽ"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("Ẹ"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("Ê"), SL("e"), 1);
	add_assoc_stringl_ex(replace, SS("í"), SL("i"), 1);
	add_assoc_stringl_ex(replace, SS("ì"), SL("i"), 1);
	add_assoc_stringl_ex(replace, SS("ỉ"), SL("i"), 1);
	add_assoc_stringl_ex(replace, SS("ĩ"), SL("i"), 1);
	add_assoc_stringl_ex(replace, SS("ị"), SL("i"), 1);
	add_assoc_stringl_ex(replace, SS("Í"), SL("i"), 1);
	add_assoc_stringl_ex(replace, SS("Ì"), SL("i"), 1);
	add_assoc_stringl_ex(replace, SS("Ỉ"), SL("i"), 1);
	add_assoc_stringl_ex(replace, SS("Ĩ"), SL("i"), 1);
	add_assoc_stringl_ex(replace, SS("Ị"), SL("i"), 1);
	add_assoc_stringl_ex(replace, SS("ố"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ồ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ổ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ỗ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ộ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ố"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ồ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ổ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ô"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ộ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ớ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ờ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ở"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ỡ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ợ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ớ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ờ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ở"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ỡ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ợ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ứ"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("ừ"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("ử"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("ữ"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("ự"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("Ứ"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("Ừ"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("Ử"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("Ữ"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("Ự"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("ý"), SL("y"), 1);
	add_assoc_stringl_ex(replace, SS("ỳ"), SL("y"), 1);
	add_assoc_stringl_ex(replace, SS("ỷ"), SL("y"), 1);
	add_assoc_stringl_ex(replace, SS("ỹ"), SL("y"), 1);
	add_assoc_stringl_ex(replace, SS("ỵ"), SL("y"), 1);
	add_assoc_stringl_ex(replace, SS("Ý"), SL("y"), 1);
	add_assoc_stringl_ex(replace, SS("Ỳ"), SL("y"), 1);
	add_assoc_stringl_ex(replace, SS("Ỷ"), SL("y"), 1);
	add_assoc_stringl_ex(replace, SS("Ỹ"), SL("y"), 1);
	add_assoc_stringl_ex(replace, SS("Ỵ"), SL("y"), 1);
	add_assoc_stringl_ex(replace, SS("Đ"), SL("d"), 1);
	add_assoc_stringl_ex(replace, SS("đ"), SL("d"), 1);
	add_assoc_stringl_ex(replace, SS("ó"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ò"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ỏ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("õ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ọ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ô"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ơ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ó"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ò"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ỏ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Õ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ọ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ô"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("Ơ"), SL("o"), 1);
	add_assoc_stringl_ex(replace, SS("ú"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("ù"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("ủ"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("ũ"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("ụ"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("ư"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("Ú"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("Ù"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("Ủ"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("Ũ"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("Ụ"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("Ư"), SL("u"), 1);
	add_assoc_stringl_ex(replace, SS("ấ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("ầ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("ẩ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("ẫ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("ậ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Ấ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Ầ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Ẩ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Ẫ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Ậ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("ắ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("ằ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("ẳ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("ẵ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("ặ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Ắ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Ằ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Ẳ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Ẵ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Ặ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Á"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("À"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Ả"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Ã"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Ạ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Â"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("Ă"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("ả"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("ã"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("ạ"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("â"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("ă"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("à"), SL("a"), 1);
	add_assoc_stringl_ex(replace, SS("á"), SL("a"), 1);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", &_0, s, replace);
	zephir_check_call_status();
	RETURN_MM();

}

