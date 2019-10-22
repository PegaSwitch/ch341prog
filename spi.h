
#ifndef __SPI_H__
#define __SPI_H__

#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * from u-boot ...
 */

#define DEVICE_TYPE_X8	(8 / 8)
#define DEVICE_TYPE_X16	(16 / 8)
#define DEVICE_TYPE_X32	(32 / 8)

#define SPI_READ_PAGE_SIZE (4*1024)			/* 4K page size */
#define SPI_WRITE_PAGE_SIZE  256

#define MAX_ERASE_REGIONS    4	

struct mtd_erase_region_info 
{
	uint32_t offset;	/* At which this region starts, from the beginning of the MTD */
	uint32_t erasesize;	/* For this region */
	uint32_t numblocks;	/* Number of blocks of erasesize in this region */
};

struct spi_flash_info 
{
	const char *name;
	const uint8_t  mfr_id; /* __u8 */
	const uint16_t dev_id; /* __u16 */
	const uint32_t operationmode; /* __u32 */
	const unsigned long size; /* u_long */
	const unsigned int max_clock;
	const int numeraseregions;
	const uint8_t address32; /* __u8 */
	const struct mtd_erase_region_info regions[MAX_ERASE_REGIONS];
};

struct spi_flash_info *spi_flash_lookup(uint8_t b1, uint8_t b2, uint8_t b3);

#ifdef __cplusplus
}
#endif

#endif
