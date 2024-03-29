#pragma once
#include <openssl/core_dispatch.h>

OSSL_FUNC_encoder_newctx_fn GsEncoderNewCtx;
OSSL_FUNC_encoder_freectx_fn GsEncoderFreeCtx;

OSSL_FUNC_encoder_newctx_fn GsEncoderToTextNewCtx;
OSSL_FUNC_encoder_freectx_fn GsEncoderToTextFreeCtx;

OSSL_FUNC_encoder_does_selection_fn GsEncoderDoesPrivateKeyInfoSelection;
OSSL_FUNC_encoder_does_selection_fn GsEncoderDoesSubjectPublicKeyInfoSelection;
OSSL_FUNC_encoder_does_selection_fn GsEncoderDoesTypeSpecificSelection;

OSSL_FUNC_encoder_set_ctx_params_fn GsEncoderSetCtxParams;
OSSL_FUNC_encoder_settable_ctx_params_fn GsEncoderSettableCtxParams;

OSSL_FUNC_encoder_encode_fn GsEncoderEncodePrivateKeyInfoToDer;
OSSL_FUNC_encoder_encode_fn GsEncoderEncodePrivateKeyInfoToPem;
OSSL_FUNC_encoder_encode_fn GsEncoderEncodeSubjectPublicKeyInfoToDer;
OSSL_FUNC_encoder_encode_fn GsEncoderEncodeSubjectPublicKeyInfoToPem;
OSSL_FUNC_encoder_encode_fn GsEncoderEncodeTypeSpecificToDer;
OSSL_FUNC_encoder_encode_fn GsEncoderEncodeTypeSpecificToPem;
OSSL_FUNC_encoder_encode_fn GsEncoderToTextEncode;

OSSL_FUNC_encoder_import_object_fn GsEncoderImportObject;
OSSL_FUNC_encoder_free_object_fn GsEncoderFreeObject;
