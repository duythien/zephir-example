
extern zend_class_entry *myapp_normalizechars_ce;

ZEPHIR_INIT_CLASS(Myapp_NormalizeChars);

PHP_METHOD(Myapp_NormalizeChars, testCast1);
PHP_METHOD(Myapp_NormalizeChars, testCast2);
PHP_METHOD(Myapp_NormalizeChars, trans);

ZEND_BEGIN_ARG_INFO_EX(arginfo_myapp_normalizechars_trans, 0, 0, 1)
	ZEND_ARG_INFO(0, s)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(myapp_normalizechars_method_entry) {
	PHP_ME(Myapp_NormalizeChars, testCast1, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Myapp_NormalizeChars, testCast2, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Myapp_NormalizeChars, trans, arginfo_myapp_normalizechars_trans, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
