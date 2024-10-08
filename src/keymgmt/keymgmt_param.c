#include <openssl/bn.h>
#include <openssl/ec.h>
#include <openssl/err.h>
#include <openssl/objects.h>
#include <yag/keymgmt/keymgmt_params.h>

struct GostR3410Params_st
{
    const int nid;
    const char* a;
    const char* b;
    const char* p;
    const char* q;
    const char* x;
    const char* y;
    const char* cofactor;
};
typedef struct GostR3410Params_st GostR3410Params;

static
GostR3410Params gGostR3410_256_paramset[] =
{
    /* 1.2.643.2.2.35.0 */
    {NID_id_GostR3410_2001_TestParamSet,
     "7",
     "5FBFF498AA938CE739B8E022FBAFEF40563F6E6A3472FC2A514C0CE9DAE23B7E",
     "8000000000000000000000000000000000000000000000000000000000000431",
     "8000000000000000000000000000000150FE8A1892976154C59CFC193ACCF5B3",
     "2",
     "08E2A8A0E65147D4BD6316030E16D19C85C97F0A9CA267122B96ABBCEA7E8FC8",
     "1"},
    /* 1.2.643.2.2.35.1 */
    {NID_id_GostR3410_2001_CryptoPro_A_ParamSet,
     "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD94",
     "a6",
     "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD97",
     "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6C611070995AD10045841B09B761B893",
     "1",
     "8D91E471E0989CDA27DF505A453F2B7635294F2DDF23E3B122ACC99C9E9F1E14",
     "1"},
    /* 1.2.643.2.2.35.2 */
    {NID_id_GostR3410_2001_CryptoPro_B_ParamSet,
     "8000000000000000000000000000000000000000000000000000000000000C96",
     "3E1AF419A269A5F866A7D3C25C3DF80AE979259373FF2B182F49D4CE7E1BBC8B",
     "8000000000000000000000000000000000000000000000000000000000000C99",
     "800000000000000000000000000000015F700CFFF1A624E5E497161BCC8A198F",
     "1",
     "3FA8124359F96680B83D1C3EB2C070E5C545C9858D03ECFB744BF8D717717EFC",
     "1"},
    /* 1.2.643.2.2.35.3 */
    {NID_id_GostR3410_2001_CryptoPro_C_ParamSet,
     "9B9F605F5A858107AB1EC85E6B41C8AACF846E86789051D37998F7B9022D7598",
     "805a",
     "9B9F605F5A858107AB1EC85E6B41C8AACF846E86789051D37998F7B9022D759B",
     "9B9F605F5A858107AB1EC85E6B41C8AA582CA3511EDDFB74F02F3A6598980BB9",
     "0",
     "41ECE55743711A8C3CBF3783CD08C0EE4D4DC440D4641A8F366E550DFDB3BB67",
     "1"},
    /* 1.2.643.2.2.36.0 */
    {NID_id_GostR3410_2001_CryptoPro_XchA_ParamSet,
     "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD94",
     "a6",
     "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD97",
     "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6C611070995AD10045841B09B761B893",
     "1",
     "8D91E471E0989CDA27DF505A453F2B7635294F2DDF23E3B122ACC99C9E9F1E14",
     "1"},
    /* 1.2.643.2.2.36.1 */
    {NID_id_GostR3410_2001_CryptoPro_XchB_ParamSet,
     "9B9F605F5A858107AB1EC85E6B41C8AACF846E86789051D37998F7B9022D7598",
     "805a",
     "9B9F605F5A858107AB1EC85E6B41C8AACF846E86789051D37998F7B9022D759B",
     "9B9F605F5A858107AB1EC85E6B41C8AA582CA3511EDDFB74F02F3A6598980BB9",
     "0",
     "41ECE55743711A8C3CBF3783CD08C0EE4D4DC440D4641A8F366E550DFDB3BB67",
     "1"},
    {NID_id_tc26_gost_3410_2012_256_paramSetA,
     /* a */
     "C2173F1513981673AF4892C23035A27CE25E2013BF95AA33B22C656F277E7335",
     /* b */
     "295F9BAE7428ED9CCC20E7C359A9D41A22FCCD9108E17BF7BA9337A6F8AE9513",
     /* p */
     "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD97",
     /* q */
     "400000000000000000000000000000000FD8CDDFC87B6635C115AF556C360C67",
     /* x */
     "91E38443A5E82C0D880923425712B2BB658B9196932E02C78B2582FE742DAA28",
     /* y */
     "32879423AB1A0375895786C4BB46E9565FDE0B5344766740AF268ADB32322E5C",
     "4"}
};

