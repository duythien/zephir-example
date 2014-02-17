
extern zend_class_entry *myapp_quantum_ce;

ZEPHIR_INIT_CLASS(Myapp_Quantum);

PHP_METHOD(Myapp_Quantum, Harmos);
PHP_METHOD(Myapp_Quantum, test);

ZEND_BEGIN_ARG_INFO_EX(arginfo_myapp_quantum_harmos, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(myapp_quantum_method_entry) {
	PHP_ME(Myapp_Quantum, Harmos, arginfo_myapp_quantum_harmos, ZEND_ACC_PUBLIC)
	PHP_ME(Myapp_Quantum, test, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
