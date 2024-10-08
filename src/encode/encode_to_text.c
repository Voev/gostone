#include <ctype.h>

#include <openssl/core.h>
#include <openssl/core_dispatch.h>
#include <openssl/core_names.h>
#include <openssl/bn.h>
#include <openssl/err.h>

#include <yag/provider_bio.h>
#include <yag/keymgmt/keymgmt_akey.h>
#include <yag/encode/encode_impl.h>
#include <yag/encode/encode_common.h>
#include <yag/encode/encode_pubkey.h>

static int GsEncodeToText(BIO* out, const void* keyData, int selection)
{
    const GsAsymmKey* key = INTERPRET_AS_CASYMM_KEY(keyData);

    if (!out || !key)
    {
        ERR_raise(ERR_LIB_PROV, ERR_R_PASSED_NULL_PARAMETER);
        return 0;
    }

    if (selection & OSSL_KEYMGMT_SELECT_PRIVATE_KEY)
    {
        const BIGNUM* privateKey = GsAsymmKeyGet0PrivateKey(key);
        BIO_printf(out, "Private key:\n");
        if (privateKey)
        {
            BN_print(out, privateKey);
            BIO_printf(out, "\n");
        }
        else
        {
            BIO_printf(out, "<undefined>\n");
        }
    }
    if (selection & OSSL_KEYMGMT_SELECT_PUBLIC_KEY)
    {
        unsigned char* rawValue = NULL;
        int rawSize = GsSerializePublicKey(key, &rawValue);
        BIO_printf(out, "Public key:\n");
        if (rawSize && 0 < rawSize)
        {
            int half = rawSize / 2;
            BIO_printf(out, "X: ");
            BIO_hex_string(out, -1, 16, rawValue, half);
            BIO_printf(out, "\nY: ");
            BIO_hex_string(out, -1, 16, rawValue + half, half);
            BIO_printf(out, "\n");
            OPENSSL_free(rawValue);
        }
        else
        {
            BIO_printf(out, "<undefined>\n");
        }
    }
    if (selection & OSSL_KEYMGMT_SELECT_DOMAIN_PARAMETERS)
    {
        int algorithm = GsAsymmKeyGetAlgorithm(key);
        int paramset = GsAsymmKeyGetParamset(key);
        BIO_printf(out, "Algorithm: %s\n", OBJ_nid2sn(algorithm));
        BIO_printf(out, "Parameters: %s\n", OBJ_nid2sn(paramset));
    }
    return 1;
}

void* GsEncoderToTextNewCtx(void* provCtx)
{
    return provCtx;
}

void GsEncoderToTextFreeCtx(ossl_unused void* vctx)
{
}

int GsEncoderToTextEncode(void* vctx, OSSL_CORE_BIO* cout, const void* key,
                          const OSSL_PARAM key_abstract[], int selection,
                          ossl_unused OSSL_PASSPHRASE_CALLBACK* cb,
                          ossl_unused void* cbarg)
{
    int ret = 0;
    BIO* out;

    if (key_abstract)
    {
        return 0;
    }
    out = GsProvBioNewFromCoreBio(vctx, cout);
    if (out)
    {
        ret = GsEncodeToText(out, key, selection);
        BIO_free(out);
    }
    return ret;
}
