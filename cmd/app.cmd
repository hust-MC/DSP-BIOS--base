SECTIONS
{
	ramfuncs      :> L03SARAM, PAGE = 0
	xc_program    :> L03SARAM, PAGE = 0

	global_data   :> L47SARAM, PAGE = 1
	xc_data       :> L7SARAM,  PAGE = 1
	
	const_data    :> L03SARAM, PAGE = 0
	IQmath        :> L03SARAM, PAGE = 0
	IQmathTables  :> BOOTROM,  PAGE = 0, TYPE = NOLOAD
}