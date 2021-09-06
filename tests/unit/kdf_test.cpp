#include <gtest/gtest.h>
#include <openssl/core_names.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/kdf.h>
#include <openssl/provider.h>
#include <vector>

#include <utilities/name_generator.hpp>
#include <utilities/ossl_pointers.hpp>
#include <utilities/ossl_tool.hpp>

/*
static std::string
BaseNameGenerator(const testing::TestParamInfo<BaseParam>& info)
{
    auto param = info.param;
    std::string name = param.group;
    NameGeneratorFiltering(name);
    return name;
}*/

class KdfTest : public testing::Test
{
  public:
    void SetUp()
    {
    }

    void TearDown()
    {
        ERR_print_errors_fp(stderr);
    }
};

unsigned char secret[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                          0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
                          0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                          0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};

unsigned char label[] = {0x26, 0xbd, 0xb8, 0x78};

unsigned char seed[] = {0xaf, 0x21, 0x43, 0x41, 0x45, 0x65, 0x63, 0x78};

TEST_F(KdfTest, Derive)
{
    ossl::EvpKdfPtr kdf(EVP_KDF_fetch(nullptr, "kdf_tree12_256", nullptr));
    ASSERT_NE(kdf.get(), nullptr);

    ossl::EvpKdfCtxPtr ctx(EVP_KDF_CTX_new(kdf.get()));
    ASSERT_NE(ctx.get(), nullptr);

    OSSL_PARAM params[4];

    params[0] = OSSL_PARAM_construct_octet_string(OSSL_KDF_PARAM_SECRET, secret,
                                                  sizeof(secret));
    params[1] = OSSL_PARAM_construct_octet_string(OSSL_KDF_PARAM_LABEL, label,
                                                  sizeof(label));
    params[2] = OSSL_PARAM_construct_octet_string(OSSL_KDF_PARAM_SEED, seed,
                                                  sizeof(seed));
    params[3] = OSSL_PARAM_END;

    ASSERT_LT(0, EVP_KDF_CTX_set_params(ctx.get(), params));

    std::vector<uint8_t> key(64);

    ASSERT_LT(0, EVP_KDF_derive(ctx.get(), key.data(), key.size(), nullptr));

    ossl::BioPtr err(BIO_new_fp(stderr, BIO_NOCLOSE));
    BIO_hex_string(err.get(), 0, 32, key.data(), key.size());
}