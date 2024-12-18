#include "ev3api.h"
#include "Action.h"
#include "app.h"
#include "Button.h"
#include "EV3ColorSensor.h"
#include "LineTraceAction.h"
#include "Motor.h"
#include "RearMotor.h"
#include "RunParameter.h"
#include "TouchSensor.h"
#include "Display.h"
#include "ArmControl.h"
#include "CalcCurrentLocation.h"
#include "RunStraightAction.h"
#include "stdio.h"
#include "DistanceJudgement.h"
#include "Tactics.h"
#include "RotateMachineAction.h"
#include "RotateAction.h"
#include "LapSectionTactics.h"
#include "ArmPositionSetAction.h"
#include "FreeAreaTactics.h"
#include "FreeArea.h"
#include "Display.h"

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

/* LCD?��t?��H?��?��?��g?��T?��C?��Y */
#define CALIB_FONT (EV3_FONT_SMALL)
#define CALIB_FONT_WIDTH (12 /*TODO: magic number*/)
#define CALIB_FONT_HEIGHT (16 /*TODO: magic number*/)
#define N 10

// using?��錾
using ev3api::Motor;
using ev3api::ColorSensor;
// using ev3api::Clock;
using ev3api::TouchSensor;

// Device objects
// ?��I?��u?��W?��F?��N?��g?��?��ÓI?��Ɋm?��ۂ�?��?��
Motor gArmMotor(PORT_A);
Motor gRightWheel(PORT_B);
Motor gLeftWheel(PORT_C);
ColorSensor gColorSensor(PORT_2);
TouchSensor gTouchSensor(PORT_1);

// ?��I?��u?��W?��F?��N?��g?��̒�`
static RearMotor *gRearMotor;
static EV3ColorSensor *gEV3ColorSensor;
static RunParameter *gRunParameter;
static LineTraceAction *gLineTraceAction;
static Button *gButton;
static Display *gDisplay;
static ArmControl *gArmControl;
static RunStraightAction *gRunStraightAction;
static CalcCurrentLocation *gCalcCurrentLocation;
static DistanceJudgement *gDistanceJudgement;
static RotateAction *gRotateAction;
static RotateMachineAction *gRotateMachineAction; 
static LapSectionTactics *gLapSectionTactics;
static ArmPositionSetAction *gArmPositionSetAction;
static FreeAreaTactics *gFreeAreaTactics;
static FreeArea *gFreeArea;

//static SpeedAdjustment *gSpeedAdjustment;

static void user_system_create()
{
    // ?��I?��u?��W?��F?��N?��g?��̐�?��?��
    // gTimerJudgement = new TimerJudgement(gClock);
    gEV3ColorSensor = new EV3ColorSensor(gColorSensor);
    // gEV3SonarSensor = new EV3SonarSensor(gSonarSensor, gClock);
    // gEV3GyroSensor = new EV3GyroSensor(gGyroSensor);
    gRearMotor = new RearMotor(gLeftWheel, gRightWheel);
    gArmControl = new ArmControl(gArmMotor);
    gCalcCurrentLocation = new CalcCurrentLocation(gRearMotor);
    gDistanceJudgement = new DistanceJudgement(gCalcCurrentLocation);
    // gStraightDetection = new StraightDetection(gRearMotor, gTimerJudgement);
    gRunParameter = new RunParameter();
    // gSpeedAdjustment = new SpeedAdjustment(gClock, gRunParameter);
    gLineTraceAction = new LineTraceAction();
    gDisplay = new Display();
    gButton = new Button(gTouchSensor);
    gArmPositionSetAction = new ArmPositionSetAction();
    gRunStraightAction = new RunStraightAction();
    gRotateMachineAction = new RotateMachineAction();
    gRotateAction = new RotateAction(gRotateMachineAction);
    gFreeAreaTactics = new FreeAreaTactics();
    // gCurvatureRunAction = new CurvatureRunAction();
    // gDecelerationRotaryAction = new DecelerationRotaryAction();
    // gSectionControlTactics = new SectionControlTactics(gColorSensor);
    gLapSectionTactics = new LapSectionTactics();
    gFreeArea = new FreeArea(gFreeAreaTactics);
    gDisplay = new Display();
    // gCalibration = new Calibration(gTouchSensor, gRunParameter, gTimerJudgement, gEV3ColorSensor, gRearMotor, gCalcCurrentLocation);
    // gIPCommunication = new IPCommunication();
    // gBlockBingo = new BlockBingo(gRearMotor);

    // gAlgori = new Algori();

    // gCleaningPutAction = new CleaningPutAction();

    // //Action?��N?��?��?��X?��ɎQ?��Ƃ�ݒ肷?��?��
    Action::setObject(gRunParameter, gRearMotor, gArmControl, gEV3ColorSensor, gCalcCurrentLocation, gLineTraceAction, gRunStraightAction, gArmPositionSetAction);
    // //Tactics?��N?��?��?��X?��ɎQ?��Ƃ�ݒ肷?��?��
    Tactics::setObject(gEV3ColorSensor, gRunParameter, gCalcCurrentLocation, gDistanceJudgement, gLineTraceAction, gRunStraightAction, gRotateMachineAction, gRotateAction, gArmControl, gDisplay);

    // LED?��?��?��I?��?��?��?��?��W?��Ɍ�?��点?��?��
    ev3_led_set_color(LED_ORANGE);
}

