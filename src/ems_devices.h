/*
 * General information about known EMS devices
 * 
 * Paul Derbyshire - https://github.com/proddy/EMS-ESP
 *
 * See ChangeLog.md for History
 * See README.md for Acknowledgments
 *
 */

#pragma once

#include "ems.h"


/*
 * Common
 */
#define EMS_TYPE_Version 0x02

/*
 * Boiler...
 */
#define EMS_TYPE_UBAMonitorFast 0x18              // is an automatic monitor broadcast
#define EMS_TYPE_UBAMonitorSlow 0x19              // is an automatic monitor broadcast
#define EMS_TYPE_UBAMonitorWWMessage 0x34         // is an automatic monitor broadcast
#define EMS_TYPE_UBAMaintenanceStatusMessage 0x1C // is an automatic monitor broadcast
#define EMS_TYPE_UBAParameterWW 0x33
#define EMS_TYPE_UBATotalUptimeMessage 0x14
#define EMS_TYPE_UBAMaintenanceSettingsMessage 0x15
#define EMS_TYPE_UBAParametersMessage 0x16
#define EMS_TYPE_UBASetPoints 0x1A
#define EMS_TYPE_UBAFunctionTest 0x1D

#define EMS_OFFSET_UBAParameterWW_wwtemp 2              // WW Temperature
#define EMS_OFFSET_UBAParameterWW_wwactivated 1         // WW Activated
#define EMS_OFFSET_UBAParameterWW_wwComfort 9           // WW is in comfort or eco mode
#define EMS_VALUE_UBAParameterWW_wwComfort_Comfort 0x00 // the value for comfort
#define EMS_VALUE_UBAParameterWW_wwComfort_Eco 0xD8     // the value for eco

/*
 * Thermostats...
 */

// Common for all thermostats
#define EMS_TYPE_RCTime 0x06               // is an automatic thermostat broadcast
#define EMS_TYPE_RCOutdoorTempMessage 0xA3 // is an automatic thermostat broadcast, outdoor external temp

// RC10 specific
#define EMS_TYPE_RC10StatusMessage 0xB1       // is an automatic thermostat broadcast giving us temps
#define EMS_TYPE_RC10Set 0xB0                 // for setting values like temp and mode
#define EMS_OFFSET_RC10Set_temp 4             // position of thermostat setpoint temperature
#define EMS_TYPE_RC10StatusMessage_setpoint 1 // setpoint temp
#define EMS_TYPE_RC10StatusMessage_curr 3     // current temp

// RC20 specific
#define EMS_TYPE_RC20StatusMessage 0x91       // is an automatic thermostat broadcast giving us temps
#define EMS_TYPE_RC20Set 0xA8                 // for setting values like temp and mode
#define EMS_OFFSET_RC20Set_mode 23            // position of thermostat mode
#define EMS_OFFSET_RC20Set_temp 28            // position of thermostat setpoint temperature
#define EMS_TYPE_RC20StatusMessage_setpoint 1 // setpoint temp
#define EMS_TYPE_RC20StatusMessage_curr 2     // current temp

// RC30 specific
#define EMS_TYPE_RC30StatusMessage 0x41       // is an automatic thermostat broadcast giving us temps
#define EMS_TYPE_RC30Set 0xA7                 // for setting values like temp and mode
#define EMS_OFFSET_RC30Set_mode 23            // position of thermostat mode
#define EMS_OFFSET_RC30Set_temp 28            // position of thermostat setpoint temperature
#define EMS_TYPE_RC30StatusMessage_setpoint 1 // setpoint temp
#define EMS_TYPE_RC30StatusMessage_curr 2     // current temp

// RC35 specific
#define EMS_TYPE_RC35StatusMessage 0x3E       // is an automatic thermostat broadcast giving us temps
#define EMS_TYPE_RC35StatusMessage_setpoint 2 // desired temp
#define EMS_TYPE_RC35StatusMessage_curr 3     // current temp
#define EMS_TYPE_RC35Set 0x3D                 // for setting values like temp and mode (Working mode HC1)
#define EMS_OFFSET_RC35Set_mode 7             // position of thermostat mode
#define EMS_OFFSET_RC35Set_temp_day 2         // position of thermostat setpoint temperature for day time
#define EMS_OFFSET_RC35Set_temp_night 1       // position of thermostat setpoint temperature for night time
#define EMS_OFFSET_RC35Get_mode_day 1         // position of thermostat day mode

