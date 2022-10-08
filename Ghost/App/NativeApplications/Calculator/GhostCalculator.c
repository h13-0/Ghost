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
#include "GhostCalculator.h"

// Standard headers.

// ThirdParty headers.

// Ghost headers.
// TODO: Use app api instead of system api.
#include "GhostClock.h"

/***********************************Defines************************************/



/***********************************Typedefs***********************************/
typedef struct
{
	GhostAppToken_t Token;
	lv_obj_t* Screen;
} GhostCalculator_t;

/**********************************Prototypes**********************************/
static GhostCalculator_t calculator;


/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <returns></returns>
static GhostError_t setupUI(void);


/// <summary>
/// Entry function of Ghost Calculator.
/// </summary>
/// <param name="Param">Pointor of Arguments.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostCalculatorRun(const GhostAppArgs_t* Args)
{
	calculator.Token = Args->AppToken;
	calculator.Screen = GhostAppGetVirtualScreen(calculator.Token, lv_color_black());

	setupUI();

	GhostAppExec(Args->AppToken);
}



static GhostError_t setupUI(void)
{

	return GhostOK;
}