static
GostR3410Params gGostR3410_512_paramset[] =
{
    {NID_id_tc26_gost_3410_2012_512_paramSetA,
     /* a */
     "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"
     "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDC4",
     /* b */
     "E8C2505DEDFC86DDC1BD0B2B6667F1DA34B82574761CB0E879BD081CFD0B6265"
     "EE3CB090F30D27614CB4574010DA90DD862EF9D4EBEE4761503190785A71C760",
     /* p */
     "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"
     "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDC7",
     /* q */
     "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"
     "27E69532F48D89116FF22B8D4E0560609B4B38ABFAD2B85DCACDB1411F10B275",
     /* x */
     "3",
     /* y */
     "7503CFE87A836AE3A61B8816E25450E6CE5E1C93ACF1ABC1778064FDCBEFA921DF16"
     "26BE4FD036E93D75E6A50E3A41E98028FE5FC235F5B889A589CB5215F2A4",
     "1"}
    ,
    {NID_id_tc26_gost_3410_2012_512_paramSetB,
     /* a */
     "8000000000000000000000000000000000000000000000000000000000000000"
     "000000000000000000000000000000000000000000000000000000000000006C",
     /* b */
     "687D1B459DC841457E3E06CF6F5E2517B97C7D614AF138BCBF85DC806C4B289F"
     "3E965D2DB1416D217F8B276FAD1AB69C50F78BEE1FA3106EFB8CCBC7C5140116",
     /* p */
     "8000000000000000000000000000000000000000000000000000000000000000"
     "000000000000000000000000000000000000000000000000000000000000006F",
     /* q */
     "8000000000000000000000000000000000000000000000000000000000000001"
     "49A1EC142565A545ACFDB77BD9D40CFA8B996712101BEA0EC6346C54374F25BD",
     /* x */
     "2",
     /* y */
     "1A8F7EDA389B094C2C071E3647A8940F3C123B697578C213BE6DD9E6C8EC7335"
     "DCB228FD1EDF4A39152CBCAAF8C0398828041055F94CEEEC7E21340780FE41BD",
     "1"},
    {NID_id_tc26_gost_3410_2012_512_paramSetC,
     /* a */
     "DC9203E514A721875485A529D2C722FB187BC8980EB866644DE41C68E1430645"
     "46E861C0E2C9EDD92ADE71F46FCF50FF2AD97F951FDA9F2A2EB6546F39689BD3",
     /* b */
     "B4C4EE28CEBC6C2C8AC12952CF37F16AC7EFB6A9F69F4B57FFDA2E4F0DE5ADE0"
     "38CBC2FFF719D2C18DE0284B8BFEF3B52B8CC7A5F5BF0A3C8D2319A5312557E1",
     /* p */
     "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"
     "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDC7",
     /* q */
     "3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"
     "C98CDBA46506AB004C33A9FF5147502CC8EDA9E7A769A12694623CEF47F023ED",
     /* x */
     "E2E31EDFC23DE7BDEBE241CE593EF5DE2295B7A9CBAEF021D385F7074CEA043A"
     "A27272A7AE602BF2A7B9033DB9ED3610C6FB85487EAE97AAC5BC7928C1950148",
     /* y */
     "F5CE40D95B5EB899ABBCCFF5911CB8577939804D6527378B8C108C3D2090FF9B"
     "E18E2D33E3021ED2EF32D85822423B6304F726AA854BAE07D0396E9A9ADDC40F",
     "4"}
};

