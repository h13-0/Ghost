/*********************
 *      INCLUDES
 *********************/
#include "GhostPlatformConfigs.h"
#include "QtSimulator.h"
#include "lvgl.h"
#include "GhostPlatformConfigs.h"
#include "GhostScreen.h"
#include <stdlib.h>
#include <stddef.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(GhostQtSimulator_t* QtSimulatorPtr);

static void disp_flush(lv_disp_drv_t* disp_drv, const lv_area_t* area, lv_color_t* color_p);
//static void gpu_fill(lv_disp_drv_t * disp_drv, lv_color_t * dest_buf, lv_coord_t dest_width,
//        const lv_area_t * fill_area, lv_color_t color);

/**********************
 *  STATIC VARIABLES
 **********************/
static GhostQtSimulator_t* simulatorPtr = NULL;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_disp_init(GhostQtSimulator_t* QtSimulatorPtr)
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/
    disp_init(QtSimulatorPtr);

    /*-----------------------------
     * Create a buffer for drawing
     *----------------------------*/

    /* Example for 3) also set disp_drv.full_refresh = 1 below*/
    static lv_disp_draw_buf_t draw_buf_dsc;
    static lv_color_t* buf_3_1 = NULL;
    static lv_color_t* buf_3_2 = NULL;
    if (buf_3_1 == NULL)
    {
        buf_3_1 = calloc(1, GhostScreenGetWidth() * GhostScreenGetHeight() * sizeof(lv_color_t));
    }
    
    if (buf_3_2 == NULL)
    {
        buf_3_2 = calloc(1, GhostScreenGetWidth() * GhostScreenGetHeight() * sizeof(lv_color_t));
    }

    lv_disp_draw_buf_init(&draw_buf_dsc, buf_3_1, buf_3_2, GhostScreenGetWidth() * GhostScreenGetHeight());   /*Initialize the display buffer*/

    /*-----------------------------------
     * Register the display in LVGL
     *----------------------------------*/

    static lv_disp_drv_t disp_drv;                         /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);                    /*Basic initialization*/

    /*Set up the functions to access to your display*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = GhostScreenGetWidth();
    disp_drv.ver_res = GhostScreenGetHeight();

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = disp_flush;

    /*Set a display buffer*/
    disp_drv.draw_buf = &draw_buf_dsc;

    /*Required for Example 3)*/
    //disp_drv.full_refresh = 1

    /* Fill a memory array with a color if you have GPU.
     * Note that, in lv_conf.h you can enable GPUs that has built-in support in LVGL.
     * But if you have a different GPU you can use with this callback.*/
     //disp_drv.gpu_fill_cb = gpu_fill;

     /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

 /*Initialize your display and the required peripherals.*/
static void disp_init(GhostQtSimulator_t* QtSimulatorPtr)
{
    /*You code here*/
    simulatorPtr = QtSimulatorPtr;
}

/*Flush the content of the internal buffer the specific area on the display
 *You can use DMA or any hardware acceleration to do this operation in the background but
 *'lv_disp_flush_ready()' has to be called when finished.*/
static void disp_flush(lv_disp_drv_t* disp_drv, const lv_area_t* area, lv_color_t* color_p)
{
    /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one*/

    GhostQtSimulatorDrawScreen(simulatorPtr, area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (unsigned char*)color_p);

    /*IMPORTANT!!!
     *Inform the graphics library that you are ready with the flushing*/
    lv_disp_flush_ready(disp_drv);
}

/*OPTIONAL: GPU INTERFACE*/

/*If your MCU has hardware accelerator (GPU) then you can use it to fill a memory with a color*/
//static void gpu_fill(lv_disp_drv_t * disp_drv, lv_color_t * dest_buf, lv_coord_t dest_width,
//                    const lv_area_t * fill_area, lv_color_t color)
//{
//    /*It's an example code which should be done by your GPU*/
//    int32_t x, y;
//    dest_buf += dest_width * fill_area->y1; /*Go to the first line*/
//
//    for(y = fill_area->y1; y <= fill_area->y2; y++) {
//        for(x = fill_area->x1; x <= fill_area->x2; x++) {
//            dest_buf[x] = color;
//        }
//        dest_buf+=dest_width;    /*Go to the next line*/
//    }
//}


/// <summary>
/// Get screen resolution.
/// </summary>
/// <param name="Width">Width.</param>
/// <param name="Height">Height.</param>
/// <returns>Always GhostOK.</returns>
GhostError_t GhostScreenGetResolution(int* Width, int* Height)
{
    return GhostQtSimulatorGetScreenResolution(simulatorPtr, Width, Height);
}

/// <summary>
/// Get screen resolution.
/// </summary>
/// <param name=""></param>
/// <returns>Width or heigth.</returns>
int GhostScreenGetWidth(void)
{
    int width;
    GhostQtSimulatorGetScreenWidth(simulatorPtr, &width);
    return width;
}

int GhostScreenGetHeight(void)
{
    int height;
    GhostQtSimulatorGetScreenHeight(simulatorPtr, &height);
    return height;
}


/// <summary>
/// Get screen fillet radius.
/// </summary>
/// <param name="Radius">Radius.</param>
/// <returns>Always GhostOK.</returns>
GhostError_t GhostScreenGetRadius(int* Radius)
{
	//
    return GhostOK;
}
    