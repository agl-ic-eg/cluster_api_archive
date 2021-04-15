#ifndef CLUSTER_API_SHIFTPOSITION_H
#define CLUSTER_API_SHIFTPOSITION_H

typedef enum
{
    IC_HMI_AT_OFF = 0,
    IC_HMI_AT_PARKING,
    IC_HMI_AT_REVERSE,
    IC_HMI_AT_NEUTRAL,
    IC_HMI_AT_DRIVE,
    IC_HMI_AT_SECOND,
    IC_HMI_AT_LOW_GEAR,
    IC_HMI_AT_FIRST,
    IC_HMI_AT_MANUAL,
    IC_HMI_AT_BRAKE,
    IC_HMI_AT_ALL_ON,
    IC_HMI_AT_ALL_OFF,
    IC_HMI_AT_UNUSED,
} IC_HMI_GEAR_AT_VAL;

typedef enum
{
    IC_HMI_MT_OFF = 0,
    IC_HMI_MT_FIRST,
    IC_HMI_MT_SECOND,
    IC_HMI_MT_THIRD,
    IC_HMI_MT_FOURTH,
    IC_HMI_MT_FIFTH,
    IC_HMI_MT_SIXTH,
    IC_HMI_MT_SEVENTH,
    IC_HMI_MT_EIGHTTH,
} IC_HMI_GEAR_MT_VAL;

IC_HMI_GEAR_AT_VAL getGearAtVal(void);
IC_HMI_GEAR_MT_VAL getGearMtVal(void);

#endif // CLUSTER_API_SHIFTPOSITION_H