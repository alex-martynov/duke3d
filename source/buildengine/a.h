/*
 * "Build Engine & Tools" Copyright (c) 1993-1997 Ken Silverman
 * Ken Silverman's official web site: "http://www.advsys.net/ken"
 * See the included license file "BUILDLIC.TXT" for license info.
 * This file IS NOT A PART OF Ken Silverman's original release
 */

#ifndef _INCLUDE_A_H_
#define _INCLUDE_A_H_

#if (defined __WATCOMC__)
#error Do not include this header with Watcom C.
#endif

#include <stdint.h>

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Arguments typed intptr_t carry addresses (framebuffer, texture or
 *  palette pointers); the rest are 32-bit fixed-point values whose
 *  wraparound the inner loops depend on.
 */
long mmxoverlay(void);
void sethlinesizes(long,long,intptr_t);
void setpalookupaddress(unsigned char *);
void setuphlineasm4(long,long);
void hlineasm4(long,unsigned long,long,unsigned long,unsigned long,intptr_t);
void setuprhlineasm4(long,long,long,intptr_t,long,long);
void rhlineasm4(long,intptr_t,long,unsigned long,unsigned long,intptr_t);
void setuprmhlineasm4(long,long,long,intptr_t,long,long);
void rmhlineasm4(long,intptr_t,long,long,long,intptr_t);
void setupqrhlineasm4(long,long,long,intptr_t,long,long);
void qrhlineasm4(long,intptr_t,long,long,long,intptr_t);
void setvlinebpl(long);
void fixtransluscence(intptr_t);
long prevlineasm1(long,intptr_t,long,long,intptr_t,intptr_t);
long vlineasm1(long,intptr_t,long,long,intptr_t,intptr_t);
void setuptvlineasm(long);
long tvlineasm1(long,intptr_t,long,long,intptr_t,intptr_t);
void setuptvlineasm2(long,intptr_t,intptr_t);
void tvlineasm2(unsigned long,unsigned long,uintptr_t,uintptr_t,unsigned long,uintptr_t);
long mvlineasm1(long,intptr_t,long,long,intptr_t,intptr_t);
void setupvlineasm(long);
void vlineasm4(long,intptr_t);
void setupmvlineasm(long);
void mvlineasm4(long,intptr_t);
void setupspritevline(intptr_t,long,long,long,long,long);
void spritevline(long,unsigned long,long,unsigned long,intptr_t,intptr_t);
void msetupspritevline(intptr_t,long,long,long,long,long);
void mspritevline(long,long,long,long,intptr_t,intptr_t);
void tsetupspritevline(intptr_t,long,long,long,long,long);
void tspritevline(long,long,long,unsigned long,intptr_t,intptr_t);
void mhline(intptr_t,long,long,long,long,intptr_t);
void mhlineskipmodify(long,unsigned long,unsigned long,long,long,intptr_t);
void msethlineshift(long,long);
void thline(intptr_t,long,long,long,long,intptr_t);
void thlineskipmodify(long,unsigned long,unsigned long,long,long,intptr_t);
void tsethlineshift(long,long);
void setupslopevlin(long,intptr_t,long);
void slopevlin(intptr_t,unsigned long,intptr_t,long,long,long);
void settransnormal(void);
void settransreverse(void);
long setupdrawslab(long,intptr_t);
long drawslab(long,long,long,long,intptr_t,intptr_t);
long stretchhline(long,long,long,long,long,long);
long is_vmware_running(void);

/* Dithered texture filtering: sub-texel offsets, in 1/256 texel, by [y&1][x&1]. */
extern const signed char texdither_u[2][2];
extern const signed char texdither_v[2][2];
void hlineasm4_dither(long,long,unsigned long,unsigned long,intptr_t,long,long);

    /* !!! This part might be better stated as "USE_ASM".  --ryan. */