// Easy specific
#define EMS_TYPE_EasyStatusMessage 0x0A        // reading values on an Easy Thermostat
#define EMS_TYPE_EasyStatusMessage_setpoint 10 // setpoint temp
#define EMS_TYPE_EasyStatusMessage_curr 8      // current temp

// Known EMS types
typedef enum {
    EMS_MODEL_NONE,
    EMS_MODEL_ALL, // common for all devices

    // generic ID for the boiler
    EMS_MODEL_UBA,

    // thermostats
    EMS_MODEL_ES73,
    EMS_MODEL_RC10,
    EMS_MODEL_RC20,
    EMS_MODEL_RC20F,
    EMS_MODEL_RC30,
    EMS_MODEL_RC35,
    EMS_MODEL_EASY,
    EMS_MODEL_RC310,
    EMS_MODEL_CW100

} _EMS_MODEL_ID;

// EMS types for known Buderus/Bosch devices. This list will be extended when new devices are recognized.
// format is MODEL_ID, PRODUCT ID, TYPE_ID, DESCRIPTION
const _Boiler_Type Boiler_Types[] = {

    {EMS_MODEL_UBA, 72, 0x08, "MC10"},
    {EMS_MODEL_UBA, 123, 0x08, "Buderus GB172/Nefit Trendline"},
    {EMS_MODEL_UBA, 115, 0x08, "Nefit Topline Compact"},
    {EMS_MODEL_UBA, 64, 0x08, "Sieger BK15 Boiler/Nefit Smartline"},
    {EMS_MODEL_UBA, 190, 0x09, "BC10 Base Controller"},
    {EMS_MODEL_UBA, 114, 0x09, "BC10 Base Controller"},
    {EMS_MODEL_UBA, 125, 0x09, "BC25 Base Controller"},
    {EMS_MODEL_UBA, 68, 0x09, "RFM20 Receiver"},
    {EMS_MODEL_UBA, 95, 0x08, "Bosch Condens 2500"},
    {EMS_MODEL_UBA, 251, 0x21, "MM10 Mixer Module"},  // warning, fake product id!
    {EMS_MODEL_UBA, 250, 0x11, "WM10 Switch Module"}, // warning, fake product id!

};

/*
 * Known thermostat types and their capabilities
 */
const _Thermostat_Type Thermostat_Types[] = {

    {EMS_MODEL_ES73, 76, 0x10, "Sieger ES73", EMS_THERMOSTAT_READ_YES, EMS_THERMOSTAT_WRITE_YES},
    {EMS_MODEL_RC10, 79, 0x17, "RC10/Nefit Moduline 100)", EMS_THERMOSTAT_READ_YES, EMS_THERMOSTAT_WRITE_YES},
    {EMS_MODEL_RC20, 77, 0x17, "RC20/Nefit Moduline 300)", EMS_THERMOSTAT_READ_YES, EMS_THERMOSTAT_WRITE_YES},
    {EMS_MODEL_RC20F, 93, 0x18, "RC20F", EMS_THERMOSTAT_READ_YES, EMS_THERMOSTAT_WRITE_YES},
    {EMS_MODEL_RC30, 78, 0x10, "RC30/Nefit Moduline 400)", EMS_THERMOSTAT_READ_YES, EMS_THERMOSTAT_WRITE_YES},
    {EMS_MODEL_RC35, 86, 0x10, "RC35", EMS_THERMOSTAT_READ_YES, EMS_THERMOSTAT_WRITE_YES},
    {EMS_MODEL_EASY, 202, 0x18, "TC100/Nefit Easy", EMS_THERMOSTAT_READ_YES, EMS_THERMOSTAT_WRITE_NO},
    {EMS_MODEL_RC310, 158, 0x10, "RC310", EMS_THERMOSTAT_READ_NO, EMS_THERMOSTAT_WRITE_NO},
    {EMS_MODEL_CW100, 255, 0x18, "Bosch CW100", EMS_THERMOSTAT_READ_NO, EMS_THERMOSTAT_WRITE_NO}

};
