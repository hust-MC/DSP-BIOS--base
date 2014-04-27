/**********************************************************************
* File: f28335_BIOS_flash.cmd -- Linker command file for DSP/BIOS code
* with DSP in Boot to Flash bootmode.
*
* History: 09/29/08 - Corrected linkage of internalMemFuncs (D. Alter)
*          12/13/07 - original (D. Alter)
**********************************************************************/


/**************************************************************/
/* Link all user defined sections                             */
/**************************************************************/
SECTIONS
{
/*** User Defined Sections ***/
   codestart      :> BEGIN_FLASH,           PAGE = 0           /* Used by file CodeStartBranch.asm */
   csm_rsvd       :> CSM_RSVD,              PAGE = 0           /* Used by file passwords.asm */         /* Used by file Xintf.c.  Link to internal memory */
   passwords      :> PASSWORDS,             PAGE = 0           /* Used by file passwords.asm */

	ramfuncs      : LOAD = FLASH_ABCDEFGH, PAGE = 0 
					RUN = L7SARAM, PAGE = 0 
					RUN_START(_ramfuncs_runstart), 
					LOAD_START(_ramfuncs_loadstart), 
					LOAD_END(_ramfuncs_loadend)

	xc_program    : LOAD = FLASH_ABCDEFGH, PAGE = 0
					RUN = L7SARAM, PAGE = 0 
					RUN_START(_xcfuncs_runstart), 
					LOAD_START(_xcfuncs_loadstart), 
					LOAD_END(_xcfuncs_loadend)

	global_data   :> L0123SARAM, PAGE = 1
	xc_data       :> L3SARAM, PAGE = 1
	const_data    :> FLASH_ABCDEFGH, PAGE = 0

	IQmath        : LOAD = FLASH_ABCDEFGH, PAGE = 0 
					RUN = L7SARAM, PAGE = 0
					RUN_START(_iqfuncs_runstart), 
					LOAD_START(_iqfuncs_loadstart), 
					LOAD_END(_iqfuncs_loadend)

	IQmathTables  :> IQTABLES, PAGE = 0, TYPE = NOLOAD
}

/******************* end of file ************************/