#ifdef USE_I386_ASM
  long asm_mmxoverlay(void);
  long asm_sethlinesizes(long,long,long);
  long asm_setpalookupaddress(char *);
  long asm_setuphlineasm4(long,long);
  long asm_hlineasm4(long,long,long,long,long,long);
  long asm_setuprhlineasm4(long,long,long,long,long,long);
  long asm_rhlineasm4(long,long,long,long,long,long);
  long asm_setuprmhlineasm4(long,long,long,long,long,long);
  long asm_rmhlineasm4(long,long,long,long,long,long);
  long asm_setupqrhlineasm4(long,long,long,long,long,long);
  long asm_qrhlineasm4(long,long,long,long,long,long);
  long asm_setvlinebpl(long);
  long asm_fixtransluscence(long);
  long asm_prevlineasm1(long,long,long,long,long,long);
  long asm_vlineasm1(long,long,long,long,long,long);
  long asm_setuptvlineasm(long);
  long asm_tvlineasm1(long,long,long,long,long,long);
  long asm_setuptvlineasm2(long,long,long);
  long asm_tvlineasm2(long,long,long,long,long,long);
  long asm_mvlineasm1(long,long,long,long,long,long);
  long asm_setupvlineasm(long);
  long asm_vlineasm4(long,long);
  long asm_setupmvlineasm(long);
  long asm_mvlineasm4(long,long);
  void asm_setupspritevline(long,long,long,long,long,long);
  void asm_spritevline(long,long,long,long,long,long);
  void asm_msetupspritevline(long,long,long,long,long,long);
  void asm_mspritevline(long,long,long,long,long,long);
  void asm_tsetupspritevline(long,long,long,long,long,long);
  void asm_tspritevline(long,long,long,long,long,long);
  long asm_mhline(long,long,long,long,long,long);
  long asm_mhlineskipmodify(long,long,long,long,long,long);
  long asm_msethlineshift(long,long);
  long asm_thline(long,long,long,long,long,long);
  long asm_thlineskipmodify(long,long,long,long,long,long);
  long asm_tsethlineshift(long,long);
  long asm_setupslopevlin(long,long,long);
  long asm_slopevlin(long,long,long,long,long,long);
  long asm_settransnormal(void);
  long asm_settransreverse(void);
  long asm_setupdrawslab(long,long);
  long asm_drawslab(long,long,long,long,long,long);
  long asm_stretchhline(long,long,long,long,long,long);
  long asm_isvmwarerunning(void);

  /*
   * !!! I need a reference to this, for mprotect(), but the actual function
   * !!!  is never called in BUILD...just from other ASM routines. --ryan.
   */
  long asm_prohlineasm4(void);

  #if ((defined __GNUC__) && (!defined C_IDENTIFIERS_UNDERSCORED))

    long asm_mmxoverlay(void) __attribute__ ((alias ("_asm_mmxoverlay")));
    long asm_sethlinesizes(long,long,long) __attribute__ ((alias ("_asm_sethlinesizes")));
    long asm_setpalookupaddress(char *) __attribute__ ((alias ("_asm_setpalookupaddress")));
    long asm_setuphlineasm4(long,long) __attribute__ ((alias ("_asm_setuphlineasm4")));
    long asm_hlineasm4(long,long,long,long,long,long) __attribute__ ((alias ("_asm_hlineasm4")));
    long asm_setuprhlineasm4(long,long,long,long,long,long) __attribute__ ((alias ("_asm_setuprhlineasm4")));
    long asm_rhlineasm4(long,long,long,long,long,long) __attribute__ ((alias ("_asm_rhlineasm4")));
    long asm_setuprmhlineasm4(long,long,long,long,long,long) __attribute__ ((alias ("_asm_setuprmhlineasm4")));
    long asm_rmhlineasm4(long,long,long,long,long,long) __attribute__ ((alias ("_asm_rmhlineasm4")));
    long asm_setupqrhlineasm4(long,long,long,long,long,long) __attribute__ ((alias ("_asm_setupqrhlineasm4")));
    long asm_qrhlineasm4(long,long,long,long,long,long) __attribute__ ((alias ("_asm_qrhlineasm4")));
    long asm_setvlinebpl(long) __attribute__ ((alias ("_asm_setvlinebpl")));
    long asm_fixtransluscence(long) __attribute__ ((alias ("_asm_fixtransluscence")));
    long asm_prevlineasm1(long,long,long,long,long,long) __attribute__ ((alias ("_asm_prevlineasm1")));
    long asm_vlineasm1(long,long,long,long,long,long) __attribute__ ((alias ("_asm_vlineasm1")));
    long asm_setuptvlineasm(long) __attribute__ ((alias ("_asm_setuptvlineasm")));
    long asm_tvlineasm1(long,long,long,long,long,long) __attribute__ ((alias ("_asm_tvlineasm1")));
    long asm_setuptvlineasm2(long,long,long) __attribute__ ((alias ("_asm_setuptvlineasm2")));
    long asm_tvlineasm2(long,long,long,long,long,long) __attribute__ ((alias ("_asm_tvlineasm2")));
    long asm_mvlineasm1(long,long,long,long,long,long) __attribute__ ((alias ("_asm_mvlineasm1")));
    long asm_setupvlineasm(long) __attribute__ ((alias ("_asm_setupvlineasm")));
    long asm_vlineasm4(long,long) __attribute__ ((alias ("_asm_vlineasm4")));
    long asm_setupmvlineasm(long) __attribute__ ((alias ("_asm_setupmvlineasm")));
    long asm_mvlineasm4(long,long) __attribute__ ((alias ("_asm_mvlineasm4")));
    void asm_setupspritevline(long,long,long,long,long,long) __attribute__ ((alias ("_asm_setupspritevline")));
    void asm_spritevline(long,long,long,long,long,long) __attribute__ ((alias ("_asm_spritevline")));
    void asm_msetupspritevline(long,long,long,long,long,long) __attribute__ ((alias ("_asm_msetupspritevline")));
    void asm_mspritevline(long,long,long,long,long,long) __attribute__ ((alias ("_asm_mspritevline")));
    void asm_tsetupspritevline(long,long,long,long,long,long) __attribute__ ((alias ("_asm_tsetupspritevline")));
    void asm_tspritevline(long,long,long,long,long,long) __attribute__ ((alias ("_asm_tspritevline")));
    long asm_mhline(long,long,long,long,long,long) __attribute__ ((alias ("_asm_mhline")));
    long asm_mhlineskipmodify(long,long,long,long,long,long) __attribute__ ((alias ("_asm_mhlineskipmodify")));
    long asm_msethlineshift(long,long) __attribute__ ((alias ("_asm_msethlineshift")));
    long asm_thline(long,long,long,long,long,long) __attribute__ ((alias ("_asm_thline")));
    long asm_thlineskipmodify(long,long,long,long,long,long) __attribute__ ((alias ("_asm_thlineskipmodify")));
    long asm_tsethlineshift(long,long) __attribute__ ((alias ("_asm_tsethlineshift")));
    long asm_setupslopevlin(long,long,long) __attribute__ ((alias ("_asm_setupslopevlin")));
    long asm_slopevlin(long,long,long,long,long,long) __attribute__ ((alias ("_asm_slopevlin")));
    long asm_settransnormal(void) __attribute__ ((alias ("_asm_settransnormal")));
    long asm_settransreverse(void) __attribute__ ((alias ("_asm_settransreverse")));
    long asm_setupdrawslab(long,long) __attribute__ ((alias ("_asm_setupdrawslab")));
    long asm_drawslab(long,long,long,long,long,long) __attribute__ ((alias ("_asm_drawslab")));
    long asm_stretchhline(long,long,long,long,long,long) __attribute__ ((alias ("_asm_stretchhline")));
    long asm_isvmwarerunning(void) __attribute__ ((alias ("_asm_isvmwarerunning")));

    /*
	 * !!! I need a reference to this, for mprotect(), but the actual function
     * !!!  is never called in BUILD...just from other ASM routines. --ryan.
	 */
    long asm_prohlineasm4(void) __attribute__ ((alias ("_asm_prohlineasm4")));

  #endif /* ELF/GCC */
#endif /* defined USE_I386_ASM */

#ifdef __cplusplus
}
#endif

#endif /* include-once-blocker. */

/* end of a.h ... */


