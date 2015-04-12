#include <stdint.h>
#define LINK_ADULT  0
#define LINK_CHILD  1

typedef struct{
    uint32_t    respawn_exit_n; /* 0x0004 */
    uint32_t    age;        /* 0x0008 */
    uint8_t __pad_00[0x014];/* 0x001C */
    char    str[5];     /* 0x0021   "ZELDA" in created file */
    uint8_t __pad_01[0x001];/* 0x0022 */
    uint16_t    death_count;    /* 0x0024 */
    uint8_t name[8];    /* 0x002C Special char encoding */
    uint8_t     __pad_02[0x006];/* 0x0032 */
    uint32_t    rupee_count;    /* 0x0036 */
    uint8_t __pad_03[0x002];/* 0x0038 */
    uint16_t    scene_count;    /* 0x003A May be uint32_t */
    uint8_t __pad_04[0xE2A];/* 0x0E64 */
    struct
    {
        float       x, y, z;    /* 0x0E70 */
        uint16_t    y_rot;      /* 0x0E72 */
        uint8_t     __pad_00[0x8];  /* 0x0E7A */
        uint16_t    scene_no;   /* 0x0E7C */
        uint32_t    map_no;     /* 0x0E80 */
        uint32_t    isset;      /* 0x0E84 */
    }
    farore_warp;
    uint8_t __pad_05[0x4CE];/* 0x1352 */
    uint16_t    chksum;     /* 0x1354 */
    uint8_t __pad_06[0x0FC];/* 0x1540 */
} z_save_file;

typedef struct{
    uint8_t sound_opt;
    uint8_t ztarget_opt;
    char tag[5]; /* "ZELDA" (not null terminated) */
    z_save_file files[3];
} z_save;

    void
calc_chksum( z_save_file *f ){
    int16_t *data = (int16_t*)(f);
    int sum = 0;
    int i;

    f->chksum = 0;

    for( i = 0; i < 0x9A9; i++ )
    {
        sum += data[i];
        sum &= 0xFFFF;
    }

    f->chksum = (uint16_t)sum;
}
