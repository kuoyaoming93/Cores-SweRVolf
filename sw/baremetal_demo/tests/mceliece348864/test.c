#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "crypto_kem.h"
#include "randombytes.h"
#include "gf.h"
#include "swervolf_print.h"

#define KAT_SUCCESS          0
#define KAT_CRYPTO_FAILURE  -4

static void phex(uint8_t* str, uint8_t len);

//unsigned char seed[48];

extern unsigned char sk[6492];
extern unsigned char pk[261120];
extern unsigned char ct[128];
extern unsigned char ss[32];

int main(void)
{
    int ret_val;
    int i;
    //unsigned char ct[crypto_kem_CIPHERTEXTBYTES];
    unsigned char ss_encrypt[crypto_kem_BYTES];
    unsigned char ss1[crypto_kem_BYTES];
    /*unsigned char pk[crypto_kem_PUBLICKEYBYTES];
    unsigned char sk[crypto_kem_SECRETKEYBYTES];*/

    /* Init UART for communication */
    init_uart();

    //swerv_printf("\nTesting McEliece 348864\n\n\r");
    //swerv_printf("\nUsing pre-computed private key, ss and ct...\n\r");

    // Create seed
    /*randombytes(seed, 256);
    swerv_printf("seed = ");
    phex(seed,48);

    if ( (ret_val = crypto_kem_keypair(pk, sk)) != 0) {
            swerv_printf("crypto_kem_keypair returned <%d>\n\r", ret_val);
            return KAT_CRYPTO_FAILURE;
        }*/
    //gf result = gf_mul(500,800);
    //gf result2 = gf_mul(1024,512);
    //swerv_printf("Result: %d\n\r",result);
    //swerv_printf("Result2: %d\n\r",result2);

    //swerv_printf("pk = %d\n\r", pk[0]);
    //swerv_printf("sk = %d\n\r", sk[0]);
    //swerv_printf("pk = %d\n\r", pk[261119]);
    //swerv_printf("sk = %d\n\r", sk[6491]);

    /*uint32_t empty_rd;
    asm volatile
    (   
        "ffwidth   %[z], %[x], %[y]\n\r\t"
        : [z] "=r" ((uint32_t)empty_rd)
        : [x] "r" ((uint32_t)12), [y] "r" ((uint32_t)0x1009)
    );  */

    //long time1,time2;
    //time1 = get_mcycle();
    //if ( (ret_val = crypto_kem_enc(ct, ss_encrypt, pk)) != 0) {
    //    swerv_printf("crypto_kem_enc returned <%d>\n\r", ret_val);
    //    return KAT_CRYPTO_FAILURE;
    //}
    //time2 = get_mcycle();
	//swerv_printf("ENC: %d cycles\n\r",time2-time1);
    //swerv_printf("ENC finished\n\r");

    //swerv_printf("ct = %s\n\r", ct);
    //swerv_printf("ss = %s\n\r", ss);

    //time1 = get_mcycle();
    crypto_kem_dec(ss1, ct, sk);
    //if ( (ret_val = crypto_kem_dec(ss1, ct, sk)) != 0) {
    //    swerv_printf("crypto_kem_dec returned <%d>\n\r", ret_val);
    //    return KAT_CRYPTO_FAILURE;
    //}
    //time2 = get_mcycle();
	//swerv_printf("DEC: %d cycles\n\r",time2-time1);

    //swerv_printf("DEC: finished\n\r");
    
    if ( memcmp(ss, ss1, crypto_kem_BYTES) ) {
        swerv_printf("FAIL>\n\r");
        //return KAT_CRYPTO_FAILURE;
    }
    else{
        swerv_printf("OK>\n\r");
    }

    while(1);

    return 0;
}

static void phex(uint8_t* str, uint8_t len)
{
    unsigned char i;
    for (i = 0; i < len; ++i)
        swerv_printf("%02x", str[i]);
    swerv_printf("\n\r");
}






