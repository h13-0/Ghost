/*******************************************************************************
 * @File   : $safeitemname$
 * @Path   : $rootnamespace$
 * @Module :
 *
 * @Author : $username$
 * @Time   : $time$
 * @license: AGPL-3.0(https://github.com/h13-0/Ghost/blob/master/LICENSE)
 * @Notes  :
 *		This template file is only applicable to visual studio.
 *
*******************************************************************************/

/***********************************Includes***********************************/
// Configs.
#include "GhostPlatformConfigs.h"
// Self headers.

// Standard headers.

// ThirdParty headers.

// Ghost headers.


/***********************************Defines************************************/



/***********************************Typedefs***********************************/


/**********************************Prototypes**********************************/





/// <summary>
/// Get virtual screen by the pointer of application info.
/// </summary>
/// <param name="AppInfoPtr">Pointor of application info.</param>
/// <param name="ScreenPtr">Pointor of virtual screen.(pointor to lv_obj_t*)</param>
/// <returns>Function execution result.</returns>
/// TODO: Release page automatically when releasing the running program.
GhostError_t GhostAppGetVirtualScreen(const GhostAppInfo_t const AppInfoPtr, lv_obj_t** const ScreenPtr)
{
	//GhostLogIfError(Warning, GhostLV_Lock());
	GhostLV_Lock();
	lv_obj_t* screen = lv_obj_create(lv_scr_act());

	if (screen != NULL)
	{
		// TODO: Check front or background.
		// lv_obj_add_flag(screen, LV_OBJ_FLAG_HIDDEN);

		// Set style.
		int width, height, radius;
		GhostScreenGetResolution(&width, &height);
		GhostScreenGetRadius(&radius);
		lv_style_set_radius(&screenStyle, radius);
		lv_obj_add_style(screen, &screenStyle, 0);
		lv_obj_set_scrollbar_mode(screen, LV_SCROLLBAR_MODE_OFF);
		lv_obj_set_pos(screen, 0, 0);
		lv_obj_set_size(screen, width, height);

	}

	GhostLogIfError(Warning, GhostLV_Unlock());
	if (screen == NULL)
	{

	}
	else {
		*ScreenPtr = screen;
		//*VirtualScreen = screen;
		return GhostOK;
	}

	return GhostOK;
}
