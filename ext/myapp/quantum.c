
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Myapp_Quantum) {

	ZEPHIR_REGISTER_CLASS(Myapp, Quantum, myapp, quantum, myapp_quantum_method_entry, 0);

	zend_declare_class_constant_double(myapp_quantum_ce, SL("PI"), 3.14159265358979323846 TSRMLS_CC);
	zend_declare_class_constant_long(myapp_quantum_ce, SL("MAX"), 751 TSRMLS_CC);

	return SUCCESS;

}

/*
 
 */
PHP_METHOD(Myapp_Quantum, Harmos) {

	zend_bool _8, _11, _27;
	int i, j, n, _9, _10, _12, _13, _28, _29;
	zval *x_param = NULL, *psr, *psi, *p2, *v, *paramater, *fp, *_0 = NULL, _1 = zval_used_for_init, _2 = zval_used_for_init, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *tmp, *_14, *_15, *_16, *_17, *_18, *_19, *_20, *_21, _22 = zval_used_for_init, *_23, *_24, *_25, *_26, *_30 = NULL;
	double x, dt, dx, k0, item_psr, item_psi;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &x_param);

		x = zephir_get_doubleval(x_param);


	dx = 0.02;
	k0 = (3.0 * 3.14159265358979323846);
	dt = ((dx * dx) / 4.0);
	ZEPHIR_INIT_VAR(paramater);
	array_init_size(paramater, 5);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_DOUBLE(_0, dx);
	zephir_array_fast_append(paramater, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_DOUBLE(_0, k0);
	zephir_array_fast_append(paramater, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_DOUBLE(_0, dt);
	zephir_array_fast_append(paramater, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_DOUBLE(_0, x);
	zephir_array_fast_append(paramater, _0);
	i = 0;
	ZEPHIR_INIT_VAR(psr);
	array_init(psr);
	ZEPHIR_INIT_VAR(psi);
	array_init(psi);
	ZEPHIR_INIT_VAR(p2);
	array_init(p2);
	ZEPHIR_INIT_VAR(v);
	array_init(v);
	ZEPHIR_INIT_VAR(fp);
	array_init(fp);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "harmos.txt", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "w", 0);
	ZEPHIR_INIT_BNVAR(fp);
	zephir_call_func_p2(fp, "fopen", &_1, &_2);
	if (!zephir_is_true(fp)) {
		RETURN_MM_LONG(1);
	}
	while (1) {
		if (!((i <= 751))) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_DOUBLE(&_1, (k0 * x));
		ZEPHIR_INIT_NVAR(_0);
		zephir_call_func_p1(_0, "sin", &_1);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_DOUBLE(&_1, ((x * x) * 2.0));
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_func_p1(_3, "exp", &_1);
		ZEPHIR_INIT_LNVAR(_4);
		div_function(_4, _0, _3 TSRMLS_CC);
		item_psi = zephir_get_numberval(_4);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_DOUBLE(&_1, (k0 * x));
		ZEPHIR_INIT_NVAR(_0);
		zephir_call_func_p1(_0, "cos", &_1);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_DOUBLE(&_1, ((x * x) * 2.0));
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_func_p1(_3, "exp", &_1);
		ZEPHIR_INIT_LNVAR(_5);
		div_function(_5, _0, _3 TSRMLS_CC);
		item_psr = zephir_get_numberval(_5);
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 2);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_DOUBLE(_3, item_psr);
		zephir_array_fast_append(_0, _3);
		zephir_array_update_long(&psr, i, &_0, PH_COPY | PH_SEPARATE, "myapp/quantum.zep", 37);
		ZEPHIR_INIT_NVAR(_3);
		array_init_size(_3, 2);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_DOUBLE(_6, item_psi);
		zephir_array_fast_append(_3, _6);
		zephir_array_update_long(&psi, i, &_3, PH_COPY | PH_SEPARATE, "myapp/quantum.zep", 38);
		ZEPHIR_INIT_NVAR(_6);
		array_init_size(_6, 2);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_DOUBLE(_7, (double) ((double) (5.0 * x) * x));
		zephir_array_fast_append(_6, _7);
		zephir_array_update_long(&v, i, &_6, PH_COPY | PH_SEPARATE, "myapp/quantum.zep", 39);
		x = (x + dx);
		i++;
	}
	i = 1;
	j = 1;
	ZEPHIR_INIT_VAR(tmp);
	array_init_size(tmp, 2);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_DOUBLE(_3, 2.0);
	zephir_array_fast_append(tmp, _3);
	_10 = 20000;
	_9 = 0;
	_8 = 0;
	if ((_9 <= _10)) {
		while (1) {
			if (_8) {
				_9++;
				if (!((_9 <= _10))) {
					break;
				}
			} else {
				_8 = 1;
			}
			n = _9;
			_13 = (751 - 1);
			_12 = 1;
			_11 = 0;
			if ((_12 <= _13)) {
				while (1) {
					if (_11) {
						_12++;
						if (!((_12 <= _13))) {
							break;
						}
					} else {
						_11 = 1;
					}
					i = _12;
					zephir_array_fetch_long(&_14, psr, i, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_15, _14, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_16, paramater, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_17, psi, (i + 1), PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_18, _17, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_19, psi, (i - 1), PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_20, _19, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_1);
					zephir_add_function(&_1, _18, _20 TSRMLS_CC);
					zephir_array_fetch_long(&_18, tmp, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_20, psi, i, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_21, _20, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_2);
					mul_function(&_2, _18, _21 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_4);
					sub_function(_4, &_1, &_2 TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_1);
					mul_function(&_1, _16, _4 TSRMLS_CC);
					zephir_array_fetch_long(&_16, paramater, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_18, paramater, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_4);
					mul_function(_4, _16, _18 TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_2);
					div_function(&_2, &_1, _4 TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_1);
					sub_function(&_1, _15, &_2 TSRMLS_CC);
					zephir_array_fetch_long(&_15, paramater, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_16, v, i, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_18, _16, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_2);
					mul_function(&_2, _15, _18 TSRMLS_CC);
					zephir_array_fetch_long(&_15, psi, i, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_18, _15, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_22);
					mul_function(&_22, &_2, _18 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_4);
					zephir_add_function(_4, &_1, &_22 TSRMLS_CC);
					zephir_array_update_multi(&psr, &_4 TSRMLS_CC, SL("ll"), 2, i, 1);
					zephir_array_fetch_long(&_18, psr, i, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_21, _18, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_23, psr, i, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_24, _23, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_1);
					mul_function(&_1, _21, _24 TSRMLS_CC);
					zephir_array_fetch_long(&_21, psi, i, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_24, _21, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_25, psi, i, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_26, _25, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_2);
					mul_function(&_2, _24, _26 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_5);
					zephir_add_function(_5, &_1, &_2 TSRMLS_CC);
					zephir_array_update_long(&p2, i, &_5, PH_COPY | PH_SEPARATE, "myapp/quantum.zep", 51);
				}
			}
			_29 = (751 - 1);
			_28 = 1;
			_27 = 0;
			if ((_28 <= _29)) {
				while (1) {
					if (_27) {
						_28++;
						if (!((_28 <= _29))) {
							break;
						}
					} else {
						_27 = 1;
					}
					j = _28;
					ZEPHIR_INIT_NVAR(_3);
					ZVAL_LONG(_3, 0);
					zephir_array_update_multi(&psr, &_3 TSRMLS_CC, SL("ll"), 2, 0, 1);
					ZEPHIR_INIT_NVAR(_6);
					ZVAL_LONG(_6, 0);
					zephir_array_update_multi(&psr, &_6 TSRMLS_CC, SL("ll"), 2, 751, 1);
					zephir_array_fetch_long(&_14, psi, j, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_15, _14, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_16, paramater, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_17, psr, (j + 1), PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_18, _17, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_19, psr, (j - 1), PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_20, _19, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_1);
					zephir_add_function(&_1, _18, _20 TSRMLS_CC);
					zephir_array_fetch_long(&_18, tmp, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_20, psr, j, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_21, _20, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_2);
					mul_function(&_2, _18, _21 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_30);
					sub_function(_30, &_1, &_2 TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_1);
					mul_function(&_1, _16, _30 TSRMLS_CC);
					zephir_array_fetch_long(&_16, paramater, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_18, paramater, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_30);
					mul_function(_30, _16, _18 TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_2);
					div_function(&_2, &_1, _30 TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_1);
					zephir_add_function(&_1, _15, &_2 TSRMLS_CC);
					zephir_array_fetch_long(&_15, paramater, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_16, v, j, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_18, _16, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_2);
					mul_function(&_2, _15, _18 TSRMLS_CC);
					zephir_array_fetch_long(&_15, psr, j, PH_NOISY | PH_READONLY TSRMLS_CC);
					zephir_array_fetch_long(&_18, _15, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_22);
					mul_function(&_22, &_2, _18 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_30);
					sub_function(_30, &_1, &_22 TSRMLS_CC);
					zephir_array_update_multi(&psi, &_30 TSRMLS_CC, SL("ll"), 2, j, 1);
				}
			}
			if (((n == 0) || ((n % 2000) == 0))) {
				i = 1;
				while (1) {
					if (!((i < (751 - 1)))) {
						break;
					}
					zephir_array_fetch_long(&_14, p2, i, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_1);
					ZVAL_STRING(&_1, "%16.8lf %16.8lf %16.8lf \n", 0);
					ZEPHIR_SINIT_NVAR(_2);
					ZVAL_DOUBLE(&_2, ((double) i * dx));
					ZEPHIR_SINIT_NVAR(_22);
					ZVAL_DOUBLE(&_22, ((double) n * dt));
					zephir_call_func_p5_noret("fprintf", fp, &_1, &_2, &_22, _14);
					i = (i + 10);
				}
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_STRING(&_1, "\n", 0);
				zephir_call_func_p2_noret("fprintf", fp, &_1);
			}
			j = 1;
			while (1) {
				if (!((j < (751 - 1)))) {
					break;
				}
				zephir_array_fetch_long(&_14, psi, j, PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_fetch_long(&_15, _14, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_update_multi(&psi, &_15 TSRMLS_CC, SL("ll"), 2, j, 0);
				zephir_array_fetch_long(&_16, psr, j, PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_fetch_long(&_17, _16, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_update_multi(&psr, &_17 TSRMLS_CC, SL("ll"), 2, j, 0);
				j++;
			}
		}
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Myapp_Quantum, test) {


	RETURN_STRING("wellcom sitepoint", 1);

}