/*
static void user_system_destroy()
{
    //?��?��?��[?��^?��̃G?��?��?��R?��[?��_?��l?��?��?��?��?��Z?��b?��g
    gRightWheel.reset();
    gLeftWheel.reset();
    // gArmMotor.reset();
    // gTailMotor.reset();

    //?��I?��u?��W?��F?��N?��g?��̍폜
}
*/

void main_task(intptr_t unused) 
{
    user_system_create(); // ?��Z?��?��?��T?��⃂�[?��^?��̏�?��?��?��?��?��?��?��?��

    sta_cyc(EV3_CYC_RUN);
    slp_tsk();
    stp_cyc(EV3_CYC_RUN);
    
    
    
    ext_tsk();
}

static int state = 0;
//static int state = 120; //?��F?��?��?��m
static char buf[100];

void run_task(intptr_t unused) 
{
    /*
    char buf[100];
    sprintf(buf, "Brightness: %lf", gEV3ColorSensor->getColorBrightness());
    //sprintf(buf, "Brightness: %d", gEV3ColorSensor->getBrightness());
    gDisplay->display(buf,0,0);
    */

    gCalcCurrentLocation->calcCurrentLocation(); //?��v?��Z?��?��?��\?��b?��h
    gEV3ColorSensor->getColorBrightness();
    switch(state){
        case 0:
        if (gButton->Touch_sensor_isPressed())//gButton->button_left_isPressed()
        {
            /*
	        ev3_lcd_set_font(EV3_FONT_MEDIUM);
	        char buf[20];
	        int voltage = ev3_battery_voltage_mV();
	        sprintf(buf, "Batt(AFT):%4.1f%%", voltage / 100.0);
	        ev3_lcd_draw_string(buf, 0, CALIB_FONT_HEIGHT * 1);
            */

            memfile_t memfile; // メモリファイルの構造体を作成
            ev3_memfile_load("ev3rt/res/Jinnguru1.wav", &memfile); //SDカード内の"test.wav"をメモリファイルとしてロード
            ev3_speaker_set_volume(10); //音量の設定
            ev3_speaker_play_file(&memfile, SOUND_MANUAL_STOP); // 音声ファイルを再生
		    /*
            gRunParameter->setArmAngle(0);
		    gRunParameter->setArmPower(15);
		    gArmPositionSetAction->updateParameter();
            */
            state = 5;
            //state = 8;
            //state = 10;
            //state = 14;
        }
        break;

        case 5:
            gArmControl->setPower(10);
            if (gArmControl->getEncoder() == 0)//0
            {
		        gArmControl->setPower(0);
		        gArmControl->setBrake(true);
		        gArmControl->resetEncoder();
                //state = 10;
                //state = 14;
                state = 120;
            }
        break;

	case 8:
		gArmPositionSetAction->start();
		if(gArmPositionSetAction->isFinished())
		{
			gArmPositionSetAction->stop();
			state=999;
		}
		break;  

        case 10:
            gLapSectionTactics->execute();
            if(gLapSectionTactics->isFinished())
            {
                //state=18;
                state=14;
            }
        break;

        //
        case 14:
            gCalcCurrentLocation->setAngle(0);
		    gRunParameter->setLineTraceSpeed(20);
		    gRunParameter->setKP(0.02);
		    gRunParameter->setKI(0);
		    gRunParameter->setKD(1);
            gDistanceJudgement->stop();
            gDistanceJudgement->setDistance(60);
            gDistanceJudgement->start();
		    gLineTraceAction->updateParameter();
		    state=15;
        break;

        case 15:
            gLineTraceAction->start();
            if(gEV3ColorSensor->isColor_RED())
            {
                ev3_speaker_play_tone(NOTE_C6, 200);
                gLineTraceAction->stop();
                gDistanceJudgement->stop();
                gDistanceJudgement->setDistance(10);
                gDistanceJudgement->start();
                state=40;
            }

        case 18:
                gDistanceJudgement->stop();
                gDistanceJudgement->setDistance(10);
                gDistanceJudgement->start();
                state = 40;
        break;

        case 20:
            gRunStraightAction->straight(20,20);
            if(gDistanceJudgement->isDistanceOut())
            {
                gRunStraightAction->stop();
                gDistanceJudgement->stop();
                gDistanceJudgement->setDistance(20);
                gDistanceJudgement->start();
		        gCalcCurrentLocation->setAngle(0);
                gRunParameter->setRotateAngle(-90);
                gRunParameter->setRotateSpeed(20);
                gRotateMachineAction->updateParameter();
		        state=40;
            }
        break;

        case 40:
            gRunStraightAction->straight(0,30);
            if(gDistanceJudgement->isDistanceOut())
            {
                gRunStraightAction->stop();
                gDistanceJudgement->stop();
                gDistanceJudgement->setDistance(10);
                gDistanceJudgement->start();
		        state=50;
            }
        break;

        case 50:
            gFreeArea->execute();
            if(gFreeArea->isFinished())
            {
                state=110;
            }
        break;

        case 100:
            gArmControl->setPower(10);
            if (gArmControl->getEncoder() == 0)//0
            {
	            ev3_speaker_play_tone(NOTE_G6, 100);
		        gArmControl->setPower(0);	//?��A?��[?��?��?��?��~
		        gArmControl->setBrake(true);
		        gArmControl->resetEncoder();	//?��G?��?��?��R?��[?��_?��l?��?��?��?��?��Z?��b?��g
                state = 110;
            }
        break;

        case 120:
            gArmControl->setPower(10);
            if (gArmControl->getEncoder() == 65)//0
            {
		        gArmControl->setPower(0);	//?��A?��[?��?��?��?��~
		        gArmControl->setBrake(true);
		        gArmControl->resetEncoder();	//?��G?��?��?��R?��[?��_?��l?��?��?��?��?��Z?��b?��g
                state = 110;
            }
        break;

        case 110:
            gEV3ColorSensor->getColorBrightness();
		    ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
		    sprintf(buf, "Calibration");
		    ev3_lcd_draw_string(buf, 0, CALIB_FONT_HEIGHT * 1);
		    sprintf(buf, "Hue : %f", gEV3ColorSensor->getHue());
		    ev3_lcd_draw_string(buf, 0, CALIB_FONT_HEIGHT * 2);		    
            sprintf(buf, "Saturation : %f", gEV3ColorSensor->getSaturation());
		    ev3_lcd_draw_string(buf, 0, CALIB_FONT_HEIGHT * 3);		    
            sprintf(buf, "getBright : %f", gEV3ColorSensor->getBright());
		    ev3_lcd_draw_string(buf, 0, CALIB_FONT_HEIGHT * 4);
        break;
    }
    ext_tsk();
}