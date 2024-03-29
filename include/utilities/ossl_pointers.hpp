#pragma once

#include <memory>
#include <openssl/types.h>
#include <openssl/encoder.h>
#include <openssl/decoder.h>
#include <openssl/provider.h>
#include <openssl/evp.h>
#include <openssl/kdf.h>
#include <openssl/x509.h>

template <typename T, void (*f)(T*)> struct static_function_deleter
{
    void operator()(T* t) const
    {
        f(t);
    }
};

#define OSSL_DEFINE_PTR_TYPE(alias, object, deleter)                           \
    using alias##Deleter = static_function_deleter<object, &deleter>;          \
    using alias##Ptr = std::unique_ptr<object, alias##Deleter>

namespace ossl
{

OSSL_DEFINE_PTR_TYPE(LibCtx, OSSL_LIB_CTX, OSSL_LIB_CTX_free);

OSSL_DEFINE_PTR_TYPE(EncoderCtx, OSSL_ENCODER_CTX, OSSL_ENCODER_CTX_free);
OSSL_DEFINE_PTR_TYPE(DecoderCtx, OSSL_DECODER_CTX, OSSL_DECODER_CTX_free);

OSSL_DEFINE_PTR_TYPE(EvpMd, EVP_MD, EVP_MD_free);
OSSL_DEFINE_PTR_TYPE(EvpMdCtx, EVP_MD_CTX, EVP_MD_CTX_free);
OSSL_DEFINE_PTR_TYPE(EvpPkey, EVP_PKEY, EVP_PKEY_free);
OSSL_DEFINE_PTR_TYPE(EvpPkeyCtx, EVP_PKEY_CTX, EVP_PKEY_CTX_free);
OSSL_DEFINE_PTR_TYPE(EvpKdf, EVP_KDF, EVP_KDF_free);
OSSL_DEFINE_PTR_TYPE(EvpKdfCtx, EVP_KDF_CTX, EVP_KDF_CTX_free);

OSSL_DEFINE_PTR_TYPE(X509PubKey, X509_PUBKEY, X509_PUBKEY_free);

OSSL_DEFINE_PTR_TYPE(Bio, BIO, BIO_free_all);

} // namespace ossl
