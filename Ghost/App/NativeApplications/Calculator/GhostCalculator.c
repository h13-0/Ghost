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


/***********************************Defines************************************/



/***********************************Typedefs***********************************/
typedef struct
{
	GhostAppToken_t token;
} GhostCalculator_t;

/**********************************Prototypes**********************************/
static GhostCalculator_t calculator;


/// <summary>
/// Entry function of Ghost Calculator.
/// </summary>
/// <param name="Param">Pointor of Arguments.</param>
/// <returns>Function execution result.</returns>
GhostError_t GhostCalculatorRun(const GhostAppArgs_t* Args)
{


	GhostAppExec(Args->AppToken);
}
