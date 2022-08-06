#include "GhostPlatformConfigs.h"

#if defined(MacroGhostThemeAppleInfograph)

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

#include "GhostTheme.h"
#include "GhostAppleInfograph.h"

DeclareNativeThemeInfo(MacroGhostThemeAppleInfograph);


/// <summary>
/// Pointers to all controls and resources.
/// </summary>
typedef struct
{
	// Essential resources.
	

	// Resources of main page.
	lv_meter_scale_t* Scale;
	lv_obj_t* HourHand;
	lv_obj_t* MinuteHand;
	lv_obj_t* SecondHand;
	lv_obj_t* SecondHandCircle;
	lv_point_t* SecondHandPoints;

	lv_style_t BubbleStyle;

} AppleInfoGraphResource_t;

/// <summary>
/// Initialize theme common resource.
///		This function will not initialize all other pages.
/// </summary>
/// <param name="void"></param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThemeAppleInfographInit(void)
{
	void* resourcePtr = GhostNativeThemeMemCalloc(1, sizeof(AppleInfoGraphResource_t));
	if (resourcePtr == NULL)
	{
		return GhostErrorThemeOutOfMemory;
	}
	GhostNativeThemeSetResourcePointor(resourcePtr);

}


/// <summary>
/// 
/// </summary>
/// <param name="MainPage"></param>
/// <returns>Function execution result.</returns>
GhostError_t GhostThemeAppleInfographMainPageCreate(lv_obj_t* MainPage, void* ResourcePtr)
{
	AppleInfoGraphResource_t* Resource = ResourcePtr;

	// Init main page.
	GhostLV_Lock();

	// Get screen info.
	int width, height;
	GhostLogTerminateIfErr(Fatal, GhostNativeThemeGetResolution(&width, &height));

	// Create scale.
	Resource->Scale = lv_meter_create(MainPage);
	int minWH = min(width, height);
	int maxWH = max(width, height);
	int margin = minWH / 20;

	int scaleSize = 0;
	if (height - 2 * margin > minWH)
	{
		scaleSize = minWH;
	}
	else {
		scaleSize = height - margin * 2;
	}
	if (scaleSize % 2)
	{
		scaleSize++;
	}

	// Set size and pos.
	lv_obj_set_size(Resource->Scale, scaleSize, scaleSize);
	lv_obj_set_pos(Resource->Scale, (width - scaleSize) / 2, (height - scaleSize) / 2);

	// Scale style
	lv_color_t centralCircleColor = lv_color_make(223, 223, 223);
	lv_obj_set_style_bg_color(Resource->Scale, centralCircleColor, 0);
	lv_obj_set_style_border_width(Resource->Scale, 0, 1);
	lv_obj_set_style_border_color(Resource->Scale, lv_color_make(227, 227, 227), 0);
	float scalePadSize = scaleSize * 0.015;
	lv_obj_set_style_pad_all(Resource->Scale, scalePadSize, 0);

	// Set scale.
	// Minute scale.
	lv_meter_scale_t* scale_min = lv_meter_add_scale(Resource->Scale);
	lv_meter_set_scale_ticks(Resource->Scale, scale_min, 121, scaleSize * 0.01, ceil(scaleSize * 0.04) - 2, lv_color_make(150, 150, 150));
	lv_meter_set_scale_range(Resource->Scale, scale_min, 0, 60, 360, 270);

	// Hour scale.
	lv_meter_scale_t* scale_hour = lv_meter_add_scale(Resource->Scale);
	lv_meter_set_scale_ticks(Resource->Scale, scale_hour, 12, 0, scaleSize * 0.04, lv_color_black());
	lv_meter_set_scale_major_ticks(Resource->Scale, scale_hour, 1, scaleSize * 0.01 + 1, scaleSize * 0.04, lv_color_make(30, 30, 30), 10);
	lv_meter_set_scale_range(Resource->Scale, scale_hour, 1, 12, 330, 300);
	// Disable label.
	lv_obj_set_style_text_opa(Resource->Scale, 0, 0);
	lv_obj_remove_style(Resource->Scale, NULL, LV_PART_INDICATOR);
	lv_obj_remove_style(Resource->Scale, NULL, LV_PART_INDICATOR);

	// hour hand.
	Resource->HourHand = lv_img_create(MainPage);
	lv_img_set_src(Resource->HourHand, "C:./System/Apps/tech.h13.ghost.launcher/Themes/AppleInfograph/Resources/hour_aw_hand_bl.png");
	lv_img_set_pivot(Resource->HourHand, 12, 8.5);
	const float handRatio = (scaleSize * 0.45 * 1.04938) / 175;
	lv_img_set_zoom(Resource->HourHand, handRatio * 256);
	lv_img_set_angle(Resource->HourHand, 150);
	lv_obj_set_pos(Resource->HourHand, width / 2 - 12 - 1, height / 2 - 8.5 - 1);

	// minute hand.
	Resource->MinuteHand = lv_img_create(MainPage);
	lv_img_set_src(Resource->MinuteHand, "C:./System/Apps/tech.h13.ghost.launcher/Themes/AppleInfograph/Resources/minute_aw_hand_bl.png");
	lv_img_set_pivot(Resource->MinuteHand, 8, 10);
	lv_img_set_zoom(Resource->MinuteHand, handRatio * 256);
	lv_img_set_angle(Resource->MinuteHand, 300);
	lv_obj_set_pos(Resource->MinuteHand, width / 2 - 8 - 1, height / 2 - 10 - 1);

	// second hand.
	//float secondHandLength = 0.6 * scaleSize;
	float secondHandFontLength = 0.81 * 0.6 * scaleSize;
	float secondHandBackLength = 0.19 * 0.6 * scaleSize;
	float secondDegree = 60;
	secondDegree = secondDegree / 180 * M_PI;

	Resource->SecondHandPoints = GhostNativeThemeMemMalloc(sizeof(lv_point_t) * 3);
	*(Resource->SecondHandPoints) = (lv_point_t){ width / 2 + sin(secondDegree) * secondHandFontLength, height / 2 - cos(secondDegree) * secondHandFontLength };
	*(Resource->SecondHandPoints + 1) = (lv_point_t){ width / 2, height / 2 };
	*(Resource->SecondHandPoints + 2) = (lv_point_t){ width / 2 - sin(secondDegree) * secondHandBackLength, height / 2 + cos(secondDegree) * secondHandBackLength };

	Resource->SecondHand = lv_line_create(MainPage);
	lv_obj_set_style_line_color(Resource->SecondHand, lv_color_make(255, 0, 0), 0);
	lv_obj_set_style_line_width(Resource->SecondHand, 3, 0);
	lv_line_set_points(Resource->SecondHand, Resource->SecondHandPoints, 3);

	// second hand cricle.
	Resource->SecondHandCircle = lv_obj_create(MainPage);
	float secondHandCircleRadius = min(width, height) / 72.0;
	lv_obj_set_size(Resource->SecondHandCircle, secondHandCircleRadius * 2, secondHandCircleRadius * 2);
	lv_obj_set_pos(Resource->SecondHandCircle, (width - secondHandCircleRadius) / 2 - 1, (height - secondHandCircleRadius) / 2 - 1);
	lv_obj_set_style_bg_color(Resource->SecondHandCircle, lv_color_black(), 0);
	lv_obj_set_style_border_color(Resource->SecondHandCircle, lv_color_make(255, 0, 0), 0);
	lv_obj_set_style_border_width(Resource->SecondHandCircle, secondHandCircleRadius / 2, 0);

	// Bubbles
	// set style.
	lv_style_init(&Resource->BubbleStyle);
	int bubbleSize = scaleSize * 0.287;
	if (bubbleSize % 2)
	{
		bubbleSize += 3;
	}
	else
	{
		bubbleSize += 2;
	}

	lv_style_set_bg_color(&Resource->BubbleStyle, lv_color_make(22, 22, 22));
	lv_style_set_radius(&Resource->BubbleStyle, bubbleSize / 2);
	lv_style_set_size(&Resource->BubbleStyle, bubbleSize);
	lv_style_set_border_color(&Resource->BubbleStyle, lv_color_make(255, 255, 255));
	lv_style_set_border_opa(&Resource->BubbleStyle, 50);
	int bubblePad = (bubbleSize * 0.05 + 0.5); //rounding.
	int bubbleBorderWidth = ceil(bubbleSize * 0.01);
	lv_style_set_pad_all(&Resource->BubbleStyle, bubblePad);
	lv_style_set_border_width(&Resource->BubbleStyle, bubbleBorderWidth);

	float bubbleMargin = scaleSize * 0.12037;
	float bubbleToEdge = bubbleMargin - scalePadSize - 2;
	float bubbleToCenter = (scaleSize - bubbleSize) / 2 - scalePadSize - 1;
	lv_obj_t* bubbleUp = lv_obj_create(Resource->Scale);
	lv_obj_add_style(bubbleUp, &Resource->BubbleStyle, 0);
	lv_obj_set_pos(bubbleUp, bubbleToCenter, bubbleToEdge);
	lv_obj_set_scrollbar_mode(bubbleUp, LV_SCROLLBAR_MODE_OFF);

	lv_obj_t* bubbleDown = lv_obj_create(Resource->Scale);
	lv_obj_add_style(bubbleDown, &Resource->BubbleStyle, 0);
	lv_obj_set_pos(bubbleDown, bubbleToCenter, scaleSize - bubbleMargin - scalePadSize + 1 - bubbleSize);
	lv_obj_set_scrollbar_mode(bubbleDown, LV_SCROLLBAR_MODE_OFF);

	lv_obj_t* bubbleLeft = lv_obj_create(Resource->Scale);
	lv_obj_add_style(bubbleLeft, &Resource->BubbleStyle, 0);
	lv_obj_set_pos(bubbleLeft, bubbleToEdge, bubbleToCenter);
	lv_obj_set_scrollbar_mode(bubbleLeft, LV_SCROLLBAR_MODE_OFF);

	lv_obj_t* bubbleRight = lv_obj_create(Resource->Scale);
	lv_obj_add_style(bubbleRight, &Resource->BubbleStyle, 0);
	lv_obj_set_pos(bubbleRight, scaleSize * 0.87963 - scalePadSize + 1 - bubbleSize, bubbleToCenter);
	lv_obj_set_scrollbar_mode(bubbleRight, LV_SCROLLBAR_MODE_OFF);

	// Set bubble images.


	// earth.
	// TODO:
	lv_obj_t* earthImg = lv_img_create(bubbleLeft);
	lv_img_header_t header;
	lv_img_decoder_get_info("C:./System/Apps/tech.h13.ghost.launcher/Themes/AppleInfograph/Resources/earth.png", &header);
	lv_img_set_src(earthImg, "C:./System/Apps/tech.h13.ghost.launcher/Themes/AppleInfograph/Resources/earth.png");
	lv_img_set_pivot(earthImg, -1, -1); //I don't know why..
	lv_img_set_zoom(earthImg, (256 * (bubbleSize - 2 * (bubblePad + bubbleBorderWidth)) / min(header.w, header.h) + 0.5));


	//lv_obj_set_style_bg_img_src(earthImg, "C:./System/Apps/tech.h13.ghost.launcher/Themes/AppleInfograph/Resources/earth.png", 0);

	GhostLV_Unlock();
}


#endif //#if defined(MacroGhostThemeAppleInfograph)