static
GostR3410Params* GsGetEcGroupParams( const char* name )
{
    GostR3410Params* params;
    int nid = OBJ_sn2nid( name );

    switch( nid )
    {
    case NID_id_tc26_gost_3410_2012_256_paramSetB:
    {
        nid = NID_id_GostR3410_2001_CryptoPro_A_ParamSet;
        break;
    }
    case NID_id_tc26_gost_3410_2012_256_paramSetC:
    {
        nid = NID_id_GostR3410_2001_CryptoPro_B_ParamSet;
        break;
    }
    case NID_id_tc26_gost_3410_2012_256_paramSetD:
    {
        nid = NID_id_GostR3410_2001_CryptoPro_C_ParamSet;
        break;
    }
    default:
        break;
    }
    if( NID_undef != nid )
    {
        params = gGostR3410_512_paramset;
        while( NID_undef != params->nid ) 
        {
            if( nid == params->nid )
            {
                return params;
            }
            params++;
        }
        params = gGostR3410_256_paramset;
        while( NID_undef != params->nid ) 
        {
            if( nid == params->nid )
            {
                return params;
            }
            params++;
        }
    }
    return NULL;
}

static 
GostR3410Params* GsExtractEcGroupParams( const OSSL_PARAM* param )
{
    if( param )
    {
        const char* curveName = NULL;

        switch( param->data_type )
        {
        case OSSL_PARAM_UTF8_STRING:
        {
            curveName = param->data;
            break;
        }
        case OSSL_PARAM_UTF8_PTR:
        {
            OSSL_PARAM_get_utf8_ptr( param, &curveName );
            break;
        }
        default:
            break;
        }
        return GsGetEcGroupParams( curveName );
    }
    return NULL;
}

static 
EC_GROUP* GsCreateEcGroup( GostR3410Params* params, BN_CTX* ctx )
{
    BIGNUM* p = BN_CTX_get( ctx );
    BIGNUM* a = BN_CTX_get( ctx ); 
    BIGNUM* b = BN_CTX_get( ctx );

    if( !p || !a || !b )
    {
        ERR_raise( ERR_LIB_PROP, ERR_R_MALLOC_FAILURE );
        return NULL;
    }
    
    if( !BN_hex2bn( &p, params->p ) ||
        !BN_hex2bn( &a, params->a ) ||
        !BN_hex2bn( &b, params->b ) )
    {
        return NULL;
    }
    return EC_GROUP_new_curve_GFp( p, a, b, ctx );
}

static
int GsSetEcGenerator( EC_GROUP* group, GostR3410Params* params, BN_CTX* ctx )
{
    BIGNUM* x = BN_CTX_get( ctx ); 
    BIGNUM* y = BN_CTX_get( ctx );
    BIGNUM* q = BN_CTX_get( ctx ); 
    BIGNUM* cofactor = BN_CTX_get( ctx );
    EC_POINT* P;

    if( !x || !y || !q || !cofactor )
    {
        ERR_raise( ERR_LIB_PROP, ERR_R_MALLOC_FAILURE );
        return 0;
    }

    if( !BN_hex2bn( &x, params->x ) ||
        !BN_hex2bn( &y, params->y ) ||
        !BN_hex2bn( &q, params->q ) ||
        !BN_hex2bn( &cofactor, params->cofactor ) )
    {
        return 0;
    }

    P = EC_POINT_new( group );
    if( !P )
    {
        ERR_raise( ERR_LIB_PROP, ERR_R_MALLOC_FAILURE );
        return 0;
    }
    
    if( !EC_POINT_set_affine_coordinates( group, P, x, y, ctx ) ||
        !EC_GROUP_set_generator( group, P, q, cofactor ) )
    {
        EC_POINT_free( P );
        return 0;
    }
    EC_POINT_free( P );
    return 1;
}

EC_GROUP* GsGetEcGroup( const OSSL_PARAM* param )
{
    GostR3410Params* params = NULL;
    EC_GROUP* group = NULL;
    BN_CTX* ctx = NULL;
    int ret = 0;

    params = GsExtractEcGroupParams( param );
    if( !params )
    {
        goto end;
    }

    ctx = BN_CTX_new_ex( NULL );
    if( !ctx )
    {
        goto end;
    }

    group = GsCreateEcGroup( params, ctx );
    if( !group )
    {
        goto end;
    }

    if( !GsSetEcGenerator( group, params, ctx ) )
    {
        goto end;
    }

    EC_GROUP_set_curve_name( group, params->nid );
    ret = 1;
end:
    if( !ret )
    {
        EC_GROUP_free( group );
        group = NULL;
    }
    BN_CTX_free( ctx );
    return group;
}
